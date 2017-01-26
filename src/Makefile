# Declaration of variables
CC = g++
CC_FLAGS = -w
 
# File names
EXEC = ../AIv2.3
SOURCES = $(wildcard *.cpp) $(wildcard **/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
 
# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)
	rm -f $(OBJECTS)
 
# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)