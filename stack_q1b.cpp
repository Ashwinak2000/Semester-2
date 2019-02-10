#include<iostream>
using namespace std; 

// A linked list (LL) node to store a queue entry 
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
		
		void pop()
		{
		node* temp=top;
		top=top->next;
		cout<<temp->data<<":deleted"<<endl;
		delete temp;
		}
		
		void push(int k)
		{
		 node* temp=new node;
		 temp->data=k;
		 if(top!=NULL)
		 {
		 temp->next=top;
		 top=temp;
		 }
		 else
		 {
		  top=temp;
		  top->next=NULL;
		 }
		}
		
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
