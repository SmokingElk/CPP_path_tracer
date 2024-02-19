#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <string>

std::string makePPM (int width, int height, char *pixelBuffer);
void savePPM (std::string savePath, int width, int height, char *pixelBuffer);