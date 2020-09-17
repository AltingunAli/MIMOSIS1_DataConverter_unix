CXX=`root-config --cxx`
CXXFLAGS=`root-config --cflags` -std=c++14  
LDFLAGS=`root-config --ldflags`

LDLIBS = `root-config --glibs` 

SOURCES= DataConverter.cpp RunControler.cpp

HEADERS=/input_data_formats.h ./globals.h
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=mimosis1reader

all: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(SOURCES) 
	$(CXX) $(CXXFLAGS) -O2 -W $(INCLUDES) -o $@ $^ $(LDFLAGS) $(LDLIBS) 

#.cc.o:
	# $(CXX) $(CXXFLAGS) -W -Wall -c $<

clean:
	rm ./*~ ./*.o ./*.so ./mimosis1reader ./AutoDict* ./*.pcm
	
	 
docs:
	doxygen Doxyfile
