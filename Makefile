CXX = g++
CXXFLAGS = -std=c++0x -Wall -Wextra -Wshadow -O3 -DNDEBUG

INCLUDES =
LDFLAGS =
LIBS =

TARGET = rbgs
HEAD1 = grid
HEAD2 = solver
OBJS = $(TARGET).o $(HEAD1).o $(HEAD2).o

all: $(TARGET)

$(TARGET): $(OBJS) Makefile
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)
$(TARGET).o: $(TARGET).cpp Timer.h Makefile
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $(TARGET).cpp
$(HEAD1).o: $(HEAD1).h $(HEAD1).cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $(HEAD1).cpp
$(HEAD2).o: $(HEAD1).h $(HEAD2).cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $(HEAD2).cpp

solve: $(HEAD1).h $(HEAD2).cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $(HEAD2).cpp -o $(HEAD2)
	
test:
	./rbgs 2 2 10

clean:
	@$(RM) -rf *.o $(TARGET)