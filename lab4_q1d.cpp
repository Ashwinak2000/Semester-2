#include<iostream>
using namespace std;

class QueueArr
{
 int queue[10];
 int front;
 int tail;
 public: QueueArr()
        {
         //Intialize the elements
         tail=front=-1;
         for(int i=0;i<10;i++)
          queue[i]=0;
        }
       
        void dequeue()
        { //check if the queue is non empty
          if(front!=tail&&front>=0)
         {//delete the top most element
          cout<<"Deleting:"<<queue[front]<<endl;
          front++;
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
       
};


int main()
{
QueueArr s;
s.enqueue(1);
s.display();
s.enqueue(2);
s.display();
s.dequeue();
s.display();
s.dequeue();
s.display();
s.dequeue();
s.display();

}

