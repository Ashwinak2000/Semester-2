#include<iostream>
using namespace std;

void swap(int a[],int i,int j)
{//Swaps the elements of the array
int temp = a[i];
a[i] = a[j];
a[j] = temp;
}


void quicksort(int arr[], int low, int high)
{
    int m = high;
    int l = low;
    int h = high;
    int pivot = arr[m];//Set last element as the pivot

    while(low<h || l<high)
    {
        while(arr[l]<pivot)
        l++;               //Move to element that is more than the pivot from the low end
        while(arr[h]>pivot)
        h--;               //Move to element that is less than the pivot from the high end

        if(l<=h){
            swap(arr,l,h);//swap these elements
            l++;
            h--;
        }
        else{//After partitioning check if high end pointer is above low
            if(low<h) 
                quicksort(arr, low, h);
            if(l<high)//After partitioning check if low end pointer is below high
                quicksort(arr,l,high);
            return;
        }
    }
}
void display(int arr[],int n)
{//Display the element
	for (int i=0;i<n;i++)
	cout<<" "<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
 int arr[] = {8,1,3,4,86,3,6,2,9};
 quicksort(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1);
 display(arr, (sizeof(arr)/sizeof(arr[0])));
 return 0;
}
