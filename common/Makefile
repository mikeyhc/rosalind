# rosalind-common: create common objects

include ../config.mk

NAME = common
SRC = fasta.c
OBJ = ${SRC:.c=.o}

all: options ${OBJ}

options:
	@echo ${NAME} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo "COV      = ${COV}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

clean:
	@echo cleaning
	@rm -f ${OBJ} *.gc??

.PHONY: all options test clean
