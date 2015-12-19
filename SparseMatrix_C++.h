#pragma once
#include <iostream>
#include "List_C++.h"
using namespace std;

namespace sm_cpp
{
	template<typename T>
	/*稀疏矩阵中每个元素类型类*/
	class SMelement
	{
	public:
		SMelement();
		SMelement(int i, int j, T e);
		int getI();
		int getJ();
		T getEle();
		void setI(int i);
		void setJ(int j);
		void setEle(T ele);
		virtual ~SMelement();
	private:
		/*稀疏矩阵中每个元素所在原矩阵中的行列位置*/
		int i, j;
		/*值*/
		T ele;
	};

	template<typename T>
	/*稀疏矩阵类型类*/
	class SparseMatrix
	{
	public:
		SparseMatrix();
		virtual ~SparseMatrix();
		/*初始化稀疏矩阵*/
		void addSMelement(int rows,int cols);
		/*初始化稀疏矩阵*/
		void addSMelement(list_cpp::List<SMelement<T>> datas,int rows, int cols);
		/*复制本稀疏矩阵并返回*/
		SparseMatrix<T> copySparseMatrix();
		/*添加稀疏矩阵中非零元素值*/
		void addSMelement(SMelement<T> e);
		/*加*/
		SparseMatrix<T> addSparseMatrix(SparseMatrix<T> sm1, SparseMatrix<T> sm2);
		/*减*/
		SparseMatrix<T> subSparseMatrix(SparseMatrix<T> sm1, SparseMatrix<T> sm2);
		/*乘*/
		SparseMatrix<T> mulSparseMatrix(SparseMatrix<T> sm1, SparseMatrix<T> sm2);
		/*转置*/
		SparseMatrix<T> transportSparseMatrix();
	private:
		/*用来存放非零元素的list*/
		list_cpp::List<SMelement<T>> datas;
		/*原矩阵行列数*/
		int rows, cols;
	};
}
