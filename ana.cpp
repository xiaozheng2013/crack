#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

int main()
{

	string a = "iloveyou";
	string b= "youlovei";
	map<char,int> m;
	int n = a.size();
	if(a.size() != b.size()) 
	{
		cout<<"not anagram"<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(m.count(a[i]) == 0) m[a[i]] = 1;
		else m[a[i]]++;
	}
	cout<<"yes, an anagram"<<endl;
	return 0;

}

