#include<iostream>
#include<bitset>

using namespace std;

int main()
{
	int a =555555555;
	cout<<"a = "<<(bitset<32>) a<<endl;
	int t1= 0xaaaaaaaa;
	int t2 = 0x55555555;

	int b = ((a & t1)>>1) | ((a & t2)<<1);
	cout<<"b = "<<(bitset<32>) b<<endl;



}

