#include<iostream>
#include<stack>
using namespace std;
class Tree
{
	private  :
  	struct Node
	{
		struct Node *left;
		int data;
		struct Node * right;
	};	
	struct Node *root;
	public :
	Tree()
	{
		root=0;
	}
	void insertRec(int data)
	{
		this->root=insertRec(this->root,data);
	}
	Node * insertRec(Node * root,int data)
	{
		
		if(root==0)
		{
			struct Node *temp=new Node();
			temp->left=0;
			temp->right=0;
			temp->data=data;
			root=temp;
			return root;
		}
		if(root->data>data)
		{
			root->left=insertRec(root->left,data);
		}
		else
		{
			root->right=insertRec(root->right,data);
		}
		return root;
	}
	void insert(int data)
	{
		struct Node *temp=new Node();
		temp->left=0;
		temp->right=0;
		temp->data=data;
		if(root==0)
		{
			root=temp;
			return;
		}
		struct Node * ptr=root;
		struct Node * pre=0;
		while(ptr!=0)
		{
			pre=ptr;
			if(ptr->data>data)
				ptr=ptr->left;
			else if(ptr->data<data)
				ptr=ptr->right;
			else
			{
				cout<<"\n Duplicate Entry not Allowed in tree.";
				return;
			}			
		}
		if(pre->data > data)
		{
			pre->left=temp;			
		}
		else
		{
			pre->right=temp;
		}
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
	tree->insertRec(8);
	tree->insertRec(5);
	tree->insertRec(3);
	tree->insert(6);
	tree->insert(12);
	tree->insert(11);
	tree->insert(13);	
	tree->nonRecInorder();		
}
