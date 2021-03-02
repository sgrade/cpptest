// B. Subsequence Hate
// NOT FINISHED

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        getline(cin >> ws, s);

        int ans = 0;
        
        if (s.size() > 2)
        {
            int zeroes = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeroes;

            if (zeroes != 0 || ones != 0)
            {
                int current_ans = 0;
                // 1...0...
                int current_ones = ones;
                int current_zeroes = zeroes;

                auto prev_one = s.find_first_of('1');
                if (prev_one != 0) 
                    current_ans += prev_one;
                    current_zeroes -= prev_one;
                --current_ones;
                
                int next_one, z;
                while(current_ones--)
                {
                    next_one = s.find_first_of('1', prev_one + 1);
                    z += next_one - (prev_one + 1);
                    if (current_ones < z)
                    {
                        current_ans += current_ones;
                        break;
                    }
                    else {
                        
                    }
                    prev_one = next_one;
                    
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
