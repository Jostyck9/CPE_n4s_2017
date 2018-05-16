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
	char *str = malloc(sizeof(char) * 5);
	char *cpy = "1:OK";

	for (int i = 0; cpy[i] != '\0'; i++)
		str[i] = cpy[i];
	str[4] = '\0';
	cr_expect_eq(NULL, destroy_buffer(str));
}

Test(destroy_buffer, good_output2)
{
	cr_assert_eq(NULL, destroy_buffer(NULL));
}

Test(destroy_buffer, bad_output)
{
	char *str = malloc(sizeof(char) * 5);
	char *cpy = "1:OK";

	for (int i = 0; cpy[i] != '\0'; i++)
		str[i] = cpy[i];
	str[4] = '\0';
	cr_assert_neq(str, destroy_buffer(str));
}

Test(destroy_buffer, bad_output2)
{
	cr_assert_neq("Hello world.", destroy_buffer(NULL));
}

Test(destroy_buffer, bad_output3)
{
	char *str = malloc(sizeof(char) * 5);
	char *cpy = "1:OK";

	for (int i = 0; cpy[i] != '\0'; i++)
		str[i] = cpy[i];
	str[4] = '\0';
	cr_assert_neq("Hello world.", destroy_buffer(str));
}
