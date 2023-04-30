# Compiler settings - Can be customized.
CC = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = 

# Makefile settings (vector)
#APPNAME = final.v.1.0.vector
# EXT = .cpp
# SRCDIR = #aplanko su failais vieta nukopijuota#
# SRCDIR = C:\Users\PC\Desktop\VU ISE\VU ISE II sem\Objektinis programavimas\final.v.1.0\final.v.1.0.vector
# OBJDIR = obj

# Makefile settings (deque)
# APPNAME = final.v.1.0.deque
# EXT = .cpp
# SRCDIR = #aplanko su failais vieta nukopijuota#
# SRCDIR = C:\Users\PC\Desktop\VU ISE\VU ISE II sem\Objektinis programavimas\final.v.1.0\final.v.1.0.deque
# OBJDIR = obj

# Makefile settings (list)
# APPNAME = final.v.1.0.list
# EXT = .cpp
# SRCDIR = #aplanko su failais vieta nukopijuota#
# SRCDIR = C:\Users\PC\Desktop\VU ISE\VU ISE II sem\Objektinis programavimas\final.v.1.0\final.v.1.0.list
# OBJDIR = obj

# Libraries to link
LIBS=student.lib

# Source files (vector)
SRCS=final.v.1.0.vector.cpp vsourceV.cpp

# Source files (deque)
# SRCS=final.v.1.0.deque.cpp vsourceD.cpp

# Header files (vektor)
HDRS=vheaderisV.h student.lib.h

# Header files (deque)
# HDRS=vheaderisD.h student.lib.h

# Header files (list)
# HDRS=vheaderisL.h student.lib.h

#txt files
TEXTFILE = kursiokai.txt studentai1000.txt studentai10000.txt studentai100000.txt studentai1000000.txt studentai10000000.txt

OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: main

main: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJS)

.DEFAULT_GOAL := all

all: | clean
