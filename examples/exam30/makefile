#  Makefile designed for use by the GNU MAKE utility and		-*-Makefile-*-
#  GCC

ifdef WINE
WINEINCPATH = /usr/include/wine
CC = winegcc -m32
else
CC = gcc
endif

ifdef TCC # target compiler
CC = $(TCC)
GCC = $(TCC)
endif

DYNACE_PATH = ../..

BINDIR = $(DYNACE_PATH)/bin
LIBDIR = $(DYNACE_PATH)/lib
INCDIR = $(DYNACE_PATH)/include


#DEBUG = -g
#DEBUG = -O

ifdef WINE
CFLAGS = -I$(INCDIR) -I$(WINEINCPATH)/windows -D_WINDOWS -D_WIN32 -D__WINE__
GFLAGS = -I$(INCDIR) -I$(WINEINCPATH)/windows -D_WINDOWS -D_WIN32 -D__WINE__ -O -w
else
CFLAGS = -I$(INCDIR)
GFLAGS = -I$(INCDIR) -O -w
endif

TARGET = main

CFILES = main.c

OBJS = $(CFILES:.c=.o) 


.c.o:
	$(CC) $(CFLAGS) $(DEBUG) -c $<


$(TARGET) : $(OBJS)
	$(CC) $(DEBUG) -o $(TARGET) $(OBJS) $(LIBDIR)/dynace.a -lm
ifdef WINE
	mv $(TARGET).exe $(TARGET)
endif

clean:
	-rm -f *.obj *.exe generics.* $(TARGET) $(TARGET).exe.so *.o *~

