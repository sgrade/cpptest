#include "logmon.cpp"
#include "string"
#include <fstream>
#include <cassert>
#include <vector>

struct TestData
{
    std::string input_filename;
    bool is_active;
    unsigned long triggered_at;
    unsigned long recovered_at;
    TestData (const std::string input_filename, const bool is_active, 
        const unsigned long triggered_at, const unsigned long recovered_at) 
    {
        this->input_filename = input_filename;
        this->is_active = is_active;
        this->triggered_at = triggered_at;
        this->recovered_at = recovered_at;
    }
};

int TestAlert (LogMon *logmon, TestData *test_data)
{
    std::ifstream input;

    input.open(test_data->input_filename);
    if (!input.is_open()) {
        std::cout << "Cannot find test file" << std::endl;
        return 1;
    }

    logmon->ProcessLog(input);

    Alert *logmon_alert = logmon->GetCurrentAlertState();

    // Checking if alert status is as expected
    assert(logmon_alert->is_active == test_data->is_active);
    // std::cout << logmon_alert->is_active << std::endl;
    std::cout << "Checkpoint #1: The alert state is as expected (" 
    << (logmon_alert->is_active ? "triggered" : "recovered")
    << ")." << std::endl;
    
    // The alert is triggered at expected time
    assert(logmon_alert->triggered_at == test_data->triggered_at);
    // std::cout << logmon_alert->triggered_at << std::endl;
    std::cout << "Checkpoint #2: The alert is triggered at expected time (" 
    << logmon_alert->triggered_at
    << ")." << std::endl;
    
    // The alert is recovered at expected time (0 if still active)
    assert(logmon_alert->recovered_at == test_data->recovered_at);
    // std::cout << logmon_alert->recovered_at << std::endl;
    std::cout << "Checkpoint #3: The alert is recovered at expected time ("
    << logmon_alert->recovered_at
    << ")." << std::endl;

    input.close();

    return 0;
}


int main() 
{

    // Container for the tests data
    std::vector<TestData*> tests;

    // NOTE: subsequent tests add data to what was left in logmon from the previous tests. 
    // seed README -> Design for details.
    
    // Test 1: 11 hits in one second. Alert should be triggered.
    tests.emplace_back(new TestData("alert_test_1.txt", true, 1549573860, 0));

    // Test 2: next second one hit. Previous alert should be recovered. 
    tests.emplace_back(new TestData("alert_test_2.txt", false, 1549573860, 1549573861));
    
    
    LogMon *logmon = new LogMon(true, 10);

    for (auto &test: tests) {
        std::cout << std::endl;
        int return_code = TestAlert(logmon, test);
        if (return_code != 0) {
            return 1;
        }
    }

    return 0;
}
