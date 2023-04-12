#include "main.h"

/**
 * _printf - format and prints to the stdout
 * @format: the format specifiers
 * Return: the number of byte printed
 */
int _printf(const char *format, ...)
{
	int byte_count;
	char *copy;
	va_list v;
	funct_pointer_t match_func;

	match_func = NULL;
	va_start(v, format);
	 copy = (char *) format;
	for (byte_count = 0; *copy; copy++)
	{
		if (*copy == '%')
		{
			match_func = get_req_funct(*(++copy));
			if (match_func) /* if format specifier function exist*/
				byte_count += match_func(v);
			else /* what do if format specifier doesn't exist */
			{
				write(1, copy, 1);
				byte_count++;
			}
		}
		else
		{
			write(1, copy, 1);
			byte_count++;
		}
	}
	va_end(v);
	return (byte_count);
}
