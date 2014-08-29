OBJS = main.o drawing_helper.o
EXENAME = mp1

COMPILER = g++
WARNINGS = 
COMPILER_OPTS = -Wno-deprecated -c -g -O0 $(WARNINGS)
LINKER = g++
LDFLAGS = -framework OpenGL -framework GLUT

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
LDFLAGS = -lGL -lGLU -lglut
endif

all: $(EXENAME)

doc/html:
	doxygen doc/Doxyfile 2> /dev/null

$(EXENAME): main.o drawing_helper.o
	$(LINKER) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: main.cpp
	$(COMPILER) $(COMPILER_OPTS) main.cpp

drawing_helper.o: drawing_helper.cpp drawing_helper.h
	$(COMPILER) $(COMPILER_OPTS) $(@:.o=.cpp)

clean:
	rm -rf *.o $(EXENAME) doc/html
