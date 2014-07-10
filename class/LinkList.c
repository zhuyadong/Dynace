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




#define	CLASS	LinkList_c
#define	ivType	LinkList_iv_t

#include "generics.h"

object	LinkList_c;


#line 48 "LinkList.c"
typedef struct  _LinkList_iv_t  {
	int iNelm;
	CRITICALSECTION iCS;
	int iCSDisposed;
}	LinkList_iv_t;


#line 39 "LinkList.d"
#include <string.h> 

#define FIRST gNext 
#define LAST gPrevious 

cmeth objrtn LinkList_cm_gNew(object self)
{ 
	object obj = oSuper(LinkList_c, gNew, self)(self); 
	accessIVsOf(obj); 
	INITIALIZECRITICALSECTION(iv->iCS); 
	gInitLink(obj, obj, obj, obj); 
	return obj; 
} 

imeth objrtn LinkList_im_gIncNelm(object self, int inc)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	if (0 > (iv->iNelm += inc)) 
		iv->iNelm = 0; 
	return self; 
} 

imeth int LinkList_im_gSize(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	return iv->iNelm; 
} 

imeth objrtn LinkList_im_gFirst(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	object r; 
	ENTERCRITICALSECTION(iv->iCS); 
	r = FIRST(self); 
	LEAVECRITICALSECTION(iv->iCS); 
	return r; 
} 

imeth objrtn LinkList_im_gLast(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	object r; 
	ENTERCRITICALSECTION(iv->iCS); 
	r = LAST(self); 
	LEAVECRITICALSECTION(iv->iCS); 
	return r; 
} 

imeth objrtn LinkList_im_gAddFirst(object self, object lnk)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	ChkArg(lnk, 2); 
	ENTERCRITICALSECTION(iv->iCS); 
	gAddAfter(self, lnk); 
	LEAVECRITICALSECTION(iv->iCS); 
	return self; 
} 

imeth objrtn LinkList_im_gAddLast(object self, object lnk)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	ChkArg(lnk, 2); 
	ENTERCRITICALSECTION(iv->iCS); 
	gAddBefore(self, lnk); 
	LEAVECRITICALSECTION(iv->iCS); 
	return self; 
} 

imeth objrtn LinkList_im_gInsertObjAt(object self, object lnk, int idx)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	ChkArg(lnk, 2); 
	ENTERCRITICALSECTION(iv->iCS); 
	if (!idx || idx < -iv->iNelm) 
		gAddAfter(self, lnk); 
	else if (idx == -1 || idx >= iv->iNelm) 
		gAddBefore(self, lnk); 
	else if (idx > 0) 
		gAddAfter(gNth(self, idx), lnk); 
	else 
		gAddBefore(gNth(self, idx+1), lnk); 
	LEAVECRITICALSECTION(iv->iCS); 
	return self; 
} 

imeth objrtn LinkList_im_gDisposeFirst(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	ENTERCRITICALSECTION(iv->iCS); 
	if (iv->iNelm) 
		gDispose(FIRST(self)); 
	LEAVECRITICALSECTION(iv->iCS); 
	return self; 
} 

imeth objrtn LinkList_im_gDeepDisposeFirst(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	ENTERCRITICALSECTION(iv->iCS); 
	if (iv->iNelm) 
		gDeepDispose(FIRST(self)); 
	LEAVECRITICALSECTION(iv->iCS); 
	return self; 
} 

imeth objrtn LinkList_im_gRemoveFirst(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	object r; 
	ENTERCRITICALSECTION(iv->iCS); 
	r = iv->iNelm ? gRemove(FIRST(self)) : NULLOBJ; 
	LEAVECRITICALSECTION(iv->iCS); 
	return r; 
} 

imeth objrtn LinkList_im_gDisposeLast(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	ENTERCRITICALSECTION(iv->iCS); 
	if (iv->iNelm) 
		gDispose(LAST(self)); 
	LEAVECRITICALSECTION(iv->iCS); 
	return self; 
} 

imeth objrtn LinkList_im_gDeepDisposeLast(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	ENTERCRITICALSECTION(iv->iCS); 
	if (iv->iNelm) 
		gDeepDispose(LAST(self)); 
	LEAVECRITICALSECTION(iv->iCS); 
	return self; 
} 

imeth objrtn LinkList_im_gRemoveLast(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	object r; 
	ENTERCRITICALSECTION(iv->iCS); 
	if (iv->iNelm) 
		r = gRemove(LAST(self)); 
	else 
		r = NULL; 
	LEAVECRITICALSECTION(iv->iCS); 
	return r; 
} 

imeth objrtn LinkList_im_gDisposeAllNodes(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	object obj; 

	ENTERCRITICALSECTION(iv->iCS); 
	while (obj = FIRST(self)) 
		gDispose(obj); 
	LEAVECRITICALSECTION(iv->iCS); 
	return self; 
} 

imeth objrtn LinkList_im_gDeepDisposeAllNodes(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	object obj; 

	ENTERCRITICALSECTION(iv->iCS); 
	while (obj = FIRST(self)) 
		gDeepDispose(obj); 
	LEAVECRITICALSECTION(iv->iCS); 
	return self; 
} 

imeth objrtn LinkList_im_gDispose(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	gDisposeAllNodes(self); 
	DELETECRITICALSECTION(iv->iCS); 
	iv->iCSDisposed = 1; 
	return oSuper(LinkList_c, gDispose, self)(self); 
} 

imeth objrtn LinkList_im_gDeepDispose(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	gDeepDisposeAllNodes(self); 
	DELETECRITICALSECTION(iv->iCS); 
	iv->iCSDisposed = 1; 
	return oSuper(LinkList_c, gDeepDispose, self)(self); 
} 

