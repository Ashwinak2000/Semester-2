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
{public:
 node* top;
        stack()
		{
		 top=NULL;
		}	
		
		int pop()
		{int t;
		node* temp=top;
		top=top->next;
		t=temp->data;
		cout<<temp->data<<":deleted"<<endl;
		delete temp;
		return t;
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


class queue
{
 stack s,s1;
public:
       void enqueue(int value)
      { int t;
       while(s.top!=NULL)
       { 
        s1.push(s.pop());
       }
        s.push(value);
         while(s1.top!=NULL)
       {
        s.push(s1.pop());
       }
      }
       void display()
      {
        s.display();
      }
      void dequeue()
      {if(s.top!=NULL)
       cout<<"Deleting:"<<s.pop();
       else
       cout<<"Queue underflow"<<endl;
      }
};


int main()
{
 queue q;
 q.enqueue(1);
 q.display();
 q.enqueue(2);
 q.display();
 q.dequeue();
 q.display();
 q.dequeue();
 q.display();
 q.dequeue();
 q.display();
}
