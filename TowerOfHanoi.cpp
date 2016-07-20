#include<iostream>
using namespace std;
void solveTowerOfHanoi(int nOfD,char A,char B,char C)
{
	if(nOfD==1)
	{
		cout<<endl<<"Move "<< nOfD << "Disk To "<<A << "To " << C;
                return;
	}
	solveTowerOfHanoi(nOfD-1,A,C,B);
	cout<<endl<<"Move Disk No "<< nOfD << A << "To "<<C;
	solveTowerOfHanoi(nOfD-1,C,A,B);  
}
int main()
{
	solveTowerOfHanoi(3,'A','B','C');
}
