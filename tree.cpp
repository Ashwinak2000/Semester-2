#include<iostream>
using namespace std;

/*
Root: is the topmost node.
Leaves: are nodes with no children.
Intermediates: are parental nodes that are neither leaf nor root.
Path: is the way followed by the pointer to traverse 
      from point A to B in the tree.
Height: is the maximum path from the root. 
Binary Tree:When each tree has atmost 2 children
Level:It is the element group that descend from a level above
      ie:nodes that are at the same height.
Balanced Tree:
1)It is a tree in which has 
least possible height given the number of nodes.
2)It is the tree where the (n-1)th level has atmost 2 nodes.
3)Self balancing tree with each node having property that
the number of inner nodes in the right and left subtree differ 
atmost by 1 element. 
*/
class node
{
 public:
 	    int data;
 	    node* lnext;
 	    node* rnext;
 	    
 	    node()
 	    {
		 lnext=NULL;
		 rnext=NULL;	
		}
};

class tree
{
 	     node* root;
 public:  
 	    tree()
		 {
          root=NULL;
		 }
	
	void insert(int data)
	{//call insert1
	 insert1(root,data);
	}
		 
    void insert1(node* cur,int data)
		{ //current node is null or not
         node* temp=NULL;
		 if(cur==NULL)
		 { //if it is insert the node
          if(root!=NULL)
		  { cur=new node;
		 	cur->data=data;
		 	return;
		  }
          //reset root if the tree is empty
          else
          {cur=new node;
           root=cur;
           root->data=data;
          }
         }
		 else
		 {  //if current's data is more than the given data insert 
		 	if(cur->data>=data)
		 	{
             if(cur->lnext!=NULL)
		 	 insert1(cur->lnext,data);
             else
             {
              cur->lnext=new node;
              cur->lnext->data=data;	
			 }
			}
			else
			{
             if(cur->rnext!=NULL)
			 insert1(cur->rnext,data);
             else
             {
              cur->rnext=new node;
              cur->rnext->data=data;
             }
			}
		 }
		}
	
	node* search(int data)
	{//call search
	 return search1(data,root);
	}
	
	node* search1(int data,node* cur)
	{//see if the node is empty
	 if(cur!=NULL)	
	 { //if not check if its data is more than data
	   if(data>cur->data)
	   {//call search1 of the right link
	    search1(data,cur->rnext);
       }
	   else if(data=<cur->data)
	   {//call the left link
	    search1(data,cur->lnext);
       }
	   else
	   {//else display success
	   	cout<<"Element found";
	   	return cur;
	   }
	 }
	 else
	 {//display error
	  cout<<"Element not found";
	  return NULL;
     }
    }
    
    void display()
    {//call display2
     display2(root);
    }	
    void display2(node* cur)
    {//check if current is null then return
     if(cur==NULL)
     return;
	    //else display the left and right nodes.
     display2(cur->lnext);
     cout<<cur->data<<",";
     display2(cur->rnext);
    }

};


int main()
{
	tree t;
	t.insert(7);
    t.insert(10);
    t.insert(11);
    t.insert(4);
	cout<<t.search(7)->data<<endl;
    cout<<t.search(10)->data<<endl;
    cout<<t.search(11)->data<<endl;
    cout<<t.search(4)->data<<endl;
    t.display();
}
