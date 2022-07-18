/*
// Balance between performance and readability / maintainability
// C++ 20
*/

#include <iostream>
#include <string>
#include <sstream>          // istringstream
#include <vector>
#include <limits>

#include <map>              // Search, removal, and insertion operations have logarithmic complexity.
#include <unordered_map>    // Search, insertion, and removal of elements have average constant-time complexity.
// Note: in practice, when number of keys is small, map works faster than unordered_map 
// because of hashing overhead in unordered_map. 
// In this problem the number of keys is small: map is preferred over unordered_map.
// If we use it for other logs, where number of keys is huge, refactor for unordered_map. Mind sorting output.


int ParseCLIArguments (const int &argc, char* argv[], bool &no_stats, int &number_of_requests_threshold) 
{
    if (argc > 3) {
        std::cout << "Too many input parameters!" << std::endl;
        return 0;
    }
    if (argc >= 2) {
        const std::string arg1(argv[1]);

        if (arg1 == "-h" || arg1 == "--help" || arg1 == "help") {
            std::cout << "Usage: logmon [THRESHOLD] [no-stats] < input_log.txt" << std::endl;;
            std::cout << "Examples: " << std::endl;
            std::cout << "./logmon < sample_csv.txt" << std::endl;
            std::cout << "./logmon no-stats < sample_csv.txt" << std::endl;
            std::cout << "./logmon 12 < sample_csv.txt" << std::endl;
            std::cout << "./logmon 12 no-stats < sample_csv.txt" << std::endl;
            std::cout << "The threshold should be in the range from 1 to " 
            << std::numeric_limits<int>::max() << std::endl;
            return 0;
        }

        if (arg1 == "no-stats") {
            no_stats = true;
        }

        else
        {   
            try 
            {
                number_of_requests_threshold = std::stoi(argv[1]);
            }
            catch (std::invalid_argument const& ex) {
                std::cout << "Invalid_argument: " << ex.what() << '\n';
                return 1;
            }
            catch (const std::exception& ex) {
                std::cout << "Standard exception: " << ex.what() << '\n';
                return 1;
            }
            if (number_of_requests_threshold < 1) {
                std::cout << "The threshold should be in the range from 1 to " 
                << std::numeric_limits<int>::max() << std::endl;
                return 1;
            }

            if (argc == 3) {
                const std::string arg2(argv[2]);
                if (arg2 == "no-stats") {
                    no_stats = true;
                }
                else {
                    std::cout << "Try 'logmon -h' for usage instructions." << std::endl;
                    return 1;
                }
            }
        }
    }
    return -1;
}

std::vector<std::string> SplitLogLine (const std::string &line) 
{
    // Declare the output.
    // the log has the same number of fields in every line:
    //  "remotehost","rfc931","authuser","date","request","status","bytes"
    // vector instead of fixed size array for easier use of modern C++ features
    // vector instead of (hash) map for performance (avoid penalties for hashing / insertion)
    std::vector<std::string> tokens(7);
    
    // convert the line to isstream:
    std::istringstream iss(line);

    // temporary string
    std::string token;

    // We could return only the lines we need for the alerting.
    // However, the problem statemen says the following:
    //  For every 10 seconds of log lines, display stats about the traffic during those 10s: 
    //  the sections of the web site with the most hits, as well as statistics that might be useful for debugging.
    // So we keep the rest of the line because it might be useful for debugging.
    for (int i = 0; i < 7; ++i) {
        std::getline(iss, token, ',');
        tokens[i] = token;
    }

    return tokens;
}

// Gets request in the following form: "GET /api/user HTTP/1.0"
// Returns the section as per problem statement:
//  A section is defined as being what's before the second '/' in the resource section of the log line. 
//  For example, the section for "/api/user" is "/api" and the section for "/report" is "/report"
std::string GetWebSiteSection (const std::string &request) 
{
    std::string section;
    size_t first_forward_slash_index = request.find('/');
    size_t section_end_index = request.find_first_of(" /", first_forward_slash_index + 1);
    return request.substr(first_forward_slash_index, section_end_index - first_forward_slash_index);
}

void PrintStatsForXSec (
    const unsigned long &prev_time, 
    const int &x_seconds,
    const std::map<std::string, unsigned long long> &hits, 
    const std::map<std::string, unsigned long long> &http_status_counter) 
{
    std::cout << "Traffic stats from " << prev_time << " plus " << x_seconds << " seconds." << std::endl;
    std::cout << " Hits: " << std::endl;
    for (const auto &[section, count]: hits) {
        std::cout << ' ' << section << ": " << count << std::endl;
    }
    // Statistics for debugging.
    // HTTP status codes count is implemented.
    // Other statistics for debugging may be aggregated in similar way.
    std::cout << " HTTP status codes count: " << std::endl;
    for (const auto &[status, count]: http_status_counter) {
        std::cout << ' ' << status << ": " << count << std::endl;
    }
}

void RestartStatsFor10Sec (
    unsigned long &prev_time,
    std::map<std::string, unsigned long long> &hits, 
    std::map<std::string, unsigned long long> &http_status_counter, 
    std::map<std::string, unsigned long long> &buffer_hits, 
    std::map<std::string, unsigned long long> &buffer_http_status_counter) 
{
    hits.clear();
    http_status_counter.clear();
    for (const auto &[key, value]: buffer_hits) {
        hits[key] = value;
    }
    for (const auto &[key, value]: buffer_http_status_counter) {
        http_status_counter[key] = value;
    }
    buffer_hits.clear();
    buffer_http_status_counter.clear();
    prev_time = prev_time + 10;
}


