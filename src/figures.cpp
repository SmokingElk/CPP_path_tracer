#include "figures.h"
using namespace std;

// CLASS SceneObject

SceneObject::SceneObject () {
    pos = vec3(0.0f);
    color = vec3(0.0f);
    roughness = 0.0f;
    isLight = false;
};

SceneObject::SceneObject (vec3 posVal, vec3 colorVal, float roughnessVal, bool light) {
    pos = posVal;
    color = colorVal / 255.0f;
    roughness = roughnessVal;
    isLight = light;
};

vec3 SceneObject::getColor () {
    return color;
};

float SceneObject::getRoughness () {
    return roughness;
};

bool SceneObject::getLight () {
    return isLight;
};

// END SceneObject

// CLASS Sphere

Sphere::Sphere () : SceneObject() {
    radius2 = 0.0f;
};

Sphere::Sphere (vec3 pos, float radius, vec3 color, float roughness, bool light) : SceneObject(pos, color, roughness, light) {
    radius2 = radius * radius;
};
    
float Sphere::getCollide (vec3 ro, vec3 rd) {
    vec3 oc = ro - pos;

    float a = rd.dot(rd);
    float b = 2.0f * oc.dot(rd);
    float c = oc.dot(oc) - radius2;

    float D = b * b - 4.0f * a * c;

    if (D < 0) return -1.0f;
    float t1 = (-b + sqrt(D)) / (a * 2.0f);
    float t2 = (-b - sqrt(D)) / (a * 2.0f);

    return min(t1, t2);
};

vec3 Sphere::getNormal (vec3 dot) {
    vec3 dir = dot - pos;
    dir.norm();
    return dir;
};

// END Sphere

// CLASS Plane

Plane::Plane (vec3 pos, vec3 normalVal, vec3 color, float roughness, bool light) : SceneObject(pos, color, roughness, light) {
    normal = normalVal;
    normal.norm();
};
    
float Plane::getCollide (vec3 ro, vec3 rd) {
    vec3 oc = ro - pos;
	return -(oc.dot(normal)) / rd.dot(normal);
};

vec3 Plane::getNormal (vec3 dot) {
    return normal;
};

// END Plane