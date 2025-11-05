#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream src("example.txt", ios::binary); // Open source file
    ofstream dest("copy_example.txt", ios::binary); // Create destination file

    dest << src.rdbuf(); // Copy content
    cout << "File copied successfully.\n";

    src.close();
    dest.close();
    return 0;
}
