#include <fstream>

using namespace std;


int main() {

  fstream myFile;
  myFile.open("file.txt", ios::out); // write
  if (myFile.is_open()) {
    myFile << "Hello\n";
    myFile.clode();
  }

  return 0;
}

// APpend
ios::app

// while (getline(myfile, line)) {

}


//Read

#include <iostream>
#include <fstream>
using namespace std;
int main() {
	fstream my_file;
	my_file.open("my_file.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {
		char ch;

		while (1) {
			my_file >> ch;
			if (my_file.eof())
				break;

			cout << ch;
		}

	}
	my_file.close();
	return 0;
}
