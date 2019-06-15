// Lic:
// TrickyStringBuilder.c
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

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "TrickyStringBuilder.h"

#undef allowchat

void chat(char *message){
	#ifdef allowchat
	printf("DEBUG:> %s\n",message);
	#endif
}


StringBuilder SB_New(unsigned int size){
	chat("Creating new String Builder");
	StringBuilder ret = malloc(sizeof(StringBuilder));
	if (size==1 )
		ret->memsize=1;
	else
		ret->memsize=size; 
	ret->strsize=0;
	ret->str=malloc(3);
	strcpy(ret->str,".");
	return ret;
}

StringBuilder SB_Create(char * str){
	chat("Creation from string requested");
	chat(str);
	StringBuilder ret = SB_New(strlen(str)+1);
	ret->str = malloc(strlen(str)+1);
	ret->memsize = strlen(str)+1;
	ret->strsize=strlen(str);
	strcpy(ret->str,str);
	#ifdef allowchat
	for(int i=0;i<ret->memsize;++i) printf("%02X ",ret->str[i]);
	printf("\n");
	#endif
	return ret;
}

StringBuilder SB_Copy(StringBuilder Ori){
	return SB_Create(Ori->str);
}

void SB_PHex(StringBuilder S){
	char *str=S->str;
	int i=0;
	do{
		printf("%02X ",str[i]);		
	}while(str[i++]);
	printf("\n");
}

void SB_Append(StringBuilder S,char *app){
	static unsigned int max = 0xFFFFFFFF; // No need to define this over and over and over!
	chat("Append request");
	chat(S->str);
	chat(app);
	chat("Appending!");
	int remalloc=0;
	if ((max-strlen(app))<strlen(S->str)+2) {
		printf("WARNING! Maximum length of a string reached! I cannot go further!");
		return;
	}
	while (S->memsize<strlen(app)+strlen(S->str)+2){
		if (S->memsize>max/2) 
			remalloc=max;
		else 
			remalloc=S->memsize*2;
		char *temp=S->str;
		#ifdef allowchat
		printf("DEBUG> Reallocating %d bytes for appended string!\n",remalloc);
		#endif
		S->str=malloc(remalloc);
		S->memsize=remalloc;
		strcpy(S->str,temp);
		free(temp);
	}
	int ins=strlen(S->str);
	for(int i=0;app[i];++i){
		#ifdef allowchat
		printf("Appeding %d/%02X at %d\n",i,app[i],i+ins);
		#endif
		S->str[i+ins] = app[i];
		S->str[i+ins+1]=0;
	}
	S->strsize=strlen(S->str);
}

void SB_AppendSB(StringBuilder S,StringBuilder app) {
	SB_Append(S,app->str);
}

void SB_Free(StringBuilder S){
	free(S->str);
	free(S);
}

bool SB_Same(StringBuilder S,char *cmp) {
	return strcmp(S->str,cmp)==0;
}

