#include "BinaryTree.h"
#include <exception>
#include <vector>
#include <cstdio>

using namespace std;
using namespace bruce;

//===================My code begin===========================
typedef vector<int>::iterator vec_int_it;

BinaryTreeNode *ConstructCore(vec_int_it itPreBegin, vec_int_it itPreEnd, 
							vec_int_it itInBegin, vec_int_it itInEnd)
{
	BinaryTreeNode *pRoot = new BinaryTreeNode(*itPreBegin);

	if (itPreBegin + 1 == itPreEnd)
	{
		if (itInBegin + 1 == itInEnd && *itInBegin == *itPreBegin)
		{
			return pRoot;
		}
		else
		{
			throw exception();
		}
	}
	
	vec_int_it itInRoot = itInBegin;

	while ( itInRoot != itInEnd && *itInRoot != pRoot->m_nValue)
		++itInRoot;
	
	if (itInRoot == itInEnd)
		throw exception();

	int leftLen = itInRoot - itInBegin;
	vec_int_it itLeftPreEnd = itPreBegin + 1 + leftLen;
	if (leftLen > 0)
	{
		pRoot->m_pLeft = ConstructCore(itPreBegin + 1, itLeftPreEnd, 
										itInBegin, itInRoot);
	}

	int rightLen = itInEnd - itInRoot - 1;
	if (rightLen > 0)
	{
		pRoot->m_pRight = ConstructCore(itLeftPreEnd, itPreEnd, 
										itInRoot + 1, itInEnd);
	}

	return pRoot;
	
}

BinaryTreeNode *Construct(vector<int> preoder, vector<int> inorder)
{
	if (preoder.size() == 0 || inorder.size() == 0 || 
		inorder.size() != preoder.size())
		return NULL;

	return ConstructCore(preoder.begin(), preoder.end(), 
						inorder.begin(), inorder.end());
}

BinaryTreeNode *Construct(int *preoder, int *inorder, int length)
{
	if (preoder == NULL || inorder == NULL || length < 1)
		return NULL;

	vector<int> vecPre(length);
	vector<int> vecIn(length);

	for (int i = 0; i != length; ++i)
	{
		vecPre[i] = preoder[i];
		vecIn[i] = inorder[i];
	}

	return Construct(vecPre, vecIn);
}

//===================My code end==============================

//=====================Test code========================================
void Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* pRoot = Construct(preorder, inorder, length);
        if (pRoot)
		{
			BinaryTree bTree(pRoot);
			bTree.PrintTree();
		}

    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}


//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}

//            1
//             \
//              2   
//               \
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

//one node tree
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

//perfect tree
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

//empty tree
void Test6()
{
    Test("Test6", NULL, NULL, 0);
}

//unmatched input
void Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
