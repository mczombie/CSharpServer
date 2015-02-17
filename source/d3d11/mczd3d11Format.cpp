#include "StdAfx.h"

#include "mczd3d11Format.h"

namespace mczd3d {

POS_VERT::POS_VERT()
{
	pos.x = pos.y = pos.z = 0.0f;
}

unsigned int GetVertexSize(VERTEXFORMAT format)
{
	return sizeof(POS_VERT);
}

}