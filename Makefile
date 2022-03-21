COMPILER = g++
COMPILE_OPTION = -g
COMPILE_LIBRARY = -c

all: memory.o

clean:
	rm -fr temp

memory.o:
	@mkdir -p temp
	@${COMPILER} ${COMPILE_LIBRARY} src/modules/memory.cpp -o temp/memory.o

test: memory.o
	@${COMPILER} ${COMPILE_LIBRARY} test/testMemory.cpp -o temp/testMemory.o
	@${COMPILER} temp/memory.o temp/testMemory.o -o temp/testMemory
	@temp/testMemory.exe