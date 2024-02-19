#pragma once
#include <math.h>
#include "config.h"
#include "vec.h"

class SceneObject {

private:
    vec3 color;
    float roughness;
    bool isLight;

protected:
    vec3 pos;
    
public:
    SceneObject ();
    SceneObject (vec3 posVal, vec3 colorVal, float roughnessVal = 1.0, bool light = false);
    
    vec3 getColor ();
    float getRoughness ();
    bool getLight ();

    virtual float getCollide (vec3 ro, vec3 rd) = 0;
    virtual vec3 getNormal (vec3 dot) = 0;
};

class Sphere : public SceneObject {

protected:
    float radius2;

public:
    Sphere ();
    Sphere (vec3 pos, float radius, vec3 color, float roughness = 1.0, bool light = false);
    
    float getCollide (vec3 ro, vec3 rd) override;
    vec3 getNormal (vec3 dot) override;

};

class Plane : public SceneObject {

protected:
    vec3 normal;

public:
    Plane (vec3 pos, vec3 normalVal, vec3 color, float roughness = 1.0, bool light = false);
    
    float getCollide (vec3 ro, vec3 rd) override;
    vec3 getNormal (vec3 dot) override;

};