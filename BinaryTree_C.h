#pragma once
#include <iostream>
using namespace std;

namespace bt_c
{
	const int ERROR = -1;

	template<typename T>
	/*���������ݽṹԭ��*/
	struct BinaryTree
	{
		/*����������ϵ�Ԫ��ֵ*/
		T data;
		/*�������н��ָ��˫�׵�ָ��*/
		BinaryTree *parent = NULL;
		/*�������н��ָ�����ӵ�ָ��*/
		BinaryTree *leftChild = NULL;
		/*�������н��ָ���Һ��ӵ�ָ��*/
		BinaryTree *rightChild = NULL;
	};

	template<typename T>
	/*���ú����ݹ���ն�������Ŀ��ֻ�ܲ��ú���*/
	void postOrderclearBinaryTree(BinaryTree<T> *root)
	{
		if (root->leftChild)
		{
			postOrderclearBinaryTree(root->leftChild);
			root->leftChild = NULL;
		}
		if (root->rightChild)
		{
			postOrderclearBinaryTree(root->rightChild);
			root->rightChild = NULL;
		}
		if (root && root->parent)
		{
			delete root;
		}
	}

	template<typename T>
	/*��ʼ��������*/
	void initBinaryTree(BinaryTree<T> *root)
	{
		if (!root)
		{
			exit(ERROR);
		}
		if (root->leftChild || root->rightChild)
		{
			postOrderclearBinaryTree(root);
		}
		root->leftChild = NULL;
		root->rightChild = NULL;
		root->parent = NULL;
	}

	template<typename T>
	void createBinaryTree(BinaryTree<T> &root)
	{
		if (&root == NULL)
		{
			exit(ERROR);
		}
		root.data = 11;
		BinaryTree<T> *bt1 = new BinaryTree<T>;
		bt1->data = 12;
		bt1->parent = &root;
		bt1->leftChild = NULL;
		bt1->rightChild = NULL;
		root.leftChild = bt1;
		BinaryTree<T> *bt2 = new BinaryTree<T>;
		bt2->data = 13;
		bt2->parent = &root;
		bt2->leftChild = NULL;
		bt2->rightChild = NULL;
		root.rightChild = bt2;
	}

	template<typename T>
	/*ǰ�����������*/
	void preOrderTraverse(BinaryTree<T> *root)
	{
		if (root != NULL)
		{
			cout << root->data << endl;
		}
		if (root->leftChild)
		{
			preOrderTraverse(root->leftChild);
		}
		if (root->rightChild)
		{
			preOrderTraverse(root->rightChild);
		}
	}

	template<typename T>
	/*�������������*/
	void inOrderTraverse(BinaryTree<T> *root)
	{
		if (root->leftChild)
		{
			preOrderTraverse(root->leftChild);
		}
		if (root != NULL)
		{
			cout << root->data << endl;
		}
		if (root->rightChild)
		{
			preOrderTraverse(root->rightChild);
		}
	}

	template<typename T>
	/*�������������*/
	void postOrderTraverse(BinaryTree<T> *root)
	{
		if (root->leftChild)
		{
			preOrderTraverse(root->leftChild);
		}
		if (root->rightChild)
		{
			preOrderTraverse(root->rightChild);
		}
		if (root != NULL)
		{
			cout << root->data << endl;
		}
	}

	template<typename T>
	void levelOrderTraverse(BinaryTree<T> root)
	{

	}
	


	/***************************����������ʾ��***********************************/
	/***************************1��˫�ױ�ʾ��***********************************/
	template<typename T>
	struct PTNode
	{
		/*�����Ԫ��ֵ*/
		T data;
		/*���˫���������е��±�*/
		int parentIndex;
	};

	template<typename T>
	/*˫�ױ�ʾ����*/
	struct ParentTree
	{
		/*ָ�������ռ�--����Ļ���ַ*/
		PTNode<T> *root;
		/*���н����*/
		int nodes;
		/*�������ֱ��ʹ��ǰ���list*/
		//list_c::List<PTNode<T>> *root;
	};

	/***************************2�����ӱ�ʾ��***********************************/
	struct CTnode
	{
		/*��ź����������е��±�*/
		int childIndex;
		/*����ָ��ͬһ�����������*/
		CTnode *next;
	};

	template<typename T>
	struct CTbox
	{
		/*���Ԫ�ص�ֵ*/
		T data;
		/*ָ�����µĵ�һ������*/
		CTnode *firstChild;
	};

	template<typename T>
	/*���ӱ�ʾ����*/
	struct CTree
	{
		/*ָ�������ռ�--����Ļ���ַ*/
		CTbox<T> *root;
		/*���н����*/
		int nodes;
		/*�������ֱ��ʹ��ǰ���list*/
		//list_c::List<PTNode<T>> *root;
	};

	/*************************3��˫�׺��ӱ�ʾ��*********************************/
	struct CPTnode
	{
		/*��ź����������е��±�*/
		int childIndex;
		/*����ָ��ͬһ�����������*/
		CPTnode *next;
	};

	template<typename T>
	struct CPTbox
	{
		/*���Ԫ�ص�ֵ*/
		T data;
		/*��Ž��˫���������е��±�*/
		int parentIndex;
		/*ָ�����µĵ�һ������*/
		CPTnode *firstChild;
	};

	template<typename T>
	/*˫�׺��ӱ�ʾ����*/
	struct CPTree
	{
		/*ָ�������ռ�--����Ļ���ַ*/
		CPTbox<T> *root;
		/*���н����*/
		int nodes;
		/*�������ֱ��ʹ��ǰ���list*/
		//list_c::List<PTNode<T>> *root;
	};

	/*************************4�������ֵܱ�ʾ��*********************************/
	template<typename T>
	/*�����ֵܱ�ʾ����*/
	struct CSTree
	{
		/*�����Ԫ��ֵ*/
		T data;
		/*ָ�����µ�һ�����Ӻ͸ý�����һ���ֵ�*/
		CSTree *firstChild, *nextSibling;
	};

}