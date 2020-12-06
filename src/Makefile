# ************************************************************************** #
# **   Project: Aplikace pro řízený přístup                               ** #
# **            ke vzdáleným dokumentům pro GNU/Linux                     ** #
# **   University: VUT FIT Brno                                           ** #
# **   Authors: Jan Bernard                                               ** #
# **   Created: 17.11.2020                                                ** #
# **   Module: makefile                                                   ** #
# ************************************************************************** #
.PHONY: build test clean

CPP = g++
CPPFLAGS =-std=c++11 -Wall -Wextra -pedantic
OBJDIR = obj

SRCFILES = api.cpp
OBJFILES = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCFILES))

SRCTESTFILES = tests_api_auth.cpp tests_api_file.cpp tests_api_ping.cpp
OBJTESTFILES = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCTESTFILES))

TARGET = run
TARGETTESTS = run_tests

build: $(OBJFILES)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $< main.cpp

$(OBJDIR)/%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

build_tests: $(OBJTESTFILES) $(OBJFILES)
	$(CPP) $(CPPFLAGS) -pthread -o $(TARGETTESTS) $? tests/main.cpp -lgtest -lpthread

$(OBJDIR)/%.o: tests/%.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJDIR)/*.o