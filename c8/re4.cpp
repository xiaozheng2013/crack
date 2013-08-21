#include<iostream>
#include<vector>
#include<string>

using namespace std;

void add_char(vector<string>& res, char c)
{
	int s = res.size();
	int s1 = res[0].size();
	for(int j=0;j<s;j++)
	{

		for(int k=1;k<s1+1;k++)
		{
			string tmp(res[j]);
			tmp.insert(tmp.begin() + k,c);
			res.push_back(tmp);
		}

		res[j].insert(res[j].begin(), c);
	}
	return;
}


void perm(string& ori,int i,int size, vector<string>& res)
{
	if(i > size) return;
	if(i == 0) 
	{
		string tmp;
		tmp = tmp + ori[0];
		res.push_back(tmp);
	}
	else{
		char c = ori[i];
		add_char(res, c);
	}
	perm(ori,i+1,size,res);
	return;

}

int main()
{
	string ori = "iloveyou";
	vector<string> res;
	perm(ori,0,ori.size()-1,res);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}
