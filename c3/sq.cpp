#include "head.h"

using namespace std;

int main(void)
{

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


