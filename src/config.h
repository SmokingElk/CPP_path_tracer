#pragma once
#include <memory>
#include <vector>
#include "vec.h"
#include "figures.h"

#define SAVE_PATH       "res.ppm"

#define RES_WIDTH       1920
#define RES_HEIGHT      1080
#define SAMPLES_COUNT   256
#define BOUNCE_LIMIT    8
#define ANTIALIASING    0.00125f

#define CAMERA_ORIGIN   vec3(0.0f, 0.6f, 5.0f)
#define MIN_RENDER_DIST 0.0000001f
#define MAX_RENDER_DIST 1000.0f

#define SKY_COLOR       vec3(115.0f, 210.0f, 241.0f) / 255.0f
#define SUN_COLOR       vec3(241.0f, 232.0f, 139.0f) / 255.0f
#define SUN_DIR         vec3(0.57735f)
#define SUN_SIZE        32.0f