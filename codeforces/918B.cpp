// B. Radio Station

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<string, string> ip_name;

    string name, ip;
    while (n--) {
        cin >> name >> ip;
        ip_name[ip] = name;
    }

    string command, output;
    while (m--) {
        cin >> command >> ip;
        ip.pop_back();
        output = command + ' ' + ip + "; #" + ip_name[ip] + '\n';
        cout << output;
    }

    return 0;
}
