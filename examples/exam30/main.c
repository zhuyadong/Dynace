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



#include "generics.h"


int main(int argc, char *argv[])
{
	object	myObj, seq, lnk;


	InitDynace(&argc);


	myObj = gSubClasses(Object);
	for (seq=gSequence(myObj) ; lnk = gNext(seq) ; )
		gPrint(lnk, stdoutStream);
	gDispose(myObj);


	printf("\n\n");

	myObj = gSuperClasses(Dictionary);
	for (seq=gSequence(myObj) ; lnk = gNext(seq) ; )
		gPrint(lnk, stdoutStream);
/*	gDispose(myObj);  */


	printf("\n\n");

	printf("%s\n", gIsKindOf(myObj, Object) ? "Yes" : "No");
	printf("%s\n", gIsKindOf(myObj, LinkObject) ? "Yes" : "No");
	printf("%s\n", gIsKindOf(myObj, LinkList) ? "Yes" : "No");
	printf("%s\n", gIsKindOf(myObj, Dictionary) ? "Yes" : "No");


	printf("\n\n");

	printf("%s\n", IsaClass(Link) ? "Yes" : "No");
	printf("%s\n", IsaClass(myObj) ? "Yes" : "No");

	printf("\n\n");

	printf("%s\n", IsInstanceOf(myObj, LinkObject) ? "Yes" : "No");
	printf("%s\n", IsInstanceOf(myObj, LinkList) ? "Yes" : "No");

	printf("\n\n");

	printf("%s\n", RespondsTo(myObj, gFirst) ? "Yes" : "No");
	printf("%s\n", RespondsTo(myObj, gDispose) ? "Yes" : "No");
	printf("%s\n", RespondsTo(myObj, gShortValue) ? "Yes" : "No");


	return 0;
}









