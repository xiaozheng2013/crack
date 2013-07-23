#include<iostream>
#include<assert.h>
#include<vector>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

int isSubstring(string& a, string& b)
{

	for(int i=0,n=b.size()-a.size();i<=n;i++)
	{
		int j=0;
		for(;j<a.size();j++)
		{
			if(b[i+j] != a[j]) break;
		}
		if (j==a.size()) return 1;
	}	

	return 0;
	

}


int main()
{
	string s1 = "waterbottle";
	string s2 = "waterbottle";
	
/*
	if(s1.size() != s2.size()) 
	{
		cout<<" not substring "<<endl;
		return 0;	
	}
*/
	assert(s1.size() == s2.size());
	assert(s1.size() != 0 && s2.size() != 0);
	if (s1 == s2) 
	{
		cout<<"here"<<endl;
		cout<<" is a substring"<<endl;
		return 0;
	}
	
		
	string str;
	str.append(s1);
	str.append(s1);
	cout<<str<<endl;
	
	if (isSubstring(s2,str)	== 0)
	cout<<" not substring "<<endl;

	else cout<<" is a substring"<<endl;
	return 0;

}

