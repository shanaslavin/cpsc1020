# Compiler Config
CC=g++
CFLAGS=-Wall -g -std=c++11
LFLAGS=-lm

# Output Config
TARGET=driver
SRCDIR=src
OBJDIR=bin

# Generate source and object lists
SRCS := $(wildcard *.cpp) \
	$(wildcard $(SRCDIR)/*.cpp) \
	$(wildcard $(SRCDIR)/**/*.cpp)

HDRS := $(wildcard *.hpp) \
	$(wildcard $(SRCDIR)/*.hpp) \
	$(wildcard $(SRCDIR)/**/*.hpp)

OBJS := $(patsubst %.cpp, $(OBJDIR)/%.o, $(wildcard *.cpp))
OBJS += $(filter %.o, $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS)))

# Link all built objects
$(TARGET): $(OBJS)
	@mkdir -p $(dir $(TARGET))
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

# Catch root directory src files
$(OBJDIR)/%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Catch all nested directory files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

which:
	@echo "FOUND SOURCES: ${SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "GENERATED OBJS: ${OBJS}"

clean:
	rm -f $(TARGET)
	rm -rf $(OBJDIR)

run: $(TARGET)
	./$(TARGET)
