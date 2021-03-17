// C. Woodcutters

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    int x, h;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> h;
        mp[x] = h;
    }

    int ans = 1;

    if (n == 2)
    {
        ans = 2;
    }
    else if (n > 2)
    {   
        map<int, int>::iterator it1 = mp.begin(), it2 = mp.begin(), it3 = mp.begin();
        ++it2;
        ++it3;
        ++it3;
        
        bool segment_clear = true;
        for (int i = 0; i < n-2; ++i)
        {
            h = it2->second;
            if (segment_clear && it2->first - h > it1->first)
            {
                ++ans;
                segment_clear = true;
            }
            else if (!segment_clear && it2->first - h > it1->first + it1->second)
            {
                ++ans;
                segment_clear = true;
            }
            else if (it2->first + h < it3->first)
            {
                ++ans;
                segment_clear = false;
            }
            else
            {
                segment_clear = true;
            }
            
            ++it1;
            ++it2;
            ++it3;
        }
        ++ans;
    }

    cout << ans << endl;

    return 0;
}
