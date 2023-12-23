# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -Iinclude

# Linker flags
LDFLAGS =

# Directory names
SRCDIR = src
BUILDDIR = build

# Object files to build
OBJFILES = $(BUILDDIR)/main.o $(BUILDDIR)/array.o

# Target executable
TARGET = $(BUILDDIR)/array

# Search path for source files
VPATH = $(SRCDIR)

# Default target
all: $(TARGET)

# Target to build the executable
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) -ggdb $(OBJFILES) $(LDFLAGS)

# Target to build main.o
$(BUILDDIR)/main.o: main.c include/array.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Target to build array.o
$(BUILDDIR)/array.o: array.c include/array.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Target to clean up object files and the executable
clean:
	rm -f $(OBJFILES) $(TARGET) *~
	rm -rf $(BUILDDIR)
