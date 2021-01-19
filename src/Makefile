# ************************************************************************** #
# **   Project: Aplikace pro řízený přístup                               ** #
# **            ke vzdáleným dokumentům pro GNU/Linux                     ** #
# **   University: VUT FIT Brno                                           ** #
# **   Authors: Jan Bernard                                               ** #
# **   Created: 17.11.2020                                                ** #
# **   Module: makefile                                                   ** #
# ************************************************************************** #
.PHONY: run run_tests build build_tests doxygen clean

CPP = g++
CPPFLAGS =-std=c++17 -Wall -Wextra -pedantic
OBJDIR = obj

SRCFILES = api.cpp string.cpp 
OBJFILES = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCFILES))

SRCTESTFILES = tests_api.cpp
OBJTESTFILES = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCTESTFILES))

TARGET = run
TARGETTESTS = run_tests

run: build
	./$(TARGET)

run_tests: build_tests
	./$(TARGETTESTS)

build: $(OBJFILES)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $^ main.cpp -lcurl

$(OBJDIR)/%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

# $(OBJDIR)/api.o: $(OBJDIR)/string.o api.cpp 
# 	$(CPP) $(CPPFLAGS) -c -o $@ $^

build_tests: $(OBJTESTFILES) $(OBJFILES)
	$(CPP) $(CPPFLAGS) -pthread -o $(TARGETTESTS) $? tests/main.cpp -lgtest -lpthread -lcurl

$(OBJDIR)/%.o: tests/%.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

doxygen:
	doxygen Doxyfile

clean:
	rm -f $(OBJDIR)/*.o
	rm -rf doxygen_docs