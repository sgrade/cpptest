// B2. Wonderful Coloring - 2
// Time limit exceeded on test 2

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;
    
    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        map<int, int> cntr;
        for (auto &el: a) {
            cin >> el;
            ++cntr[el];
        }

        int elements_to_paint = n;
        // If required number of colors > k, the element is not to paint
        for (auto &p: cntr) {
            elements_to_paint -= max(0, p.second - k);
        }
        // all colors should have equal number of elements
        elements_to_paint -= elements_to_paint % k;

        vector<int> ans(n);

        if (elements_to_paint != 0) {

            // in the map's internal vector v: 
            // v[0] - number of colors used for element (to compare with k)
            // v[1]...v[k] = 1 if the color is already used, 0 otherwise (so colors for element are different)
            // Note: since we start from 1, colors are 1-indexed already
            map<int, vector<int>> colors_used_for_element;
            vector<int> tmp(k+1);
            for (auto &p: cntr) {
                colors_used_for_element[p.first] = tmp;
            }

            // to choose next color
            vector<int> colors(k);
            vector<int>::iterator next_color_it = begin(colors);
            int next_color;
            int max_elements_in_one_color = elements_to_paint / k;

            for (int i = 0; i < n; ++i) {

                ++colors_used_for_element[a[i]][0];

                if (elements_to_paint == 0 || colors_used_for_element[a[i]][0] > k) {
                    ans[i] = 0;
                }

                else {

                    --elements_to_paint;

                    while(true) {
                        if (next_color_it == end(colors)) {
                            next_color_it = begin(colors);
                        }
                        if (*next_color_it == max_elements_in_one_color) {
                            ++next_color_it;
                            continue;
                        }
                        next_color = distance(begin(colors), next_color_it) + 1;
                        if (colors_used_for_element[a[i]][next_color] == 1) {
                            ++next_color_it;
                            continue;
                        }
                        break;
                    }

                    ans[i] = next_color;
                    colors_used_for_element[a[i]][next_color] = 1;
                    ++(*next_color_it);
                    ++next_color_it;
                }
            }
        }

        for (auto &el: ans) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
