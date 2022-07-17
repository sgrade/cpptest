// Balance between performance and readability / maintainability

#include <iostream>
#include <string>
#include <sstream>          // istringstream
#include <vector>
#include <queue>

#include <map>              // Search, removal, and insertion operations have logarithmic complexity.
#include <unordered_map>    // Search, insertion, and removal of elements have average constant-time complexity.
// Note: in practice, in some cases map works faster than unordered_map 
// because of hashing overhead in unordered_map. 


std::vector<std::string> SplitLogLine (const std::string &line) {
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
std::string GetWebSiteSection (const std::string &request) {
    std::string section;
    size_t first_forward_slash_index = request.find('/');
    size_t section_end_index = request.find_first_of(" /", first_forward_slash_index + 1);
    return request.substr(first_forward_slash_index, section_end_index - first_forward_slash_index);
}

void PrintStatsFor10Sec (
    const std::unordered_map<std::string, unsigned long long> &hits, 
    const std::unordered_map<std::string, unsigned long long> &http_status_counter) 
{
    std::cout << "Current stats: \n";
    for (const auto &[section, count]: hits) {
        std::cout << section << ":\t" << count << '\n';
    }
    std::cout << "HTTP status counts: \n";
    for (const auto &[status, count]: http_status_counter) {
        std::cout << status << ":\t" << count << '\n';
    }
}

void RestartStatsFor10Sec (
    long &prev_time,
    std::unordered_map<std::string, unsigned long long> &hits, 
    std::unordered_map<std::string, unsigned long long> &http_status_counter, 
    std::unordered_map<std::string, unsigned long long> &buffer_hits, 
    std::unordered_map<std::string, unsigned long long> &buffer_http_status_counter) 
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
    http_status_counter.clear();
    prev_time = prev_time + 10;
}


int main() {

    // The below two line speed up input/output greatly
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // The entries in the log are not strictly sorted by time. 
    // If we find a log entry with timestamp >= prev_time + 10, 
    // we will wait (max_log_delay) time for the lagging (older) log entries.
    // Then we will print the stats. 
    // How much we should wait we will learn empirically.
    int max_log_delay = 0;

    // Time-related variables.
    long prev_time = 32503676400, current_time, max_time = 0;
    
    // Data structure to count number of hits for each section of the web site
    // It is required for the following from the problem statement:
    //  "For every 10 seconds of log lines, display stats about the traffic during those 10s"
    // The data structures with "buffer_" prefix are to handle out-of-order log entries. 
    std::unordered_map<std::string, unsigned long long> hits, buffer_hits;

    // Problem statement:
    //  "as well as statistics that might be useful for debugging"
    // The data structures with "buffer_" prefix are to handle out-of-order log entries. 
    std::unordered_map<std::string, unsigned long long> http_status_counter, buffer_http_status_counter;
 
    // temporary string to store input file lines
    std::string line;

    // read the first line of the log file with the column names:
    //  "remotehost","rfc931","authuser","date","request","status","bytes"
    std::cin >> line >> std::ws;
    // we don't process the first line

    // Moving average for past two minutes
    // Using lambda to compare elements in the min heap
    auto cmp = [](const std::pair<long, int> &left, const std::pair<long, int> &right) { 
        return left.first > right.first; 
    };
    // Min heap to store traffic for past 2 minutes
    std::priority_queue<std::pair<long, int>, std::vector<std::pair<long, int>>, decltype(cmp)> traffic_past_2_min;
    // Helper variables for the moving average
    unsigned long long total_traffic_past_2_min = 0ULL;
    long double average = 0.0;

    // read the rest of the input line by line
    while (std::getline(std::cin, line)) 
    {
        std::vector<std::string> tokens = SplitLogLine(line);
        std::string section = GetWebSiteSection(tokens[4]);

        // Current log entry time
        current_time = std::stol(tokens[3]);

        // Handle out-of-order log entries
        max_time = std::max(max_time, current_time);
        max_log_delay = std::max(0L, current_time - max_time);
        prev_time = std::min(prev_time, current_time);

        // Increment the stats.
        // tokens[5] is "status"
        if (current_time - prev_time > 10) {
            // Add to buffer stats
            ++buffer_hits[section];
            ++buffer_http_status_counter[tokens[5]];
        }
        else {
            // Add to current stats
            ++hits[section];
            ++http_status_counter[tokens[5]];
        }
        if (current_time - prev_time >= 10 + max_log_delay) {
            // Print the stats
            PrintStatsFor10Sec(hits, http_status_counter);
            // Clear current stats, move the stats from the buffer to current, clear the buffer
            RestartStatsFor10Sec(prev_time, hits, http_status_counter, 
                buffer_hits, buffer_http_status_counter);
        }

        // Calculate past 2 minutes average
        while (!traffic_past_2_min.empty() && current_time - traffic_past_2_min.top().first > 120) {
            total_traffic_past_2_min -= traffic_past_2_min.top().second;
            traffic_past_2_min.pop();
        }
        // tokens[6] is bytes
        int bytes = stoi(tokens[6]);
        total_traffic_past_2_min += bytes;
        traffic_past_2_min.emplace(std::pair<long, int>(current_time, bytes));
        average = 1.0 * total_traffic_past_2_min / traffic_past_2_min.size();
        std::cout << "Average: " << average << '\n';
    }

    return 0;
}
