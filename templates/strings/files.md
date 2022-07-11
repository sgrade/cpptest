# Files

[Source](https://www.w3schools.com/cpp/cpp_files.asp)



## Classes

Include both `<iostream>` and `<fstream>`

- ofstream	Creates and writes to files
- ifstream	Reads from files
- fstream	A combination of ofstream and ifstream: creates, reads, and writes to files

## Create and write to a file

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  // Create and open a text file
  ofstream MyFile("filename.txt");

  // Write to the file
  MyFile << "Files can be tricky, but it is fun enough!";

  // Close the file
  MyFile.close();
}
```

## Read a file

```cpp
// Create a text string, which is used to output the text file
string myText;

// Read from the text file
ifstream MyReadFile("filename.txt");

// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
  // Output the text from the file
  cout << myText;
}

// Close the file
MyReadFile.close();
```
