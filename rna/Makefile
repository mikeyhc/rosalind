# rosalind-rna: convert a dna to rna

include ../config.mk

APP = rna
NAME = rosalind-${APP}
SRC = main.c
OBJ = ${SRC:.c=.o}
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

${NAME}: ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ ${OBJ} ${LDFLAGS}

test: all
	@echo TEST ${NAME}
	@for test in ${TESTS}; do \
		$$test; \
	done
	@${COV} ${SRC}

clean:
	@echo cleaning
	@rm -f ${NAME} ${OBJ} *.gc??

.PHONY: all options test clean
