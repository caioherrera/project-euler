IN := in/
OUT := out/
DIR := ./

SRCS := $(wildcard *.cpp)
EXECS := $(patsubst %.cpp, %.o, $(SRCS))
OUTPUTS := $(patsubst %.cpp, %.out, $(SRCS))

all : clean ${EXECS}

run_all : ${OUTPUTS}

%.o : %.cpp
	g++ $< -o $@

%.out : %.o ${IN}%.in
	${DIR}$< < $(filter %.in, $^) > ${OUT}$@
	cat ${OUT}$@

clean :
	rm -rf "*.o"
