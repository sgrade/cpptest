#include <iostream>
#include <algorithm>
#include <string_view>

using namespace std;

int main()
{
    
    // Remove prefix
    // https://en.cppreference.com/w/cpp/string/basic_string_view/remove_prefix
    std::string str = "   trim me";
    std::string_view v = str;
    v.remove_prefix(std::min(v.find_first_not_of(" "), v.size()));
    std::cout << "String: '" << str << "'\n"
              << "View  : '" << v << "'\n";

    // Remove suffix
    // https://en.cppreference.com/w/cpp/string/basic_string_view/remove_suffix
    char arr[] = {'a', 'b', 'c', 'd', '\0', '\0', '\0'};
    std::string_view v2(arr, sizeof arr);
    auto trim_pos = v2.find('\0');
    if(trim_pos != v2.npos)
        v2.remove_suffix(v2.size() - trim_pos);
    std::cout << "Array: '" << arr << "', size=" << sizeof arr << '\n'
              << "View : '" << v << "', size=" << v.size() << '\n';
    
    string s = "Population UK: 64000000";
    size_t pos = s.find(':');
}
