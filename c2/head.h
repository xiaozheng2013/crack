#include<iostream>
#include<map>
//#include<math>
//#include<algorithm>
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
		void nodup();
		node* n_th_last(int n);
		void del(node *r);
//		list* sum(list& a,list &b);
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

	//cout<<"here"<<endl;
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
			//cout<<"tmp_o ="<<tmp_o->val<<" tmp = "<<tmp->val<<endl;
			return;
		}
			
	}	
	return;	
}

void list::nodup()
{
	if(len <= 1) return;
	map<int,int> m;
	node* t0 = head;
	node* t1 = head;
	
	int i=0;
	int N = len;
	//cout<<"len = "<<len<<endl;
	while(i<N)	
	{
		if(m.count(t1->val) == 0)
		{
			m[t1->val] = 1;
			t0 = t1;
			t1 = t1->next;
		}
		else
		{
			t0->next = t1->next;
			t1 = t1->next;
			if(t1!=NULL&&t1->prev != NULL)
			{
//				if(t1->prev != NULL)
//				{
					t1->prev = t0;
//				}
			}
			len--;
		}
		//cout<<"i = "<<i<<" OK!"<<endl;
		i++;
	}
	return;
}

node* list::n_th_last(int n)
{
	assert(n<=len);
	node* t1;
	node* t2;
	t1 = head;
	t2 = head;
	for(int i=1;i<n;i++)
	{	
		t2 = t2->next;
	}
	while(t2->next != NULL)
	{
		t1 = t1->next;
		t2 = t2->next;
	}
	return t1;

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

//	cout<<"love"<<endl;
//	cout<<"len = "<<len<<endl;
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
						
void list::del(node* r)
{
		
		r->val = r->next->val;
		node* tmp = r->next;
		r->next = r->next->next;

		delete tmp;
}

list* sum(list& a, list& b)
{

// if one of thme is null list, just return the other list`
	if(a.len == 0) return &b;
	else if(b.len == 0) return &a;
	int n = max(a.len,b.len);
	

	node* s1;
	node* s2;
	s1 = a.head;
	s2 = b.head;


// check the sum digit by digit, node by node, if node of one list ends, just copy the node of the other list
	list *r = new list();
	
	int inc = 0;
	for(int i =0;i<n;i++)
	{
		if(s1 == NULL) 
		{
			node* tp = new node(s2->val + inc);
			r->add(tp,1),
			s2 = s2->next;
			inc = 0;
			continue;
		}
		else if(s2 == NULL)
		{
			node* tp = new node(s1->val + inc);
			r->add(tp,1),
			s1 = s1->next;
			inc = 0;
			continue;
		}
		int tmp = s1->val + s2->val;
		if( tmp + inc< 10)
		{
			node* tp = new node(tmp+inc);
			r->add(tp,1);		
			inc = 0;
		}
		else
		{
//			if(i == 2) cout<<"tmp = "<<tmp<<endl;
			tmp = (tmp+inc)%10;
//			if(i == 2) cout<<"tmp = "<<tmp<<endl;
			node* tp = new node(tmp);
			r->add(tp,1);		
			inc = 1;	
		}
		s1 = s1->next;
		s2 = s2->next;
		
	}
	return r;

}



