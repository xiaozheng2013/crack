#include<iostream>
#include<fstream>
#include<assert.h>

using namespace std;

class node
{
	public:
		int val;
		node* next;
		node* prev;
		
		node(){};
		node(int v)
		{
			val = v;
			next = NULL;
			prev = NULL;
		}
};

class list
{
	public:
		node* head;
		int len;
	
		list() { head = NULL; len = 0; }
		void add(node* e, int ind);
		void display();
		void remove(int n);
};

void list::remove(int n)
{
	assert(len != 0);
	node* tmp = head;
	if (tmp->val == n)
	{
		if (head->prev != NULL)
		{
			tmp->next->prev = head->prev;
			head->prev->next = tmp->next;
		}
		head = tmp->next;
		len--;
	}

	cout<<"here"<<endl;
	node* tmp_o;
	for(int i=0;i<len-1;i++)
	{
		tmp_o = tmp;
		tmp = tmp->next;
		if(tmp == NULL) break;
		if(tmp->val != n) continue;
		if(tmp->val == n)
		{
			if(tmp->prev != NULL)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;	
				len--;
				return;
			}
			tmp_o->next = tmp->next;
			len--;
			cout<<"tmp_o ="<<tmp_o->val<<" tmp = "<<tmp->val<<endl;
			return;
		}
			
	}	
	return;	
}

void list::display()
{
	node *ind = head;
	for(int i=0;i<len;i++)	
	{
		cout<<ind->val<<" ";
		ind = ind->next;
	}
	cout<<endl;
	return;
}

void list::add(node* e, int ind)
{
			if(len == 0)
			{
				head = e;
				 
				if( ind == 3) 
				{		
					head->next = e;
					head->prev = e;
				}
			}
			else
			{

				node *end = head;
				int i=0;
				while (i<len-1)	
				{
					end = end->next;
					i++;
				}
					
				end->next = e;
				if(ind != 1)
				{
					e->prev = end;
					if(ind == 3)
					{
						e->next = head;
						head->prev = e;
					}
				}
			}
			len++;
		return;
}
						



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
		int tmp = rand() % 10 + 1;
		node* tp = new node(tmp);
		a.add(tp,1);
	}

	a.display();		
	a.remove(4);
cout<<"hao le"<<endl;
	a.display();		
	return 0;


}

