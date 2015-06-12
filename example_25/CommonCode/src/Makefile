# W. H. Bell
# A Makefile to build libCommonCode.a

CC=g++
TARGET=../lib/libCommonCode.a
OBJECTS=RootDictionary.o

$(TARGET): $(OBJECTS)
	@echo "**"
	@echo "** Creating Library"
	@echo "**"
	ar $(OBJECTS) $(LIBS) -o $(TARGET)

clean:
	@rm -f *.o *~

veryclean: clean
	@rm -f $(TARGET).exe

%.o: %.cc
	@echo "**"
	@echo "** Compiling C++ Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) $< 

RootDictionary.cxx: LinkDef.h
	@echo "**"
	@echo "** Creating Root dictionary"
	@echo "**"
	rootcint -f RootDictionary.cxx -c $<

RootDictionary.o: RootDictionary.cxx
	@echo "**"
	@echo "** Compiling C++ Source" 
	@echo "**"
	$(CC) -c $(INCFLAGS) RootDictionary.cxx

