#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
int stack[10], n=10, top=-1;


void push(int val) {
   if(top>=n-1)
   cout<<"Stack Overflow"<<endl;
   else {
      top++;
      stack[top]=val;
   }
}
int pop() {
   if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else {
      top--;
      return stack[top+1];
   }
}

void display() {
   if(top>=0) {
      cout<<"Stack elements :";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}


int main() { 

    auto start = high_resolution_clock::now();


    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);
    display();
    for(int i=0;i<5;i++){
        pop();
    }
    display();
    push(4);
    push(30);
    push(3);
    push(1);
    display();

 


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << " "<<endl;
    cout << " "<<endl;
    cout << " "<<endl;
    cout << "Time taken by function: "
    << duration.count() << " microseconds" << endl;
   
    return 0;
    
}