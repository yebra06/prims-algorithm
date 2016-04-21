# Programmer: Alfredo Yebra Jr.
# Date: March 20, 2016

#---- Target executable ----
TARGET 		= graph
SRC 		= src
INCS 		= includes
SRCFILES	= $(wildcard $(SRC)/*.cpp)
OBJS 		= $(SRCFILES:.cpp=.o)
CXX			= g++
CFLAGS		= -g -Wall -I $(INCS)
RM 			= rm -rf

# Use phony to ensure proper functionality of 'make' command.
.PHONY: 	all
all: 		$(TARGET)

# Build executable from objects.
$(TARGET): 	$(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^

# Recipe to generate object files from .cpp files.
%.o:		%.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

# Clean up objects and executables.
.PHONY: 	clean
clean:
	$(RM) $(TARGET)
	$(RM) $(SRC)/*.o