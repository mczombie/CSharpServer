#pragma once

namespace mcz {

struct vector3 {
	vector3() {}
	vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	float x, y, z;
};

struct vector4 {
	float x, y, z, w;
};


}