#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include "utils.h"
#include "config.h"
#include "ppm.h"
#include "renderer.h"
using namespace std;

int main () {
    srand(time(nullptr));

    char *pixelBuffer = new char[RES_WIDTH * RES_HEIGHT * 3];

    auto start = chrono::high_resolution_clock::now();
    renderScene(RES_WIDTH, RES_HEIGHT, pixelBuffer);

    chrono::duration<float> duration = chrono::high_resolution_clock::now() - start;
    cout << "Render has been finished\nTime: " << duration.count() << "s" << endl;

    savePPM(SAVE_PATH, RES_WIDTH, RES_HEIGHT, pixelBuffer);

    delete[] pixelBuffer;
    return 0;
}