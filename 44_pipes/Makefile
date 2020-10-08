# -*-Makefile-*-

include ../Makefile.global

EXECUTABLES = 01_pipe_demo  \
			  02_redirection

all:
	@ for item in ${EXECUTABLES}; do \
		(gcc $${item}.c -o $${item} ${CFLAGS} ${USE_LIB}); done

.PHONY: clean
clean:
	${RM} *.o ${EXECUTABLES}
