#include <iostream>
#include "stringOperation.h"

size_t strlength (const char *s)
{
	size_t len = 0;
	if (s != nullptr)
	{
		const char *cur = s;
		while (* (cur++));
		len =  cur - s - 1 ;
	}
	return len;
}

size_t strlength (char *s)
{
	size_t len = 0;
	if (s != nullptr)
	{
		const char *cur = s;
		while (* (cur++));
		len =  cur - s - 1 ;
	}
	return len;
}

