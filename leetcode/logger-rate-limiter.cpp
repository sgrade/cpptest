// 359. Logger Rate Limiter
// https://leetcode.com/problems/logger-rate-limiter/

#include <bits/stdc++.h>

using namespace std;


class Logger {
public:
    map<string, int> messages;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        bool ans = false;
        if (messages.find(message) == messages.end() || timestamp - messages[message] > 9) {
            ans = true;
            messages[message] = timestamp;
        }
        
        return ans;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
