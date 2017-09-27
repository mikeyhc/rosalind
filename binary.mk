NAME = rosalind-${APP}

all: options ${NAME}

${EXTERN_OBJ}:
	make -C ../common

${NAME}: ${OBJ} ${EXTERN_OBJ}
	@echo CC -o $@
	@${CC} -o $@ $^ ${LDFLAGS}
