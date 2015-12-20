#pragma once
#include<iostream>
#include "ListStack_C++.h"
#include "LinkStack_C++.h"
#include "List_C++.h"

namespace util
{
	/*工具类*/
	class Util
	{
	public:
		/*构造方法*/
		Util();
		/*析构函数*/
		virtual ~Util();
		/*将给定整形N转成指定d进制数，返回结果栈---ListStack*/
		ls_cpp::ListStack<int> conversion(int N, int d);
		/*将给定整形N转成指定d进制数，返回结果栈---LinkStack*/
		linkS_cpp::LinkStack<int> conversion_(int N, int d);
		/*括号匹配，匹配返回true，不匹配返回false*/
		bool bracketMatching(char bracket);
	private:
		static list_cpp::List<char> BRACKETS;
		/*用来存放最急迫括号*/
		ls_cpp::ListStack<char> bracketsStack;
	};

	/*迷宫类*/
	class Maze
	{
		/*提前声明*/
		class MazeElement;
	public:
		/*无参构造，默认生成一个10*10的迷宫*/
		Maze();
		/*指定生成一个rows*cols的迷宫*/
		Maze(int rows,int cols);
		virtual ~Maze();
		/*查找迷宫通路*/
		ls_cpp::ListStack<MazeElement> findMazePath();
		/*显示查找到的通路*/
		void showMazePath();
	private:
		/*迷宫上每个格点的数据类型类*/
		class MazeElement
		{
		public:
			MazeElement() {};
			/*构建格点，指定在迷宫上的坐标x,y---data=wall和path分别代表墙和通路*/
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
			/*顺时针*/
			enum DIRS {forward, right，back,left};
			enum MazeElementTypes {wall,path};
		};
		/*用二维数组代表迷宫，mazeBox为指向该数组的指针*/
		MazeElement *mazeBox[10];
	};

	/*算数运算符类*/
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

	/*表达式求值类---例如(1+2)*3-5#*/
	class EvaluateExpression
	{
	public:
		EvaluateExpression();
		~EvaluateExpression();
		/*计算数值*/
		void evaluate(double value);
		/*计算运算符，以#表示表达式结束*/
		double evaluate(char oper);
		static const int FLAG_VALUE = 1;
		static const int FLAG_OPERA = 2;
		static const int FLAG_INIT = 3;
	private:
		void evaluate(double value1, double value2,char oper_);
		/*用来放运算符的栈*/
		ls_cpp::ListStack<char> oper;
		/*用来放数值的栈*/
		ls_cpp::ListStack<double> values;
		/*所有合法运算符集合*/
		static list_cpp::List<char> OPERATORS;
		/*标记最后一次是数值还是运算符*/
		int flag = FLAG_INIT;
	};

	/*汉诺塔类---递归实现*/
	class Hanoi
	{
	public:
		/*汉诺塔构造函数，默认构造一个10层的汉诺塔*/
		Hanoi();
		~Hanoi();
		/*递归移动汉诺塔*/
		void hanoi(int n, char from, char to, char fuzu);
	private:
		/*打印移动方式*/
		void move(int index,char from,char to);
	};
}