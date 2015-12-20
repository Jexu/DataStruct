#include "AppOfStack.h"
#include <iostream>
#include <fstream>
#include "ListStack_C++.h"
#include "LinkStack_C++.h"
#include "List_C++.h"
#include <time.h>
using namespace std;
using namespace util;

/******************************************************/
/*工具类*/
Util::Util()
{
	this->bracketsStack = *(new ls_cpp::ListStack<char>());
}

Util::~Util()
{
	if (this->bracketsStack.getLength() >= 0)
	{
		bracketsStack.clearStack();
		delete &this->bracketsStack;
	}
}

ls_cpp::ListStack<int> Util::conversion(int N, int d)
{
	if (N <= 0)
	{
		cout << "输入的数非法" << endl;
		exit(ls_cpp::ERROR);
	}
	ls_cpp::ListStack<int> *ls = new ls_cpp::ListStack<int>();
	//cout << N << "的" << d << "进制数：" << endl;
	while (N)
	{
		ls->push(N%d);
		N /= d;
	}
	return *ls;
}

linkS_cpp::LinkStack<int> Util::conversion_(int N, int d)
{
	if (N <= 0)
	{
		cout << "输入的数非法" << endl;
		exit(linkS_cpp::ERROR);
	}
	linkS_cpp::LinkStack<int> *ls = new linkS_cpp::LinkStack<int>();
	//cout << N << "的" << d << "进制数：" << endl;
	while (N)
	{
		ls->push(N%d);
		N /= d;
	}
	return *ls;
}

list_cpp::List<char> Util::BRACKETS = *(new list_cpp::List<char>(6, '[', ']', '(', ')', '{', '}'));

bool Util::bracketMatching(char bracket)
{
	if (BRACKETS.findElement(bracket) == -1)
	{
		//cout << "输入的不是合法括号" << endl;
		return false;
	}
	if (bracket == '[' || bracket == '(' || bracket == '{')
	{
		this->bracketsStack.push(bracket);
		return true;
	}
	if ((bracket == ']' || bracket == ')' || bracket == '}') && this->bracketsStack.getLength() != 0)
	{
		if (BRACKETS.getElement(BRACKETS.findElement(bracketsStack.getTop()) + 1) == bracket)
		{
			this->bracketsStack.pop();
			return true;
		}
		return false;
	}
	return false;
}


/********************************************************************/
/*迷宫类*/
Maze::Maze()
{
	/*生成一个10*10的迷宫*/
	Maze::MazeElement mazeBox_[10][10];
	/*上墙*/
	for (int i = 0; i < 10; i++)
	{
		mazeBox_[0][i] = *(new Maze::MazeElement(Maze::MazeElement::MazeElementTypes::wall, 0, i));
	}
	/*上墙和下墙中间部分*/
	for (int i = 1; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0 || j == 9)
			{
				mazeBox_[i][j] = *(new Maze::MazeElement(Maze::MazeElement::MazeElementTypes::wall, i, j));
			}
			else
			{
				srand((unsigned int)time(NULL));
				/*定义随机随范围为[1,5]*/
				if (rand() % (5 - 1 + 1) + 1 != 1)
				{
					/*4/5为路，通路为随机产生的*/
					mazeBox_[i][j] = *(new Maze::MazeElement(Maze::MazeElement::MazeElementTypes::path, i, j));
				}
				else
				{
					mazeBox_[i][j] = *(new Maze::MazeElement(Maze::MazeElement::MazeElementTypes::wall, i, j));
				}
			}
		}
	}
	/*下墙*/
	for (int i = 0; i < 10; i++)
	{
		mazeBox_[9][i] = *(new Maze::MazeElement(Maze::MazeElement::MazeElementTypes::wall, 0, i));
	}

	//this->mazeBox = mazeBox_;	//不能赋值，不知道为什么
}

Maze::~Maze()
{

}

ls_cpp::ListStack<Maze::MazeElement> Maze::findMazePath()
{
	ls_cpp::ListStack<Maze::MazeElement> mazePath = *(new ls_cpp::ListStack<Maze::MazeElement>());
	return mazePath;
}

void Maze::showMazePath()
{

}

/**************************************************************/
/*运算符类*/
Expression::Expression()
{

}
Expression::Expression(char ex)
{
	this->ex = ex;
}
Expression::~Expression()
{

}
bool Expression::operator< (Expression ex)
{
	bool result = false;
	switch (this->ex)
	{
	case '+':
	case '-':
		if (ex.ex == '+' || ex.ex == '-' || ex.ex == ')' || ex.ex == '#')
		{
			result = false;
		}
		else if (ex.ex == '*' || ex.ex == '/' || ex.ex == '(')
		{
			result = true;
		}
		break;
	case '*':
	case '/':
		if (ex.ex == '+' || ex.ex == '-' || ex.ex == '*' || ex.ex == '/' || ex.ex == ')' || ex.ex == '#')
		{
			result = false;
		}
		else if (ex.ex == '(')
		{
			result = true;
		}
		break;
	case '(':
		if (ex.ex == '+' || ex.ex == '-' || ex.ex == '*' || ex.ex == '/' || ex.ex == '(')
		{
			result = true;
		}
		break;
	case ')':
		if (ex.ex == '+' || ex.ex == '-' || ex.ex == '*' || ex.ex == '/' || ex.ex == ')' || ex.ex == '#')
		{
			result = false;
		}
		break;
	case '#':
		if (ex.ex == '+' || ex.ex == '-' || ex.ex == '*' || ex.ex == '/' || ex.ex == '(')
		{
			result = true;
		}
		break;
	default:
		break;
	}
	return result;
}

