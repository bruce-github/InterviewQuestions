
namespace bruce
{
	class BinaryTreeNode
	{
	public:
		BinaryTreeNode(int value);
		void ConnectTreeNodes(BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
		void PrintTreeNode();
		
	public:
		int m_nValue;
		BinaryTreeNode* m_pLeft; 
		BinaryTreeNode* m_pRight;
	};
	
	class BinaryTree
	{
	public:
		BinaryTree(BinaryTreeNode *pRoot);
		void PrintTree();
		~BinaryTree();
	
	private:
		void DestroyTree(BinaryTreeNode* pRoot);
		void PrintTree(BinaryTreeNode* pRoot);
		
	private:
		BinaryTreeNode *m_pRoot;
	};
	
	//BinaryTreeNode* CreateBinaryTreeNode(int value);
	//void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
	//void PrintTreeNode(BinaryTreeNode* pNode);
	//void PrintTree(BinaryTreeNode* pRoot);
	//void DestroyTree(BinaryTreeNode* pRoot);
}
