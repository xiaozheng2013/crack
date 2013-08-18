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

int find2(int a, int i, int* hash)
{
	int tmp1 = 1<<i;
	int tmp2 = 1<<(i+1);
	if( (a|tmp1) == a) 
	{
		hash[0]++;
		hash[hash[0]] = i;
		return 0;
	}

	else if( (a|tmp1) != a && (a|tmp2) == a)
	{
		return 1;
	}
			
}

int main()
{

	int a = 478;	
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

	//need to find the first zero from the right, and 1 on the left of zero
	hash[0] = 0;
	i = 0;
	while(find2(a,i,hash) == 0 && i<31)
	{
		i++;

	}
	if(i == 31) cout<<"error, there is no qualified largest previous number"<<endl;	
	int a_p = a | (1<<i);
	a_p = a_p ^ (1<<(i+1));
	rec = hash[0];
	for(int j=0;j<rec;j++)
	{
		a_p = a_p ^ (1<<hash[j+1]);
	}
		
	for(int j= i-1;j>i-1-rec;j--)
	{
		a_p = a_p | (1<<j);
	}
	cout<<" the previous number is "<<(bitset<32>) a_p<<endl;
		
		
	
	return 0;


}


