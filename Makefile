CC = g++

CXXFLAGS = -U__STRICT_ANSI__ -Wall -std=c++11 -O3

INCLUDES = 
LFLAGS =
LIBS = 

OTHER_SRC =                                        \
    src/Board.cpp                                  \
    src/main.cpp

SRCS = $(OTHER_SRC)
OBJDIR = _objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

MAIN = Sudoku-Solver

.PHONY: depend clean test

all:    $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) -c $(INCLUDES) -o $@ $< $(CXXFLAGS)

# TEST_SRC is anyting that ends in _UT (unit test)
TEST_SRC = $(wildcard test/*_UT.cpp)
# TEST_DEPENDS is all the OBJS without main and Gtest
_MAIN_OBJ = $(OBJDIR)/src/main.o
TEST_DEPENDS = $(filter-out $(_MAIN_OBJ), $(OBJS))
TEST_OBJS = $(addprefix $(OBJDIR)/, $(TEST_SRC:.cpp=.o))
TEST_MAIN = unit_test
TEST_CXXFLAGS = $(CXXFLAGS)

test: $(TEST_OBJS) $(TEST_DEPENDS)
	$(CC) $(TEST_CXXFLAGS) $(INCLUDES) -o $(OBJDIR)/$(TEST_MAIN) $(TEST_OBJS) $(TEST_DEPENDS) $(LFLAGS) $(LIBS)
	./$(OBJDIR)/$(TEST_MAIN)

clean:
	$(RM) -rf $(OBJDIR)
	$(RM) $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^
