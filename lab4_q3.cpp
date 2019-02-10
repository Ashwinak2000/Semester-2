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

// The queue, front stores the front node of LL and rear stores ths 
// last node of LL 
class Queue 
{ 
  node *front, *rear; 
 public:
        Queue()
        {
         front=NULL;
         rear=NULL;
		}
        
// The function to add a data k to q 
void enQueue(int k) 
{  
    node* temp=new node;
    temp->data=k;
	// If queue is empty, then new node is front and rear both 
	if (front == NULL) 
	{ 
	 front=temp; 
	 rear=temp; 
	} 
	else// Add the new node at the end of queue and change rear 
	{
	 rear->next=temp; 
	 rear=temp; 
    }
} 

// Function to remove a key from given queue q 
int deQueue() 
{ 
	// If queue is empty, return NULL. 
	if (front==NULL) 
	cout<<"Queue is empty"; 

	// Store previous front and move front one node ahead 
    node *temp=front; 
	front=front->next; 

	// If front becomes NULL, then change rear also as NULL 
	if (front==NULL) 
	rear=NULL; 
	cout<<temp->data<<":deleted"<<endl;
	return temp->data;
	 
} 

void display()
{
	node* temp=front;
	while(temp!=NULL)
	{
	 cout<<temp->data<<" ";
	 temp=temp->next;
	}
	cout<<endl;
}

int size()
{int size;
 node* temp=front;
 while(temp!=NULL)
 {
  size++;
  temp=temp->next;
 } 
 return size;
}
}; 
class stack
{
 Queue q;
 public: void push(int value)
        {
         q.enQueue(value);
         int size=q.size();
         for(int i=0;i<1;i++)
          q.enQueue(q.deQueue());
        }
         void display()
        {
         q.display();
        }
        void pop()
       {
         q.deQueue();
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
 s.push(4);
 s.display();
 s.pop();
 s.display();
 s.pop();
 s.display();
 s.pop();
 s.display();
 s.pop();
 s.display();
 s.pop();
 s.display();
}


