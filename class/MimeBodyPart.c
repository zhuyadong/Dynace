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



#line 3 "MimeBodyPart.d"
#ifdef _MSC_VER 
#if _MSC_VER > 1200 
#define _POSIX_ 
#endif 


#line 7 "MimeBodyPart.d"
#endif 


#define	CLASS	MimeBodyPart_c
#define	ivType	MimeBodyPart_iv_t

#include "generics.h"

object	MimeBodyPart_c;


#line 58 "MimeBodyPart.c"
typedef struct  _MimeBodyPart_iv_t  {
	object iStr;
	object iHeaders;
	object iHeadersAsString;
	object iContent;
}	MimeBodyPart_iv_t;



#line 19 "MimeBodyPart.d"
PMETHOD objrtn initInstance(object self, char *content); 
PMETHOD char * headersToString(object self); 
PMETHOD void resetString(object self, object *pobj, char *initValue); 

cmeth objrtn MimeBodyPart_cm_gNewMimeBodyPart(object self, char *content)
{ 
	return initInstance(oSuper(MimeBodyPart_c, gNew, self)(self), content); 
} 

PMETHOD objrtn initInstance(object self, char *content)
{ MimeBodyPart_iv_t *iv = GetIVs(MimeBodyPart, self);
	iv->iHeaders = gNew(LinkObject); 
	iv->iContent = gNewWithStr(String, content); 
	return self; 
} 

imeth objrtn MimeBodyPart_im_gDispose(object self)
{ MimeBodyPart_iv_t *iv = GetIVs(MimeBodyPart, self);
	if (iv->iStr) 
		gDispose(iv->iStr); 
	if (iv->iContent) 
		gDispose(iv->iContent); 
	if (iv->iHeadersAsString) 
		gDispose(iv->iHeadersAsString); 
	if (iv->iHeaders) 
		gDeepDispose(iv->iHeaders); 
	return oSuper(MimeBodyPart_c, gDispose, self)(self); 
} 

imeth objrtn MimeBodyPart_im_gAddHeader(object self, char *name, char *value)
{ MimeBodyPart_iv_t *iv = GetIVs(MimeBodyPart, self);
	gAddLast(iv->iHeaders, vBuild(String, name, ": ", value, END)); 
	return self; 
} 

imeth objrtn MimeBodyPart_im_gGetHeaders(object self)
{ MimeBodyPart_iv_t *iv = GetIVs(MimeBodyPart, self);
	return iv->iHeaders; 
} 

imeth char * MimeBodyPart_im_gGetHeader(object self, char *name)
{ MimeBodyPart_iv_t *iv = GetIVs(MimeBodyPart, self);
	object header, seq; 
	char tmpBuf[256]; 

	for (seq=gSequence(iv->iHeaders) ; header = gNext(seq) ; ) { 
		char *valpos, *startPos; 

		startPos = gStringValue(header); 
		strncpy(tmpBuf, startPos, sizeof(tmpBuf)); 
		valpos = strchr(tmpBuf, ':'); 
		if (!valpos) 
			continue; 
		*valpos++ = '\0'; 
		if (stricmp(tmpBuf, name)) 
			continue; 
		while (*valpos == ' ') 
			valpos++; 
		gDispose(seq); 
		return startPos + (valpos - tmpBuf); 
	} 

	return NULL; 
} 

imeth char * MimeBodyPart_im_gGetBodyContent(object self)
{ MimeBodyPart_iv_t *iv = GetIVs(MimeBodyPart, self);
	return gStringValue(iv->iContent); 
} 

PMETHOD char * headersToString(object self)
{ MimeBodyPart_iv_t *iv = GetIVs(MimeBodyPart, self);
	object header, seq; 
	resetString(MimeBodyPart, &iv->iHeadersAsString, NULL); 
	for (seq=gSequence(iv->iHeaders) ; header = gNext(seq) ; ) { 
		gAppend(iv->iHeadersAsString, header); 
		gAppend(iv->iHeadersAsString, (object)"\r\n"); 
	} 

	return gStringValue(iv->iHeadersAsString); 
} 

imeth char * MimeBodyPart_im_gStringValue(object self)
{ MimeBodyPart_iv_t *iv = GetIVs(MimeBodyPart, self);
	resetString(MimeBodyPart, &iv->iStr, headersToString(self)); 
	gAppend(iv->iStr, (object)"\r\n"); 
	gAppend(iv->iStr, iv->iContent); 
	return gStringValue(iv->iStr); 
} 

PMETHOD void resetString(object self, object *pobj, char *initValue)
{ 
	if (IsObj(*pobj)) 
		gDispose(*pobj); 
	*pobj = gNewWithStr(String, initValue ? initValue : ""); 
} 

#line 166 "MimeBodyPart.c"

objrtn	MimeBodyPart_initialize(void)
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

	if (MimeBodyPart_c) {
		LEAVECRITICALSECTION(cs);
		return MimeBodyPart_c;
	}
	INHIBIT_THREADER;
	MimeBodyPart_c = gNewClass(Class, "MimeBodyPart", sizeof(MimeBodyPart_iv_t), 0, END);
	cMethodFor(MimeBodyPart, gNewMimeBodyPart, MimeBodyPart_cm_gNewMimeBodyPart);
	iMethodFor(MimeBodyPart, gGetHeader, MimeBodyPart_im_gGetHeader);
	iMethodFor(MimeBodyPart, gDispose, MimeBodyPart_im_gDispose);
	iMethodFor(MimeBodyPart, gGetBodyContent, MimeBodyPart_im_gGetBodyContent);
	iMethodFor(MimeBodyPart, gGetHeaders, MimeBodyPart_im_gGetHeaders);
	iMethodFor(MimeBodyPart, gDeepDispose, MimeBodyPart_im_gDispose);
	iMethodFor(MimeBodyPart, gStringValue, MimeBodyPart_im_gStringValue);
	iMethodFor(MimeBodyPart, gAddHeader, MimeBodyPart_im_gAddHeader);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return MimeBodyPart_c;
}



