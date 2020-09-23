// A. Laptops

#include <iostream>
#include <set>

using namespace std;


int main(){

    int n;
    cin >> n;

    struct Laptop{
        int price;
        int quality;

        /*
        // compare price and quality
        bool operator < (const Laptop& pt) const
        {
            return  (price < pt.price) ||
                    // according to task, all prices and qualities are distinct, 
                    // but I made this check anyway
                    ((price == pt.price) && (quality < pt.quality));
        }
        */
    };

    // set<struct Laptop> st;

    for (int i=0; i<n; ++i){

        Laptop tmp;
        cin >> tmp.price >> tmp.quality;

        // Editorial says this check is enough, but I believe this is wrong
        // E.g. with this test:
        // 2
        // 1 2
        // 2 3
        if (tmp.price != tmp.quality) {
            cout << "Happy Alex" << endl;
            exit(0);
        }

        // st.insert(tmp);

    }

    /*
    set<struct Laptop>::iterator it;
   
    for (it=st.begin(); it!=st.end(); it++){
        cout << (*it).price << (*it).quality << endl;
    }
    */

    cout << "Poor Alex" << endl;

    return 0;
}