#include<iostream>
using namespace std;

class stackArr
{
 int stack[10];
 int top;
 public: stackArr()
        {
         //Intialize the elements
         top=-1;
         for(int i=0;i<10;i++)
          stack[i]=0;
        }
       
        void pop()
        { //check if the stack is non empty
          if(top!=-1)
         {//delete the top most element
          cout<<"Deleting:"<<stack[top]<<endl;
          top--;
         }
         else
         cout<<"Stack underflow"<<endl;//else display error message
        }
       
        void push(int value)
        {
         int size=sizeof(stack)/sizeof(stack[0]);
         //check if stack is full(overflowing)
          if(top>size)
          cout<<"Stack Overflow"<<endl;//If yes display error
          else
         {
          top++;
          stack[top]=value; //Else add a new element
         }
        }

        void display()
         {
          for(int i=top;i>=0;i--)
          cout<<stack[i]<<" ";//Display stack elements
          cout<<endl;

         }
       
};


int main()
{
stackArr s;
s.push(1);
s.display();
s.push(2);
s.display();
s.pop();
s.display();
s.pop();
s.display();
s.pop();
s.display();
 
}
