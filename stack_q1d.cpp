#include<iostream>
using namespace std;

void enqueue(int queue[],int& first,int& last,int value)
{
 if(first==last)
 cout<<"queue overflow"<<endl;
 else
 {
  last++;
  queue[last]=value;
 }
}
void dequeue(int queue[],int& first,int& last)
{
 if(first==last)
 cout<<"stack underflow";
 else
 {
  cout<<queue[first]<<":deleted"<<endl;
  first--;
 }
}

void display(int queue[],int& front,int& end)
{
 for(int i=front;i<end;i++)
 cout<<" "<<queue[i]<<" ";
 cout<<endl;
}
int main()
{
 int arr[10];
 int front=-1,end=-1;
 for(int i=0;i<10;i++)
 enqueue(arr,front,end,2*i+1);
 display(arr,front,end);
 for(int i=0;i<10;i++)
 {
 	dequeue(arr,front,end);
 }	
 
}