bool Expression::operator> (Expression ex)
{
	bool result = false;
	switch (this->ex)
	{
	case '+':
	case '-':
		if (ex.ex == '+' || ex.ex == '-' || ex.ex == ')' || ex.ex == '#')
		{
			result = true;
		}
		else if (ex.ex == '*' || ex.ex == '/' || ex.ex == '(')
		{
			result = false;
		}
		break;
	case '*':
	case '/':
		if (ex.ex == '+' || ex.ex == '-' || ex.ex == '*' || ex.ex == '/' || ex.ex == ')' || ex.ex == '#')
		{
			result = true;
		}
		else if (ex.ex == '(')
		{
			result = false;
		}
		break;
	case '(':
		if (ex.ex == '+' || ex.ex == '-' || ex.ex == '*' || ex.ex == '/' || ex.ex == '(')
		{
			result = false;
		}
		break;
	case ')':
		if (ex.ex == '+' || ex.ex == '-' || ex.ex == '*' || ex.ex == '/' || ex.ex == ')' || ex == '#')
		{
			result = true;
		}
		break;
	case '#':
		if (ex.ex == '+' || ex.ex == '-' || ex.ex == '*' || ex.ex == '/' || ex.ex == '(')
		{
			result = false;
		}
		break;
	default:
		break;
	}
	return result;
}

bool Expression::operator== (Expression ex)
{
	if (this->ex == '(' && ex.ex == ')')
	{
		return true;
	}
	else if (this->ex == '#' && ex.ex == '#')
	{
		return true;
	}
	else
	{
		return false;
	}
}

/********************************************************/
/*表达式求值类*/
EvaluateExpression::EvaluateExpression()
{
	this->oper = *(new ls_cpp::ListStack<char>());
	this->values = *(new ls_cpp::ListStack<double>());
}
EvaluateExpression::~EvaluateExpression()
{
	this->oper.clearStack();
	this->values.clearStack();
}
list_cpp::List<char> EvaluateExpression::OPERATORS = *(new list_cpp::List<char>(7, '+', '-', '*', '/', '(', ')', '#'));
void EvaluateExpression::evaluate(double value)
{
	if (!&this->values)
	{
		cout << "Error" << endl;
		exit(ls_cpp::ERROR);
	}
	if (this->flag == EvaluateExpression::FLAG_VALUE)
	{
		cout << "输入不合法" << endl;
		exit(ls_cpp::ERROR);
	}
	this->flag = EvaluateExpression::FLAG_VALUE;
	this->values.push(value);
}

double EvaluateExpression::evaluate(char oper)
{
	double result = -7894561230000000000;
	if (this->values.getLength() == 0 && oper != '(')
	{
		cout << "输入不合法" << endl;
		exit(ls_cpp::ERROR);
	}
	if (this->OPERATORS.findElement(oper) == -1)
	{
		cout << "输入不合法" << endl;
		exit(ls_cpp::ERROR);
	}
	if (this->flag == EvaluateExpression::FLAG_OPERA)
	{
		cout << "输入不合法" << endl;
		exit(ls_cpp::ERROR);
	}
	if (this->oper.getLength() == 0)
	{
		this->flag = EvaluateExpression::FLAG_OPERA;
		this->oper.push(oper);
	}
	else if (*(new Expression(oper)) > *(new Expression(this->oper.getTop())))
	{
		if (oper != ')')
		{
			this->flag = EvaluateExpression::FLAG_OPERA;
			this->oper.push(oper);
		}
		else
		{
			while (this->oper.getTop() != '(')
			{
				if (this->values.getLength() < 2)
				{
					cout << "Error" << endl;
					exit(ls_cpp::ERROR);
				}
				double value2 = this->values.pop();
				double value1 = this->values.pop();
				this->evaluate(value1, value2, this->oper.pop());
				result = this->values.getTop();
			}
			this->oper.pop();
		}
	}
	else if (*(new Expression(oper)) < *(new Expression(this->oper.getTop())))
	{
		if (this->oper.getTop() != '(')
		{
			if (this->values.getLength() < 2)
			{
				cout << "Error" << endl;
				exit(ls_cpp::ERROR);
			}
			double value2 = this->values.pop();
			double value1 = this->values.pop();
			this->evaluate(value1, value2, this->oper.pop());
			this->oper.push(oper);
			result = this->values.getTop();
			if (oper == '#')
			{
				this->values.clearStack();
				this->oper.clearStack();
			}
		}
		else
		{
			this->oper.push(oper);
		}
		this->flag = EvaluateExpression::FLAG_OPERA;
	}
	else
	{
		/*僵尸---似乎执行不到这里--可以删去*/
		this->oper.pop();
		result = this->values.getTop();
	}
	return result;
}

void EvaluateExpression::evaluate(double value1, double value2, char oper_)
{
	switch (oper_)
	{
	case '+':
		this->values.push(value1 + value2);
		break;
	case '-':
		this->values.push(value1 - value2);
		break;
	case '*':
		this->values.push(value1 * value2);
		break;
	case '/':
		this->values.push(value1 / value2);
		break;
	case '#':
		this->oper.clearStack();
		break;
	default:
		break;
	}
}

/********************************************/
/*汉诺塔类*/
Hanoi::Hanoi()
{
}
Hanoi::~Hanoi()
{
}

void Hanoi::hanoi(int n,char from, char to, char fuzu)
{
	if (n <= 0)
	{
		cout << "输入n不合法" << endl;
		exit(-1);
	}
	if (n==1)
	{
		this->move(1, from, to);
	}
	else
	{
		hanoi(n - 1, 'x', 'y', 'z');
		this->move(n, 'x', 'z');
		hanoi(n - 1, 'y', 'z', 'x');
	}
}
void Hanoi::move(int index, char from, char to)
{
	cout << index << ":" << from << "->" << to << endl;
}