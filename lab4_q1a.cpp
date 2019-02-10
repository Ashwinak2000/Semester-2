#include<iostream>
using namespace std; 

// A linked list (LL) node to store a stack entry 
class node 
{ 
    public:
	int data; 
	node *next; 
	node()
	{
		data=0;
		next=NULL;
	}
}; 
class stack
{
 node* top;
 public:
        stack()
		{
		 top=NULL;
		}	
		// remove the top most element
		void pop()
		{
		node* temp=top;
		top=top->next;
		cout<<temp->data<<":deleted"<<endl;
		delete temp;
		}
		// adds the new element 
		void push(int k)
		{
		 node* temp=new node;
		 temp->data=k;
			// check if the stack is empty
		 if(top!=NULL)
		 {// if not add new element as top
		 temp->next=top;
		 top=temp;
		 }
		 else
		 {//else add new element as temp
		  top=temp;
		  top->next=NULL;
		 }
		}
		//displays the stack elements
		void display()
		{
		 node* temp=top;
		 
		 while(temp!=NULL)
		 {
		  cout<<temp->data<<" ";
		  temp=temp->next;
		 }
		 cout<<endl;
		}
};

int main()
{
 stack s;
 s.push(1);
 s.display();
 s.push(2);
 s.display();
 s.push(3);
 s.display();
 s.pop();
 s.display();
}
