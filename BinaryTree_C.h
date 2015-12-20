#pragma once
#include <iostream>
using namespace std;

namespace bt_c
{
	const int ERROR = -1;

	template<typename T>
	/*二叉树数据结构原型*/
	struct BinaryTree
	{
		/*二叉树结点上的元素值*/
		T data;
		/*二叉树中结点指向双亲的指针*/
		BinaryTree *parent = NULL;
		/*二叉树中结点指向左孩子的指针*/
		BinaryTree *leftChild = NULL;
		/*二叉树中结点指向右孩子的指针*/
		BinaryTree *rightChild = NULL;
	};

	template<typename T>
	/*采用后续递归清空二叉树，目测只能采用后续*/
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
	/*初始化二叉树*/
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
	/*前序遍历二叉树*/
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
	/*中序遍历二叉树*/
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
	/*后序遍历二叉树*/
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
	


	/***************************树的其它表示法***********************************/
	/***************************1：双亲表示法***********************************/
	template<typename T>
	struct PTNode
	{
		/*结点中元素值*/
		T data;
		/*结点双亲在数组中的下标*/
		int parentIndex;
	};

	template<typename T>
	/*双亲表示法树*/
	struct ParentTree
	{
		/*指向连续空间--数组的基地址*/
		PTNode<T> *root;
		/*树中结点数*/
		int nodes;
		/*这里可以直接使用前面的list*/
		//list_c::List<PTNode<T>> *root;
	};

	/***************************2：孩子表示法***********************************/
	struct CTnode
	{
		/*存放孩子在数组中的下标*/
		int childIndex;
		/*用来指向同一层的其它孩子*/
		CTnode *next;
	};

	template<typename T>
	struct CTbox
	{
		/*结点元素的值*/
		T data;
		/*指向结点下的第一个孩子*/
		CTnode *firstChild;
	};

	template<typename T>
	/*孩子表示法树*/
	struct CTree
	{
		/*指向连续空间--数组的基地址*/
		CTbox<T> *root;
		/*树中结点数*/
		int nodes;
		/*这里可以直接使用前面的list*/
		//list_c::List<PTNode<T>> *root;
	};

	/*************************3：双亲孩子表示法*********************************/
	struct CPTnode
	{
		/*存放孩子在数组中的下标*/
		int childIndex;
		/*用来指向同一层的其它孩子*/
		CPTnode *next;
	};

	template<typename T>
	struct CPTbox
	{
		/*结点元素的值*/
		T data;
		/*存放结点双亲在数组中的下标*/
		int parentIndex;
		/*指向结点下的第一个孩子*/
		CPTnode *firstChild;
	};

	template<typename T>
	/*双亲孩子表示法树*/
	struct CPTree
	{
		/*指向连续空间--数组的基地址*/
		CPTbox<T> *root;
		/*树中结点数*/
		int nodes;
		/*这里可以直接使用前面的list*/
		//list_c::List<PTNode<T>> *root;
	};

	/*************************4：孩子兄弟表示法*********************************/
	template<typename T>
	/*孩子兄弟表示法树*/
	struct CSTree
	{
		/*结点中元素值*/
		T data;
		/*指向结点下第一个孩子和该结点的下一个兄弟*/
		CSTree *firstChild, *nextSibling;
	};

}