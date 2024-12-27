CXX = g++
CXXFLAGS = -std=c++11 -Wall -I/usr/include/lua5.3
LIBS = -ltinyxml2 -llua5.3

SRCS = main.cpp lua.cpp map.cpp element.cpp player.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = programa

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

start:
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
