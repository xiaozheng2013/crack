#include<iostream>

using namespace std;

int main()
{
	
	cout<<"please enter value of n"<<endl;
	int n;
	cin>>n;

	int res = 0;
	int a[2];
	a[0] = a[1] = 1;
	if(n<3) 
	{
		cout<<"the "<<n<<"-th fibonacci number is 1"<<endl;
		return 0;
	}

	for(int i=3;i<n+1;i++)
	{
		res = a[0] + a[1];
		a[0] = a[1];
		a[1] = res;
	}

	cout<<"the "<<n<<"-th fibonacci number is "<<res<<endl;

	return 0;


		
		



}

