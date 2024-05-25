CXX = g++
CXXFLAGS = -std=c++17 -g

SRCDIR = source
SRCS = $(SRCDIR)/main.cpp $(SRCDIR)/node.cpp $(SRCDIR)/tree.cpp
TARGET = featSearch

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

# Feature-Search: main.cpp node.cpp tree.cpp
# 	$(CC) -o FeatSearch ../source/main.cpp ../source/node.cpp ../source/tree.cpp -I
