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

        // compare price and quality
        bool operator < (const Laptop& pt) const
        {
            return (this->price < pt.price) && (this->quality > pt.quality);
        }
    };

    set<struct Laptop> st;

    for (int i=0; i<n; ++i){

        Laptop tmp;
        cin >> tmp.price >> tmp.quality;

        st.insert(tmp);

    }

    set<struct Laptop>::iterator it;

    for (it=st.begin(); it!=st.end(); it++){
        cout << (*it).price << (*it).quality << endl;
    }

    return 0;
}