#include<iostream>
#include<vector>

using namespace std;
int N = 0;

void ways(int n,int k, int* a)
{
	if(n < 0) return;
	if(k == 3)  { N++; return; }
	int m = n;
	int tp = a[k];
	do
	{
		ways(n,k+1,a);
		n = n - a[k];

	}
	while(n >= 0);

	return;
			

} 

int main()
{
	int n = 25;
	int a[4];
	a[0] = 25;
	a[1] = 10;
	a[2] = 5;
	a[3] = 1;
	ways(n,0,a);
	cout<<"N = "<<N<<endl;


}

