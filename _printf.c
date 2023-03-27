#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					char c = (char)va_arg(args, int);
					putchar(c);
					count++;
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char *);
					int i;
					for (i = 0; s[i] != '\0'; i++)
					{
						putchar(s[i]);
						count++;
					}
					break;
				}
				case 'd':
				case 'i':
				{
					int i = 0;
					char buf[20];
					int num = va_arg(args, int);
					if (num < 0)
					{
						putchar('-');
						count++;
						num = -num;
					}
					do {
						buf[i++] = (num % 10) + '0';
						num /= 10;
					} while (num > 0);
					while (i > 0)
					{
						putchar(buf[--i]);
						count++;
					}
					break;
				}
				case '%':
				{
					putchar('%');
					count++;
					break;
				}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return count;
}
