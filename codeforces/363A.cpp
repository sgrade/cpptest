// A. Soroban

#include <iostream>
#include <vector>

using namespace std;


int main(){

    string n;
    cin >> n;

    for(int i = n.size()-1; i >= 0; --i){
        int x = n[i] - 48;
        string line;
        if (x >= 5){
            line += "-O";
            x -= 5;
        }
        else line += "O-";
        line += '|';
        
        while (x--){
            line += 'O';
        }
        line += '-';
        for (int i = 8 - line.size(); i > 0; --i){
            line += 'O';
        }

        cout << line << endl;
    }

    return 0;
}
