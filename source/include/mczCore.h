#pragma once

#include <assert.h>

#define SAFE_DELETE(n)			if(n) { delete (n); (n)=nullptr; }
#define SAFE_DELETE_ARRAY(n)	if(n) { delete [] (n); (n)=nullptr; }
#define SAFE_RELEASE(n)			if(n) { n->Release(); }
#define ZOMBIE_PURE				=0

namespace mczCore
{


}