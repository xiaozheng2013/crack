#include<iostream>
#include<stdio.h>

using namespace std;

void change(char* a, int m, int n)
{
	char tmp = a[m];
	a[m] = a[n];
	a[n] = tmp;
}

int main()
{
	char a[] = "i love you";
	cout<<a<<endl;

	int i=0;
	while(a[i] != '\0')
	{
		i++;
	}
	for(int j=i-1;j>=i/2;j--)
	{
		change(a,j,i-1-j);
	}

	cout<<a<<endl;
	return 0;

}


