#include <iostream>
#include "logmon.cpp"

int ParseCLIArguments (const int &argc, char* argv[], bool &no_stats, int &requests_alert_threshold) 
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
                requests_alert_threshold = std::stoi(argv[1]);
            }
            catch (std::invalid_argument const& ex) {
                std::cout << "Invalid_argument: " << ex.what() << '\n';
                return 1;
            }
            catch (const std::exception& ex) {
                std::cout << "Standard exception: " << ex.what() << '\n';
                return 1;
            }
            if (requests_alert_threshold < 1) {
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

int main(int argc, char* argv[]) 
{
    // The below two lines speed up input/output greatly
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bool no_stats = false;
    int requests_alert_threshold = 10;

    // Parsing CLI arguments
    int parse_cli_return_code = ParseCLIArguments(argc, argv, no_stats, requests_alert_threshold);
    if (parse_cli_return_code != -1) {
        return parse_cli_return_code;
    }

    LogMon logmon(no_stats, requests_alert_threshold);
    logmon.ProcessLog(std::cin);

    return 0;
}
