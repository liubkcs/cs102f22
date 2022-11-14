RUN = 11-14/readfile.exe
PROGS = $(patsubst %.cpp, %.exe, $(wildcard */*.cpp))

CXX = clang++
override CXXFLAGS += -g -Wno-everything

all: $(PROGS)

run: $(RUN)
	"$<"

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) "$<" -o "$@"

test-smallest: 09-19/lab3-22.exe
	echo 1 2 3 | 09-19/lab3-22.exe
	echo 1 3 2 | 09-19/lab3-22.exe
	echo 2 3 1 | 09-19/lab3-22.exe
	echo 2 1 3 | 09-19/lab3-22.exe
	echo 3 1 2 | 09-19/lab3-22.exe
	echo 3 2 1 | 09-19/lab3-22.exe

clean:
	rm -f $(PROGS)
