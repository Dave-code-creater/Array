# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -Iinclude

# Linker flags
LDFLAGS =

TESTFLAGS = -fprofile-arcs -ftest-coverage

# Directory names
SRCDIR = src
TESTDIR = test
BUILDDIR = build
LIBDIR = libs

# Lib name 
LIB_NAME = array


# Object files to build
OBJFILES = $(BUILDDIR)/main.o $(BUILDDIR)/array.o $(BUILDDIR)/utils.o

# Target executables
TARGET = $(BUILDDIR)/array

# Search path for source files
VPATH = $(SRCDIR)

# Default target
all: $(TARGET) $(LIBDIR)/lib$(LIB_NAME).a $(LIBDIR)/lib$(LIB_NAME).so

# Target to build the executable
$(TARGET): $(OBJFILES) | $(BUILDDIR)
	$(CC) $(CFLAGS) -o $(TARGET) -ggdb $(OBJFILES) $(LDFLAGS)

# Target to build static library
$(LIBDIR)/lib$(LIB_NAME).a: $(OBJFILES) | $(LIBDIR)
	ar rcs $@ $^

# Target to build dynamic library
$(LIBDIR)/lib$(LIB_NAME).so: $(OBJFILES) | $(LIBDIR)
	$(CC) $(CFLAGS) -o $@ $^

# Target to build main.o
$(BUILDDIR)/main.o: main.c include/array.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Target to build array.o
$(BUILDDIR)/array.o: array.c include/array.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Target to build the utils.c 
$(BUILDDIR)/utils.o: utils.c include/array.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Create the library directory if it doesn't exist
$(LIBDIR):
	mkdir -p $(LIBDIR)

# Target to clean up object files, executables, and test files
clean:
	rm -f $(OBJFILES) $(TARGET) $(TESTTARGET) *~
	rm -rf $(BUILDDIR)