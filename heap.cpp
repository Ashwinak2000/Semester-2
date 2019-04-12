#include<iostream>
using namespace std;


class heap
{
 public:
 int msize,csize,*bhArr;
 heap(int i)
{
bhArr= new int[i];
msize=i;
csize=0;
}//gives the left child
 int left(int i)
{
 return 2*i+1;
}
//gives the right child
 int right(int i)
{
 return 2*i;
}
//gives the parent
 int parent(int i)
{
 return (i-1)/2;
}
//finds the least element
 int getmin()
{
 return bhArr[0];
}
// inserts elements
 int insert(int value)
{int temp;
 //check if the array is not full
 if(csize!=msize)
 {int i=csize;
 bhArr[csize++]=value;
  //swap if the parent is less than the child or it is the first element
	 while(i!=0||(bhArr[parent(i)]<=bhArr[i]))
	 {
	  temp=bhArr[parent(i)];
	  bhArr[parent(i)]=bhArr[i];
	  bhArr[i]=temp;
          i=parent(i);
	 }
 }
 else
 cout<<"Heap overflow"<<endl;
}
 int getMin()
 { //return the root
  return bhArr[0];
 } 

int extractMin() 
{ 
    if (csize <= 0) 
        return -1; 
    if (csize == 1) 
    { 
        csize--; 
        return bhArr[0]; 
    } 
  
    // Store the minimum value, and remove it from heap 
    int root = bhArr[0]; 
    bhArr[0] = bhArr[csize-1]; 
    csize--; 
    Heapify(0); 
  
    return root; 
} 

void decreaseKey(int i, int new_val) 
{  int temp;
    bhArr[i] = new_val; 
  //decrease key and heapify
    while (i != 0 && bhArr[parent(i)] > bhArr[i]) 
    { 
       temp=bhArr[i];
       bhArr[i]=bhArr[parent(i)];
       bhArr[parent(i)]=temp;
       i = parent(i); 
    } 
} 
void deleteKey(int i) 
{ if(i<csize)
 {//decrease key of the needed element and extract min
    decreaseKey(i, INT_MIN); 
    extractMin(); 
 }
 else
 cout<<"No such element exists"<<endl;
}
void Heapify(int i)
{   int temp;
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
   //find the smallest element after i
    if (l < csize && bhArr[l] < bhArr[i]) 
        smallest = l; 
    if (r < csize && bhArr[r] < bhArr[smallest]) 
        smallest = r; 
    //if the smallest is not the same element swap the two and heapify again
    if (smallest != i) 
    { 
       temp= bhArr[i];
       bhArr[i]=bhArr[smallest];
       temp=bhArr[smallest]; 
        Heapify(smallest); 
    } 
}
};
int main()
{
heap h(19); 
h.insert(3); 
h.insert(2); 
h.deleteKey(12); 
h.insert(15); 
h.insert(5); 
h.insert(34); 
h.insert(4); 
cout << h.extractMin() << " "; 
cout << h.getMin() << " "; 
h.decreaseKey(2,1); 
cout << h.getMin();  
}
