#pragma once
#include<iostream>
#include "ListStack_C++.h"
#include "LinkStack_C++.h"
#include "List_C++.h"

namespace util
{
	/*������*/
	class Util
	{
	public:
		/*���췽��*/
		Util();
		/*��������*/
		virtual ~Util();
		/*����������Nת��ָ��d�����������ؽ��ջ---ListStack*/
		ls_cpp::ListStack<int> conversion(int N, int d);
		/*����������Nת��ָ��d�����������ؽ��ջ---LinkStack*/
		linkS_cpp::LinkStack<int> conversion_(int N, int d);
		/*����ƥ�䣬ƥ�䷵��true����ƥ�䷵��false*/
		bool bracketMatching(char bracket);
	private:
		static list_cpp::List<char> BRACKETS;
		/*��������������*/
		ls_cpp::ListStack<char> bracketsStack;
	};

	/*�Թ���*/
	class Maze
	{
		/*��ǰ����*/
		class MazeElement;
	public:
		/*�޲ι��죬Ĭ������һ��10*10���Թ�*/
		Maze();
		/*ָ������һ��rows*cols���Թ�*/
		Maze(int rows,int cols);
		virtual ~Maze();
		/*�����Թ�ͨ·*/
		ls_cpp::ListStack<MazeElement> findMazePath();
		/*��ʾ���ҵ���ͨ·*/
		void showMazePath();
	private:
		/*�Թ���ÿ����������������*/
		class MazeElement
		{
		public:
			MazeElement() {};
			/*������㣬ָ�����Թ��ϵ�����x,y---data=wall��path�ֱ����ǽ��ͨ·*/
			MazeElement(int type, int x, int y) 
			{ 
				this->type = type;
				this->x = x;
				this->y = y;
				this->di = DIRS::forward;
			};
			int type;
			int x;
			int y;
			int di;
			/*˳ʱ��*/
			enum DIRS {forward, right��back,left};
			enum MazeElementTypes {wall,path};
		};
		/*�ö�ά��������Թ���mazeBoxΪָ��������ָ��*/
		MazeElement *mazeBox[10];
	};

	/*�����������*/
	class Expression
	{
	public:
		Expression();
		Expression(char ex);
		virtual ~Expression();
		bool operator> (Expression ex);
		bool operator< (Expression ex);
		bool operator== (Expression ex);
		char ex;
	};

	/*���ʽ��ֵ��---����(1+2)*3-5#*/
	class EvaluateExpression
	{
	public:
		EvaluateExpression();
		~EvaluateExpression();
		/*������ֵ*/
		void evaluate(double value);
		/*�������������#��ʾ���ʽ����*/
		double evaluate(char oper);
		static const int FLAG_VALUE = 1;
		static const int FLAG_OPERA = 2;
		static const int FLAG_INIT = 3;
	private:
		void evaluate(double value1, double value2,char oper_);
		/*�������������ջ*/
		ls_cpp::ListStack<char> oper;
		/*��������ֵ��ջ*/
		ls_cpp::ListStack<double> values;
		/*���кϷ����������*/
		static list_cpp::List<char> OPERATORS;
		/*������һ������ֵ���������*/
		int flag = FLAG_INIT;
	};

	/*��ŵ����---�ݹ�ʵ��*/
	class Hanoi
	{
	public:
		/*��ŵ�����캯����Ĭ�Ϲ���һ��10��ĺ�ŵ��*/
		Hanoi();
		~Hanoi();
		/*�ݹ��ƶ���ŵ��*/
		void hanoi(int n, char from, char to, char fuzu);
	private:
		/*��ӡ�ƶ���ʽ*/
		void move(int index,char from,char to);
	};
}