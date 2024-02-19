#include "utils.h"
using namespace std;

float random () {
    return (float)rand() / RAND_MAX;
};

vec3 reflect (vec3 rd, vec3 normal) {
    return rd - normal * 2.0 * normal.dot(rd);
};

vec3 sphereRandomUniform () {
    float theta = random() * 2.0f * 3.14159265f;
	float phi = acos(2.0f * random() - 1.0f);

	return vec3(
        sin(phi) * cos(theta), 
        sin(phi) * sin(theta), 
        cos(phi)
    );
};

vec3 vecMix (vec3 a, vec3 b, float k) {
    return vec3 (
        b.x * k + (1.0f - k) * a.x,
        b.y * k + (1.0f - k) * a.y,
        b.z * k + (1.0f - k) * a.z
    );
};

vec3 randomVec (float spread) {
    return vec3(
        random() * 2.0f - 1.0f,
        random() * 2.0f - 1.0f,
        random() * 2.0f - 1.0f
    ) * spread;
};