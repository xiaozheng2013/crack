#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<assert.h>

using namespace std;

void sub_gen(vector<int>& ori, int t0,int i, int j, vector< int >&res)
{
	assert(i<=j);
	
	int t1 = t0;	
	t1 *= ori[i];
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

void subsets_product(vector<int>& ori, vector< int >&res)
{
//	vector<int> tmp;
	int tmp=1;
	sub_gen(ori,tmp,0,ori.size()-1,res);
	return;
}

int main()
{
	vector<int> a(5);
	for(int i=0;i<5;i++)
	{
		a[i] = (i+1)%2;
	}
	vector< int > res;
	subsets_product(a,res);
	
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;;
	}

	ofstream o1("value.txt");
	
	for(int i=0;i<res.size();i++)
	{
		o1<<res[i]<<endl;;
	}


	
	return 0;


}

