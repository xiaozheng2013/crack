#include<string.h>
#include<iostream>
#include<map>

using namespace std;

int main()
{
	string a = "abcdefa";
	map<char,int> m;
	for(int i=0;i<a.size();i++)
	{
		if(m.count(a[i]) == 0) 
			m[a[i]] = 1;
		else 
		{
			cout<<a[i]<<" is not unique"<<endl;
			return 0;
		}
	}
	cout<<"Unique"<<endl;;
	return 0;
	

}

