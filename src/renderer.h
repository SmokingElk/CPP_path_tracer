#pragma once
#include <memory>
#include <vector>
#include <math.h>
#include "utils.h"
#include "figures.h"
#include "config.h"
#include "vec.h"

vec3 viewport (int x, int y, int width, int height, float aspectRatio, float screenDist);
vec3 clampColor (vec3 color);
vec3 gammaCorrection (vec3 color);
vec3 getSky (vec3 rd);
float closestCollide (vec3 ro, vec3 rd, Sphere &closestObject);
vec3 castRay (vec3 &ro, vec3 &rd, bool &end);
vec3 traceRay (vec3 ro, vec3 rd);
void renderScene(int width, int height, char *pixelBuffer);
