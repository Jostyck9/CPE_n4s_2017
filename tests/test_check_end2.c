/*
** EPITECH PROJECT, 2017
** test_check_end2.c
** File description:
** tests function check_end.
*/

#include <criterion/criterion.h>
#include "ai.h"

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
