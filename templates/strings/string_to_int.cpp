#include <iostream>

using namespace std;


// Source - https://stackoverflow.com/questions/16826422/c-most-efficient-way-to-convert-string-to-int-faster-than-atoi/16826908
int fast_atoi( const char * str )
{
    int val = 0;
    while( *str ) {
        val = val*10 + (*str++ - '0');
    }
    return val;
}

int main() {
    
    cout << fast_atoi("222") << endl;

    return 0;
}