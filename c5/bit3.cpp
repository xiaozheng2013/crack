#include<iostream>
#include<bitset>
using namespace std;

int find(int a, int i, int* hash)
{
	int tmp1 = 1<<i;
	int tmp2 = 1<<(i+1);

	if( (a | tmp1) == a)
	{
		hash[0]++;
		hash[hash[0]] = i;
		if((a | tmp2) != a)
		{
			return 1;
		}
	}
	return 0;



}

int main()
{

	int a = 123;	
	cout<<" a ="<<(bitset<32>) a<<endl;
	
	int hash[33] = {};
	if(a == 0)
	{
		cout<<" the next number is 0, and the previous number is also 0"<<endl;
		return 0;
	}
	int i =0;
	while(find(a,i,hash) == 0)
	{
		i++;	
	}


	int a_n = a ^ (1<<i);
	a_n = a_n | (1<<(i+1));
	hash[0]--;
	int rec = hash[0];
	for(int i =1;i<rec+1;i++)
	{
		a_n = a_n ^ (1<<hash[i]);
	}
	
	for(int i =0;i<rec;i++)
	{
		a_n = a_n | (1<<i);
	}
		
	cout<<" the next number is "<<(bitset<32>) a_n<<endl;
	
	return 0;


}


