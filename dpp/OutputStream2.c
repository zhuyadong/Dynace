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



#line 31 "OutputStream2.d"
#include "dpp.h" 

#define	CLASS	OutputStream2_c
#define	ivType	OutputStream2_iv_t

#include "generics.h"

object	OutputStream2_c;


#line 50 "OutputStream2.c"
typedef struct  _OutputStream2_iv_t  {
	object iS1;
	object iS2;
	int iUse;
}	OutputStream2_iv_t;


#line 40 "OutputStream2.d"
#include <ctype.h> 
#include <stdarg.h> 
#include <string.h> 

cmeth objrtn OutputStream2_cm_gNew(object self)
{ 
	return gShouldNotImplement(self, "gNew"); 
} 

cmeth objrtn OutputStream2_cm_gNewWithStrStr(object self, char *file, char *ifile)
{ 
	object obj = oSuper(OutputStream2_c, gNew, self)(self); 
	ivType *iv = ivPtr(obj); 
	iv->iS1 = gNewWithStrStr(OutputStream, file, ifile); 
	return obj; 
} 

imeth objrtn OutputStream2_im_gOpenStream2(object self, char *file, char *ifile)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	if (iv->iS2) 
		gDispose(iv->iS2); 
	iv->iS2 = gNewWithStrStr(OutputStream, file, ifile); 
	return self; 
} 

imeth objrtn OutputStream2_im_gUseStream(object self, int n)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	iv->iUse = n; 
	return self; 
} 

imeth int OutputStream2_im_gFlush(object self)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	if (iv->iS1 && (!iv->iUse || iv->iUse == 1)) 
		gFlush(iv->iS1); 
	if (iv->iS2 && (!iv->iUse || iv->iUse == 2)) 
		gFlush(iv->iS2); 
	return 0; 
} 



imeth objrtn OutputStream2_im_gFlushm(object self)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	if (iv->iS1 && (!iv->iUse || iv->iUse == 1)) 
		gFlushm(iv->iS1); 
	if (iv->iS2 && (!iv->iUse || iv->iUse == 2)) 
		gFlushm(iv->iS2); 
	return self; 
} 

imeth objrtn OutputStream2_im_gDispose(object self)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	if (iv->iS1 && (!iv->iUse || iv->iUse == 1)) 
		gDispose(iv->iS1); 
	if (iv->iS2 && (!iv->iUse || iv->iUse == 2)) 
		gDispose(iv->iS2); 
	return oSuper(OutputStream2_c, gDispose, self)(self); 
} 

imeth objrtn OutputStream2_im_gPut(object self, object tkn)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	if (iv->iS1 && (!iv->iUse || iv->iUse == 1)) 
		gPut(iv->iS1, tkn); 
	if (iv->iS2 && (!iv->iUse || iv->iUse == 2)) 
		if (iv->iUse == 2) 
		gPut(iv->iS2, tkn); 
	else 
		gPut(iv->iS2, gCopy(tkn)); 
	return self; 
} 

imeth objrtn OutputStream2_im_gPutm(object self, object tkn)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	if (iv->iS1 && (!iv->iUse || iv->iUse == 1)) 
		gPutm(iv->iS1, tkn); 
	if (iv->iS2 && (!iv->iUse || iv->iUse == 2)) 
		if (iv->iUse == 2) 
		gPutm(iv->iS2, tkn); 
	else 
		gPutm(iv->iS2, gCopy(tkn)); 
	return self; 
} 

imeth int OutputStream2_im_gPuts(object self, char *str)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	int r = 0; 

	if (iv->iS1 && (!iv->iUse || iv->iUse == 1)) 
		r = gPuts(iv->iS1, str); 
	if (iv->iS2 && (!iv->iUse || iv->iUse == 2)) 
		r = gPuts(iv->iS2, str); 
	return r; 
} 

ivmeth int OutputStream2_ivm_vPrintf(object self, va_list _rest_)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);char * fmt = va_arg(_rest_, char *);
	char buf[256]; 
	int r=0; 
	MAKE_REST(fmt); 

	vsprintf(buf, fmt, _rest_); 
	if (iv->iS1 && (!iv->iUse || iv->iUse == 1)) 
		r = vPrintf(iv->iS1, "%s", buf); 
	if (iv->iS2 && (!iv->iUse || iv->iUse == 2)) 
		r = vPrintf(iv->iS2, "%s", buf); 
	return r; 
} 

