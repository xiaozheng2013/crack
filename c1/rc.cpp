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
	int r[N],c[N];
	for(int i=0;i<N;i++)
	{
		r[i] = 0;
		c[i] = 0;
		for(int j=0;j<N;j++)
		{
			a[i][j] = rand() % 10;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(a[i][j] == 0)
			{
				r[i] = 1;
				c[j] = 1;
			}
		}
	
	for(int i =0;i<N;i++)
	{
		if ( r[i] == 1)
		{
			for(int j=0;j<N;j++)
			a[i][j] = 0;
		}
	}
	for(int j =0;j<N;j++)
	{
		if ( c[j] == 1)
		{
			for(int i=0;i<N;i++)
			a[i][j] = 0;
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

/*
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(r[i] == 0|| c[j] == 0)
			a[i][j] = 0;
	
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
*/

	return 0;

}

