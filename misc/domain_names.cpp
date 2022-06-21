/*
Part 1:
A website domain "api.fareharbor.com" consists of various subdomains. 
At the top level, we have "com", at the next level, we have "fareharbor.com" and at the lowest level, "api.fareharbor.com". 
When we visit a domain like "api.fareharbor.com", we will also visit the parent domains "fareharbor.com" and "com" implicitly.

A count-paired domain is a domain that has one of the two formats "rep a1.a2.a3" or "rep b1.b2", where rep is the number of visits to the domain and a1.a2.a3, b1.b2 are the domains in full.

For example, "9001 api.fareharbor.com" is a count-paired domain that indicates that api.fareharbor.com was visited 9001 times.
Given an array of count-paired domains cpdomains, return an array of the count-paired domains of each subdomain in the input. 
You may return the answer in any order.

Example 1:
input: ["9001 api.fareharbor.com"]
output: ["9001 fareharbor.com","9001 api.fareharbor.com","9001 com"]

Example 2:
input: ["150 montara.fareharbor.com", "100 api.fareharbor.com", "300 fareharbor.com", "137 mail.com", "300 fareharbor.mail.com"]
output: ["437 mail.com","100 api.fareharbor.com","550 fareharbor.com","300 fareharbor.mail.com","987 com","150 montara.fareharbor.com"]
*/

#include <bits/stdc++.h>
using namespace std;


int getCount (const string &s) {
  string first = s.substr(0, s.find(' '));
  return stoi(first);
}

vector<string> getTokens (const string &s) {
  size_t index = s.find(' ');
  if (index + 1 == string::npos) {
    cout << "Exception";
  }
  string second = s.substr(index + 1);
  vector<string> output;
  int n = second.size(), i = n - 1;
  string tmp_full;
  while (true) {
    string tmp;
    while (i >= 0 && second[i] != '.') {
      tmp += second[i];
      --i;
    }
    reverse(tmp.begin(), tmp.end());
    --i;
    if (i <= -1) {
      tmp_full = tmp + tmp_full;
      output.push_back(tmp_full);
    }
    else {
      tmp_full = tmp + tmp_full;
      output.push_back(tmp_full);
      tmp_full = '.' + tmp_full;
    } 
    output.push_back(tmp_full);
  }
  return output;
}


int main() {

  vector<string> a = {"150 montara.fareharbor.com", "100 api.fareharbor.com", "300 fareharbor.com", "137 mail.com", "300 fareharbor.mail.com"};

  map<string, int> counter;

  for (int i = 0; i < a.size(); ++i) {
    int count = getCount(a[i]);
    // cout << count << ": ";
    vector<string> tokens = getTokens(a[i]);  // ["montara", "fareharbor", "com"]
    // ".".join(tokens) // montara.fareharbor.com
    tokens.pop_back(); // ["fareharbor", "com"]
    // ".".join(tokens) // fareharbor.com
    tokens.pop_back(); // com

    for (auto &t: tokens) {
      // cout << t << ' ';
      counter[t] += count;
    }
  }
  return 0;
}

/*
150: com fareharbor.moc montara.com.robraheraf 100: com fareharbor.moc api.com.robraheraf 300: com fareharbor.moc 137: com mail.moc 300: com mail.moc fareharbor.com.liam 
*/