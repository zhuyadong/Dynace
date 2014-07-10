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




#define	CLASS	Restart_c
#define	ivType	Restart_iv_t

#include "generics.h"

object	Restart_c;


#line 48 "Restart.c"
typedef struct  _Restart_iv_t  {
	object iCond;
}	Restart_iv_t;



#line 33 "Restart.d"
PMETHOD objrtn init(object self, object cond)
{ Restart_iv_t *iv = GetIVs(Restart, self);
	iv->iCond = cond; 
	return self; 
} 




cvmeth objrtn Restart_cvm_vNew(object self, va_list _rest_)
{ 
	object cond = va_arg(_rest_, object);

#line 44 "Restart.d"
	if (ClassOf(self) == CLASS) 
		gShouldNotImplement(self, "New"); 
	ChkArgTypNul(cond, 2, Condition); 
	return init(oSuper(Restart_c, gNew, self)(self), cond); 
} 

#line 76 "Restart.c"

static	objrtn	Restart_cfm_vNew(object self, ...)
{
	va_list	_rest_;
	va_start(_rest_, self);
	return Restart_cvm_vNew(self, _rest_);
}



#line 50 "Restart.d"
imeth objrtn Restart_im_gDeepDispose(object self)
{ Restart_iv_t *iv = GetIVs(Restart, self);
	if (iv->iCond != NULL) 
		gDeepDispose(iv->iCond); 
	return oSuper(Restart_c, gDispose, self)(self); 
} 

imeth objrtn Restart_im_gCopy(object self)
{ 
	return gShouldNotImplement(self, "Copy/DeepCopy"); 
} 

imeth objrtn Restart_im_gValue(object self)
{ Restart_iv_t *iv = GetIVs(Restart, self);
	return iv->iCond; 
} 


#line 106 "Restart.c"

objrtn	Restart_initialize(void)
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

	if (Restart_c) {
		LEAVECRITICALSECTION(cs);
		return Restart_c;
	}
	INHIBIT_THREADER;
	Restart_c = gNewClass(Class, "Restart", sizeof(Restart_iv_t), 0, END);
	cvMethodFor(Restart, vNew, Restart_cvm_vNew, Restart_cfm_vNew);
	iMethodFor(Restart, gValue, Restart_im_gValue);
	iMethodFor(Restart, gCopy, Restart_im_gCopy);
	iMethodFor(Restart, gDeepDispose, Restart_im_gDeepDispose);
	iMethodFor(Restart, gDeepCopy, Restart_im_gCopy);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return Restart_c;
}


