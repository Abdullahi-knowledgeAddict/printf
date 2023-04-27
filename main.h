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
int nsc(va_list, int, int);
void ips(unsigned int);
int chr(va_list);
int dp(va_list);
int ip(va_list);
int pc(va_list);
int pb(va_list);
int po(va_list);
int px(va_list);
int pX(va_list);
int str(va_list);
int sb(va_list);
int up(va_list);
/* formatting functions end here! */

#endif /* MAIN_H */
