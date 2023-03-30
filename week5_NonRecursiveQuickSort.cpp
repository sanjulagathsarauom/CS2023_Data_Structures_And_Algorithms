#include <iostream>
#include <algorithm>
#include <chrono>
#include <chrono>


using namespace std;
using namespace std::chrono;
  
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
/* This function is same in both iterative and recursive*/
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
  
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
  
/* A[] --> Array to be sorted, 
l --> Starting index, 
h --> Ending index */
void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
  
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);
  
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
  
// A utility function to print contents of arr
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
  
// Driver code
int main()
{
    cout << " "<<endl;
 cout << " "<<endl;
 cout << " "<<endl;
 cout << " "<<endl;
 int sz;
 cout<<"Enter the size of array::";
 cin>>sz;
 int arr[sz];
 for(int i=0;i<sz;i++)
 arr[i]=rand()%100; //Generate number between 0 to 99




 int arr_size = sizeof(arr) / sizeof(arr[0]);

 //cout << "Given array is \n";
 //printArr(arr, arr_size);

 auto start = high_resolution_clock::now();

 quickSortIterative(arr, 0, arr_size - 1);

 auto stop = high_resolution_clock::now();
 auto duration = duration_cast<microseconds>(stop - start);
 cout << " "<<endl;

 //cout << "\nSorted array is \n";
 //printArr(arr, arr_size);
 cout << " "<<endl;
 cout << " "<<endl;
 cout << "Time taken by function: "
 << duration.count() << " microseconds" << endl;
 cout << " "<<endl;
 cout << " "<<endl;
 cout << " "<<endl;
 cout << " "<<endl;





}