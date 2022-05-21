// https://www.hackerrank.com/challenges/messages-order/problem

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// https://www.hackerrank.com/challenges/messages-order/forum/comments/549750
#include <chrono>

class Message {
public: 
    Message() {}
    Message(string message) 
    : message_(message) {id_ = chrono::high_resolution_clock::now();}   
    const string& get_text() {
        return message_;
    }
    // https://en.cppreference.com/w/cpp/language/operators
    friend bool operator<(const Message& m1, const Message& m2) {
        return m1.id_ < m2.id_;
    }
private:
    string message_;
    chrono::time_point<chrono::high_resolution_clock> id_;
};

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        return Message(text);
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
