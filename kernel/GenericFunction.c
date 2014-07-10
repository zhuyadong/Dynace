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



#line 31 "GenericFunction.d"
#include "kernels.h" 
#include <string.h> 

#define	CLASS	GenericFunction_c
#define	ivType	GenericFunction_iv_t

#include "generics.h"

object	GenericFunction_c;

#include "GenericFunction.iv"



#line 48 "GenericFunction.d"
imeth void GenericFunction_im_gInvalidObject(object self, int argn, object arg1)
{ 
	char buf[256]; 

	sprintf(buf, "\nDynace: Generic %s passed an invalid object on arg %d.\n", gName(self), argn); 
	if (argn != 1 && arg1) 
		if (IsaClass(arg1)) 
		sprintf(buf+strlen(buf), "First argument to generic %s was the class %s\n", gName(self), gName(arg1)); 
	else 
		sprintf(buf+strlen(buf), "First argument to generic %s was an instance of the %s class\n", gName(self), gName(ClassOf(arg1))); 
	gError(self, buf); 
} 

imeth void GenericFunction_im_gInvalidType(object self, int argn, object arg1, object cls, object arg)
{ 
	char buf[320]; 

	sprintf(buf, "\nDynace: Generic %s passed an invalid object type on arg %d.\n", gName(self), argn); 
	sprintf(buf+strlen(buf), "Expected an instance of %s\n", gName(cls)); 
	sprintf(buf+strlen(buf), "Received an instance of %s\n", gName(ClassOf(arg))); 
	if (argn != 1 && arg1) 
		if (IsaClass(arg1)) 
		sprintf(buf+strlen(buf), "First argument to generic %s was the class %s\n", gName(self), gName(arg1)); 
	else 
		sprintf(buf+strlen(buf), "First argument to generic %s was an instance of the %s class\n", gName(self), gName(ClassOf(arg1))); 
	gError(self, buf); 
} 

imeth void * GenericFunction_im_gGetGenericPtr(object self)
{ GenericFunction_iv_t *iv = GetIVs(GenericFunction, self);
	return iv->ptrGeneric; 
} 

imeth char * GenericFunction_im_gName(object self)
{ GenericFunction_iv_t *iv = GetIVs(GenericFunction, self);
	return iv->name; 
} 

imeth int GenericFunction_im_gTrace(object self, int mode)
{ GenericFunction_iv_t *iv = GetIVs(GenericFunction, self);
	int pmode = iv->trace; 
	iv->trace = mode; 
	return pmode; 
} 

imeth objrtn GenericFunction_im_gCopy(object self)
{ 
	return gShouldNotImplement(self, "gCopy/gDeepCopy"); 
} 

objrtn GenericFunction_initialize(void) 
{ 
	static int done = 0; 




	if (done) 
		return GenericFunction_c; 

	done = 1; 



	iMethodFor(GenericFunction, gInvalidObject, GenericFunction_im_gInvalidObject); 
	iMethodFor(GenericFunction, gInvalidType, GenericFunction_im_gInvalidType); 
	iMethodFor(GenericFunction, gName, GenericFunction_im_gName); 
	iMethodFor(GenericFunction, gGetGenericPtr, GenericFunction_im_gGetGenericPtr); 
	iMethodFor(GenericFunction, gTrace, GenericFunction_im_gTrace); 
	iMethodFor(GenericFunction, gCopy, GenericFunction_im_gCopy); 
	iMethodFor(GenericFunction, gDeepCopy, GenericFunction_im_gCopy); 
	return GenericFunction_c; 
} 

#if 0 

cmeth objrtn GenericFunction_cm_gNewGeneric(object self, char *n, void *fp){} 
cmeth objrtn GenericFunction_cm_gGetAll(object self){} 
cmeth objrtn GenericFunction_cm_gFindGeneric(object self, char *nam){} 

#endif 
