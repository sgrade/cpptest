// 359. Logger Rate Limiter
// https://leetcode.com/problems/logger-rate-limiter/

#include <bits/stdc++.h>

using namespace std;


class Logger {
public:
    unordered_map<string, int> messages;
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        if (messages.find(message) == messages.end()) {
            messages[message] = timestamp + 9;
            return true;
        }
        if (timestamp > messages[message]) {
            messages[message] = timestamp + 9;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