int main(int argc, char* argv[]) 
{
    // The below two lines speed up input/output greatly
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // To supress printing stats for every 10 seconds of the logs, set to true
    // This is useful e.g. for debugging alerts
    bool no_stats = false;

    // Acoording to the problem statement:
    //  The default threshold should be 10 requests per second but should be configurable
    int number_of_requests_threshold = 10;

    // Parsing CLI arguments
    int parse_cli_return_code = ParseCLIArguments(argc, argv, no_stats, number_of_requests_threshold);
    if (parse_cli_return_code != -1) {
        return parse_cli_return_code;
    }
    
    // The entries in the log are not strictly sorted by time. 
    // If we find a log entry with timestamp >= prev_time + 10, 
    // we will wait (max_log_delay) time for the lagging (older) log entries.
    // Then we will print the stats. 
    // How much we should wait we will learn empirically.
    unsigned long max_log_delay = 0;

    // Time-related variables.
    unsigned long prev_time = 32503676400, current_time, max_time = 0;
    
    // Data structure to count number of hits for each section of the web site
    // It is required for the following from the problem statement:
    //  "For every 10 seconds of log lines, display stats about the traffic during those 10s"
    // hits stores stats for current 10 seconds
    // buffer_hits stores stats for next period
    // after current stats is printed, buffer becomes current
    std::map<std::string, unsigned long long> hits, buffer_hits;

    // Problem statement:
    //  "as well as statistics that might be useful for debugging"
    // The data structures with "buffer_" prefix are to handle out-of-order log entries (same as for hits). 
    std::map<std::string, unsigned long long> http_status_counter, buffer_http_status_counter;
 
    // temporary string to store input file lines
    std::string line;

    // read the first line of the log file with the column names:
    //  "remotehost","rfc931","authuser","date","request","status","bytes"
    std::cin >> line >> std::ws;
    // we don't process the first line

    // Moving average for past two minutes
    // key is timestamp, value is request count (int)
    std::map<unsigned long, int> traffic_past_2_min;
    // Helper variables to calculate the moving average
    unsigned long long total_requests_past_2_min = 0ULL;
    long double average = 0.0;
    // Helper variable to track if an alert is active to comply with the following:
    //  Duplicate alerts should not be triggered - a second alert should not be triggered
    //  before a recovery of the first
    bool alert = false;

    // read the rest of the input line by line
    while (std::getline(std::cin, line)) 
    {
        std::vector<std::string> tokens = SplitLogLine(line);
        std::string section = GetWebSiteSection(tokens[4]);

        // For every 10 seconds of log lines, display stats about the traffic during those 10s
        // Current log entry time
        current_time = std::stol(tokens[3]);
        // Handle out-of-order log entries
        max_time = std::max(max_time, current_time);
        if (current_time < max_time) {
            max_log_delay = std::max(max_log_delay, max_time - current_time);
        }
        prev_time = std::min(prev_time, current_time);
        // Increment the stats.
        // tokens[5] is "status"
        if (current_time - prev_time > 9) {
            // Add to buffer stats
            ++buffer_hits[section];
            ++buffer_http_status_counter[tokens[5]];
        }
        else {
            // Add to current stats
            ++hits[section];
            ++http_status_counter[tokens[5]];
        }
        if (max_time - prev_time > 9 + max_log_delay) {
            // Print the stats
            if (!no_stats) {
                PrintStatsForXSec(prev_time, 10, hits, http_status_counter);
            }
            // Clear current stats, move the stats from the buffer to current, clear the buffer
            RestartStatsFor10Sec(prev_time, hits, http_status_counter, 
                buffer_hits, buffer_http_status_counter);
        }

        // Calculate past 2 minutes average
        int time_diff = 0;
        // std::map sorts items automatically (red-black tree).
        // Thus, the first (begin) and last (rbegin) elements of the map point to
        // the oldest and the youngest timestamps of the traffic stats window
        while (!traffic_past_2_min.empty() && 
            (time_diff = traffic_past_2_min.rbegin()->first - traffic_past_2_min.begin()->first) > 119) 
        {
            total_requests_past_2_min -= traffic_past_2_min.begin()->second;
            traffic_past_2_min.erase(traffic_past_2_min.begin());
        }
        ++traffic_past_2_min[current_time];
        ++total_requests_past_2_min;
        average = 1.0 * total_requests_past_2_min / (time_diff + 1);

        // Alert logic
        if (!alert && average > number_of_requests_threshold) {
            std::cout << "High traffic generated an alert - hits = " << average;
            std::cout << ", triggered at " << traffic_past_2_min.rbegin()->first << '.' 
            << std::endl;
            alert = true;
        }
        else if (alert && average <= number_of_requests_threshold) {
            std:: cout << "The alert recovered - hits = " << average << ", recovered at " 
            << traffic_past_2_min.rbegin()->first << '.' << std::endl;
            alert = false;
        }
    }

    // If last portion of 10-sec stats is not printed
    if (!no_stats) {
        int x_seconds = max_time - prev_time + 1;
        if (x_seconds <= 10) {
            PrintStatsForXSec(prev_time, x_seconds, hits, http_status_counter);
        }
        else {
            PrintStatsForXSec(prev_time, 10, hits, http_status_counter);
            PrintStatsForXSec(prev_time + 10, x_seconds - 10, buffer_hits, buffer_http_status_counter);
        }
    }

    return 0;
}
