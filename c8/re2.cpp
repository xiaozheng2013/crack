#include<iostream>
#include<vector>
#include<string>

using namespace std;

void add_string(vector< string >& route, string& tmp)
{
	for(int i=0;i<route.size();i++)
	{
		route[i] = route[i] + tmp;
	}
	return;

}

void Print( vector< string >& route)
{
	for(int i=0;i<route.size();i++)
	{
		cout<<route[i]<<endl;
	}
	return;
}

void Print_all_paths(int i,int j, vector< string > path)
{
	if(j>0)
	{
		vector< string > route_r = path;
		if(path.size() == 0) 
		{
			string s1 = "right";
			route_r.push_back(s1);
		}
		else{
		string tmp = " right";
		add_string(route_r,tmp);
		}
		Print_all_paths(i,j-1,route_r);
	} 	
	if(i>0)
	{
		vector< string > route_d = path;
		if(path.size() == 0) 
		{
			string s1 = "down";
			route_d.push_back(s1);
		}
		else{
		string tmp = " down";
		add_string(route_d,tmp);
		}
		Print_all_paths(i-1,j,route_d);
	} 	

	if( i==0 && j == 0)
	{
		Print(path);
	}
	return;


}

int main()
{
	
	cout<<"please enter value of n"<<endl;
	int n;
	cin>>n;
	vector< string > path;
	Print_all_paths(n-2,n-2,path);
	return 0;
}

