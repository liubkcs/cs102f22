RUN = 09-07/fig1-3-1.exe
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
