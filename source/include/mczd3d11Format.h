#pragma once

#include "mczMath.h"

namespace mczd3d {

enum VERTEXFORMAT {
	POS_VERTEX,
	POS_RHW_VERTEX,
	NUM_VERTEXFORMAT,
};

struct POS_VERT {
	POS_VERT();
	mcz::vector3	pos;
};


}