INC=./inc
CPP=g++
RM=rm
CPP_FLAGS=-std=c++20 -W -Wall -O2 

CPP_SOURCE= \
			src/Sphinx_main.cc   \
			src/Sphinx_module.cc \
			src/Sphinx_task.cc   \
			src/Sphinx_error.cc  \
			src/Sphinx_socket.cc

OBJ_SOURCE= $(CPP_SOURCE:.cc=.o)

build: sphinx_server

sphinx_server: $(OBJ_SOURCE)
	$(CPP) $(CPP_FLAGS) -o $@ $^ -I$(INC)

%.o: %.cc
	$(CPP) $(CPP_FLAGS)-c -o $@ $^ -I$(INC)

clean:
	$(RM) -rf sphinx_server $(OBJ_SOURCE)