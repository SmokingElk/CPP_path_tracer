#include "vec.h"
using namespace std;

// CLASS vec3

vec3::vec3 () {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
};

vec3::vec3 (float xVal, float yVal, float zVal) {
    x = xVal;
    y = yVal;
    z = zVal;
};

vec3::vec3 (float commonVal) {
    x = commonVal;
    y = commonVal;
    z = commonVal;
};

vec3 vec3::operator+ (vec3 other) {
    return vec3(
        x + other.x,
        y + other.y,
        z + other.z
    );
};

vec3& vec3::operator+= (vec3 other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
};

vec3 vec3::operator- (vec3 other) {
    return vec3(
        x - other.x,
        y - other.y,
        z - other.z
    );
};

vec3& vec3::operator-= (vec3 other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
};

vec3 vec3::operator* (vec3 other) {
    return vec3(
        x * other.x,
        y * other.y,
        z * other.z
    );
};

vec3& vec3::operator*= (vec3 other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
};

vec3 vec3::operator* (float number) {
    return vec3(
        x * number,
        y * number,
        z * number
    );
};

vec3& vec3::operator*= (float number) {
    x *= number;
    y *= number;
    z *= number;
    return *this;
};

vec3 vec3::operator/ (vec3 other) {
    return vec3(
        x / other.x,
        y / other.y,
        z / other.z
    );
};

vec3& vec3::operator/= (vec3 other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
};

vec3 vec3::operator/ (float number) {
    return vec3(
        x / number,
        y / number,
        z / number
    );
};

vec3& vec3::operator/= (float number) {
    x /= number;
    y /= number;
    z /= number;
    return *this;
};

float vec3::mag () {
    return sqrt(x * x + y * y + z * z);
};

vec3& vec3::norm () {
    return *this /= this->mag();
};

float vec3::dot (vec3 other) {
    return x * other.x + y * other.y + z * other.z;
};

ostream& operator<< (ostream &stream, vec3 &vec) {
    stream << "vec3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return stream;
};

// END vec3

// CLASS vec4

vec4::vec4 () {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
};

vec4::vec4 (float xVal, float yVal, float zVal, float wVal) {
    x = xVal;
    y = yVal;
    z = zVal;
    w = wVal;
};

vec4::vec4 (float commonVal) {
    x = commonVal;
    y = commonVal;
    z = commonVal;
    w = commonVal;
};

vec4 vec4::operator+ (vec4 other) {
    return vec4(
        x + other.x,
        y + other.y,
        z + other.z,
        w + other.w
    );
};

vec4& vec4::operator+= (vec4 other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
};

vec4 vec4::operator- (vec4 other) {
    return vec4(
        x - other.x,
        y - other.y,
        z - other.z,
        w - other.w
    );
};

vec4& vec4::operator-= (vec4 other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
};

vec4 vec4::operator* (vec4 other) {
    return vec4(
        x * other.x,
        y * other.y,
        z * other.z,
        w * other.w
    );
};

vec4& vec4::operator*= (vec4 other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
};

vec4 vec4::operator* (float number) {
    return vec4(
        x * number,
        y * number,
        z * number,
        w * number
    );
};

vec4& vec4::operator*= (float number) {
    x *= number;
    y *= number;
    z *= number;
    w *= number;
    return *this;
};

vec4 vec4::operator/ (vec4 other) {
    return vec4(
        x / other.x,
        y / other.y,
        z / other.z,
        w / other.w
    );
};

vec4& vec4::operator/= (vec4 other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
    return *this;
};

vec4 vec4::operator/ (float number) {
    return vec4(
        x / number,
        y / number,
        z / number,
        w / number
    );
};

vec4& vec4::operator/= (float number) {
    x /= number;
    y /= number;
    z /= number;
    w /= number;
    return *this;
};

float vec4::mag () {
    return sqrt(x * x + y * y + z * z + w * w);
};

vec4& vec4::norm () {
    return *this /= this->mag();
};

float vec4::dot (vec4 other) {
    return x * other.x + y * other.y + z * other.z + w * other.w;
};

ostream& operator<< (ostream &stream, vec4 &vec) {
    stream << "vec4(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
    return stream;
};

// END vec4