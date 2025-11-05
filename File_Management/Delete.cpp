#include <iostream>
#include <cstdio> 
using namespace std;

int main() {
    if (remove("example.txt") == 0) {
        cout << "File deleted successfully.\n";
    } else {
        cout << "Error deleting the file.\n";
    }
    return 0;
}
