
CXX = g++-mp-7

CXX_STD = -std=c++11
OPT_FLAGS = -O3 -Wall

# source directories
SDIR = .
HEADER_DIR = $(SDIR)/../include
# LIBS= -framework Accelerate

SOURCES_TESTS= $(wildcard $(SDIR)/*.cpp)
OBJECTS_TESTS= $(SOURCES_TESTS:.cpp=.test)

all: $(OBJECTS_TESTS)

$(SDIR)/%.test: $(SDIR)/%.cpp
	$(CXX) $(OPT_FLAGS) $(CXX_STD) -I$(HEADER_DIR) $< -o $@ $(LIBS)

# cleanup and install
.PHONY: clean
clean:
	@rm -f *.test
