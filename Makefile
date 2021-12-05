CC := g++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
TARGET := bin/masdl
SOURCES := $(shell find src -type f -name "*.cpp")
OBJECTS := $(patsubst src/%,build/%,$(SOURCES:.cpp=.o))
CFLAGS := -g -Wall -std=c++20
LIB := -L/opt/homebrew/lib -lSDL2
INC := -I lib

$(TARGET): $(OBJECTS)
	@echo " Linking..."x
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

build/%.o: src/%.cpp
	@mkdir -p build/{memory,cpu,screen,cartridge} build/cpu/{registers,instruction_sets}
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r build $(TARGET)"; $(RM) -r build $(TARGET)

.PHONY: clean
