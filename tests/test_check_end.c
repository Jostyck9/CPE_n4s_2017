/*
** EPITECH PROJECT, 2017
** test_touched_watered.c
** File description:
** test touched_watered function.
*/

#include <criterion/criterion.h>
#include "ai.h"

Test(check_end, good_input)
{
	char *str = "1:OK:No errors so far:Track Cleared";

	cr_assert_eq(true,  check_end(str));
}

Test(check_end, bad_input_but_work)
{
	char *str = "1:KO:No errors so far:Track Cleared";

	cr_assert_eq(true, check_end(str));
}

Test(check_end, bad_input_but_work2)
{
	char *str = "1:OKNo errors so far:Track Cleared";

	cr_assert_eq(true, check_end(str));
}

Test(check_end, bad_input_but_work3)
{
	char *str = "1OK:No errors so far:Track Cleared";

	cr_assert_eq(true, check_end(str));
}

Test(check_end, bad_input)
{
	char *str = "1:OK:No errors so far:";

	cr_assert_eq(false, check_end(str));
}

Test(check_end, bad_input2)
{
	char *str = "1:OK:No errors so far:Track";

	cr_assert_eq(false, check_end(str));
}

Test(check_end, bad_input3)
{
	char *str = "1:OK:No errors so far:Track Clear";

	cr_assert_eq(false, check_end(str));
}

Test(check_end, bad_input4)
{
	char *str = "1:OK:No errors so far:track cleared";

	cr_assert_eq(false, check_end(str));
}
