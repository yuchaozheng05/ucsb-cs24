CXX = g++
#CXX = clang++
CXXFLAGS = -Wall -Wno-uninitialized

BINARIES= censor

COMMON_OBJECT_FILES = censor.o

all: ${BINARIES}

tests: ${BINARIES}
	./censor

censor: censor.o ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o