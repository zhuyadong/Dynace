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




#define	CLASS	MultipartMime_c
#define	ivType	MultipartMime_iv_t

#include "generics.h"

object	MultipartMime_c;


#line 48 "MultipartMime.c"
typedef struct  _MultipartMime_iv_t  {
	object iBodyParts;
	object iStr;
	char iBoundaryString [ 256 ];
	char iSubType [ 32 ];
	char iContentType [ 64 ];
}	MultipartMime_iv_t;



#line 11 "MultipartMime.d"
PMETHOD objrtn initParseInstance(object self, char *content, char *boundary); 
PMETHOD objrtn initNewInstance(object self, char *subType, char *boundaryString); 
PMETHOD void resetString(object self, object *pobj, char *initValue); 

cmeth objrtn MultipartMime_cm_gNewMultipartMime(object self, char *subType, char *boundaryString)
{ 
	if (!boundaryString || !subType) 
		return NULL; 
	return initNewInstance(oSuper(MultipartMime_c, gNew, self)(self), subType, boundaryString); 
} 

cmeth objrtn MultipartMime_cm_gParseMultipartFromString(object self, char *content, char *boundary)
{ 
	object newDoc; 
	if (!content || !boundary || *content == '\0' || *boundary == '\0') 
		return NULL; 
	newDoc = oSuper(MultipartMime_c, gNew, self)(self); 
	if (!initParseInstance(newDoc, content, boundary)) 
		newDoc = gDispose(newDoc); 
	return newDoc; 
} 

PMETHOD objrtn initParseInstance(object self, char *content, char *boundary)
{ MultipartMime_iv_t *iv = GetIVs(MultipartMime, self);
	char *curPos = NULL, *endPos, boundaryBuf[256], *buf; 
	int boundaryLen, lineBreakCharCnt = 0, headerErr = 0; 
	object bodyPart; 

	strncpy(iv->iBoundaryString, boundary, sizeof(iv->iBoundaryString) - 1); 
	iv->iBodyParts = gNew(LinkObject); 
	*boundaryBuf = boundaryBuf[1] = '-'; 
	boundaryBuf[2] = '\0'; 
	strncat(boundaryBuf, boundary, sizeof(boundaryBuf) - 4); 
	boundaryLen = strlen(boundaryBuf); 
	while (!headerErr) { 
		object headerNames, headerMap, bodyPart, seq, val; 
		int contentLen; 
		char *bufPos; 

		if (!curPos) { 
			curPos = strstr(content, boundaryBuf); 
			if (!curPos) 
				return NULL; 
			curPos += boundaryLen; 
		} 
		endPos = strstr(curPos, boundaryBuf); 

		if (!endPos) 
			return NULL; 

		while (*curPos == '\r' || *curPos == '\n' || *curPos == ' ') 
			curPos++; 

		contentLen = endPos - curPos; 
		buf = malloc(contentLen + 1); 
		memcpy(buf, curPos, contentLen); 
		buf[contentLen] = '\0'; 


		bufPos = buf; 
		headerNames = gNew(LinkObject); 
		headerMap = gNew(StringDictionary); 
		while (1) { 
			char *headerEndPos, *headerVal, headerEndPosChar; 

			if (*bufPos == '\r' || *bufPos == '\n') { 
				if (*bufPos == '\r' && bufPos[1] == '\n') 
					bufPos += 2; 
				else 
					bufPos++; 
				break; 
			} 
			headerEndPos = strpbrk(bufPos, "\r\n"); 
			if (!headerEndPos) { 
				headerErr = 1; 
				break; 
			} 
			headerEndPosChar = *headerEndPos; 

			*headerEndPos = '\0'; 
			headerVal = strchr(bufPos, ':'); 
			if (headerVal) { 
				*headerVal++ = '\0'; 
				while (*headerVal == ' ') 
					headerVal++; 
				if (*headerVal != '\0') { 
					gAddLast(headerNames, gNewWithStr(String, bufPos)); 
					gAddStr(headerMap, bufPos, gNewWithStr(String, headerVal)); 
				} 
			} 
			bufPos = headerEndPos + 1; 
			if (headerEndPosChar == '\r' && *bufPos == '\n') 
				bufPos++; 
		} 

		if (!headerErr) { 

			bodyPart = gNewMimeBodyPart(MimeBodyPart, bufPos); 
			for (seq=gSequence(headerNames) ; val = gNext(seq) ; ) 
				gAddHeader(bodyPart, gStringValue(val), gStringValue(gFindValueStr(headerMap, gStringValue(val)))); 

			gAddLast(iv->iBodyParts, bodyPart); 
			curPos = endPos + boundaryLen; 
		} 

		free(buf); 
		gDeepDispose(headerNames); 
		gDeepDispose(headerMap); 

		if (!headerErr && *curPos == '-' && curPos[1] == '-') 
			break; 
	} 

	return self; 
} 

