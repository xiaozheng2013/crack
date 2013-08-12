#include "head.h"
#include<assert.h>

using namespace std;

void form_bal_tree(node* r, int* a, int i, int j)
{
	assert(i<=j);
	cout<<"love i = "<<i<<" j ="<<j<<endl;
	int k = (i+j)/2;
	r = new node(a[k]);
	cout<<"node a["<<k<<"] = "<<a[k]<<" is formed!"<<endl;
	
	if ( i < j) 
	{
		node* rl;
		node* rr;
	
		if(i == 0&&j==4) cout<<"here 1"<<endl<<endl;
		if(i<k)
		{
			cout<<"go to its left branch"<<endl;
			form_bal_tree(rl,a,i,k-1);
			r->lch = rl;
			rl->par = r;
	cout<<"r->val = "<<r->val<<"rl->val = "<<rl->val<<endl;
		}
		
		if(i == 0&&j==4) cout<<"here 2"<<endl<<endl;
		if(k<j)
		{
			cout<<"go to its right branch"<<endl;
			form_bal_tree(rr,a,k+1,j);
			r->rch = rr;
			rr->par = r;
		}
	}
		
	cout<<endl;
	return;

}

int main(void)
{
	int a[5];
	for(int i =0;i<5;i++)
		a[i] = i+1;

	node* r;	
	form_bal_tree(r,a,0,4);
	//r->inorder();
//	cout<<"right?"<<endl;
	tree* t = new tree(r,5);
	t->display(1);

/*
	for(int i=0;i<10;i++)
	{
		t.bin_add(i);
	}
*/
/* 4.1
	t.bin_add(5);
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

