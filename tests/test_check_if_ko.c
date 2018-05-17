/*
** EPITECH PROJECT, 2017
** test_check_if_ko.c
** File description:
** tests function check_if_ko.
*/

#include <criterion/criterion.h>
#include "ai.h"

Test(check_if_ko, good_input)
{
	char *str = "1:KO:No errors so far:Track Cleared";

	cr_assert_eq(true, check_if_ko(str));
}

Test(check_if_ko, good_input2)
{
	char *str = "1:OK:No errors so far:Track Cleared";

	cr_assert_eq(false, check_if_ko(str));
}

Test(check_if_ko, bad_input_but_work)
{
	cr_assert_eq(true, check_if_ko(NULL));
}

Test(check_if_ko, bad_input_but_work2)
{
	char *str = "1O:K:No errors so far:Track Cleared";

	cr_assert_eq(true, check_if_ko(str));
}
