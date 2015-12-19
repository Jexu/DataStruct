#pragma once
#include <iostream>
#include <ctype.h>
#include "List_C.h"
using namespace std;

namespace sm_c
{
	const int ERROR = -1;

	template<typename T>
	/*ϡ�������ÿ��Ԫ������*/
	struct SMelement
	{
		/*ϡ�������ÿ��Ԫ������ԭ�����е�����λ��*/
		int i, j;
		/*ֵ*/
		T ele;
	};

	template<typename T>
	/*ϡ���������*/
	struct SparseMatrix
	{
		/*������ŷ���Ԫ�ص�list*/
		list_c::List<SMelement<T>> datas;
		/*ԭ����������*/
		int rows, cols;
	};

	template<typename T>
	/*��ʼ��ϡ�����*/
	void initSparseMatrix(SparseMatrix<T> &sm, int rows, int cols)
	{
		if (&sm == NULL)
		{
			exit(ERROR);
		}
		if (sm.datas.length > 0)
		{
			list_c::clearList(sm.datas);
		}
		sm.datas = *(new list_c::List<SMelement<T>>);
		list_c::initList(sm.datas);
		sm.rows = rows;
		sm.cols = cols;
	}

	template<typename T>
	/*���ϡ������з���Ԫ��ֵ*/
	void addSMelement(SparseMatrix<T> &sm, SMelement<T> e)
	{
		if (&sm == NULL)
		{
			exit(ERROR);
		}
		if (sizeof(e.ele) != 4 || sizeof(e.ele) != 8 || e.i < 0 || e.i >= sm.rows || e.j < 0 || e.j >= sm.cols)
		{
			exit(ERROR);
		}
		list_c::addElement(sm.datas, e);
	}

	template<typename T>
	/*����ϡ�����sm1��ϡ�����sm��*/
	void copySparseMatrix(SparseMatrix<T> &sm, SparseMatrix<T> sm1)
	{

	}

	template<typename T>
	/*ϡ�����sm1+sm2������浽sm��*/
	void addSparseMatrix(SparseMatrix<T> &sm, SparseMatrix<T> sm1, SparseMatrix<T> sm2)
	{

	}

	template<typename T>
	/*ϡ�����sm1-sm2������浽sm��*/
	void subSparseMatrix(SparseMatrix<T> &sm, SparseMatrix<T> sm1, SparseMatrix<T> sm2)
	{

	}

	template<typename T>
	/*ϡ�����sm1*sm2������浽sm��*/
	void mulSparseMatrix(SparseMatrix<T> &sm, SparseMatrix<T> sm1, SparseMatrix<T> sm2)
	{

	}

	template<typename T>
	/*ϡ�����sm1ת�ã�����浽sm��*/
	void transportSparseMatrix(SparseMatrix<T> &sm, SparseMatrix<T> sm1)
	{

	}
}