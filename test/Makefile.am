AM_CXXFLAGS = -std=c++11 -Wall -Wextra  -Wno-unused-parameter
AM_CPPFLAGS = -I../include -I.

AM_LDFLAGS = $(shell cppunit-config --libs)
LDADD = ../src/libautotoolerpp.a

%.o: %.cpp
	g++ $(AM_CXXFLAGS) $(AM_CPPFLAGS) -D$*_STANDALONE -c $< $(AM_LDFLAGS)

bin_PROGRAMS = initial

initial_SOURCES = test_initial.cpp testutils.cpp


