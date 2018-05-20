/*
** EPITECH PROJECT, 2017
** test_check_end.c
** File description:
** tests function check_end.
*/

#include <criterion/criterion.h>
#include "ai.h"

Test(check_end, good_input)
{
	char *str = "1:OK:No errors so far:Track Cleared";

	cr_assert_eq(true, check_end(str));
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
