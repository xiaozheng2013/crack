#include<iostream>
//#include<math>

using namespace std;

class node{
public:
	int val;
	node* par;
	node* lch;
	node* rch;

	node(){lch = rch = par = NULL; }
	node(int i){ val = i;lch = rch = par = NULL; }
	
	void inorder();
	void preorder();
	void postorder();
	
	node* first();
	node* next();


	int depth(int &isB);
	
};

class list_node{
public:
	node* val;
	list_node* next;
	list_node(node *tp) { val = tp; next = NULL;}
	
};

class list{
public:
	list_node* root;
	int size;
	list(){size = 0; root = NULL;}
	void add(list_node *ne);
	
	void display();
	
};
	
class tree{
public:
	node* root;
	int size;
	
	tree(){size = 0;}
	tree(node* r, int s)
	{
		root = r;
		size =s;
	}
	void bin_add(int i);
	void display(int i);
	int isBalanced();
};

void list::add(list_node* ne)
{
	ne->next = root;
	root = ne;
	size++;
	return;

}

void list::display()
{
	list_node* p = root;
	for(int i=0;i<size;i++)
	{
		cout<<p->val->val<<" ";
		p = p->next;
	}
	cout<<endl;


}

void node::inorder()
{
	if(lch != NULL) lch->inorder();
	cout<<val<<" ";
	if(rch != NULL) rch->inorder();

	return;
}
	
void node::preorder()
{
	cout<<val<<" ";
	if(lch != NULL) lch->preorder();
	if(rch != NULL) rch->preorder();

	return;
}

void node::postorder()
{
	if(lch != NULL) lch->postorder();
	if(rch != NULL) rch->postorder();
	cout<<val<<" ";

	return;
}

node* node::first()
{
	node* p = this;
	while(p->lch != NULL)
	{

		p = p->lch;
	}
	return p;
}

node* node::next()
{
	if(rch != NULL) return rch->first();
	else
	{
		node* p = this;
		while(p->par!=NULL && p->par->lch != p)
		{
			p = p->par;
		}
		if(p->par == NULL) 
		{
			cout<<"this node is already the last node of the tree, there is no node after it"<<endl;
			return NULL;
		}
		else
		{
			return p->par;
		}
	}
}

int node::depth(int &isB)
{
	int a,b;
	if(lch != NULL) a = lch->depth(isB);
	else a = 0;
	
	if(rch != NULL) b = rch->depth(isB);
	else b = 0;

	
	if( abs(a-b) > 1)
		isB++;

	return 1 + max(a,b); 

}

void tree::bin_add(int i)
{
	if(size ==0)
	{
		root = new node(i);
	
	}
	else
	{
		node* p0 = root;
		node* p1=root;	
		while(p1!=NULL)
		{
			if(i<p1->val )
			{
				p0 = p1;
				p1 = p1->lch;
			}
			else
			{
				p0 = p1;
				p1 = p1->rch;
			}
		}
		if(i<p0->val)
		{
			p0->lch = new node(i);
			p1 = p0->lch;
			p1->par = p0;
		}
		else
		{
			p0->rch = new node(i);
			p1 = p0->rch;
			p1->par = p0;
		} 
	}
	size = 1;
	return;

}

int tree::isBalanced()
{
	int isB = 0;
	int d = root->depth(isB);
	cout<<"the depth of the tree is "<<d-1<<endl;
	if(isB > 0) return 0;
	else return 1;

}

void tree::display( int i)
{
	if(size == 0) return;
	if(i == 1) // in-order
	{
		root->inorder();
	}
	else if(i == 2)
	{
		root->preorder();
	}
	else if(i == 3)
	{
		root->postorder();
	}
	return;

}