imeth objrtn LinkList_im_gSequence(object self)
{ 
	return gNewWithObj(LinkSequence, FIRST(self)); 
} 

imeth objrtn LinkList_im_gCopy(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	object nobj; 
	ivType *iv2; 
	object lnk; 

	ENTERCRITICALSECTION(iv->iCS); 
	nobj = oSuper(LinkList_c, gCopy, self)(self); 
	iv2 = ivPtr(nobj); 

	memset(&iv2->iCS, 0, sizeof iv->iCS); 
	INITIALIZECRITICALSECTION(iv2->iCS); 

	iv2->iNelm = 0; 
	gInitLink(nobj, nobj, nobj, nobj); 
	for (lnk=FIRST(self) ; lnk ; lnk = gNext(lnk)) 
		gAddBefore(nobj, gCopy(lnk)); 
	LEAVECRITICALSECTION(iv->iCS); 
	return nobj; 
} 

imeth objrtn LinkList_im_gDeepCopy(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	object nobj; 
	ivType *iv2; 
	object lnk; 

	ENTERCRITICALSECTION(iv->iCS); 
	nobj = oSuper(LinkList_c, gDeepCopy, self)(self); 
	iv2 = ivPtr(nobj); 

	memset(&iv2->iCS, 0, sizeof iv->iCS); 
	INITIALIZECRITICALSECTION(iv2->iCS); 

	iv2->iNelm = 0; 
	gInitLink(nobj, nobj, nobj, nobj); 
	for (lnk=FIRST(self) ; lnk ; lnk = gNext(lnk)) 
		gAddBefore(nobj, gDeepCopy(lnk)); 
	LEAVECRITICALSECTION(iv->iCS); 
	return nobj; 
} 

imeth objrtn LinkList_im_gStringRep(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	object lnk, s, t; 

	ENTERCRITICALSECTION(iv->iCS); 
	s = oSuper(LinkList_c, gStringRepValue, self)(self); 
	gAppend(s, (object) "  ("); 
	for (lnk = FIRST(self) ; lnk ; ) { 
		t = gStringRepValue(lnk); 
		if (lnk = gNext(lnk)) 
			vBuild(s, NULL, t, ", ", NULL); 
		else 
			gAppend(s, t); 
		gDispose(t); 
	} 
	gAppend(s, (object) ")\n"); 
	LEAVECRITICALSECTION(iv->iCS); 
	return s; 
} 

imeth objrtn LinkList_im_gEnterCriticalSection(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	if (!iv->iCSDisposed) 
		ENTERCRITICALSECTION(iv->iCS); 
	return self; 
} 

imeth objrtn LinkList_im_gLeaveCriticalSection(object self)
{ LinkList_iv_t *iv = GetIVs(LinkList, self);
	if (!iv->iCSDisposed) 
		LEAVECRITICALSECTION(iv->iCS); 
	return self; 
} 


#line 312 "LinkList.c"

objrtn	LinkList_initialize(void)
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

	if (LinkList_c) {
		LEAVECRITICALSECTION(cs);
		return LinkList_c;
	}
	INHIBIT_THREADER;
	Link_initialize();
	if (LinkList_c)  {
		ENABLE_THREADER;
		LEAVECRITICALSECTION(cs);
		return LinkList_c;
	}
	LinkList_c = gNewClass(Class, "LinkList", sizeof(LinkList_iv_t), 0, Link, END);
	cMethodFor(LinkList, gNew, LinkList_cm_gNew);
	iMethodFor(LinkList, gRemoveFirst, LinkList_im_gRemoveFirst);
	iMethodFor(LinkList, gAddFirst, LinkList_im_gAddFirst);
	iMethodFor(LinkList, gInsertObjAt, LinkList_im_gInsertObjAt);
	iMethodFor(LinkList, gDisposeAllNodes, LinkList_im_gDisposeAllNodes);
	iMethodFor(LinkList, gSize, LinkList_im_gSize);
	iMethodFor(LinkList, gDisposeFirst, LinkList_im_gDisposeFirst);
	iMethodFor(LinkList, gDeepDisposeAllNodes, LinkList_im_gDeepDisposeAllNodes);
	iMethodFor(LinkList, gEnterCriticalSection, LinkList_im_gEnterCriticalSection);
	iMethodFor(LinkList, gDeepDisposeFirst, LinkList_im_gDeepDisposeFirst);
	iMethodFor(LinkList, gFirst, LinkList_im_gFirst);
	iMethodFor(LinkList, gDispose, LinkList_im_gDispose);
	iMethodFor(LinkList, gLast, LinkList_im_gLast);
	iMethodFor(LinkList, gDeepDisposeLast, LinkList_im_gDeepDisposeLast);
	iMethodFor(LinkList, gSequence, LinkList_im_gSequence);
	iMethodFor(LinkList, gCopy, LinkList_im_gCopy);
	iMethodFor(LinkList, gRemoveLast, LinkList_im_gRemoveLast);
	iMethodFor(LinkList, gDeepDispose, LinkList_im_gDeepDispose);
	iMethodFor(LinkList, gLeaveCriticalSection, LinkList_im_gLeaveCriticalSection);
	iMethodFor(LinkList, gDisposeLast, LinkList_im_gDisposeLast);
	iMethodFor(LinkList, gStringRep, LinkList_im_gStringRep);
	iMethodFor(LinkList, gIncNelm, LinkList_im_gIncNelm);
	iMethodFor(LinkList, gAddLast, LinkList_im_gAddLast);
	iMethodFor(LinkList, gDeepCopy, LinkList_im_gDeepCopy);

	ENABLE_THREADER;

	LEAVECRITICALSECTION(cs);

	return LinkList_c;
}


