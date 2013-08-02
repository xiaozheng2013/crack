#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;

class node{
public:	
	int val;
	node* next;

	node() {};
	node(int i){ val = i; next = NULL;}

};

class Stack{
public:
	node* top;
	int size;

	Stack(){ size = 0; top = NULL;}
	void push(node* t);
	int pop();
	void display();
};

class Stack_m: public Stack{
public:
	vector<int> min_a;
	Stack_m():Stack(){cout<<"weird"<<endl; }
	void push(node* t);
	int pop();
	int Min();

};

class Queue{
public:
	node* head;
	node* tail;
	int size;

	Queue(){head = NULL; tail = NULL; size = 0;}
	void enqueue(node *t);
	int dequeue();
	void display();
};

void Stack::push(node *t)
{
	t->next = top;
	top = t;
	size++;
}

void Stack_m::push(node *t)
{
		
	if(size == 0)
	{
		min_a.push_back(t->val);
	}
	else
		min_a.push_back( min(t->val,min_a[size-1]) );
	Stack::push(t);
	return;

}

int Stack::pop()
{
	assert(size>0);

	node* tp = top;
	top = top->next;
	int v = tp->val;
	delete tp;
	size--;
	cout<<"the value "<<v<<" is popped !"<<endl;
	return v;
}

int Stack_m::pop()
{
	min_a.erase(min_a.begin() + size - 1);	
	return Stack::pop();
}

int Stack_m::Min()
{
	return min_a[size-1];
}

void Stack::display()
{
	node* tmp = top;
	for(int i=0;i<size;i++)
	{
		cout<<tmp->val<<" ";
		tmp = tmp->next;
	}
	cout<<endl;
}

void Queue::enqueue(node* t)
{
	if(size == 0) 
	{
		head = tail = t;
	}
	else
	{
		tail->next = t;
		tail = t;
	}

	size++;
	return;
}

int Queue::dequeue()
{
	assert(size>0);
	node* tmp = head;
	int r = tmp->val;

	head = head->next;	
	if(size == 1) 
	{
		tail = NULL;
	}

	delete tmp;
	size--;
	cout<<"the value "<<r<<" is dequeued !"<<endl;
	return r;
}

void Queue::display()
{
	node* tmp = head;
	for(int i=0;i<size;i++)
	{
		cout<<tmp->val<<" ";
		tmp = tmp->next;
	}
	cout<<endl;
}

