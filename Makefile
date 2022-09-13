all: main

RUN = 09-07/fig1-3-1
PROGS = $(basename $(wildcard */*.cpp))

CXX = clang++
override CXXFLAGS += -g -Wno-everything

all: $(PROGS)

run: $(RUN)
	"$<"

%: %.cpp
	$(CXX) $(CXXFLAGS) "$<" -o "$@"
	@grep "/$@" .gitignore > .gtmp || true
	@[ -s .gtmp ] || echo "/$@" >> .gitignore; rm .gtmp

clean:
	rm -f $(PROGS)
