
#  Makefile designed for use by the DMAKE.EXE utility and
#  Borland C 32 bit


TARGET = main

C_SRC = main.c


BORLAND_HOME = j:\bc45

DYNACE_PATH = ..\..

BINDIR = $(DYNACE_PATH)\bin
LIBDIR = $(DYNACE_PATH)\lib
INCDIR = $(DYNACE_PATH)\include


CC = bcc32
WARNINGS = -w-par -w-pia -w-pro -w-stu
.IF $(DEBUG)
OPT = -Od -v
LFLAGS = /c /x /v
.ELSE
OPT  = -O -Z -OtglbWimpv -k- # -Oe doesn't work
LFLAGS = /c /x
.END
COPT = -a4 -d -N- -D_WINDOWS
CFLAGS = $(COPT) $(OPT) $(WARNINGS)

INC  = -I$(INCDIR) -I$(BORLAND_HOME)\include

LIBS = $(LIBDIR)\{dwdsnb dynlcb}.lib

BLIBS = $(BORLAND_HOME)\lib\{cw32 import32}.lib


BSTARTUP = $(BORLAND_HOME)\lib\c0w32.obj


OBJS = {$(C_SRC:b)}.obj



# Since DMAKE diversions treat the backslach like an escape sequence it is
# necessary to double up the backslashes located in paths
BSTARTUP2 := $(BSTARTUP:s/\/\\/)
BLIBS2    := $(BLIBS:s/\/\\/)
LIBS2     := $(LIBS:s/\/\\/)
OBJS2     := $(OBJS:s/\/\\/)


.c.obj:
	@echo $(CFLAGS) >bcc32.cfg
	@echo $(INC) >>bcc32.cfg
	$(CC) -c $<
	@rm -zq bcc32.cfg


$(TARGET).exe : $(OBJS) $(TARGET).def $(LIBS) $(TARGET).res
	tlink32 @$(mktmp,lnk.rsp  \
		$(LFLAGS) $(BSTARTUP2) +  \n\
		$(OBJS2) \n\
		$@ \n\
		\n\
		$(LIBS2) +\n\
		$(BLIBS2) \n\
		$(TARGET).def \n\
		$(TARGET).res \n)
		

$(OBJS) : resource.h

$(TARGET).res : $(TARGET).rc
	brcc -w32 $<


clean:
	$(BINDIR)\rm -zq *.obj
	$(BINDIR)\rm -zq *.exe
	$(BINDIR)\rm -zq *.ex1
	$(BINDIR)\rm -zq *.res
	$(BINDIR)\rm -zq *.aps
	$(BINDIR)\rm -zq *.pdb
	$(BINDIR)\rm -zq *.wsp
	$(BINDIR)\rm -zq *.ilk
	$(BINDIR)\rm -zq *.bsc
	$(BINDIR)\rm -zq *.vcp
	$(BINDIR)\rm -zq *.pch
	$(BINDIR)\rm -zq *.sbr
	$(BINDIR)\rm -zq *.vcw
	$(BINDIR)\rm -zq *.map
	$(BINDIR)\rm -zq generics.*
	$(BINDIR)\rm -zqr WinDebug
	$(BINDIR)\rm -zqr WinRel
	$(BINDIR)\rm -zq *.rws
	$(BINDIR)\rm -zq *.~re
	$(BINDIR)\rm -zq *.csm
	$(BINDIR)\rm -zq *.dsw
	$(BINDIR)\rm -zq *.~de