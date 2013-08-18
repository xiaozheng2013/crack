#include<iostream>
#include<math.h>
#include<vector>
#include<bitset>

using namespace std;

int show_bit(int a, int col) 
{
	return ( (a | (1<<col)) == a);

}

int find_missing(vector<int>& a, int col)
{
	if(a.size() == 0) return 0;
	vector<int> even;
	vector<int> odd;
	for(int i=0;i<a.size();i++)
	{
		if(show_bit(a[i],col) == 0) even.push_back(a[i]);
		else odd.push_back(a[i]);
	}
	
	cout<<"col = "<<col<<" no. of odd = "<<odd.size()<<" no. of even = "<<even.size()<<endl;
	if(even.size() <= odd.size())
	{
		return ( find_missing(even,col+1) << 1 ) | 0;
	}
	else
		return ( find_missing(odd,col+1) << 1 ) | 1;

		

}

int main()
{
	cout<<"please input n"<<endl;
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		a[i] = i;
	}
	a[n-1] = n;
//	N = log2(n);	
	int res = find_missing(a,0);
	cout<<"the missing integer is "<<( bitset<32> ) res<<endl;

	return 0;

}

