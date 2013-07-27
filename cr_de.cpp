#include "head.h"

int main(void)
{
	cout<<"which kind of linked list do you want to creat? singly (1), doubly (2), or circled (3) ?"<<endl;
	int k,n;
	cin>>k;
	cout<<"with length ?"<<endl;
	cin>>n;
	
	list a;
	for(int i=0;i<n;i++)
	{
		int tmp = rand() % 10;
		node* tp = new node(tmp);
		a.add(tp,1);
	}

	cout<<"list a is"<<endl;
	a.display();		
	//a.nodup(); // 2.1
	//a.display();		
	//node* test = a.n_th_last(3);// 2.2
	//cout<<"the 3rd to last element in the list is "<<test->val<<endl; 
	list b;
	for(int i=0;i<n/2;i++)
	{
		int tmp = rand() % 10;
		node* tp = new node(tmp);
		b.add(tp,1);
	}

	cout<<"list b is"<<endl;
	b.display();	


	list* c;
	c = sum(a,b);
	cout<<"sum of a and b is"<<endl;
	c->display();

	return 0;


}

