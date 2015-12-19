#pragma once
#include <iostream>
#include <ctype.h>
#include "List_C.h"
using namespace std;

namespace sm_c
{
	const int ERROR = -1;

	template<typename T>
	/*稀疏矩阵中每个元素类型*/
	struct SMelement
	{
		/*稀疏矩阵中每个元素所在原矩阵中的行列位置*/
		int i, j;
		/*值*/
		T ele;
	};

	template<typename T>
	/*稀疏矩阵类型*/
	struct SparseMatrix
	{
		/*用来存放非零元素的list*/
		list_c::List<SMelement<T>> datas;
		/*原矩阵行列数*/
		int rows, cols;
	};

	template<typename T>
	/*初始化稀疏矩阵*/
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
	/*添加稀疏矩阵中非零元素值*/
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
	/*复制稀疏矩阵sm1到稀疏矩阵sm中*/
	void copySparseMatrix(SparseMatrix<T> &sm, SparseMatrix<T> sm1)
	{

	}

	template<typename T>
	/*稀疏矩阵sm1+sm2，结果存到sm中*/
	void addSparseMatrix(SparseMatrix<T> &sm, SparseMatrix<T> sm1, SparseMatrix<T> sm2)
	{

	}

	template<typename T>
	/*稀疏矩阵sm1-sm2，结果存到sm中*/
	void subSparseMatrix(SparseMatrix<T> &sm, SparseMatrix<T> sm1, SparseMatrix<T> sm2)
	{

	}

	template<typename T>
	/*稀疏矩阵sm1*sm2，结果存到sm中*/
	void mulSparseMatrix(SparseMatrix<T> &sm, SparseMatrix<T> sm1, SparseMatrix<T> sm2)
	{

	}

	template<typename T>
	/*稀疏矩阵sm1转置，结果存到sm中*/
	void transportSparseMatrix(SparseMatrix<T> &sm, SparseMatrix<T> sm1)
	{

	}
}