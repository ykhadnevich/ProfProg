#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

// Function to process the input file and generate the output file
void processFile(const string& inputFileName, const string& outputFileName, const vector<int>& favoriteColor) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file!" << endl;
        return;
    }
    
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to create output file!" << endl;
        return;
    }
    
    vector<vector<vector<int>>> pixels(16, vector<vector<int>>(16, vector<int>(3))); // 16x16 image pixels
    
    // Read input file
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            char comma;
            if (!(inputFile >> pixels[i][j][0] >> comma >> pixels[i][j][1] >> comma >> pixels[i][j][2])) {
                cerr << "Error: Invalid input format in line " << i + 1 << ", column " << j + 1 << "!" << endl;
                return;
            }
            if (pixels[i][j][0] < 0 || pixels[i][j][0] > 255 ||
                pixels[i][j][1] < 0 || pixels[i][j][1] > 255 ||
                pixels[i][j][2] < 0 || pixels[i][j][2] > 255) {
                cerr << "Error: Pixel values out of range in line " << i + 1 << ", column " << j + 1 << "!" << endl;
                return;
            }
        }
    }
    
    // Check and modify pixels according to favorite color
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (pixels[i][j] == favoriteColor) {
                if (i == 0 || j == 0) {
                    pixels[i][j] = favoriteColor;
                } else {
                    pixels[i][j][0] = pixels[i][0][0];
                    pixels[i][j][1] = pixels[0][j][1];
                    pixels[i][j][2] = pixels[0][j][2];
                }
            }
        }
    }
    
    // Write output to file
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            outputFile << pixels[i][j][0] << "," << pixels[i][j][1] << "," << pixels[i][j][2] << " ";
        }
        outputFile << endl;
    }
    
    cout << "Output file generated successfully: " << outputFileName << endl;
}
void runTests() {
    vector<vector<int>> testFavoriteColors = {{255,0,0}}; // Adjust the favorite color if needed
    vector<string> testInputFiles = {"picture.txt"}; // Adjust to include only the path to your input file
    vector<string> testOutputFiles = {"test_output1.txt"}; // Adjust if needed
    
    for (int i = 0; i < testFavoriteColors.size(); ++i) {
        processFile(testInputFiles[i], testOutputFiles[i], testFavoriteColors[i]);
    }
}


int main() {
    runTests(); // Run automated tests
    
    return 0;
}
