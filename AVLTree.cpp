#include<iostream>
#include<stdlib>
#include<algorithm>
#include<stack>
using namespace std;
class Tree
{
	private  :
  	struct Node
	{
		struct Node *left;
		int data;
		int height;
		struct Node * right;
	};	
	struct Node *root;
	public :
	Tree()
	{
		root=0;
	}
	void insert(int data)
	{
		root=insert(root,data);
	}
	void insert(Node * root,int data)
	{
		
		if(root==0)
		{
			struct Node *temp=new Node();
			temp->left=0;
			temp->right=0;
			temp->height=1;
			temp->data=data;
			root=temp;
			return root;
		}
		if(data > root->data)
		{
			root->right = insert(root->right,data);
			if(abs(height(root->right)-height(root->left))==2)
			{
				
			}			
		}
		else
		{
			root->left = insert(root->left,data);
			if(abs(height(root->right)-height(root->left))==2)
			{
				
			}
		}
		return root;
	}
	Node * rightRoate(Node *root)
	{
		Node * newRoot=root->right;
		root.right=newRoot.left;
		newRoot->left=root;
		root->height=max(height(root.left),height(root.right))+1;
		newRoot->height=max(height(newRoot.left),height(newRoot.right))+1;
		return newRoot;
				
	}
	Node * leftRoate(Node *root)
	{
		Node * newRoot=root->left;
		root.left=newRoot.right;
		newRoot->right=root;
		root->height=max(height(root.left),height(root.right))+1;
		newRoot->height=max(height(newRoot.left),height(newRoot.right))+1;
		return newRoot;
				
	}
	int height(Node *root)
	{
		if(root==0)
			return -1;
		else 	
			return root.height
	}
	void inorderTraverse()
	{
		inorder(root);
	}
	void inorder(Node* root)
	{
		if(root==0)
		{
			return;
		}
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
	void nonRecInorder()
	{
		stack<Node *> * stk=new stack<Node *>();
		if(root==0)
		{
			cout<<"Tree is Empty.";
			return;
		}
		Node * ptr=root;
		while(1)
		{
			
			while(ptr->left!=0)
			{
				stk->push(ptr);
				ptr=ptr->left;
			}
			
			while(ptr->right==0)
			{
				cout<<ptr->data << " " ;
				if(stk->empty())
				return;
				ptr=stk->top();
				stk->pop();					
			}
			cout<<ptr->data << " " ;
			ptr=ptr->right;
						
		}
	}
	
};
int main()
{
	Tree * tree=new Tree();
	tree->insert(8);
	tree->insert(5);
	tree->insert(3);
	tree->insert(6);
	tree->insert(12);
	tree->insert(11);
	tree->insert(13);	
	tree->nonRecInorder();		
}
