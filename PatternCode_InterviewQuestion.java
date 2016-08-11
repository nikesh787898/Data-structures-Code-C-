import java.io.*;
class A
{
	public static void main(String argsp[])
	{
		Console con=System.console();
		int n=Integer.parseInt(con.readLine());
		int MAX_COL=n;
		for(int i=2;i<=n;i++)
			MAX_COL+=i;
		System.out.println(MAX_COL);
		int MAX_SPACE=n+1;
		int prevS=MAX_COL-MAX_SPACE;
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			for(int j=1;j<MAX_COL;j++)
				System.out.print(" ");
			else
			{
				for(int j=1;j<prevS;j++)
					System.out.print(" ");
					MAX_SPACE--;
					prevS=prevS-MAX_SPACE;
			}
			if(i==1)
			{
				System.out.print("X");
			}
			else
			{
				int ss=n-i+2;
				
				for(int j=n-i+2;j<=n;j++)
				{
					System.out.print("X");
					for(int k=0;k<ss;k++)
						System.out.print("_");
					ss++;
					
					
				}
				System.out.print("X");	
			}
			System.out.println();
		}
	}
}
