// C. Social Distance

#include <iostream>
#include <string>


int main(){

    int t;
    std::cin >> t;

    while (t--) {

        int n, k;
        std::cin >> n >> k;

        std::string s;
        getline(std::cin >> std::ws, s);

        int max_tables = 0;

        int i;
        int first_one_index = s.find('1');
        if (first_one_index != std::string::npos && first_one_index <= k){
            i = first_one_index + 1;
        }
        else{
            i = 1;
            ++ max_tables;
        }
        
        while (i < n){
            int segment_len;
            int found = s.find('1', i + 1);
            if (found != std::string::npos) {
                segment_len = std::max(0, found - i - k);
                i = found + 1;
            }
            else {
                segment_len = s.size() - i;
                i = n;
            }
            
            max_tables += segment_len / (k + 1);

        }

        std::cout << max_tables << std::endl;
        
    }

    return 0;
}
