TESTS = $(wildcard t/*.pl)
TEST_SRC = $(wildcard t/*c)
TEST_BIN = ${TEST_SRC:.c=}

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

${EXTERN_OBJ}:
	make -C ../common

${TEST_BIN}: ${TEST_BIN}.c ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ $^ ${CFLAGS} ${LDFLAGS} -O0

test: all ${TEST_BIN}
	@echo TEST ${NAME}
	@for test in ${TESTS} ${TEST_BIN}; do $$test; done
	@${COV} ${SRC} ${TEST_SRC} 1>/dev/null

clean:
	@echo cleaning
	@rm -f ${NAME} ${OBJ} *.gc?? ${TEST_BIN} vgcore.*

.PHONY: all options test clean
