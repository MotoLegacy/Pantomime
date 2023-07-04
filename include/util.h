#ifndef _UTIL_H_
#define _UTIL_H_

#include "types.h"

extern char* Util_CharDeleteAtIndex(char* src, int index);
extern char* Util_BuildStringFromChunk(char* str, int start, int end);

#endif // _UTIL_H_
