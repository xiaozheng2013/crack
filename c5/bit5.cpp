#include<iostream>
#include<bitset>

using namespace std;

int main()
{
	int a = 31;
	int b = 14;
	int tp = a ^ b;
	int num=0;
	for(int i=0;i<32;i++)
	{
		if( (tp | (1<<i)) == tp)
		num++;
	}

	cout<<num<<" bit(s) need to be changed in order to convert a to b"<<endl; 



}



