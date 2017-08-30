NAME = rosalind-${APP}
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
	@${CC} -o $@ $^ ${LDFLAGS}

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
