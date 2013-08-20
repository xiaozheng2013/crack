#include<iostream>
#include<assert.h>

using namespace std;

int myfun(int n)
{
	assert(n>0);
	if(n == 1) return 1;
	if(n == 2) return 1;
	return myfun(n-1) + myfun(n-2);


}


int main()
{
	cout<<"please enter value of n"<<endl;
	int n;
	cin>>n;

	cout<<"the "<<n<<"-th fibonacci number is "<<myfun(n)<<endl;

	return 0;



}

