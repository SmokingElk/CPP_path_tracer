#include <math.h>
#include <ctime>
#include "vec.h"
#pragma once

float random ();
vec3 reflect (vec3 rd, vec3 normal);
vec3 sphereRandomUniform ();
vec3 vecMix (vec3 a, vec3 b, float k);
vec3 randomVec (float spread);