#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;
int threshold = 10;

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
	vector<int> min;
	
	Stack(){ size = 0; top = NULL;}
	void push(node* t);
	int pop();
	void display();
	int Min()
	{
		return min[size-1];
	}
	
};

class SetOfStacks{
public:
	vector< Stack > s_list;
	int num; // number of stacks;
	int size;
	
	SetOfStacks() { size = 0; num = 0;}
	void push(node* t);
	int pop();
	int popAt(int ind);

	void display();

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
	int m_t;
	if (size == 1) 
	{
		m_t = t->val;
		min.push_back(m_t);
		return;
	}
	
	m_t = min[size - 2]; 	
	if ( t->val < m_t)
	{
		//cout<<"here t->val = "<<t->val<<" m_t = "<<m_t<<endl;
		min.push_back(t->val);
	} 
	else
	{
//		cout<<"here t->val = "<<t->val<<" m_t = "<<m_t<<endl;
		min.push_back(m_t);
	}
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
	min.erase(min.begin() + size);
	return v;
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

void SetOfStacks::push(node* t)
{
	if(num == 0 || s_list[num-1].size == threshold)
	{
		Stack* a = new Stack();
		a->push(t);
		s_list.push_back(*a);
		num++;
		}			
	else
	{
		s_list[num - 1].push(t);
	}	
	size++;
	return;
}

int SetOfStacks::pop()
{
	assert(size > 0);
	int tmp;
	if(s_list[num -1].size == 1)
	{
		tmp = s_list[num-1].pop();
		s_list.erase(s_list.begin() + num-1);
		num--;
	}
	else
	{
		tmp = s_list[num-1].pop();
		
	}		
	size--;
	return tmp; 
}

int SetOfStacks::popAt(int ind)
{
	assert( ind<num && ind>=0);
	int tmp = s_list[ind].pop();
	if(s_list[ind].size == 0)
	{
		s_list.erase(s_list.begin() + ind);
	}
	size--;
	return tmp;

}

void SetOfStacks::display()
{
	for(int i=0;i<num;i++)
	{
		s_list[i].display();
	}
	cout<<" ";
	return;

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

