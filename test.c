// Lic:
// ***********************************************************
// test.c
// This particular file has been released in the public domain
// and is therefore free of any restriction. You are allowed
// to credit me as the original author, but this is not
// required.
// This file was setup/modified in:
// 
// If the law of your country does not support the concept
// of a product being released in the public domain, while
// the original author is still alive, or if his death was
// not longer than 70 years ago, you can deem this file
// "(c) Jeroen Broks - licensed under the CC0 License",
// with basically comes down to the same lack of
// restriction the public domain offers. (YAY!)
// ***********************************************************
// Version 19.06.15
// EndLic

#include <stdio.h>
#include <string.h>
#include "TrickyStringBuilder.h"


void AllOut(StringBuilder S){
	printf("String All Out!\nstring:\t\t%s\nmemory size:\t%9d\nstring size:\t%9d\ntrue str size:\t%9d\ntrue mem size:\t%9d\n\n",S->str,S->memsize,S->strsize,strlen(S->str),sizeof(S->str));
}

int main(){
	printf("Test utility for StringBuilder\n");
	StringBuilder s1 = SB_Create("Jeroen");
	StringBuilder s2 = SB_Create("Jeroen Broks");
	//SB_PHex(s2);
	printf("Definition output go #1:\n");
	printf("1:%s\t2:%s\tsame:%d\n",s1->str,s2->str,0); //SB_Same(s1,s2->str));
	AllOut(s1);
	AllOut(s2);
	printf("Same: %d\n",SB_Same(s1,s2->str));
	printf("Ready to append!\n");
	SB_Append(s1," Broks");
	printf("Definition output go #2:\n");
	printf("1:%s\t2:%s\tsame:%d\n",s1->str,s2->str,SB_Same(s1,s2->str));
	printf("%s\n",s1->str);
	AllOut(s1);
	AllOut(s2);
	SB_Free(s1);
	SB_Free(s2);
	printf("Test complete\n\n");
}

