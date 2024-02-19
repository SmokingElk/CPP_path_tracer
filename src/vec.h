#pragma once
#include <iostream>
#include <math.h>

class vec3 {
public:
    float x, y, z;

    vec3 ();
    vec3 (float xVal, float yVal, float zVal);
    vec3 (float commonVal);

    vec3 operator+ (vec3 other);
    vec3& operator+= (vec3 other);

    vec3 operator- (vec3 other);
    vec3& operator-= (vec3 other);

    vec3 operator* (vec3 other);
    vec3& operator*= (vec3 other);

    vec3 operator* (float number);
    vec3& operator*= (float number);

    vec3 operator/ (vec3 other);
    vec3& operator/= (vec3 other);

    vec3 operator/ (float number);
    vec3& operator/= (float number);

    float mag ();
    vec3& norm ();
    float dot (vec3 other);
};

std::ostream& operator<< (std::ostream &stream, vec3 &vec);

class vec4 {
public:
    float x, y, z, w;

    vec4 ();
    vec4 (float xVal, float yVal, float zVal, float wVal = 0.0f);
    vec4 (float commonVal);

    vec4 operator+ (vec4 other);
    vec4& operator+= (vec4 other);

    vec4 operator- (vec4 other);
    vec4& operator-= (vec4 other);

    vec4 operator* (vec4 other);
    vec4& operator*= (vec4 other);

    vec4 operator* (float number);
    vec4& operator*= (float number);

    vec4 operator/ (vec4 other);
    vec4& operator/= (vec4 other);

    vec4 operator/ (float number);
    vec4& operator/= (float number);

    float mag ();
    vec4& norm ();
    float dot (vec4 other);
};