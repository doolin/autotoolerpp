
INCLUDES = -I../include -I./

AM_CXXFLAGS = -std=c++11 -Wall -Wextra  -Wno-unused-parameter

#AM_CPPFLAGS = -Wall -Wextra  -Wno-unused-parameter
AM_LDFLAGS = $(shell cppunit-config --libs)
LDADD = ../src/libautotoolerpp.a


bin_PROGRAMS = initial

initial_SOURCES = test_initial.cpp testutils.cpp


