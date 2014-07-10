/*
  Copyright (c) 1996 Blake McBride
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:

  1. Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/



/*  This file automatically generated by dpp - do not edit  */

#define	DPP_STRATEGY	2
#define	DPP_FASTWIDE	0



#line 30 "ArgumentList.d"
#include "dpp.h" 

#define	CLASS	ArgumentList_c
#define	ivType	ArgumentList_iv_t

#include "generics.h"

object	ArgumentList_c;


#line 34 "ArgumentList.d"
static void process_file(object, char *); 

cmeth objrtn ArgumentList_cm_gNew(object self)
{ 
	return gShouldNotImplement(self, "gNew"); 
} 

cmeth objrtn ArgumentList_cm_gNewArglist(object self, int argc, char **argv)
{ 
	int i; 
	object obj = oSuper(ArgumentList_c, gNew, self)(self); 
	for (i=0 ; i < argc ; i++) 
		if (argv[i][0] == '@') 
		process_file(obj, 1+argv[i]); 
	else 
		gAddLast(obj, gNewWithStr(String, argv[i])); 
	return obj; 
} 

static void process_word(char *word, object list, int noexpand) 
{ 
	int wild=0; 
	char *w; 

	if (!noexpand) 
		for (w=word ; *w ; w++) 
		if (*w == '*' || *w == '?') { 
		wild = 1; 
		break; 
	} 
	if (!wild) { 
		gAddLast(list, gNewWithStr(String, word)); 
		return; 
	} 



	gAddLast(list, gNewWithStr(String, word)); 
} 


#define space(x) ((x) <= ' ') 

static char *process_token(char *p, object list) 
{ 
	char word[128], *w; 
	int inquote, noexpand; 

	while (*p && space(*p)) 
		p++; 
	if (noexpand = inquote = *p == '"') 
		p++; 
	for (w=word ; *p && (!space(*p) || inquote) ; p++) 
		if (inquote && *p == '"') 
		inquote = 0; 
	else 
		*w++ = *p; 
	*w = '\0'; 
	if (*word == '@') 
		process_file(list, word+1); 
	else if (*word) 
		process_word(word, list, noexpand); 
	return p; 
} 

static void process_file(object list, char *file) 
{ 
	char buf[256], *p; 
	object fobj; 

	fobj = gOpenFile(File, file, "r"); 
	if (!fobj) { 
		vPrintf(stdoutStream, "Can't open %s\n", file); 
		exit(1); 
	} 
	while (gGets(fobj, buf, sizeof buf)) 
		for (p=buf ; *(p=process_token(p, list)) ; ); 
	gDispose(fobj); 
} 

#line 131 "ArgumentList.c"

objrtn	ArgumentList_initialize(void)
{
	static  CRITICALSECTION  cs;
	static  int volatile once = 0;

	ENTERCRITICALSECTION(_CI_CS_);
	if (!once) {
		INITIALIZECRITICALSECTION(cs);
		once = 1;
	}
	LEAVECRITICALSECTION(_CI_CS_);

	ENTERCRITICALSECTION(cs);

	if (ArgumentList_c) {
		LEAVECRITICALSECTION(cs);
		return ArgumentList_c;
	}
	INHIBIT_THREADER;
	LinkObject_initialize();
	if (ArgumentList_c)  {
		ENABLE_THREADER;
		LEAVECRITICALSECTION(cs);
		return ArgumentList_c;
	}
	ArgumentList_c = gNewClass(Class, "ArgumentList", 0, 0, LinkObject, END);
	cMethodFor(ArgumentList, gNew, ArgumentList_cm_gNew);
	cMethodFor(ArgumentList, gNewArglist, ArgumentList_cm_gNewArglist);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return ArgumentList_c;
}


