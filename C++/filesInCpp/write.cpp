#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream file("file.txt");

	string s;
	getline(cin, s);

	file << s << endl;
	file.close();
	return 0;
}
