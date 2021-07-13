// B. AquaMoon and Stolen String
// Time limit exceeded on test 3

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<string> original(n), reordered(n-1);
        string tmp;
        for (auto &el: original) {
            getline(cin >> ws, tmp);
            el = tmp;
        }
        for (auto &el: reordered) {
            getline(cin >> ws, tmp);
            el = tmp;
        }

		vector<bool> taken_or(n), taken_re(n-1);
		int taken_or_count = 0;
		string ans = "";
		
		// Is there the same string in reordered?
		for (int i = 0; i < n; ++i) {
			if (taken_or[i]) {
				continue;
			}

			for (int j = 0; j < n-1; ++j) {
				if (taken_re[j]) {
					continue;
				}
				if (original[i] == reordered[j]) {
					taken_or[i] = true;
					++taken_or_count;
					taken_re[j] = true;
				}
            }
        }

		if (taken_or_count < n-1) {

			// Reordered?
			for (int i = 0; i < n; ++i) {
				if (taken_or[i]) {
					continue;
				}

				if (taken_or_count == n-1) {
					ans = original[i];
					break;
				}

				for (int j = i+1; j < n; ++j) {
					if (taken_or[j]) {
						continue;
					}

					int idx = 0;
					char ch1, ch2;

					for (int k = 0; k < n-1; ++k) {
						if (taken_re[k]) {
							continue;
						}
					
						int l = k+1;
						for (; l < n-1; ++l) {
							if (taken_re[l]) {
								continue;
							}

							ch1 = original[i][idx];
							ch2 = original[j][idx];

							while (true) {
								if 
								(
									(ch1 == reordered[k][idx] && ch2 == reordered[l][idx]) 
									|| 
									(ch2 == reordered[k][idx] && ch1 == reordered[l][idx])
								) 
								{
									++idx;
								}
								else {
									break;
								}

								if (idx == m) {
									break;
								}
								
								ch1 = original[i][idx];
								ch2 = original[j][idx];
							}

							if (idx == m) {
								taken_or[i] = true;
								taken_or[j] = true;
								taken_or_count += 2;
								taken_re[k] = true;
								taken_re[l] = true;
								goto next_i;
							}
						}
					}
				}

				next_i:
					continue;
			}
		}

		if (ans != "") {
			cout << ans << endl;
		}

		else {
			auto it = find(begin(taken_or), end(taken_or), 0);
			int d = distance(begin(taken_or), it);
			cout << original[d] << endl;
		}

    }

    return 0;
}
