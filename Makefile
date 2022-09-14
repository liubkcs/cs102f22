RUN = 09-12/divide-pie.exe
PROGS = $(patsubst %.cpp, %.exe, $(wildcard */*.cpp))

CXX = clang++
override CXXFLAGS += -g -Wno-everything

all: $(PROGS)

run: $(RUN)
	"$<"

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) "$<" -o "$@"

clean:
	rm -f $(PROGS)
