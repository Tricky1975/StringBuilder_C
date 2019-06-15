// Lic:
// TrickyStringBuilder.h
// Tricky's String Builder
// version: 19.06.15
// Copyright (C)  Jeroen P. Broks
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgment in the product documentation would be
// appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
// EndLic

#include <stdbool.h>


typedef struct {
	unsigned int memsize;
	unsigned int strsize;
	char* str;
} *StringBuilder;

StringBuilder SB_New(unsigned int size);
StringBuilder SB_Create(char * str);
StringBuilder SB_Copy(StringBuilder Ori);
void SB_Append(StringBuilder S,char *app);
void SB_AppendSB(StringBuilder S,StringBuilder app);
bool SB_Same(StringBuilder S,char *cmp);
void SB_Free(StringBuilder S);
void SB_PHex(StringBuilder S); // Only meant for debugging purposes!

