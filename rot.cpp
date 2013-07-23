#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	int N;	
	cin>>N;
	int a[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			a[i][j] = rand() % 10 + 1;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<endl;
	for(int i=0;i<N/2;i++)
		for(int j=i;j<N-1-i;j++)
		{
			int t1;
			t1 = a[j][N-1-i]; 
			a[j][N-1-i] = a[i][j];

			int t2;
			t2 = a[N-1-i][N-1-j];
			a[N-1-i][N-1-j] = t1;
			
			t1 = a[N-1-j][i];
			a[N-1-j][i] = t2;
				
			a[i][j] = t1;
		}
		
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}


	
			
}

