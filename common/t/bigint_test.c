#include <assert.h>
#include <stdio.h>

#include "../bigint.h"

#define BEGIN_TEST int _exit = 0
#define END_TEST return _exit

#define TEST_EQ(a, b, m) \
	if (a != b) { \
		fprintf(stderr, "failed %s:\n", m); \
		fprintf(stderr, "        got: %lu\n", a); \
		fprintf(stderr, "  exepected: %lu\n", b); \
		_exit = 1; \
	}

#define TEST(t, m) \
	if (!(t)) { \
		fprintf(stderr, "failed %s\n", m); \
		_exit = 1; \
	}

#define RUN_SUITE(n) if(n()) { _exit = 1; }
#define TEST_SUITE(n) int n(void)

TEST_SUITE(init) {
	BEGIN_TEST;

	BIGINT(a);

	bigint_init(10lu, a);
	TEST_EQ(a[0], 10lu, "setting small bigint");
	bigint_init(10000000000, a);
	TEST_EQ(a[1], 1lu, "setting bigint high bits");
	TEST_EQ(a[0], 0lu, "setting bigint low bits");
	bigint_init(10000000050, a);
	TEST_EQ(a[1], 1lu, "setting bigint high bits");
	TEST_EQ(a[0], 50lu,"setting bigint low bits");

	END_TEST;
}

TEST_SUITE(copy) {
	BEGIN_TEST;

	BIGINT(a);
	BIGINT(b);

	bigint_init(10lu, a);
	bigint_bigint_copy(b, a);
	TEST(bigint_bigint_equal(a, b), "small bigint copy");

	bigint_init(1000000005010lu, a);
	bigint_bigint_copy(b, a);
	TEST(bigint_bigint_equal(a, b), "big bigint copy");

	END_TEST;
}

TEST_SUITE(equals) {
	BEGIN_TEST;

	BIGINT(a);
	BIGINT(b);

	bigint_init(10lu, a);
	bigint_init(10lu, b);
	TEST(bigint_bigint_equal(a, b), "small bigint equality");

	bigint_init(10lu, a);
	bigint_init(11lu, b);
	TEST(!bigint_bigint_equal(a, b), "small bigint inequality");

	bigint_init(1000000005010lu, a);
	bigint_init(1000000005010lu, b);
	TEST(bigint_bigint_equal(a, b), "big bigint equality");

	bigint_init(1000000005010lu, a);
	bigint_init(1100000005010lu, b);
	TEST(!bigint_bigint_equal(a, b), "big bigint inequality");

	END_TEST;
}

TEST_SUITE(add) {
	BEGIN_TEST;

	BIGINT(a);
	BIGINT(b);
	BIGINT(c);

	bigint_init(10, a);
	bigint_init(20, b);
	bigint_bigint_add(a, b, c);
	TEST_EQ(c[0], 30lu, "adding small bigint");
	bigint_init(10000000000, a);
	bigint_init(20000000000, b);
	bigint_bigint_add(a, b, c);
	TEST_EQ(c[1], 3lu, "adding bigint high bits");
	TEST_EQ(c[0], 0lu, "adding bigint low bits");
	bigint_init(10000000050, a);
	bigint_init(20000000100, b);
	bigint_bigint_add(a, b, c);
	TEST_EQ(c[1], 3lu, "adding bigint high bits");
	TEST_EQ(c[0], 150lu,"adding bigint low bits");

	END_TEST;
}

TEST_SUITE(sub) {
	BEGIN_TEST;

	BIGINT(a);
	BIGINT(b);
	BIGINT(c);

	bigint_init(20, a);
	bigint_init(10, b);
	bigint_bigint_sub(a, b, c);
	TEST_EQ(c[0], 10lu, "subing small bigint");
	bigint_init(20000000000, a);
	bigint_init(10000000000, b);
	bigint_bigint_sub(a, b, c);
	TEST_EQ(c[1], 1lu, "subing bigint high bits");
	TEST_EQ(c[0], 0lu, "subing bigint low bits");
	bigint_init(20000000050, a);
	bigint_init(10000000100, b);
	bigint_bigint_sub(a, b, c);
	TEST_EQ(c[1], 0lu, "subing bigint high bits");
	TEST_EQ(c[0], 9999999950lu,"subing bigint low bits");

	END_TEST;
}

int
main(void)
{
	BEGIN_TEST;
	RUN_SUITE(init);
	RUN_SUITE(copy);
	RUN_SUITE(equals);
	RUN_SUITE(add);
	RUN_SUITE(sub);
	END_TEST;
}
