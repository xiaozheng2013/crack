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
// Here I need to creat a filter, such that when my 'a' & with my filter, then only bits between i-th and j-th place set to zero.
	int t1 = (~0)<<(j+1);
	int t2 = ( 1<<(i+1) )- 1;
	
	cout<<"t2 = "<<(bitset<32>) t2<<endl;
	
	
	int t = t1 | t2;

	cout<<"before the operation"<<endl;
	cout<<"a = "<<(bitset<32>) a<<endl;
	cout<<"b = "<<(bitset<32>) b<<endl;
	cout<<"t = "<<(bitset<32>) t<<endl;
	
	cout<<"During the operation"<<endl;
	a = a & t;	
	b = b<<i;
	cout<<"a = "<<(bitset<32>) a<<endl;
	cout<<"b = "<<(bitset<32>) b<<endl;
	
	a = a | b;
	cout<<"after the operation"<<endl;
	cout<<"a = "<<(bitset<32>) a<<endl;
	return 0;
	
}
		
	
