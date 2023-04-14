#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef int (*funct_pointer_t)(va_list);/* a type to dclr the fnctn pointer */
/**
 * struct life - assocites a char to matching formating function
 * @c: the char for format specification
 * @func_point: pointer to the matching formating function
 */
typedef struct life
{
	char c;
	funct_pointer_t func_point;
} associate_t;			/* a type do declare this field at any time */


/* formatting functions and function to get them */
funct_pointer_t get_req_funct(const char);
int _printf(const char *format, ...);
int chr(va_list);
int pc(va_list v);
int dp(va_list v);
int ip(va_list v);
void ips(long int);
int str(va_list);
/* formatting functions end here! */

#endif /* MAIN_H */
