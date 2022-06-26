COMPILER = g++
COMPILE_OPTION = -g --std=c++11
COMPILE_LIBRARY = -c --std=c++11

all: memory.o

clean:
	rm -fr temp

memory.o:
	@mkdir -p temp
	@${COMPILER} ${COMPILE_LIBRARY} src/modules/memory.cpp -o temp/memory.o

test: memory.o
	@${COMPILER} ${COMPILE_LIBRARY} test/testMemory.cpp -o temp/testMemory.o
	@${COMPILER} ${COMPILE_OPTION} temp/memory.o temp/testMemory.o -o temp/testMemory
	@temp/testMemory.exe