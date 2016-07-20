#include<iostream>
using namespace std;
//min Heap
class HeapTree
{
	private :
	int *arr;
	int size;
	int n;
	public: 
	HeapTree(int size)
	{
		this->size=size;
		arr=new int[this->size];
		n=1;		
	}
	void print()
	{
		for(int i=1;i<n;i++)
		{
			cout<< arr[i]  <<  " ";
		}
	}
	void insert(int item)
	{
		arr[n++]=item;
		restoreUp();
	}
	void restoreUp()
	{
		int k=arr[n-1];
		int i=n-1;
		int par=i/2;
		while(arr[par] > k && i > 0 )
		{
			arr[i]=arr[par];
			i=par;
			par=i/2;
		}
		arr[i]=k;
	}
	int remove()
	{
		int item=arr[1];
		arr[1]=arr[--n];
		restoreDown();
		return item;
	}
	void restoreDown()
	{
		int i=1;
		int k=arr[i];
		int lchild=2*i;
		int rchild=lchild+1;
		while(rchild<=n)
		{
			if(k <= arr[lchild] && k <= arr[rchild])
			{
				arr[i]=k;
				return;
			}
			if(arr[lchild] < arr[rchild])
			{
				arr[i]=arr[lchild];
				i=lchild;
			}
			else
			{
				arr[i]=arr[rchild];
				i=rchild;
			}
			lchild=2*i;
			rchild=lchild+1;
			
		}
		arr[i]=k;
	}
};
int main()
{
	HeapTree * heap=new HeapTree(10);
	heap->insert(8);
	heap->insert(9);
	heap->insert(5);
	heap->insert(99);
	cout<< heap->remove() <<endl;
	cout<< heap->remove() << endl;
	cout<< heap->remove() << endl;
	cout<< heap->remove() << endl;		
}