PMETHOD objrtn initNewInstance(object self, char *subType, char *boundaryString)
{ MultipartMime_iv_t *iv = GetIVs(MultipartMime, self);
	iv->iBodyParts = gNew(LinkObject); 
	strncpy(iv->iBoundaryString, boundaryString, sizeof(iv->iBoundaryString) - 1); 
	strncpy(iv->iSubType, subType, sizeof(iv->iSubType)-1); 
	strcpy(iv->iContentType, "multipart/"); 
	strcat(iv->iContentType, subType); 
	return self; 
} 

imeth objrtn MultipartMime_im_gDispose(object self)
{ MultipartMime_iv_t *iv = GetIVs(MultipartMime, self);
	if (iv->iStr) 
		gDispose(iv->iStr); 
	if (iv->iBodyParts) 
		gDeepDispose(iv->iBodyParts); 
	return oSuper(MultipartMime_c, gDispose, self)(self); 
} 

imeth objrtn MultipartMime_im_gAddBodyPart(object self, object bodyPart)
{ MultipartMime_iv_t *iv = GetIVs(MultipartMime, self);
	gAddLast(iv->iBodyParts, bodyPart); 
	return self; 
} 

imeth char * MultipartMime_im_gGetContentType(object self)
{ MultipartMime_iv_t *iv = GetIVs(MultipartMime, self);
	return iv->iContentType; 
} 

imeth char * MultipartMime_im_gGetBoundaryString(object self)
{ MultipartMime_iv_t *iv = GetIVs(MultipartMime, self);
	return iv->iBoundaryString; 
} 

imeth objrtn MultipartMime_im_gGetBodyParts(object self)
{ MultipartMime_iv_t *iv = GetIVs(MultipartMime, self);
	return iv->iBodyParts; 
} 

imeth char * MultipartMime_im_gStringValue(object self)
{ MultipartMime_iv_t *iv = GetIVs(MultipartMime, self);
	object bodyPart, seq; 
	resetString(MultipartMime, &iv->iStr, ""); 
	for (seq=gSequence(iv->iBodyParts) ; bodyPart = gNext(seq) ; ) { 
		gAppend(iv->iStr, (object)"--"); 
		gAppend(iv->iStr, (object)iv->iBoundaryString); 
		gAppend(iv->iStr, (object)"\r\n"); 
		gAppend(iv->iStr, (object)gStringValue(bodyPart)); 
		gAppend(iv->iStr, (object)"\r\n\r\n"); 
	} 
	gAppend(iv->iStr, (object)"--"); 
	gAppend(iv->iStr, (object)iv->iBoundaryString); 
	gAppend(iv->iStr, (object)"--"); 
	return gStringValue(iv->iStr); 
} 

PMETHOD void resetString(object self, object *pobj, char *initValue)
{ 
	if (IsObj(*pobj)) 
		gDispose(*pobj); 
	*pobj = gNewWithStr(String, initValue ? initValue : ""); 
} 

#line 240 "MultipartMime.c"

objrtn	MultipartMime_initialize(void)
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

	if (MultipartMime_c) {
		LEAVECRITICALSECTION(cs);
		return MultipartMime_c;
	}
	INHIBIT_THREADER;
	MultipartMime_c = gNewClass(Class, "MultipartMime", sizeof(MultipartMime_iv_t), 0, END);
	cMethodFor(MultipartMime, gNewMultipartMime, MultipartMime_cm_gNewMultipartMime);
	cMethodFor(MultipartMime, gParseMultipartFromString, MultipartMime_cm_gParseMultipartFromString);
	iMethodFor(MultipartMime, gGetBodyParts, MultipartMime_im_gGetBodyParts);
	iMethodFor(MultipartMime, gGetContentType, MultipartMime_im_gGetContentType);
	iMethodFor(MultipartMime, gAddBodyPart, MultipartMime_im_gAddBodyPart);
	iMethodFor(MultipartMime, gDispose, MultipartMime_im_gDispose);
	iMethodFor(MultipartMime, gGetBoundaryString, MultipartMime_im_gGetBoundaryString);
	iMethodFor(MultipartMime, gDeepDispose, MultipartMime_im_gDispose);
	iMethodFor(MultipartMime, gStringValue, MultipartMime_im_gStringValue);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return MultipartMime_c;
}



