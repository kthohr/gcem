# GCEM Test build

ifeq ($(CXX),)
	CXX = g++
endif

CXX_STD = -std=c++11

ifneq (,$(findstring clang,$(CXX)))
	OPT_FLAGS = -g -O0 -Wall -Wextra --coverage -fno-inline
else
	OPT_FLAGS = -g -O0 -Wall -Wextra --coverage -fno-inline -fno-inline-small-functions -fno-default-inline
endif

# source directories
SDIR = .
HEADER_DIR = $(SDIR)/../include

SOURCES_TESTS= $(wildcard $(SDIR)/*.cpp)
OBJECTS_TESTS= $(SOURCES_TESTS:.cpp=.test)

all: $(OBJECTS_TESTS)

$(SDIR)/%.test: $(SDIR)/%.cpp
	$(CXX) $(CXX_STD) $(OPT_FLAGS) -I$(HEADER_DIR) $< -o $@ $(LIBS)

# cleanup and install
.PHONY: clean
clean:
	@rm -rf *.test *.gcov *.gcno *.gcda *.dSYM
