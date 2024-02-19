#include "ppm.h"
using namespace std;

string makePPM (int width, int height, char *pixelBuffer) {
    string content; 
    content = content + "P6 " + to_string(width) + " " + to_string(height) + " 255 ";

    int pixelBufferLength = width * height * 3;

    int headerLength = content.length();
    content.resize(headerLength + pixelBufferLength);

    for (int i = 0; i < pixelBufferLength; i++) {
        content[headerLength + i] = pixelBuffer[i];
    }

    return content;
};

void savePPM (string savePath, int width, int height, char *pixelBuffer) {
    ofstream fout; 

    fout.exceptions(ofstream::badbit | ofstream::failbit);
    fout.open(savePath);
    string content = makePPM(width, height, pixelBuffer);

    fout << content;
    fout.close();
};