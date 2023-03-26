// 1236. Web Crawler
// https://leetcode.com/problems/web-crawler/

#include <bits/stdc++.h>

using namespace std;


// This is the HtmlParser's API interface.
// You should not implement it, or speculate about its implementation
class HtmlParser {
  public:
    vector<string> getUrls(string url);
};


class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<string> ans;
        string start_hostname = startUrl.substr(7, startUrl.find('/', 7) - 7);
        size_t  start_hostname_len = start_hostname.size();

        queue<string> q;
        q.emplace(startUrl);
        unordered_set<string> visited;
        visited.emplace(startUrl);
        string current_url, hostname;
        while (!q.empty()) {
            current_url = q.front();
            q.pop();
            for (string url: htmlParser.getUrls(current_url)) {
                if (visited.find(url) != visited.end()) 
                    continue;
                hostname = url.substr(7, start_hostname_len);
                if (hostname == start_hostname) {
                    q.emplace(url);
                    visited.emplace(url);
                }
            }
        }
        return vector<string>(visited.begin(), visited.end()); 
    }
};
