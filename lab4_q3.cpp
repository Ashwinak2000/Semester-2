#include<iostream>
using namespace std;

class QueueArr
{
 int queue[100];
 int front;
 int tail;
 public: QueueArr()
        {
         //Intialize the elements
         tail=front=-1;
         for(int i=0;i<100;i++)
          queue[i]=0;
        }
      
        int dequeue()
        { //check if the queue is non empty
          if(front!=tail&&front>=0)
         {//delete the top most element
          int t=queue[front];
          cout<<"Deleting:"<<queue[front]<<endl;
          front++;
          return t;
         }
         else
         cout<<"Queue underflow"<<endl;//else display error message
        }
      
        void enqueue(int value)
        {int size=sizeof(queue)/sizeof(queue[0]);
         if(front==-1)
         {
          front=tail=0;
          queue[front]=value;
         }
         if(tail<size)
         {
          queue[tail]=value;
          tail++;
         }
        }

        void display()
         {
          for(int i=front;i<tail;i++)
          cout<<queue[i]<<" ";//Display queue elements
          cout<<endl;
         }
        int size(int value)
       {
        if(value==0)
        return sizeof(queue)/sizeof(queue[0]);
        else
        return tail-front-1;
       }
      
       int is_empty()
       {
         if(front==tail&&front==-1)
          return 1;
         else
          return 0;
       }
};

class stack
{
 QueueArr q;
 public: void push(int value)
        {
         q.enqueue(value);
         int size=q.size(1);
         for(int i=0;i<size;i++)
          q.enqueue(q.dequeue());
        }
         void display()
        {
         q.display();
        }
        void pop()
       {
         q.dequeue();
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


