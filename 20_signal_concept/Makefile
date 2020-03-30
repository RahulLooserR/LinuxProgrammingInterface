# -*-Makefile-*-

include ../Makefile.global

EXECUTABLES = 01_changing_signal_disposition	\
			  02_temporary_disposition			\
			  03_sending_signal					\
			  04_sendingSignals					\
			  05_checkingExistence


all:
	@ for item in ${EXECUTABLES}; do \
		(gcc $${item}.c -o $${item} ${CFLAGS} ${USE_LIB}); done

.PHONY: clean
clean:
	${RM} *.o ${EXECUTABLES}
