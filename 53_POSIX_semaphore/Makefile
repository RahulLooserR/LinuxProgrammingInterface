# -*-Makefile-*-

include ../Makefile.global

PTHREAD_FLAG = -pthread
EXECUTABLES = 01_named_semaphore    \

all:
	@ for item in ${EXECUTABLES}; do \
		(gcc $${item}.c -o $${item} ${CFLAGS} ${PTHREAD_FLAG} ${USE_LIB}); done

.PHONY: clean
clean:
	${RM} *.o ${EXECUTABLES}
