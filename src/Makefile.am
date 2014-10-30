CC=gcc
CXX=g++

CPPFLAGS = -Wall -Wextra

AM_CPPFLAGS = -I/usr/local/include -I../include

noinst_LIBRARIES = libautotoolerpp.a
libautotoolerpp_a_SOURCES = autotoolerpp.cpp
libautotoolerpp_a_CPPFLAGS = -O0 -pg  -Wall -Wextra -fno-inline $(AM_CPPFLAGS) -DIL_STD -L/usr/local/lib -DNDEBUG -w


bin_PROGRAMS = getsome
getsome_SOURCES = main.cpp
getsome_CPPFLAGS = -O0 -pg  -Wall -Wextra -fno-inline $(AM_CPPFLAGS) -DIL_STD -L/usr/local/lib #-DNDEBUG -w -finstrument-functions-exclude-file-list=iostream.h,string.h,vector.h
getsome_LDFLAGS = -pg  -O0
getsome_LDADD = -L. -lautotoolerpp

