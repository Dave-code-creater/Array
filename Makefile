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

# Object files to build
OBJFILES = $(BUILDDIR)/main.o $(BUILDDIR)/array.o

# Target executables
TARGET = $(BUILDDIR)/array
TESTTARGET = $(BUILDDIR)/test

# Search path for source files
VPATH = $(SRCDIR):$(TESTDIR)

# Default target
all: $(TARGET)

# Target to build the executable
$(TARGET): $(OBJFILES) | $(BUILDDIR)
	$(CC) $(CFLAGS) -o $(TARGET) -ggdb $(OBJFILES) $(LDFLAGS)

# Target to build main.o
$(BUILDDIR)/main.o: main.c include/array.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Target to build array.o
$(BUILDDIR)/array.o: array.c include/array.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Test target: Compile and run unit tests
test: $(TESTTARGET)
	./$(TESTTARGET)

# Target to build the test executable
$(TESTTARGET): test.c include/array.h array.c | $(BUILDDIR)
	$(CC) $(CFLAGS) $(TESTFLAGS) -o $(TESTTARGET) $^

# Target to generate tests
generate_tests: $(TESTTARGET)
	./$(TESTTARGET) < test/test_case_1.txt

# Create the build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)



# Target to clean up object files, executables, and test files
clean:
	rm -f $(OBJFILES) $(TARGET) $(TESTTARGET) *~
	rm -rf $(BUILDDIR)