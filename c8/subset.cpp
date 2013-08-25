#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<assert.h>

using namespace std;

void sub_gen(vector<int>& ori, vector<int> t0,int i, int j, vector< vector<int> >&res)
{
	assert(i<=j);
	
	vector<int> t1 = t0;	
	t1.push_back(ori[i]);
	if(i == j)
	{
		res.push_back(t0);
		res.push_back(t1);
	}
	else
	{
		sub_gen(ori,t0,i+1,j,res);
		sub_gen(ori,t1,i+1,j,res);
	}
	return;

}

void subsets(vector<int>& ori, vector< vector<int> >&res)
{
	vector<int> tmp;
	sub_gen(ori,tmp,0,ori.size()-1,res);
	return;
}

int main()
{
	vector<int> a(10);
	for(int i=0;i<10;i++)
	{
		a[i] = i+1;
	}
	vector< vector<int> > res;
	subsets(a,res);
	
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<"V"<<res[i][j];
		cout<<endl;
	}

	ofstream o1("head.txt");
	
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			o1<<"V"<<res[i][j];
		o1<<endl;
	}


	
	return 0;


}

