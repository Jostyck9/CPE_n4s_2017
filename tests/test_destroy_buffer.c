/*
** EPITECH PROJECT, 2017
** test_destroy_buffer.c
** File description:
** tests function destroy_buffer.
*/

#include <criterion/criterion.h>
#include "ai.h"

Test(destroy_buffer, good_output)
{
	char str[] = "1:OK:No errors so far:Track Cleared";

	cr_assert_str_eq(NULL, destroy_buffer(str));
}

Test(destroy_buffer, good_output2)
{
	cr_assert_str_eq(NULL, destroy_buffer(NULL));
}

Test(destroy_buffer, bad_output)
{
	char str[] = "Hello World.";

	cr_assert_str_neq("Hello World.", destroy_buffer(str));
}

Test(destroy_buffer, bad_output2)
{
	cr_assert_str_neq("Hello world.", destroy_buffer(NULL));
}

Test(destroy_buffer, bad_output3)
{
	char str[] = "Yes my lord.";

	cr_assert_str_neq("Hello world.", destroy_buffer(str));
}
