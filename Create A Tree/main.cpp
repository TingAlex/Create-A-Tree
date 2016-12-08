#include<iostream>
#include<queue>
#include<stack>
using namespace std;
template<class T>
class BinaryTree;
template<class T>
class BinaryTreeNode
{
	friend class BinaryTree<T>;
private:
	T element;
	BinaryTreeNode<T> *leftChild;
	BinaryTreeNode<T> *rightChild;
public:
	BinaryTreeNode()
	{
		leftChild = NULL;
		rightChild = NULL;
	}
	BinaryTreeNode(const T& ele)
	{
		element = ele;
		leftChild = NULL;
		rightChild = NULL;
	}
	BinaryTreeNode(const T&ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r)
	{
		element = ele;
		leftChild = l;
		rightChild = r;
	}
	BinaryTreeNode<T> *getLeftChild()const
	{
		return leftChild;
	}
	BinaryTreeNode<T> *getRightChild()const
	{
		return rightChild;
	}
	void setLeftChild(BinaryTreeNode<T> *l)
	{
		leftChild = l;
	}
	void setRightChild(BinaryTreeNode<T> *r)
	{
		rightChild = r;
	}
	T getValue()const
	{
		return element;
	}
	void setValue(const T& val)
	{
		element = val;
	}
	bool isLeaf()const
	{
		if (leftChild == NULL && rightChild == NULL)
			return true;
		else
			return false;
	}
};

template<class T>
class BinaryTree
{
private:
	BinaryTreeNode<T> *root;
public:
	BinaryTree()
	{
		root = NULL;
	}
	bool isEmpty()const
	{
		if (root == NULL)
			return true;
		else
			return false;
	}
	BinaryTreeNode<T> *getRoot()const
	{
		return root;
	}
	BinaryTreeNode<T>* createTreeByPreIn(T A[],int s1,int e1,T B[],int s2,int e2)
	{								//先序数组	起始	末尾 中序数组	起始	末尾
	T rtdata=A[s1];
	int k;
	for(k=s2;k<=e2;k++)
	{
	if(B[k]==rtdata)
	break;
	}
	if(k==e2+1)
	return 0;
	int leftlen=k-s2;	//左子树长度
	int rightlen=e2-k;	//右子树长度
	BinaryTreeNode<T>* rt = new BinaryTreeNode<T>(rtdata,NULL,NULL);
	if(leftlen>0)
	rt->leftChild=createTreeByPreIn(A,s1+1,s1+leftlen,B,s2,k-1);
	if(rightlen>0)
	rt->rightChild=createTreeByPreIn(A,s1+leftlen+1,e1,B,k+1,e2);
	return rt;
	}																	
	BinaryTreeNode<T>* createTreeByPostIn(char A[],int s1,int e1,char B[],int s2,int e2)
	{									//后序数组	起始	末尾 中序数组	起始	末尾
	char rtdata=A[e1];
	int k;
	for(k=s2;k<=e2;k++)
	{
	if(B[k]==rtdata)
	break;
	}
	if(k==e2+1)
	return 0;
	int leftlen=k-s2;	//左子树长度
	int rightlen=e2-k;	//右子树长度
	BinaryTreeNode<T>* rt = new BinaryTreeNode<T>(rtdata,NULL,NULL);
	if(leftlen>0)
	rt->leftChild=createTreeByPostIn(A,s1,s1+leftlen-1,B,s2,k-1);
	if(rightlen>0)
	rt->rightChild=createTreeByPostIn(A,s1+leftlen,e1-1,B,k+1,e2);
	return rt;
	}
	void preOrder(BinaryTreeNode<T> *root)		//先序递归
	{
		if (root != NULL)
		{
			Visit(root);
			preOrder(root->getLeftChild());
			preOrder(root->getRightChild());
		}
	}
	void Visit(BinaryTreeNode<T> *root) {
		cout << root->getValue();
	}
};
int main() {
	BinaryTree<char> tree;
	char A[7] = { 'A','B','D','G','C','E','F' };
	char B[7] = { 'D','G','B','A','E','C','F' };
	char C[7] = { 'G','D','B','E','F','C','A' };
	tree.preOrder(tree.createTreeByPreIn(A, 0, 6, B, 0, 6));
	cout << endl;
	BinaryTree<char> tree2;
	tree.preOrder(tree.createTreeByPostIn(C, 0, 6, B, 0, 6));
	cout << endl;
}