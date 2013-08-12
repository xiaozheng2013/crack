#include<iostream>
#include<bitset>

using namespace std;

int main()
{
	int a,b;
	a = (1<<10);
	b = 1<<4 | 1<<2 | 1;
	int i,j;
	i = 2; j = 6;
	cout<<"a = "<<(bitset<11>) a<<endl;
	cout<<"b = "<<(bitset<5>) b<<endl;
	for(int k = 2;k<=6;k++)
	{
		int t = ~(1<<k);
		a = a & t;
	}
	b = b<<i;
	cout<<"a = "<<(bitset<11>) a<<endl;
	cout<<"b = "<<(bitset<7>) b<<endl;
	
	a = a | b;
	cout<<"a = "<<(bitset<11>) a<<endl;
	return 0;
	
}
		
	
