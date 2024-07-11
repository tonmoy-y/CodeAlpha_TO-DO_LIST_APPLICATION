#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Example vector of strings
    vector<string> lines = {
        "Hello, World!",
        "This is a test file.",
        "Each line will be written to the file."
    };

    ofstream outputFile("output.txt");

    if (outputFile.is_open()) {
        for (const string &line : lines) {
            outputFile << line << '\n';  // Write each string followed by a newline character
        }
        outputFile.close();
    } else {
        cerr << "Unable to open file for writing" << endl;
        return 1;
    }

    cout << "Strings have been written to output.txt" << endl;

    return 0;
}
