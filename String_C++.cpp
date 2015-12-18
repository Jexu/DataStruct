#include "String_C++.h"
#include <malloc.h>
using namespace str_cpp;


String::String()
{
	this->ch = NULL;
	this->length = 0;
}

String::String(char *str)
{
	int len = 0;
	for (char *p = str; *p != '\0'; p++)
	{
		len++;
	}
	this->ch = (char *)malloc((len + 1)*sizeof(char));
	if (!this->ch)
	{
		exit(ERROR);
	}
	for (int i = 0; i < len; i++)
	{
		this->ch[i] = str[i];
	}
	this->ch[len] = '\0';
	this->length = len;
}

String::~String()
{
	
}

int String::getLength()
{
	if (!this || this->ch == NULL)
	{
		exit(ERROR);
	}
	return this->length;
}

void String::strAssign(char *str)
{
	if (!this)
	{
		exit(ERROR);
	}
	if (this->ch)
	{
		delete this->ch;
	}
	int len = 0;
	for (char *p = str; *p != '\0'; p++)
	{
		len++;
	}
	this->ch = (char *)malloc((len + 1)*sizeof(char));
	if (!this->ch)
	{
		exit(ERROR);
	}
	for (int i = 0; i < len; i++)
	{
		this->ch[i] = str[i];
	}
	this->ch[len] = '\0';
	this->length = len;
}

int String::compare(char *str)
{
	if (!this || !this->ch)
	{
		exit(ERROR);
	}
	int len = 0;
	for (char *p = str; *p != '\0'; p++)
	{
		len++;
	}
	int i = 0, j = 0;
	while (i < this->length && j<len)
	{
		if (this->ch[i] != str[j])
		{
			return this->ch[i] - str[j];
		}
		i++;
		j++;
	}
	return this->length - len;
}

int String::compare(String str)
{
	if (!this || &str == NULL || !this->ch || !str.ch)
	{
		exit(ERROR);
	}
	int i = 0, j = 0;
	while (i < this->length && j<str.getLength())
	{
		if (this->ch[i] != str.ch[j])
		{
			return this->ch[i] - str.ch[j];
		}
		i++;
		j++;
	}
	return this->length - str.getLength();
}

bool String::operator> (String str)
{
	if (this->compare(str) > 0)
	{
		return true;
	}
	return false;
}

bool String::operator< (String str)
{
	if (this->compare(str) < 0)
	{
		return true;
	}
	return false;
}

bool String::operator== (String str)
{
	if (this->compare(str) == 0)
	{
		return true;
	}
	return false;
}

void String::strCat(char *str)
{
	this->strCat(*(new String(str)));
}

void String::strCat(String str)
{
	if (!this || &str == NULL || this->ch == NULL || str.ch == NULL)
	{
		exit(ERROR);
	}
	this->ch = (char *)realloc(this->ch, (this->length + str.getLength() + 1)*sizeof(char));
	if (!this->ch)
	{
		exit(ERROR);
	}
	for (int i = 0; i < str.getLength(); i++)
	{
		this->ch[i + this->length] = str.ch[i];
	}
	this->ch[this->length + str.getLength()] = '\0';
	this->length += str.getLength();
}

String String::strCopy()
{
	if (!this || this->ch == NULL)
	{
		exit(ERROR);
	}
	
	char *ch = (char *)malloc((this->length + 1) * sizeof(char));
	if (!ch)
	{
		exit(ERROR);
	}
	for (int i = 0; i < this->length; i++)
	{
		ch[i] = this->ch[i];
	}
	ch[this->length] = '\0';
	return *(new String(ch));
}

String String::subString(int pos, int len)
{
	if (!this || this->ch == NULL)
	{
		exit(ERROR);
	}
	if (pos < 0 || pos >= this->length || len <= 0 || pos + len>this->length)
	{
		exit(ERROR);
	}
	char *ch = (char *)malloc((len + 1)* sizeof(char));
	if (!ch)
	{
		exit(ERROR);
	}
	for (int i = pos, j = 0; i < pos + len; i++)
	{
		ch[j++] = this->ch[i];
	}
	ch[len] = '\0';
	return *(new String(ch));
}

int String::strLocate(char *str)
{
	return this->strLocate(*(new String(str)));
}
//这里只用了传统的方法，----可以采用KMP算法，在部分情况下会更快
int String::strLocate(String str)
{
	if (!this || &str == NULL || this->ch == NULL || str.ch == NULL)
	{
		exit(ERROR);
	}
	if (this->length < str.getLength())
	{
		return -1;
	}
	for (int pos = 0; pos < this->length - str.getLength(); pos++)
	{
		int j = 0;
		for (; j < str.getLength();)
		{
			if (this->ch[pos + j] == str.ch[j])
			{
				j++;
			}
			else
			{
				break;
			}
		}
		if (j == str.getLength())
		{
			return pos;
		}
	}
	return -1;
}

char String::strCharAt(int i)
{
	if (!this || !this->ch || i < 0 || i >= this->length)
	{
		exit(ERROR);
	}
	return this->ch[i];
}

char *String::toString()
{
	if (!this || !this->ch)
	{
		exit(ERROR);
	}
	return this->ch;
}

void String::strClearing()
{
	if (!this || !this->ch)
	{
		exit(ERROR);
	}
	delete this->ch;
	this->ch = NULL;
	this->length = 0;
}
