#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

// This function is long enough and it does everything.
// It is better to split it to few parts - one is related to checks of inputs, another reads data or even better - 
// we can introduce class for Image and then load and save will be a part of its interface
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
    
    // 16 should be defined as a constexpr constant in anonymous namespace instead of hardcoding in many places.
    vector<vector<vector<int>>> pixels(16, vector<vector<int>>(16, vector<int>(3))); // 16x16 image pixels
    
    // Read input file
    for (int i = 0; i < 16; ++i) {
        // I hope that it is better to read file line by line here to ensure that format matches.
        // then you can split the line into array of substrings with std::ranges split and std::ranges::to<std::vector<std::string>>
        // x,y,z can be also split with ranges and deliimiter comma
        for (int j = 0; j < 16; ++j) {
            // It seems that you should encapsulate part of the logic into Pixel struct.
            // This struct should have isValid method to validate pixel values are in range 0-255.
            // Also you will be able to overload << and >> operators for Pixel struct
            // which will allow you to make more readable code and will hide the format details
            // For example:
            // auto& curPixel = pixels[i][j];
            // inputFile >> curPixel;
            // if (!curPixel.isValid()) {
            //     cerr << "Error: Invalid pixel values in line " << i + 1 << ", column " << j + 1 << "!" << endl;
            //     return;
            // }
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
                // when you will encapsulate part of the logic into Pixel struct,
                // you will be able to simplify this code.
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
        // you can use std::views::join_with to get that string of pixels and with overloaded << operator pixel serialization will be simpler
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
