#include "head.h"

using namespace std;

void Hanoi_move(Stack& t1,int n, Stack& t2, Stack&t3)
{
	assert(n>=1);
	if(n==1)
	{
		int tmp = t1.pop();
		node* tn = new node(tmp);
		t3.push(tn);
		return;
	}

	Hanoi_move(t1,n-1,t3,t2);
	Hanoi_move(t1,1,t2,t3);
	Hanoi_move(t2,n-1,t1,t3);
	return; 

}

int main(void)
{

//3.6 sort a stack with restricted functions	
	
	Stack t;
	int n = 10;
	for(int i = 0;i<n;i++)
	{
		node *tmp = new node(i);

		t.push(tmp);
	}
	t.display();

	sort(t,n);
	t.display();

/* 3.5

	S2Queue a;
	for(int i=0;i<10;i++)
	{
		node *tmp = new node(i);
		a.enqueue(tmp);
	}
	a.display();
	a.dequeue();
	a.display();
	a.dequeue();
	a.display();
	a.dequeue();
	a.display();
*/	




/*
	// 3.4 Tower of Hanoi
	Stack t1,t2,t3;
	int n = 10;
	for(int i = n;i>0;i--)
	{
		node *tmp = new node(i);

		t1.push(tmp);
	}

	cout<<"before moving, t1, t2, t3 are as follows"<<endl;
	t1.display();
	t2.display();
	t3.display();
	Hanoi_move(t1,n,t2,t3);
	
	cout<<"after moving, t1, t2, t3 are as follows"<<endl;
	t1.display();
	t2.display();
	t3.display();
*/
		
/*
* 3.3 SetOfStacks
	SetOfStacks t;
	for(int i=0;i<22;i++)
	{
		node *tmp = new node(i);
		t.push(tmp);
		t.display();
		//cout<<"now the min number is "<<t.Min()<<endl;
	}
		
	t.display();

	t.pop();
	t.display();
	for(int i=0;i<10;i++)
	t.popAt(1);

	t.display();
*/
/*
	Queue p;
	for(int i=0;i<5;i++)
	{
		node *tmp = new node(i);
		p.enqueue(tmp);
	}
		
	p.display();


	p.dequeue();
	p.display();
	p.dequeue();
	p.display();
	p.dequeue();
	p.display();
	p.dequeue();
	p.display();
	p.dequeue();
	p.display();

	p.dequeue();
	p.display();

*/
	return 0;

}


