#include<iostream>
using namespace std;

//Create a class containing int data and a pointer of the class type
class node
{  
	public:
		// create data elements
		int data;
		//pointer which stores the address of the next node
		node* next;
		//intialize the ele
		node()
		{
			data=0;
			next=NULL;
		}
};

class Linkedlist
{
//Create Head,Tail and temporary nodes
node* Head;
node* Tail;
node* temp;
//intialize the nodes
	public: Linkedlist()
	        {
	        	Head=NULL;
	        	Tail=NULL;
	        	temp=NULL;
			}
			
//Define a function that inserts a new element 
void Insert(int data)
{  //create a new node
	temp=new node;
	temp->data=data;
	temp->next=NULL;
	//check if the list is empty
	if(Head==NULL)
	{
	//If yes, then set head to this node
	 Head=temp;	
	}
	
	else
	{ //if no, set tail to this node
		Tail->next=temp;
	}
	Tail=temp;
}
// Define a function that inserts at a position or else returns "Linked list does not have that many elements" 
void InsertAt(int pos,int data)
{
	//create a new node
	int count=0;
	temp=Head;
	node* temp1=Head->next;
	node* current=new node;
	//find number of elements in the list
	while(temp->next!=NULL)
	{
		count++;
		temp=temp->next;
	}
	count++;
   temp=Head;
   //see if the position is less than the number of elements
	if(count>=pos)
	{ //move the pointers so that they are around the given node
	 for(int i=1;i<pos-1;i++)
	 {
	 	temp=temp->next;
	 	temp1=temp1->next;
	 }	
	 // insert the new node
	 current->data=data;
	 temp->next=current;
	 current->next=temp1;
	}
	else
	{ //print error
		cout<<"Linked list does not have that many elements";
		return;
	}
}	
//Define a function that deletes the last element
void Delete()
{
	temp=Head;
	//move to the last element
	while(temp->next!=Tail)
	{
		temp=temp->next;
	}
	//check if the list is empty
	if(Head==NULL)
	{//display error if yes
	 cout<<"There are no elements left to delete";
	}
	
	else
	{ //delete the tail element if no
		temp->next=NULL;
		delete Tail;
		Tail=temp;
	}
}
//Define a function that deletes at a position or else returns "Linked list does not have that many elements" 
void DeleteAt(int pos)
{   
	int count=0;
	temp=Head;
	node* temp1=Head->next;
	node* current;
	//find the number of elements in the list
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	count++;
	temp=Head;
	//check if the positon is less than elements in the list
	if(count>=pos)
	{//move the pointers so that they surround the element to be deleted if yes
	 for(int i=1;i<pos-1;i++)
	 {
	 	temp=temp->next;
	 	temp1=temp1->next;
	 }	
	 // connect the neighbouring elements while deleting the needed node
	 current=temp1;
	 temp1=temp1->next;
	 current->next=NULL;
	 temp->next=temp1;
	 delete current;
	}
	else
	{
		cout<<"Linked list does not have that many elements";
		return;
	}
}


//Define a function to count the number of nodes
void countItems()
{ //traverse the list and count the number of elements
	int count=0;
	temp=Head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	cout<<"The number of elements:"<<count;
}
//Define a function to display the output
void display()
{ //traverse the list and display
	temp=Head;
	while(temp!=NULL)
	{
		if(temp!=Tail)
		cout<<temp->data<<"->";
		else
		{
			cout<<temp->data;
		}
	temp=temp->next;
	}	
	cout<<endl;
}  

};


int main()
{
Linkedlist L1;
L1.Insert(1);
L1.Insert(2);
L1.Insert(3);
L1.display();
L1.Delete();
L1.display();
L1.InsertAt(2,8);
L1.display();
L1.DeleteAt(2);
L1.display();
}

