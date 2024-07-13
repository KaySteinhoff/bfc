#ifndef BFC_STRING_H_
#define BFC_STRING_H_
#include <bfc.h>
#include <stdio.h>

typedef struct
{
	char *str;
	size_t length;
	size_t capacity;
}string_t;

string_t newString(void);
bool stringPushBack(string_t *str, char c);
bool stringPushFront(string_t *str, char c);
bool stringAppend(string_t *str, char *append, size_t length);
string_t stringRemove(string_t str, size_t start, size_t length);
string_t stringReplace(string_t str, char *substring, size_t subLength, char *replace, size_t repLength);
string_t stringSubstring(string_t str, size_t start, size_t length);
bool stringClear(string_t *str);

#endif
