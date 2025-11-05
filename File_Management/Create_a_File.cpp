#include <iostream>
#include <fstream> 
using namespace std;

int main() {
    // Step 1: Create and write to a file
    ofstream file("example.txt"); // Create or overwrite the file
    
    if (file.is_open()) {
        file << "Hello, this is a new file.\n";
        file << "This is the second line of text.\n";
        file.close(); // Close after writing
        cout << "File created and written successfully.\n";
    } else {
        cout << "Failed to create file.\n";
        return 0; 
    }


    // Step 2: Read and display the file content
    ifstream readFile("example.txt"); // Open file for reading
    if (readFile.is_open()) {
        cout << "\n--- File Content ---\n";
        string line;

        while (getline(readFile, line)) { // Read line by line
            cout << line << endl;        // Display each line
        }

        readFile.close();
    } else {
        cout << "Unable to open file for reading.\n";
    }

    return 0;
}
