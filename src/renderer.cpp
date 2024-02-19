#include "renderer.h"
using namespace std;

Sphere sceneObjects[] = {
    Sphere(vec3(0.0f, 0.5f, 0.0f), 0.5f, vec3(220.0f), 0.0f),
    Sphere(vec3(1.0f, 0.4f, 0.0f), 0.4f, vec3(255.0f, 190.0f, 51.0f), 0.0f),
    Sphere(vec3(0.0f, -100.0f, 0.0f), 100.0f, vec3(220.0f), 0.9f),
};

vec3 randomDirs[1024];
int randomDirIndex = 0;

vec3 randomOffsets[1024];
int randomOffsetIndex = 0;

void generateRandomDirs () {
    for (int i = 0; i < 1024; i++) {
        randomDirs[i] = sphereRandomUniform();
    }

    randomDirIndex = 0;
};

vec3 getRandomDir () {
    randomDirIndex = (randomDirIndex + 1) % 1024;
    return randomDirs[randomDirIndex];
};

void generateRandomOffsets () {
    for (int i = 0; i < 1024; i++) {
        randomOffsets[i] = randomVec(ANTIALIASING);
    }

    randomOffsetIndex = 0;
};

vec3 getRandomOffset () {
    randomOffsetIndex = (randomOffsetIndex + 1) % 1024;
    return randomOffsets[randomOffsetIndex];
};

vec3 viewport (int x, int y, int width, int height, float aspectRatio, float screenDist) {
    vec3 dir(
        ((float)x / width - 0.5f) * aspectRatio,
        (float)(height - y) / height - 0.5f,
        -screenDist
    );

    dir.norm();
    return dir;
};

vec3 clampColor (vec3 color) {
    return vec3(
        max(0.0f, min(1.0f, color.x)),
        max(0.0f, min(1.0f, color.y)),
        max(0.0f, min(1.0f, color.z))
    ) * 255.0f;
};

vec3 gammaCorrection (vec3 color) {
    return vec3(
        pow(color.x, 0.45f),
        pow(color.y, 0.45f),
        pow(color.z, 0.45f)
    );
};

vec3 getSky (vec3 rd) {
    float sunPower = pow(max(0.0f, rd.dot(SUN_DIR)), SUN_SIZE);
    return SKY_COLOR * 0.7f + SUN_COLOR * 0.3f * sunPower;
};

float closestCollide (vec3 ro, vec3 rd, Sphere &closestObject) {
    float t = MAX_RENDER_DIST;

    for (auto i : sceneObjects) {
        float collide = i.getCollide(ro, rd);

        if (collide < t && MIN_RENDER_DIST < collide && collide < MAX_RENDER_DIST) {
            closestObject = i;
            t = collide;
        }
    }

    return t;
};

vec3 castRay (vec3 &ro, vec3 &rd, bool &end) {
    Sphere closestObject;
    float t = closestCollide(ro, rd, closestObject);

    if (t >= MAX_RENDER_DIST) {
        end = true;
        return getSky(rd);
    } 

    if (closestObject.getLight()) {
        end = true;
        return closestObject.getColor();
    }

    vec3 collidePoint = ro + rd * t;
    vec3 normal = closestObject.getNormal(collidePoint);

    vec3 specular = reflect(rd, normal);
    vec3 diffuse = getRandomDir();
    
    diffuse *= diffuse.dot(normal);
    diffuse.norm();

    ro = collidePoint;
    rd = vecMix(specular, diffuse, closestObject.getRoughness());

    return closestObject.getColor();
};

vec3 traceRay (vec3 ro, vec3 rd) {
    vec3 res(1.0f);
    bool end = false;

    for (int i = 0; i < BOUNCE_LIMIT; ++i) {
        vec3 color = castRay(ro, rd, end);
        res *= color;

        if (end) return res;
    }

    return vec3(0.0f);
};

void renderScene (int width, int height, char *pixelBuffer) {
    float aspectRatio = (float)width / height;
    float screenDist = aspectRatio / 2.0f / 0.577f;
    
    generateRandomDirs();
    generateRandomOffsets();

    int pixAddr = -1;
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            vec3 rd = viewport(x, y, width, height, aspectRatio, screenDist);            
            
            vec3 color(0.0f);
            for (int i = 0; i < SAMPLES_COUNT; ++i) {
                vec3 ro = CAMERA_ORIGIN + getRandomOffset();
                color += traceRay(ro, rd);
            }
            
            color /= SAMPLES_COUNT;
            vec3 colorConverted = clampColor(gammaCorrection(color));

            pixelBuffer[++pixAddr] = (char)colorConverted.x;
            pixelBuffer[++pixAddr] = (char)colorConverted.y;
            pixelBuffer[++pixAddr] = (char)colorConverted.z;
        }

        float progress = (float)(y + 1) / height * 100.0f;
        cout << progress << "% is ready" << endl;
    }
};