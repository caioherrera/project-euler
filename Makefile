INPUT := in/
OUTPUT := out/
DIR := ./

all : clean

% : %.cpp
	g++ $< -o $@

%.out : % ${INPUT}%.in
	${DIR}$< < ${INPUT}$<.in > ${OUTPUT}$@
	cat ${OUTPUT}$@

clean :
	find . -type f ! -name "*.*" -delete
