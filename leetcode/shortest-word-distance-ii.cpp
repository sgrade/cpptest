// 244. Shortest Word Distance II
// https://leetcode.com/problems/shortest-word-distance-ii/

#include <bits/stdc++.h>

using namespace std;


class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            indexes[wordsDict[i]].emplace_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        return GetDistance(word1, word2);
    }
private:
    map<string, vector<int>> indexes;
    int GetDistance(const string& w1, const string& w2) {
        vector<int>::iterator it1 = indexes[w1].begin(), it2 = indexes[w2].begin();
        int ans = abs(*it1 - *it2);
        bool w1_finished = true;
        while (true) {
            if (*it1 < *it2) {
                ++it1;
                if (it1 == indexes[w1].end()) {
                    break;
                }
            }
            else {
                ++it2;
                if (it2 == indexes[w2].end()) {
                    w1_finished = false;
                    break;
                }
            }
            ans = min(ans, abs(*it1 - *it2));
        }
        int last, current;
        if (w1_finished) {
            last = indexes[w1].back();
            while (++it2 < indexes[w2].end()) {
                current = *it2;
                if (abs(current - last) > ans) {
                    break;
                }
                ans = current - last;
            }
        }
        else {
            last = indexes[w2].back();
            while (++it1 < indexes[w1].end()) {
                current = *it1;
                if (abs(current - last) > ans) {
                    break;
                }
                ans = current - last;
            }
        }

        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
