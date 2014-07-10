
# DMAKE makefile for Borland C 16 bit



.IMPORT .IGNORE : BORLAND_HOME


BINDIR = ..\bin
LIBDIR = ..\lib
INCDIR = ..\include


CC = bcc
WARNINGS = -w-par -w-pia -w-pro -w-stu
OPT  = -O -Ot -Z
COPT = -Yo- -Y- -a2 -d
INC  = -I$(INCDIR) -I$(BORLAND_HOME)\include
MM   = -ml
CFLAGS = $(INC) $(COPT) $(MM) $(OPT) $(WARNINGS) -N- $(CFEXTRA)

.d.c .PRECIOUS :
	$(BINDIR)\dpp $(STRAT) -C -g $(INCDIR)\generics.h -ni -p $<

.c.obj:
	@echo $(CFLAGS) >turboc.cfg
	$(CC) -c $<
	@$(BINDIR)\rm -zq turboc.cfg


CLASSES = object.d behavior.d metaclas.d class.d method.d genfun.d dynace.d


OBJ = $(CLASSES:s/.d/.obj/) kernel.obj

curlib.db .LIBRARY : $(OBJ) jumpto.obj
	+tlib $(LIBDIR)\dynldb.lib /E /C /P32 @$(mktmp,tmp.lnk -+$(?:t" &\n-+")\n)
	$(BINDIR)\rm -zq *.obj $(LIBDIR)\dynldb.bak
	echo Done >$@

jumpto.obj : jumpto\jumpto.tc
	tasm /ml $<

kernel.obj : kernels.h object.iv behavior.iv method.iv genfun.iv

object.obj : object.iv

behavior.obj : kernels.h behavior.iv

genfun.obj : kernels.h genfun.iv

method.obj : method.iv

newgens:
	$(BINDIR)\dpp $(STRAT) -C -g $(INCDIR)/generics.h -ni -p *.d -h $(INCDIR)\generics.h

reallynewgens:
	$(BINDIR)\dpp $(STRAT) -C -ni -p *.d -h $(INCDIR)\generics.h


clean :
	$(BINDIR)\rm -zq *.obj generics.* *.o *.pdb *.err
	$(BINDIR)\rm -zq *.~ *.?~ *.??~ *.{* *.bak #*.*

realclean : clean
	$(BINDIR)\rm -zq curlib.*
