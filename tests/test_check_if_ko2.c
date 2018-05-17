/*
** EPITECH PROJECT, 2017
** test_check_if_ko.c
** File description:
** tests function check_if_ko.
*/

#include <criterion/criterion.h>
#include "ai.h"

Test(check_if_ko, bad_input_but_work3)
{
	char *str = "";

	cr_assert_eq(true, check_if_ko(str));
}

Test(check_if_ko, bad_input)
{
	char *str = "1:OKNo errors so far:Track Cleared";

	cr_assert_eq(false, check_if_ko(str));
}

Test(check_if_ko, bad_input2)
{
	char *str = "1OK:No errors so far:Track Cleared";

	cr_assert_eq(false, check_if_ko(str));
}
