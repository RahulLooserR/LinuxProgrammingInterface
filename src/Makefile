# -*-Makefile-*-

include ../Makefile.global

allgen :
	${CC} -c -g ${CFLAGS} *.c
	${RM} ${UTIL_LIB}
	${AR} rs ${UTIL_LIB} *.o

.PHONY: clean
clean:
	${RM} *.o ${EXECUTABLES}
