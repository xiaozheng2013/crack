#include "head.h"

using namespace std;

int main(void)
{

	Stack t;
	for(int i=0;i<5;i++)
	{
		node *tmp = new node(i);
		t.push(tmp);
	}
		
	t.display();

	t.pop();
	t.display();

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

	return 0;

}


