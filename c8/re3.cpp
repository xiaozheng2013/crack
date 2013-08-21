/* return all subsets of a set */
#include<iostream>
#include<vector>

using namespace std;

void gen_sub(vector<int>& ori, int i, int size, vector< vector<int> >&res)
{
	if(i > size)
	{
		return;
	}
	if(i == 0) 
	{
		vector<int> t1;
		vector<int> t2;
		t2.push_back(ori[i]);
		res.push_back(t1);
		res.push_back(t2);
	}
	else{
	int s = res.size();

	for(int j=0;j<s;j++)
	{
		vector<int> t1 = res[j];
		t1.push_back(ori[i]);
		res.push_back(t1);
	}
	}
	gen_sub(ori, i+1,size,res);
	return;

}

int main()
{
	vector<int> ori;
	for(int i=0;i<5;i++)
	{
		ori.push_back(i);
	}
	
	// now let's generate all subsets;
	vector< vector<int> > res;
	gen_sub( ori, 0, ori.size() -1,res); 


	cout<<"res.size = "<<res.size()<<endl;
	for(int i= 0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
		{
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}


