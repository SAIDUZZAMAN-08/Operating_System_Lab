#include <iostream>
#include <cstdio> // For rename()
using namespace std;

int main() {
    if (rename("copy_example.txt", "moved_example.txt") == 0) {
        cout << "File moved/renamed successfully.\n";
    } else {
        cout << "Error moving/renaming file.\n";
    }
    return 0;
}
