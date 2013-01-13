#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

namespace bruce
{
	//BinaryTreeNode begin
	BinaryTreeNode::BinaryTreeNode(int value) : m_nValue(value), m_pLeft(NULL), m_pRight(NULL)
	{
	}

	void BinaryTreeNode::ConnectTreeNodes(BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
	{
	    m_pLeft = pLeft;
	    m_pRight = pRight;
	}

	void BinaryTreeNode::PrintTreeNode()
	{
	
	    printf("value of this node is: %d\n", m_nValue);

	    if(m_pLeft != NULL)
	        printf("value of its left child is: %d.\n", m_pLeft->m_nValue);
	    else
	        printf("left child is null.\n");

	    if(m_pRight != NULL)
	        printf("value of its right child is: %d.\n", m_pRight->m_nValue);
	    else
	        printf("right child is null.\n");

		printf("\n");
	}
	//BinaryTreeNode end

	//BinaryTree begin
	BinaryTree::BinaryTree(BinaryTreeNode *pRoot) : m_pRoot(pRoot)
	{
	}

	void BinaryTree::PrintTree(BinaryTreeNode *pRoot)
	{
		pRoot->PrintTreeNode();

		if(pRoot != NULL)
		{
		    if(pRoot->m_pLeft != NULL)
		        PrintTree(pRoot->m_pLeft);

		    if(pRoot->m_pRight != NULL)
		        PrintTree(pRoot->m_pRight);
		}
	}
	void BinaryTree::PrintTree()
	{
		PrintTree(m_pRoot);
	}

	void BinaryTree::DestroyTree(BinaryTreeNode* pRoot)
	{
		if(pRoot != NULL)
		{
			BinaryTreeNode* pLeft = pRoot->m_pLeft;
			BinaryTreeNode* pRight = pRoot->m_pRight;

			delete pRoot;
			pRoot = NULL;

			DestroyTree(pLeft);
			DestroyTree(pRight);
		}
	}
	
	BinaryTree::~BinaryTree()
	{
		DestroyTree(m_pRoot);
	}
	//BinaryTree end
}
