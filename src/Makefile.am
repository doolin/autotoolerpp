CXX=g++
CC=gcc

CPPFLAGS = -Wall -Wextra 


INCLUDES = -I/usr/local/include -I../include

noinst_LIBRARIES = libautotoolerpp.a
libautotoolerpp_a_SOURCES = autotooler.cpp
libautotoolerpp_a_CPPFLAGS = -O0 -pg  -Wall -Wextra -fno-inline $(INCLUDES) -DIL_STD -L/usr/local/lib -DNDEBUG -w


bin_PROGRAMS = getsome 
getsome_SOURCES = main.cpp autotoolerpp.cpp
getsome_CPPFLAGS = -O0 -pg  -Wall -Wextra -fno-inline $(INCLUDES) -DIL_STD -L/usr/local/lib #-DNDEBUG -w -finstrument-functions-exclude-file-list=iostream.h,string.h,vector.h
getsome_LDFLAGS = -pg  -O0
getsome_LDADD = libautoloolerpp.a

