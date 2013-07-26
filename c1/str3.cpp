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

int same( string& a,int k)
{
	for(int i =0;i<k;i++)
		if(a[i] == a[k])
			return 1;
	return 0;
}

int main()
{
	string a = "abababa";
	int k=0;
	int r=a.size();
	
	for(int i=0;i<r;i++)
	{
		if( k!=0&&same(a,k) == 1) 
		{
			a.erase(a.begin() + k);
		}
		else k++;
	}

	cout<<a<<endl;
	return 0;
}

