#include<iostream>
using namespace std;
/* Complete Binary tree can be implemented using arrays.
insert
no element( plain insert)
size overflow(csize==msize)
insert at the end arr[csize]=value;
Check for Binary Heap rule 2(ie is parent greater than child then swap) 
(place it in a while loop)
*/
class node
{
 public:
 	    int data;
 	    node* lnext;
 	    node* rnext;
        node* parent;
 	    
 	    node()
 	    {
		 lnext=NULL;
		 rnext=NULL;
         parent=NULL;	
		}
};

class tree
{
 public:
 	node* root;  
    tree()
	 {
      root=NULL;
	 }
	
	void insert(int data)
	{
	 insert1(root,data);
	}
		 
    void insert1(node* cur,int data)
	{ //current node is null or not
	 if(cur==NULL)
	 { //if it is insert the node
      if(root!=NULL)
	  { cur=new node;
	 	cur->data=data;
	 	return;
	  }
      //reset root if the tree is empty
      else
      {root=new node;
       root->data=data;
       root->parent=NULL;
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
          cur->lnext->parent=cur;	
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
          cur->rnext->parent=cur;
         }
		}
	 }
	}
	
	node* search(int data)
	{
	 return search1(data,root);
	}
	
	node* search1(int data,node* cur)
	{
	 if(cur!=NULL)	
	 {
	   if(data>cur->data)
	   {
	    search1(data,cur->rnext);
       }
	   else if(data<cur->data)
	   {
	    search1(data,cur->lnext);
       }
	   else
	   {
	   	cout<<"Element found"<<endl;
	   	return cur;
	   }
	 }
	 else
	 {
	  cout<<"Element not found"<<endl;
	  return NULL;
     }
    }
    
    void display()
    {
     display2(root);
    }	
    void display2(node* cur)
    {
     if(cur==NULL)
     return;
     display2(cur->lnext);
     cout<<cur->data<<",";
     display2(cur->rnext);
    }

  node * find_min(node* cur) 
 { 
    node* current =cur; 
  
    // loop down to find the lnextmost leaf 
    while (current->lnext != NULL) 
           current=current->lnext; 
    return current; 
 } 

void replace_at_parent(node* cur,node* temp)
{
 node* rep=cur->parent;
 //Check if the node is the parents lnext or rnext
 if(rep->data>=cur->data)
 {//if its the lnext node replace the lnext node by temp
  cur->lnext=NULL;
  cur->rnext=NULL;
  rep->lnext=temp;
 }
 else
 {//if its the rnext node replace the rnext node by temp
  cur->lnext=NULL;
  cur->rnext=NULL;
  rep->rnext=temp;
 }
}

void delNode(int value)
{
 node* cur=search(value);
 if(cur!=NULL)
 {
 if(cur->lnext==NULL&&cur->rnext==NULL)
  {
   delnode(cur,0);
  }
 if(cur->lnext!=NULL&&cur->rnext!=NULL)
  {
   delnode(cur,2);
  }
 else
  {
   delnode(cur,1);
  }
 }
 else
 {
  cout<<"Element not found"<<endl;
  return;
 }
}
node* find_max(node* cur)
{
node* current =cur; 

// loop down to find the lnextmost leaf 
while (current->rnext != NULL) 
       current=current->lnext; 
return current; 
}

void delnode(node* temp,int child)
{if(temp!=root)
{

 if(child==0)
{
 replace_at_parent(temp,NULL);
 delete temp;
 temp=NULL;
}
 if(child==1)
{
 if(temp->lnext!=NULL)
 {
  replace_at_parent(temp,temp->lnext);
 }
 else
 {
  replace_at_parent(temp,temp->rnext);
 }
 delete temp;
 temp=NULL;
}
 if(child==2)
{
  node* temp1=find_min(temp->rnext);
  temp->data=temp1->data;
  delnode(temp->rnext,temp1->data); 
}
}
else
{
if(child==0)
{
 delete temp;
 root=temp=NULL;
}
 if(child==1)
{
 if(temp->lnext!=NULL)
 {
  temp=temp->lnext;
  delete temp->parent;
 }
 else
 {
  temp=temp->rnext;
  delete temp->parent;
 }
}
 if(child==2)
 {
  node* temp1=find_min(temp->rnext);
  temp->data=temp1->data;
  delnode(temp->rnext,temp1->data);
 }
}
}
void print2DUtil(node *root, int space)  
    {  
        // Base case  
        if (root == NULL)  
            return;  
        // Increase distance between levels  
        space += 5;  
        // Process rnext child first  
        print2DUtil(root->rnext, space);  
    
        // Print current node after space  
        // count  
        cout<<endl;  
        for (int i = 5; i < space; i++)  
            cout<<" ";  
        cout<<root->data<<"\n";  
        // Process lnext child  
        print2DUtil(root->lnext, space);  
    }  
  
    // Wrapper over print2DUtil()  
    void print2D()  
    {  
        cout << "******************************" << endl;
        // Pass initial space count as 0  
        print2DUtil(root, 0);  
        cout << "******************************" << endl;
        
    }
  int count(node* node)  
{  //if it is empty
    if(node == NULL)      
        return 0;  
  // if it is a leaf
    if(node->lnext == NULL && node->rnext == NULL)  
        return 1;         
    else //else add count of both subtrees
        return count(node->lnext)+count(node->rnext);  
}  
  int rangeSearch(int k1, int k2) 
 {
   print(root,k1,k2);
 }
 void print(node *root, int k1, int k2)  
{  
    // base case 
    if ( NULL == root )  
        return;  
      
    /*  If root->data is greater than k1,  
        then only we can get output keys  
        in lnext subtree */
    if ( k1 < root->data )  
        print(root->lnext, k1, k2);  
      
    /* if root's data lies in range,  
    then prints root's data */
    if ( k1 <= root->data && k2 >= root->data )  
        cout<<root->data<<" ";  
      
    /* If root->data is smaller than k2, 
        then only we can get output keys  
        in rnext subtree */
    if ( k2 > root->data )  
        print(root->rnext, k1, k2);  
}  
 int height(node *node)
{
 if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = height(node->lnext);  
        int rDepth = height(node->rnext);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
        return(lDepth + 1);  
        else 
        return(rDepth + 1);  
    }  
}
};

int main()
{
 tree t;
 for(int i=1;i<10;i++)
 t.insert(i);
 t.display();
 cout<<endl;
 cout<<t.count(t.root)<<endl;
t.rangeSearch(2,9);
}
