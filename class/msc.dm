
# DMAKE makefile for Microsoft Visual C 32 & 64 bit


BINDIR = ..\bin
LIBDIR = ..\lib
INCDIR = ..\include

MY_SSL = 1

#MY_SSL_CFLAGS = -DWIN32 -DWIN32_LEAN_AND_MEAN -DL_ENDIAN -DMY_SSL
.IF $(MY_SSL)
MY_SSL_CFLAGS = -DMY_SSL
.ELSE
MY_SSL_CFLAGS = 
.END

CFEXTRA += -MT

.IF $(NATIVE_THREADS)
CFEXTRA += -DNATIVE_THREADS
.END

CC = cl
.IF $(DEBUG)
CFLAGS = -I$(INCDIR) -WX -nologo -W2 -Od -Zi $(MY_SSL_CFLAGS) -Fd$(LIBDIR)\dynm32.pdb $(CFEXTRA) 
.ELSE
CFLAGS = -I$(INCDIR) -WX -nologo -W2 -O2 $(MY_SSL_CFLAGS) $(CFEXTRA)
.END


.d.c .PRECIOUS :
	$(BINDIR)\dpp $(STRAT) -C -g $(INCDIR)\generics.h -p $<


CLASSES = LinkList.d Link.d LinkValue.d LinkObject.d ShortInteger.d Association.d \
	LookupKey.d Set.d Dictionary.d String.d LongInteger.d DoubleFloat.d \
	Character.d SetSequence.d LinkObjectSequence.d StringAssociation.d StringDictionary.d LinkSequence.d UnsignedShortInteger.d \
	Date.d Pointer.d memalloc.d Number.d ObjectAssociation.d \
	Sequence.d Stream.d File.d LowFile.d Array.d CharacterArray.d \
	Constant.d ShortArray.d UnsignedShortArray.d IntegerArray.d LongArray.d FloatArray.d \
	DoubleFloatArray.d BitArray.d ObjectArray.d PointerArray.d NumberArray.d IntegerAssociation.d \
	IntegerDictionary.d FindFile.d BTree.d BTreeNode.d Memory.d Socket.d XMLNode.d \
	crc.d Time.d DateTime.d PropertyList.d BufferedTempFile.d MultipartMime.d MimeBodyPart.d ObjectPool.d \
	Abort.d Condition.d Error.d Restart.d SeriousCondition.d SimpleRestart.d SimpleWarning.d Warning.d WeakPointer.d

OBJ = $(CLASSES:s/.d/.obj/) 

allok.cm .LIBRARY :  $(INCDIR)\generics.h curlib.cm
	echo Done >$@

curlib.cm .LIBRARY : $(OBJ)
	lib /nologo /out:$(LIBDIR)\dynlcm.lib $(LIBDIR)\dynlcm.lib @$(mktmp $(?:t"\n")\n)
	$(BINDIR)\rm -zq *.obj
	echo Done >$@

$(INCDIR)\generics.h : $(CLASSES)
	$(BINDIR)\dpp $(STRAT) -C -g $(INCDIR)\generics.h -t $(INCDIR)\generics.h -h $(INCDIR)\generics.h -p @$(mktmp $(^:t"\n"))

dict.obj set.obj setseq.obj strdict.obj intdict.obj : set1.h

string.obj array.obj : memalloc.h

array.obj : array2.h

array.obj charary.obj  shortary.obj ushrtary.obj longary.obj floatary.obj \
	dblary.obj bitary.obj objary.obj pntrary.obj: array1.h

newgens:
	$(BINDIR)\dpp $(STRAT) -C -g $(INCDIR)/generics.h -p *.d -h $(INCDIR)\generics.h

makegens:
	$(BINDIR)\dpp $(STRAT) -C -g $(INCDIR)/generics.h -s *.d -h $(INCDIR)\generics.h

XPath.exe : XMLNode.c
	$(CC) $(CFLAGS) /Fe$@ -DTEST $< $(LIBDIR)\dynlcm.lib
	$(BINDIR)\rm -zq XMLNode.obj

clean :
	$(BINDIR)\rm -zq *.obj generics.* *.o *.pdb *.err
	$(BINDIR)\rm -zq *.~ *.?~ *.??~ *.{* *.bak #*.*

realclean : clean
	$(BINDIR)\rm -zq curlib.* allok.*


