#include<iostream>
#include<assert.h>
#include<vector>
#include<string>
using namespace std;

void rec_pri(int l, int r, string par)
{
	if(l == 0 && r == 0) 
	{
		cout<<par<<endl;
		return;
	}

	assert(r != 0 && l>=0);
	
	if(l>0) 
	{
		string tmp = par;
		tmp.push_back('('); // char should use '' instead of ""
		rec_pri(l-1,r,tmp);
	}
	if(r>l)
	{
		string tmp = par;
		tmp.push_back(')');
		rec_pri(l,r-1,tmp);
	}
	return;
		
}

void Print_par(int i)
{
	string par;
	int l,r,count;
	l = r = i;
	rec_pri(l,r,par);
	return;
}

int main()
{
	
	cout<<"please enter value of n"<<endl;
	int n;
	cin>>n;
	
	
	Print_par(n);
	return 0;
}

