#include<iostream>
using namespace std;
int fibonicSeries(int n)
{
	if(n==0 || n==1)
	{
	 	return 1;	
	}
	return fibonicSeries(n-1)+fibonicSeries(n-2);
}
int main()
{
	cout<<fibonicSeries(4);
}
