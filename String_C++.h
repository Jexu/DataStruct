#pragma once
#include<iostream>
using namespace std;

namespace str_cpp
{
	const int ERROR = -1;
	/*�ַ�����---���ַ����ƺ����ܼ��ݺ���--һ������Ҫռ�����ֽ�*/
	class String
	{
	public:
		String();
		/*�ø����ַ���str������String����*/
		String(char *str);
		virtual ~String();
		/*�ø����ַ���str������string����*/
		void strAssign(char *str);
		/*��ȡ��ǰ�ַ����ĳ���*/
		int getLength();
		/*�Ƚ������ַ�������Ĵ�С�����������㣬�����ֽ������ʾ���ڣ����ڣ�С��*/
		int compare(char *str);
		/*�Ƚ������ַ�������Ĵ�С�����������㣬�����ֽ������ʾ���ڣ����ڣ�С��*/
		int compare(String str);
		bool operator >(String str);
		bool operator <(String str);
		bool operator ==(String str);
		/*���ַ���strճ�ᵽ���ַ�������*/
		void strCat(char *str);
		/*���ַ���strճ�ᵽ���ַ�������*/
		void strCat(String str);
		/*���Ʊ��ַ���������һ������*/
		String strCopy();
		/*�ӱ��ַ����е�posλ�ý�ȡһ��len���ȵ��Ӵ�����,pos>=0 && pos<str.length,len >0 && len < str2.length*/
		String subString(int pos, int len);
		/*�����Ӵ�str�ڱ��ַ����е�һ�γ��ֵ�λ��pos,pos>=0 && pos<str.length����û�ҵ�����-1*/
		int strLocate(char *str);
		/*�����Ӵ�str�ڱ��ַ����е�һ�γ��ֵ�λ��pos,pos>=0 && pos<str.length����û�ҵ�����-1*/
		int strLocate(String str);
		/*�����ַ����е�i��λ���ϵ��ַ���i>=0 && i<str.length*/
		char strCharAt(int i);
		/*���ظ��ַ���ָ��*/
		char *toString();
		/*����ַ������ڴ�ռ�*/
		void strClearing();
	private:
		/*ָ�������ָ��*/
		char *ch = NULL;
		/*��ǰ�ַ����ĳ���*/
		int length = 0;
	};
}


