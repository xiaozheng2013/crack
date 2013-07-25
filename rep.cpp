#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	char* ori = "i love you, honey!";
	cout<<ori<<endl;
	int len,i,sp,len_n,j;
	len = 0;
	i = 0;
	j = 0;
	sp = 0;
	while(ori[i] != '\0')
	{
		len++;	
		i++;
		if(ori[i] == ' ') sp++;
	}

	len_n = len + 2*sp;
	cout<<"len ="<<len<<" sp ="<<sp<<" len_n ="<<len_n<<endl;
	
	char* str_n = (char *)calloc(len_n + 1, sizeof(char));
	for(int i=0;i<len;i++)
	{
		if(ori[i] == ' ')
		{
			str_n[j] = '%'; 
			j++;
			str_n[j] = '2';
			j++;
			str_n[j] = '0';
		}
		else
			str_n[j] = ori[i];


		j++; 
			
	}	
	str_n[j] = '\0';

	cout<<str_n<<endl;
	return 0;
}

