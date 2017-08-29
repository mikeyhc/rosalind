# sis version
VERSION = 0.1

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

# flags
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=2 \
	   -DVERSION=\"${VERSION}\"
CFLAGS = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os \
	 ${CPPFLAGS} -g -fprofile-arcs -ftest-coverage -Wextra
LDFLAGS = -static -lgcov --coverage

# compiler
CC = musl-gcc
COV = gcov
