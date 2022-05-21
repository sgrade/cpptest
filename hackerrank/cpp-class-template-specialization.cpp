// https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem

#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template<typename T> struct Traits {
    static string name(int index) {
        // https://en.cppreference.com/w/cpp/language/enum
        switch(index)
        {
            // https://www.hackerrank.com/challenges/cpp-class-template-specialization/forum/comments/365228
            case 0:
                return (typeid(T) == typeid(Color)) ? 
                "red" : "apple";
            case 1:
                return (typeid(T) == typeid(Color)) ? 
                "green" : "orange";
            case 2:
                return (typeid(T) == typeid(Color)) ? 
                "orange" : "pear";
            default:
                return "unknown";
        }
        return "unknown";
    }
};


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
