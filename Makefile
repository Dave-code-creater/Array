# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -Iinclude
CFLAGS += -I$(GTEST_DIR)
# Linker flags
LDFLAGS += -L$(GTEST_DIR) -lgtest -lgtest_main

# Valgrind flags
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes


# Directory names
SRCDIR = src
TESTDIR = test
BUILDDIR = build
LIBDIR = libs
VALGRINDDIR = valgrind
GTEST_DIR = gtest

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

# Add a rule for building GTest
$(GTEST_DIR)/gtest-all.o: $(GTEST_DIR)/gtest-all.cc
	$(CC) $(CFLAGS) -c $< -o $@

# Add a rule for building your test executable
$(BUILDDIR)/test: $(OBJFILES) $(GTEST_DIR)/gtest-all.o | $(BUILDDIR)
	$(CC) $(CFLAGS) -o $@ -ggdb $(OBJFILES) $(GTEST_DIR)/gtest-all.o $(LDFLAGS)

# Run your tests
test: $(BUILDDIR)/test
	./$(BUILDDIR)/test

# Create the build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Create the lib directory if it doesn't exist
$(LIBDIR):
	mkdir -p $(LIBDIR)

# Write a valgrind log file
valgrind: $(TARGET) | $(VALGRINDDIR)
	$(VALGRIND) $(TARGET) 2> $(VALGRINDDIR)/valgrind.log

# Target to clean up object files, executables, and test files
clean:
	rm -f $(OBJFILES) $(TARGET) $(TESTTARGET) *~
	rm -rf $(BUILDDIR)