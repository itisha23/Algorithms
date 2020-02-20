#include<bits/stdc++.h>
using namespace std;

class kStacks {
    int *arr;
    int *next;
    int *top;

    int free;
    int k;
    int n;

    public:
    kStacks(int k, int n);
    void push(int stno, int ele);
    int pop(int stno);
    int getTop(int stno);
}

kStacks::kStacks(int k, int n){

    this->k = k;
    this->n = n;

    int *arr = new int[n];
    int *next = new int[n];

    int *top = new int[k];

    for(i=0;i<n;i++)
        next[i] = next[i+1];
    next[n-1] = -1;

    for(i=0; i<k i++)
        top[i] = -1;

    free =0;

}

void kStacks::push(int stno, int ele){
   

    if(free == -1){
        cout<<"stack overflow";
    }

    int ind = free;
    arr[ind] = ele;

    free = next[ind]; // so next[ind] stores what is the next index avalable for the free
    next[ind] = top[k]; // so here it denotes what is the next index available for a stack
    top[k] = ind;

}

int kStacks::pop(int stno) {
    if(free == 0)
        cout<<" Stack underflow\n";

    int ind = top[stno];
    int ele = arr[ind];

    next[ind] = free;
    free = ind;

    return ele;
}

int kStacks::getTop(int stno){
    if(top[stno] == -1){
        cout<<"Stack is empty\n";
    }
    return arr[top[stno]];
}

int main() {

    
    kStacks obj(3, 20);
    // perfoem 
    obj.push(0, 20);
    obj.pop(0);
    // and bla bla
}