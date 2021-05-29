# -*-Makefile-*-

include ../Makefile.global

EXECUTABLES = 01_pipe_demo              \
			  02_redirection            \
			  03_redirection_with_pipe  \
			  04_fifo_write_first       \
			  04_fifo_reads_first

all:
	@ for item in ${EXECUTABLES}; do \
		(gcc $${item}.c -o $${item} ${CFLAGS} ${USE_LIB}); done

.PHONY: clean
clean:
	${RM} *.o ${EXECUTABLES}
