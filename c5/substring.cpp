#include<iostream>
#include<bitset>

using namespace std;

int main()
{
	int a,b;
	a = b =0;
	a = 1<<10;
	a = ~a;
	b = 1<<4 | 1<<2 | 1 ;
	bitset<11> x(a);
	cout<<b<<endl;
	cout<<"a = "<<(bitset<11>) a<<" b = "<<
	( bitset<6> ) b<<endl;

	return 0;
	
}
