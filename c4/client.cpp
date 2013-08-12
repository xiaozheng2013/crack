#include "head.h"
//#include "list.h"
#include<vector>
#include<assert.h>

using namespace std;

node* common_anc(node* a,node* b)
{
	int d1,d2;
	d1 =d2 =0;
	d1 = a->depth();
	d2 = b->depth();
	cout<<"d1 d2 = "<<d1<<" "<<d2<<endl;
	node* p1 = a;
	node* p2 = b;
	if(d1>d2)
	{
		int d = d1 - d2;
		for(int i=0;i<d;i++)
		{
			p1=p1->par;
		}
	}
	else if(d2>d1)
	{
		int d = d2-d1;
		
		for(int i=0;i<d;i++)
		{
			p2=p2->par;
		}
	}
	while(p1!=p2)
	{
		p1=p1->par;
		p2 = p2->par;
	}
	if(p1 == p2) return p1;

}

void form_bal_tree(node*& r, int* a, int i, int j)
{
	assert(i<=j);
	//cout<<"love i = "<<i<<" j ="<<j<<endl;
	int k = (i+j)/2;
	r = new node(a[k]);
	//cout<<"node a["<<k<<"] = "<<a[k]<<" is formed!"<<endl;
	
	if ( i < j) 
	{
		node* rl;
		node* rr;
	
//		if(i == 0&&j==4) cout<<"here 1"<<endl<<endl;
		if(i<k)
		{
			//cout<<"go to its left branch"<<endl;
			form_bal_tree(rl,a,i,k-1);
			r->lch = rl;
			rl->par = r;
	//cout<<"r->val = "<<r->val<<"rl->val = "<<rl->val<<endl;
		}
		
//		if(i == 0&&j==4) cout<<"here 2"<<endl<<endl;
		if(k<j)
		{
			//cout<<"go to its right branch"<<endl;
			form_bal_tree(rr,a,k+1,j);
			r->rch = rr;
			rr->par = r;
		}
	}
		
	//cout<<endl;
	return;

}

int main(void)
{
// 4.3
	int n = 16;
	int a[n];
	for(int i =0;i<n;i++)
		a[i] = i+1;

	node* r;	
	form_bal_tree(r,a,0,n-1);
	//r->inorder();
//	cout<<"right?"<<endl;
	tree* t = new tree(r,n);
	t->display(1);
	t->isBalanced();
	cout<<endl;

// 4.4
// 4.5  
	node* p1;
	node* p2;
	node* t1 = t->root;
	//cout<<"t1->val = "<<t1->val<<endl;
	
	node* t2 = t1->next();
	//cout<<"t2->val = "<<t2->val<<endl;
	
	t1 = t2->next();
	//cout<<"t1->val = "<<t1->val<<endl;

	t2 = t1->next();
	//cout<<"t2->val = "<<t2->val<<endl;
	
	t1 = t2->next();
	//cout<<"t1->val = "<<t1->val<<endl;

	p1 = t1;cout<<"now p1 points to "<<p1->val<<endl;
	t2 = t1->next();
	//cout<<"t2->val = "<<t2->val<<endl;
	
	t1 = t2->next();
	//cout<<"t1->val = "<<t1->val<<endl;

	t2 = t1->next();
	//cout<<"t2->val = "<<t2->val<<endl;

	p2 = t2;cout<<"now p2 points to "<<p2->val<<endl;
	t1 = t2->next();
	//cout<<"t1->val = "<<t1->val<<endl;

	cout<<t1->next();

	p1 = common_anc(p1,p2); 
	cout<<"their common ancestor is "<<p1->val<<endl;
//	t2 = t1->next();
//	cout<<"t2->val = "<<t2->val<<endl;
	
/*
// 4.4 list of each level of nodes
	if(t->size > 0)
	{
		int isB;
		int d = t->root->depth(isB);
		vector< list > node_list(d);
		
		list_node* tmp = new list_node(t->root); 
		node_list[0].add(tmp);
		node_list[0].display();
		for(int i=0;i<d-1;i++)
		{
			int kk = node_list[i].size;
		
			list_node* init = node_list[i].root;
			for(int j =0;j<kk;j++)
			{
				if(init->val->lch != NULL)
				{
					list_node* tmp1 = new list_node(init->val->lch);
					node_list[i+1].add(tmp1);
				}
				
				if(init->val->rch != NULL)
				{
					list_node* tmp2 = new list_node(init->val->rch);
					node_list[i+1].add(tmp2);
				}
				init = init->next;
			}
			node_list[i+1].display();
		}

	}	
*/

/*
	for(int i=0;i<10;i++)
	{
		t.bin_add(i);
	}
*/
/* 4.1
	t.bin_add(n);
	t.bin_add(4);
	t.bin_add(6);
	t.bin_add(3);
	t.bin_add(7);

	t.display(1);
	cout<<endl;
	t.display(2);
	cout<<endl;
	t.display(3);
	cout<<endl;

	if(t.isBalanced() == 0) 
		cout<<"the tree is not balanced !"<<endl;
	else 
		cout<<"the tree is balanced !"<<endl;
*/
	return 0;

	
}

