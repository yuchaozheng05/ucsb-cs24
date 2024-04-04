#CXX = g++
CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES= censor

COMMON_OBJECT_FILES = censor.cpp

all: ${BINARIES}

tests: ${BINARIES}
	./censor

censor: censor.cpp ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o