TARGETS := all test clean
SUBDIRS := $(wildcard */.)

${TARGETS}: ${SUBDIRS}

${SUBDIRS}:
	${MAKE} -C $@ ${MAKECMDGOALS}

.PHONY: ${TARGETS} ${SUBDIRS}
