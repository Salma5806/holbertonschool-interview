#include "holberton.h"

/**
 * wildcmp - Compares two strings and returns 1 if they can be considered identical
 * @s1: The first string
 * @s2: The second string (can contain '*' wildcard)
 *
 * Return: 1 if identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	/* If both strings reach the end, they match */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* If s2 has '*', it can match zero or more characters */
	if (*s2 == '*')
	{
		/* Two cases:
		 * 1. '*' matches zero characters (skip '*' in s2)
		 * 2. '*' matches one or more characters (skip one char in s1)
		 */
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	}

	/* If characters match, continue comparing next characters */
	if (*s1 == *s2 && *s1 != '\0')
		return (wildcmp(s1 + 1, s2 + 1));

	/* Characters don't match and s2 is not '*' */
	return (0);
}
