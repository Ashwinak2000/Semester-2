#include<iostream>
using namespace std;

class stackArr
{ public:
 int stack[10];
 int top;
 stackArr()
        {
         //Intialize the elements
         top=-1;
         for(int i=0;i<10;i++)
          stack[i]=0;
        }
       
        int pop()
        { //check if the stack is non empty
          int t;
          if(top>-1)
         {//delete the top most element and return it
          t=stack[top];
          //cout<<"Deleting:"<<stack[top]<<endl;
          top--;
          return t;
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

class queue
{
 stackArr s,s1;
public:
       void enqueue(int value)
      { int t;
       while(s.top!=-1)
       { 
        s1.push(s.pop());
       }
        s.push(value);
         while(s1.top!=-1)
       {
        s.push(s1.pop());
       }
      }
       void display()
      {
        s.display();
      }
      void dequeue()
      {if(s.top!=-1)
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
