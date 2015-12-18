#pragma once
#include<iostream>
#include<malloc.h>
using namespace std;

namespace str_c
{
	const int ERROR = -1;

	/*�ַ����ṹ---���ַ����ƺ����ܼ��ݺ���--һ������Ҫռ�����ֽ�*/
	struct String
	{
		/*ָ�������ָ��*/
		char *ch = NULL;
		/*��ǰ�ַ����ĳ���*/
		int length = 0;
	};
	/*�ø����ַ���T������str����*/
	void strAssign(String &str,char *T)
	{
		if (&str == NULL)
		{
			exit(ERROR);
		}
		if (str.ch)
		{
			delete str.ch;
		}
		int len = 0;
		for (char *p = T; *p != '\0'; p++)
		{
			len++;
		}
		str.ch = (char *)malloc((len + 1)*sizeof(char));
		if (!str.ch)
		{
			exit(ERROR);
		}
		for (int i = 0; i < len;i++)
		{
			str.ch[i] = T[i];
		}
		str.ch[len] = '\0';
		str.length = len;
	}
	/*��ȡ��ǰ�ַ����ĳ���*/
	int strLength(String str)
	{
		if (&str == NULL || str.ch == NULL)
		{
			exit(ERROR);
		}
		return str.length;
	}
	/*�Ƚ������ַ�������Ĵ�С�����������㣬�����ֽ������ʾ���ڣ����ڣ�С��*/
	int strCompare(String str1, String str2)
	{
		if (&str1 == NULL || &str2 == NULL || str1.ch == NULL || str2.ch == NULL)
		{
			exit(ERROR);
		}
		int i = 0, j = 0;
		while (i < str1.length && j<str2.length)
		{
			if (str1.ch[i] != str2.ch[j])
			{
				return str1.ch[i] - str2.ch[j];
			}
			i++;
			j++;
		}
		return str1.length - str2.length;
	}
	/*���ַ���str2ճ�ᵽ�ַ���str1����*/
	void strCat(String &str1, String str2)
	{
		if (&str1 == NULL || &str2 == NULL || str1.ch == NULL || str2.ch == NULL)
		{
			exit(ERROR);
		}
		str1.ch = (char *)realloc(str1.ch, (str1.length + str2.length + 1)*sizeof(char));
		if (!str1.ch)
		{
			exit(ERROR);
		}
		for (int i = 0; i < str2.length; i++)
		{
			str1.ch[i + str1.length] = str2.ch[i];
		}
		str1.ch[str1.length + str2.length] = '\0';
		str1.length += str2.length;
	}
	/*���ַ���str2���Ƶ�str1��*/
	void strCopy(String &str1, String str2)
	{
		if (&str1 == NULL || &str2 == NULL || str2.ch == NULL)
		{
			exit(ERROR);
		}
		if (str1.ch)
		{
			delete str1.ch;
		}
		str1.length = 0;
		str1.ch = (char *)malloc((str2.length + 1) * sizeof(char));
		if (!str1.ch)
		{
			exit(ERROR);
		}
		for (int i = 0; i < str2.length; i++)
		{
			str1.ch[i] = str2.ch[i];
		}
		str1.ch[str2.length] = '\0';
		str1.length = str2.length;
	}
	/*���ַ���str2�е�posλ�ý�ȡһ��len���ȵ��Ӵ���str1��,pos>=0 && pos<str.length,len >0 && len < str2.length*/
	void subString(String &str1, String str2, int pos, int len) 
	{
		if (&str1 == NULL || &str2 == NULL || str2.ch == NULL)
		{
			exit(ERROR);
		}
		if (pos < 0 || pos >= str2.length || len <=0 || pos+len>str2.length)
		{
			exit(ERROR);
		}
		if (str1.ch)
		{
			delete str1.ch;
		}
		str1.length = 0;
		str1.ch = (char *)malloc((len + 1)* sizeof(char));
		if (!str1.ch)
		{
			exit(ERROR);
		}
		for (int i = pos,j=0; i < pos + len; i++)
		{
			str1.ch[j++] = str2.ch[i];
		}
		str1.ch[len] = '\0';
		str1.length = len;
	}
	/*�����Ӵ�T��str1�е�һ�γ��ֵ�λ��pos,pos>=0 && pos<str.length����û�ҵ�����-1*/
	int strLocate(String str1, String str2)
	{
		if (&str1 == NULL || &str2 == NULL || str1.ch == NULL || str2.ch == NULL)
		{
			exit(ERROR);
		}
		if (str1.length < str2.length)
		{
			return -1;
		}
		for (int pos = 0; pos < str1.length - str2.length;pos++)
		{
			int j = 0;
			for (;j < str2.length;)
			{
				if (str1.ch[pos + j] == str2.ch[j])
				{
					j++;
				}
				else
				{
					break;
				}
			}
			if (j == str2.length)
			{
				return pos;
			}
		}
		return -1;
	}
	/*�����Ӵ�T��str1�е�һ�γ��ֵ�λ��pos,pos>=0 && pos<str.length����û�ҵ�����-1*/
	int strLocate(String str1, char *T)
	{
		if (&str1 == NULL || !str1.ch)
		{
			exit(ERROR);
		}
		String str2;
		strAssign(str2, T);
		return strLocate(str1, str2);
	}
	/*�����ַ����е�i��λ���ϵ��ַ���i>=0 && i<str.length*/
	char strCharAt(String str, int i)
	{
		if (&str == NULL || !str.ch || i < 0 || i >= str.length)
		{
			exit(ERROR);
		}
		return str.ch[i];
	}
	/*����ַ������ڴ�ռ�*/
	void clearString(String &str)
	{
		if (&str == NULL || !str.ch)
		{
			exit(ERROR);
		}
		delete str.ch;
		str.ch = NULL;
		str.length = 0;
	}

}
