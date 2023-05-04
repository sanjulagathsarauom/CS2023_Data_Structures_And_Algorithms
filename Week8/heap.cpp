#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
    int largest = root; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * root + 1; // left = 2*i + 1
    int r = 2 * root + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != root) {
        swap(arr[root], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
  
   
}
//
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   
   for (int i = (n / 2) - 1; i >= 0; i--){
      //  cout<<i;
        heapify(arr, n, i);
   }
    
  
   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    int sz = 0;
    cout<<"Size of Array : ";
    cin>>sz;
    int heap_arr[sz];
    for(int i=0;i<sz;i++)
    heap_arr[i]=rand()%100; //Generate number between 0 to 99

   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}