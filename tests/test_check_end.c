/*
** EPITECH PROJECT, 2017
** test_touched_watered.c
** File description:
** test touched_watered function.
*/

#include "ai.h"
#include <criterion/criterion.h>

Test(check_end, good_inputs)
{
	char *str = "1:OK:No errors so far:Track Cleared";

	cr_assert_eq(true,  check_end(str, END_STR));
}

Test(check_end, bad_inputs)
{
	char *str = "1:KO:No errors so far:Track Cleared";

	cr_assert_eq(false, check_end(str, END_STR));
}
