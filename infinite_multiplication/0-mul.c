#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * _is_digit - checks if a string contains only digits
 * @s: string
 * Return: 1 if only digits, 0 otherwise
 */
int _is_digit(char *s)
{
	while (*s)
	{
		if (!isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

/**
 * print_error - prints "Error" and exits
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * multiply - multiplies two numbers as strings
 * @num1: first number
 * @num2: second number
 */
void multiply(char *num1, char *num2)
{
	int len1 = strlen(num1), len2 = strlen(num2);
	int len = len1 + len2;
	int *result = calloc(len, sizeof(int));
	int i, j;

	if (!result)
		print_error();

	/* Multiply each digit */
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int mul = (num1[i] - '0') * (num2[j] - '0');
			int sum = result[i + j + 1] + mul;
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	/* Skip leading zeros */
	i = 0;
	while (i < len && result[i] == 0)
		i++;

	if (i == len)
		printf("0");
	else
	{
		for (; i < len; i++)
			printf("%d", result[i]);
	}
	printf("\n");
	free(result);
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error();

	if (!_is_digit(argv[1]) || !_is_digit(argv[2]))
		print_error();

	multiply(argv[1], argv[2]);

	return (0);
}