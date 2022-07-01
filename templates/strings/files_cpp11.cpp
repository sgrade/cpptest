// https://www.youtube.com/watch?v=A9aNn6q-P6Y

#include <iostream>
#include <fstream>

using namespace std;


int main() {

    string filename = "templates/strings/stats.txt";
    ifstream input;

    input.open(filename);

    if (!input.is_open()) {
        return 1;
    }

    while (input) {
        string line;

        getline(input, line, ':');

        int population;
        input >> population;

        // Discard new line char
        // input.get();
        input >> ws;

        if (!input) {
            break;
        }

        cout << "'" << line << "'" << " -- '" << population << "'" << endl;
    }

    input.close();

    return 0;
}