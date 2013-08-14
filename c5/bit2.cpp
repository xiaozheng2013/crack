#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	string input = "3.25";
	int pos = input.find(".");	
	// pos = input.find_first_of(".");
	string intPart = input.substr(0,pos);
	string decPart = input.substr(pos);
	int inP = atoi(intPart.c_str()); 
	double decP = atof(decPart.c_str());

	string intS = "";// don't forget initialization
	while(inP != 0)
	{
//		fastformat::write(intS,t,intS);
		//intS = "t" + intS;
		int t = inP % 2;
		stringstream sstm;
		sstm << t << intS;	
		intS = sstm.str();
		inP = inP>>1;
	}
		
	
	string decS = "";
	while(decP != 0)
	{
		if(decS.size() > 32) { cout<<"ERROR"<<endl; return 0;}
		decP = decP*2;
		int t;
		if(decP >= 1)
		{
			t = 1;
			decP--;
		}
		else t = 0;
		stringstream sstm;
		sstm << decS << t;
		decS = sstm.str();
		
	}	
	
cout<<"decS = "<<decS<<endl;
	string result;
	result = intS + "." + decS;
	cout<<"the result is "<<result<<endl;
	return 0;
	


}

