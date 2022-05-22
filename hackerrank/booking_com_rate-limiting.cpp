// Rate limiting
// Hackerrank assessment: Coding part
// NOT FINISHED

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'droppedRequests' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY requestTime as parameter.
 */

int droppedRequests(vector<int> requestTime) {

    int ans = 0;
    
    int n;
    cin >> n;
    
    map<int, int> cnt;
    
    for (int &r: requestTime) {
        ++cnt[r];
    }
    
    auto it = cnt.begin(), it3 = cnt.begin(), it10 = cnt.begin(), it60 = cnt.begin();
    int t3 = it3->first, t10 = it10->first, t60 = it60->first;

    int cur = cnt.begin()->first;
    long long total = 0;

    while (true) {

    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string requestTime_count_temp;
    getline(cin, requestTime_count_temp);

    int requestTime_count = stoi(ltrim(rtrim(requestTime_count_temp)));

    vector<int> requestTime(requestTime_count);

    for (int i = 0; i < requestTime_count; i++) {
        string requestTime_item_temp;
        getline(cin, requestTime_item_temp);

        int requestTime_item = stoi(ltrim(rtrim(requestTime_item_temp)));

        requestTime[i] = requestTime_item;
    }

    int result = droppedRequests(requestTime);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
