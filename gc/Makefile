# rosalind-gc: find string with the highest gc content

include ../config.mk

APP = gc
NAME = rosalind-${APP}
SRC = main.c
OBJ = ${SRC:.c=.o}
EXTERN_OBJ = "../common/fasta.o"
TESTS = $(wildcard t/*.pl)

all: options ${NAME}

options:
	@echo ${NAME} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo "COV      = ${COV}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${EXTERN_OBJ}:
	make -C ../common

${NAME}: ${OBJ} ${EXTERN_OBJ}
	@echo CC -o $@
	@${CC} -o $@ ${OBJ} ${EXTERN_OBJ} ${LDFLAGS}

test: all
	@echo TEST ${NAME}
	@for test in ${TESTS}; do \
		$$test; \
	done
	@${COV} ${SRC}

clean:
	@echo cleaning
	@rm -f ${NAME} ${OBJ} *.gc??

.PHONY: all options test clean ${EXTERN_OBJ}
