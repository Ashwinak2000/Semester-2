#include<iostream>
using namespace std;

void push(int stack[],int& top,int value)
{
 int size=10;
 if(top>=size)
 cout<<"stack overflow"<<endl;
 else
 {
  top++;
  stack[top]=value;
 }
}
void pop(int stack[],int& top)
{
 if(top==-1)
 cout<<"stack underflow";
 else
 {
  cout<<stack[top]<<":deleted"<<endl;
  top--;
 }
}

void display(int stack[],int& top)
{
 for(int i=top;i>=0;i--)
 cout<<" "<<stack[i]<<" ";
 cout<<endl;
}
int main()
{
 int arr[10];
 int top=-1;
 for(int i=0;i<10;i++)
 push(arr,top,2*i+1);
 display(arr,top);
 for(int i=0;i<10;i++)
 {
 	pop(arr,top);
 }	
 
}
