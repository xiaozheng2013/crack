#include<iostream>
#include<vector>
using namespace std;

int qualify(vector<int>& res,int c)
{
	int row = res.size();
	int col = c;
	for(int i=0;i<row;i++)
	{
		if ( col == res[i] || row - col == i - res[i] || row + col == i + res[i] )
		{
			return 0;
		}
	}
	return 1; 


}

void place_queue(vector<int> res, int p, vector< vector<int> >& all_res)
{
	if (p == 4) { all_res.push_back(res); return; }
	else{
		for(int i=0;i<4;i++)
		{
			if (qualify(res,i) == 1)
			{	
				vector<int> tmp = res;
				tmp.push_back(i);
				place_queue(tmp,p+1,all_res);
			}
		}
	}
	return;
}

int main()
{
	vector<int> res; //store result
	vector< vector<int> > all_res;
	place_queue(res,0,all_res);

	cout<<"there are "<<all_res.size()<<" many ways of setting queues"<<endl;
	for(int i=0;i<all_res.size();i++)
	{
		for(int j=0;j<all_res[i].size();j++)
		{
			cout<<all_res[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

