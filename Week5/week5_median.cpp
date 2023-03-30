// Median Finding code

// This is coded by gathsara J.A.S.
// 210180L
// recursive quick sort

#include <iostream>
#include <iomanip>
using namespace std;
 
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}
int partition (int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
 
    for (int j = p; j <= r- 1; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap (&A[i], &A[j]);
        }
    }
    swap (&A[i + 1], &A[r]);
    return (i + 1);
}
 
void quickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p,r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
}


int main(){

    int b[] = {2,6,5,1,3,4};

   

    int sizeb = sizeof(b)/sizeof(int);

     cout<<" Input - [";
    printArr(b,sizeb);
    cout<<"]"<<endl;

    //cout<<sizeb;

    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"     Sorted                             Median"<<endl;
    cout<<" "<<endl;

    for(int i=1;i<=sizeb;i++){
    
    int a[i];

    

    for(int k=0;k<i;k++){
        a[k] = b[k];
    }

    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a,0,n-1);
    cout<<"[ ";
    for(int i=0;i<n-1;i++)
    cout<<a[i]<<", ";

    cout<<a[n-1]<<" ]";



    if(n%2 == 1){

        //cout<<"                     "<<a[(n-1)/2]<<endl;
        std::cout << std::right << std::setw(43-3*i) <<setprecision(2)<<float(a[(n-1)/2]+0.0) << std::endl;

    }
    else{

       // cout<<"                     "<<(a[n/2]+a[(n-2)/2])/2.0<<endl;
        std::cout << std::right << std::setw(43-3*i) <<setprecision(2)<< float((a[n/2]+a[(n-2)/2])/2.0+0.0) << std::endl;

    }

    }
    cout<<" "<<endl;
    cout<<" "<<endl;
    return 0;
}