#include <bfcStr.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (a > b ? b : a)
#define max(a, b) (a > b ? a : b)
#define clamp(v, minV, maxV) (max(min(v, maxV), minV))

string_t newString(char *str, size_t length)
{
	string_t result = {
		.str = malloc(length<<1),
		.length = length,
		.capacity = length<<1
	};

	memcpy(result.str, str, length);

	return result;
}

bool stringPushBack(string_t *str, char c)
{
	str->str[str->length++] = c;

	if(str->length < str->capacity)
		return TRUE;
	str->capacity <<= 1;
	char *tmp = realloc(str->str, str->capacity);
	if(!tmp)
		return FALSE;
	str->str = tmp;
	return TRUE;
}

bool stringPushFront(string_t *str, char c)
{
	for(int i = str->length++; i > 0; ++i)
		str->str[i] = str->str[i-1];
	str->str[0] = c;

	if(str->length < str->capacity)
		return TRUE;
	str->capacity <<= 1;
	char *tmp = realloc(str->str, str->capacity);
	if(!tmp)
		return FALSE;
	str->str = tmp;
	return TRUE;
}

bool stringEquals(string_t str1, char *str2, size_t length)
{
	if(str1.length != length)
		return FALSE;
	for(size_t i = 0; i < str1.length; ++i)
		if(str1.str[i] != str2[i])
			return FALSE;
	return TRUE;
}
//Append, Remove, Replace, Substring, Clear
bool stringAppend(string_t *str, char *append, size_t length)
{
	if(str->length + length >= str->capacity)
	{
		char *tmp = realloc(str->str, str->capacity+(length<<1));
		if(!tmp)
			return FALSE;
		str->capacity += length<<1;
		str->str = tmp;
	}

	memcpy(str->str + str->length, append, length);
	str->length += length;

	return TRUE;
}

string_t stringRemove(string_t str, size_t start, size_t length)
{
	string_t result = { 0 };

	if(start < 0  || start >= str.length || start + length >= str.length)
		return result;

	result.length = str.length - length;
	result.capacity = result.length << 1;
	result.str = malloc(result.capacity);

	if(!result.str)
		return (string_t){ 0 };
	memcpy(result.str, str.str, start);
	memcpy(result.str + start, str.str + start + length, str.length - (start + length));

	return result;
}

string_t stringReplace(string_t str, char *substring, size_t subLength, char *replace, size_t repLength)
{
	if(!substring || !replace)
		return (string_t){ 0 };
	string_t result = newString();

	for(size_t i = 0; i < str.length; ++i)
	{
		if(str.str[i] != substring[0])
		{
			stringPushBack(&result, str.str[i]);
			continue;
		}
		string_t sub = stringSubstring(str, i, subLength);
		if(stringEquals(sub, substring, subLength))
		{
			stringAppend(&result, replace, repLength);
			i += subLength;
		}
		free(sub.str);
	}

	return result;
}

string_t stringSubstring(string_t str, size_t start, size_t length)
{
	string_t result = { 0 };

	if(start < 0 || start >= str.length || start + length > str.length)
		return result;

	result.length = length;
	result.capacity = length<<1;
	result.str = malloc(result.capacity);

	if(!result.str)
		return (string_t){ 0 };

	memcpy(result.str, str.str+start, length);

	return result;
}

bool stringClear(string_t *str)
{
	str->capacity = 1;
	memset(str->str, 0, str->length);
	str->length = 0;

	return TRUE;
}
