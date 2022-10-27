//Binary Search Tree - Tushar
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node* left;
	node* right;
	node(int el)
	{
		val=el;
		left=NULL;
		right=NULL;
	}
};
//traversal
void inorder(node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->val<<endl;
	inorder(root->right);
}
//search key recursively
node* search_recursive(node* root,int key)
{
	if(root==NULL || root->val==key )
		return root;
	else
		{
			if(root->val>key)
				return search_recursive(root->left,key);
			else
				return search_recursive(root->right,key);
		}
}
node* search_iteratively(node* root,int key)
{
	while(root!=NULL && root->val!=key)
		root=root->val>key?root->left:root->right;
	return root;
}
//find successor recursively
node* succ(node* root,node* p)
{
	if(root==NULL)
		return NULL;
	if(root->val<=p->val)
		return succ(root->right,p);
	else{
		node* left=succ(root->left,p);
		return left==NULL?root:left;
	}
}
node* pred(node* root,node* p)
{
	if(root==NULL)
		return NULL;
	if(root->val>=p->val)
		return succ(root->left,p);
	else{
		node* right=succ(root->right,p);
		return right==NULL?root:right;
	}
}
//insert
node* insert(node* root,int p)
{
	if(root==NULL){
		node* child=new node(p);
		return child;
	}
		
	if(root->val>p)
		root->left=insert(root->left,p);
	else if(root->val<p)
		root->right=insert(root->right,p);
	return root;
}
//delete node
node* deletenode(node* root,int key)
{
	if(root==NULL)
		return root;
	if(root->val>key)
		root->left=deletenode(root->left,key);
	else if(root->val<key)
		root->right=deletenode(root->right,key);
	else{
		if(root->left==NULL && root->right==NULL)
		{
			delete(root);
			return NULL;
		}
		else if(root->left==NULL || root->right==NULL)
		{
			node* child;
			if(root->left==NULL)
				child=root->right;
			else
				child=root->left;
			delete(root);
			return child;
			}
		else{
			node* temp=root->right;
			while(temp->left!=NULL)
				temp=temp->left;
			root->val=temp->val;
			root->right=deletenode(root->right,root->val);
			return root;
		}	
		}	
}
int main()
{
	node *root=new node(10);
	insert(root,5);
	insert(root,20);
	insert(root,15);
	insert(root,25);
	insert(root,30);
	node* rnew=deletenode(root,20);
	inorder(rnew);
}



