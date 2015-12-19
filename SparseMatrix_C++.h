#pragma once
#include <iostream>
#include "List_C++.h"
using namespace std;

namespace sm_cpp
{
	template<typename T>
	/*ϡ�������ÿ��Ԫ��������*/
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
		/*ϡ�������ÿ��Ԫ������ԭ�����е�����λ��*/
		int i, j;
		/*ֵ*/
		T ele;
	};

	template<typename T>
	/*ϡ�����������*/
	class SparseMatrix
	{
	public:
		SparseMatrix();
		virtual ~SparseMatrix();
		/*��ʼ��ϡ�����*/
		void addSMelement(int rows,int cols);
		/*��ʼ��ϡ�����*/
		void addSMelement(list_cpp::List<SMelement<T>> datas,int rows, int cols);
		/*���Ʊ�ϡ����󲢷���*/
		SparseMatrix<T> copySparseMatrix();
		/*���ϡ������з���Ԫ��ֵ*/
		void addSMelement(SMelement<T> e);
		/*��*/
		SparseMatrix<T> addSparseMatrix(SparseMatrix<T> sm1, SparseMatrix<T> sm2);
		/*��*/
		SparseMatrix<T> subSparseMatrix(SparseMatrix<T> sm1, SparseMatrix<T> sm2);
		/*��*/
		SparseMatrix<T> mulSparseMatrix(SparseMatrix<T> sm1, SparseMatrix<T> sm2);
		/*ת��*/
		SparseMatrix<T> transportSparseMatrix();
	private:
		/*������ŷ���Ԫ�ص�list*/
		list_cpp::List<SMelement<T>> datas;
		/*ԭ����������*/
		int rows, cols;
	};
}