#line 168 "OutputStream2.c"

static	int	OutputStream2_ifm_vPrintf(object self, ...)
{
	va_list	_rest_;
	va_start(_rest_, self);
	return OutputStream2_ivm_vPrintf(self, _rest_);
}



#line 149 "OutputStream2.d"
imeth objrtn OutputStream2_im_gSetOSVars(object self, object cname, object cvs, object ivs)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	if (iv->iS1 && (!iv->iUse || iv->iUse == 1)) 
		gSetOSVars(iv->iS1, cname, cvs, ivs); 
	if (iv->iS2 && (!iv->iUse || iv->iUse == 2)) 
		gSetOSVars(iv->iS2, cname, cvs, ivs); 
	return self; 
} 

imeth objrtn OutputStream2_im_gTLineDirective(object self)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	if (iv->iS1 && (!iv->iUse || iv->iUse == 1)) 
		gTLineDirective(iv->iS1); 
	if (iv->iS2 && (!iv->iUse || iv->iUse == 2)) 
		gTLineDirective(iv->iS2); 
	return self; 
} 

imeth objrtn OutputStream2_im_gSLineDirective(object self)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	if (iv->iS1 && (!iv->iUse || iv->iUse == 1)) 
		gSLineDirective(iv->iS1); 
	if (iv->iS2 && (!iv->iUse || iv->iUse == 2)) 
		gSLineDirective(iv->iS2); 
	return self; 
} 

imeth objrtn OutputStream2_im_gForceLineDirective(object self)
{ OutputStream2_iv_t *iv = GetIVs(OutputStream2, self);
	if (iv->iS1 && (!iv->iUse || iv->iUse == 1)) 
		gForceLineDirective(iv->iS1); 
	if (iv->iS2 && (!iv->iUse || iv->iUse == 2)) 
		gForceLineDirective(iv->iS2); 
	return self; 
} 


#line 217 "OutputStream2.c"

objrtn	OutputStream2_initialize(void)
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

	if (OutputStream2_c) {
		LEAVECRITICALSECTION(cs);
		return OutputStream2_c;
	}
	INHIBIT_THREADER;
	OutputStream2_c = gNewClass(Class, "OutputStream2", sizeof(OutputStream2_iv_t), 0, END);
	cMethodFor(OutputStream2, gNew, OutputStream2_cm_gNew);
	cMethodFor(OutputStream2, gNewWithStrStr, OutputStream2_cm_gNewWithStrStr);
	iMethodFor(OutputStream2, gFlush, OutputStream2_im_gFlush);
	iMethodFor(OutputStream2, gPuts, OutputStream2_im_gPuts);
	iMethodFor(OutputStream2, gPutm, OutputStream2_im_gPutm);
	iMethodFor(OutputStream2, gForceLineDirective, OutputStream2_im_gForceLineDirective);
	iMethodFor(OutputStream2, gUseStream, OutputStream2_im_gUseStream);
	iMethodFor(OutputStream2, gDispose, OutputStream2_im_gDispose);
	iMethodFor(OutputStream2, gPut, OutputStream2_im_gPut);
	iMethodFor(OutputStream2, gSLineDirective, OutputStream2_im_gSLineDirective);
	iMethodFor(OutputStream2, gFlushm, OutputStream2_im_gFlushm);
	iMethodFor(OutputStream2, gOpenStream2, OutputStream2_im_gOpenStream2);
	ivMethodFor(OutputStream2, vPrintf, OutputStream2_ivm_vPrintf, OutputStream2_ifm_vPrintf);
	iMethodFor(OutputStream2, gSetOSVars, OutputStream2_im_gSetOSVars);
	iMethodFor(OutputStream2, gTLineDirective, OutputStream2_im_gTLineDirective);
	iMethodFor(OutputStream2, gDeepDispose, OutputStream2_im_gDispose);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return OutputStream2_c;
}


