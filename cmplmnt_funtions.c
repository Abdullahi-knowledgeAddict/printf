#include "main.h"
/* This file contains some of the complementary function */

/**
 * get_req_funct - get the required function for the specified format specifier
 * @c: the character after the '%'symbol
 * Return: pointer to the matching function
 */
funct_pointer_t get_req_funct(const char c)
{
	int i;
	associate_t asst_arr[] = {{'c', chr}, {'d', dp}, {'i', ip}, {'s', str},
				{'%', pc}, {'b', pb}, {'\0', NULL}};
	i = 0;
	while (asst_arr[i].func_point)
	{
		if (asst_arr[i].c == c)
			return (asst_arr[i].func_point);
		i++;
	}
	return (NULL);
}

/**
 * chr - format complementary function for char
 * @v: the pointer to the present argument of the variadic arguments
 * Return: the number of byte "formatted to stdout"
 */
int chr(va_list v)
{
	char c; /* a buffer to store the present variadic argument */

	c = va_arg(v, int);
	write(1, &c, sizeof(char));
	return (1);
}
/**
 * str - format complementary function for string
 * @v: the pointer to the present argument of the variadic arguments
 * Return: the number of byte "formatted to stdout"
 */
int str(va_list v)
{
	char *s; /* a buffer to store the present variadic argument */
	int count;

	s = va_arg(v, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (count = 0; *s; s++, count++)
		write(1, s, sizeof(char));
	return (count);
}

/**
 * pc - format complementary function for "%"
 * @v: the pointer to the present argument of the variadic arguments
 * Return: the number of byte "formatted to stdout"
 */
int pc(va_list v __attribute__ ((unused)))
{
	char c; /* buffer to store '%' */

	c = '%';
	write(1, &c, sizeof(char));
	return (1);
}
/**
 * pb - custom conversion specifier; formating unsigned int to binary
 * @v: the pointer to the present argument of the variadic arguments
 * Return: the number of byte "formatted to stdout"
 */
int pb(va_list v)
{
	unsigned int i, i2;
	char *s; /* pointer to buffer */
	int buff_size, buff_size_copy; /* size of buffer to store string */

	i2 = i = va_arg(v, unsigned int);
	for (buff_size = 0; i > 0; buff_size++)
		i = i / 2; /* get the the buffer required size */
	s = malloc(sizeof(char) * buff_size);
	if (s == NULL)
		return (0);
	buff_size_copy = buff_size; /* backing up size */
	s[buff_size--] = '\0'; /* buff_size amaze me alot since, due sz space*/
	while (buff_size >= 0)  /*converting the unsigned int to bin in buff*/
	{
		s[buff_size--] = (i2 % 2) + '0';
		i2 = i2 / 2;
	}
	write(1, s, buff_size_copy); /* writing to stdout */
	free(s); /* free buffer */
	return (buff_size_copy);
}
