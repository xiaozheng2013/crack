#include<iostream>
#include<vector>
using namespace std;

enum Color{
	Red,Orange,Yellow,Green,Blue,Purple,White,Black,Grassy
};

bool Paint_fill(vector< vector<Color> >& S,int i,int j,Color oc,Color nc)
{
	if(i<0 || i>S.size() || j<0 || j>S[i].size() )
	{
		return false;	
	}

	if(S[i][j] == oc)
	{
		S[i][j] = nc;
		Paint_fill(S,i-1,j,oc,nc);
		Paint_fill(S,i,j-1,oc,nc);
		Paint_fill(S,i+1,j,oc,nc);
		Paint_fill(S,i,j+1,oc,nc);
	}
	return true;

}

bool Paint_fill(vector< vector<Color> >& S,int i,int j,Color nc)
{
	return Paint_fill(S,i,j,S[i][j],nc);
}

void show(vector< vector<Color> > S)
{
	for(int i=0;i<S.size();i++)
	{
		for(int j=0;j<S[i].size();j++)
		{
			cout<<S[i][j]<<" ";
		}
		cout<<endl;
	}

}

int main()
{
	vector< vector<Color> > Screen;
	for(int j=0;j<8;j++)
	{
		vector< Color > tmp;
		
		for(int i=0;i<8;i++)
		{
			tmp.push_back((Color)j);
		}
		Screen.push_back(tmp);
	}

	show(Screen);
	cout<<endl;

	Paint_fill(Screen,3,4,Grassy);

	show(Screen);
	return 0;

}


