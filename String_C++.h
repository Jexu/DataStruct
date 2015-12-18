#pragma once
#include<iostream>
using namespace std;

namespace str_cpp
{
	const int ERROR = -1;
	/*字符串类---部分方法似乎不能兼容汉字--一个汉字要占两个字节*/
	class String
	{
	public:
		String();
		/*用给定字符串str来构建String对象*/
		String(char *str);
		virtual ~String();
		/*用给定字符串str来创建string对象*/
		void strAssign(char *str);
		/*获取当前字符串的长度*/
		int getLength();
		/*比较两个字符串对象的大小，返回正，零，负三种结果，表示大于，等于，小于*/
		int compare(char *str);
		/*比较两个字符串对象的大小，返回正，零，负三种结果，表示大于，等于，小于*/
		int compare(String str);
		bool operator >(String str);
		bool operator <(String str);
		bool operator ==(String str);
		/*将字符串str粘结到本字符串后面*/
		void strCat(char *str);
		/*将字符串str粘结到本字符串后面*/
		void strCat(String str);
		/*复制本字符串，返回一个复制*/
		String strCopy();
		/*从本字符串中第pos位置截取一个len长度的子串返回,pos>=0 && pos<str.length,len >0 && len < str2.length*/
		String subString(int pos, int len);
		/*查找子串str在本字符串中第一次出现的位置pos,pos>=0 && pos<str.length；若没找到返回-1*/
		int strLocate(char *str);
		/*查找子串str在本字符串中第一次出现的位置pos,pos>=0 && pos<str.length；若没找到返回-1*/
		int strLocate(String str);
		/*返回字符串中第i个位置上的字符，i>=0 && i<str.length*/
		char strCharAt(int i);
		/*返回该字符串指针*/
		char *toString();
		/*清空字符串的内存空间*/
		void strClearing();
	private:
		/*指向数组的指针*/
		char *ch = NULL;
		/*当前字符串的长度*/
		int length = 0;
	};
}


