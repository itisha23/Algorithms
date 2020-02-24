#include<bits/stdc++.h>
using namespace std;

class kQueue {
    private:
    int *arr;
    int *front;
    int *rear;
    int *next;

    int free;
    int k;
    int n;

    public:
    kQueue(int k, int n);
    void enqueue(int qno, int ele);
}

kQueue::kQueue(int k, int n) {
    this->k = k;
    this->n = 20;

    int *arr = new arr[n];
    int *next = new next[n];
    int *front = new front[k];
    int *rear = new rear[k];

    free = 0;

    for(int i=0; i<k; i++){
        front[i] = -1;
    }

    for(i=0; i<n-1; i++) {
        next[i] = i+1;
    }
    next[n-1] = -1;
}

void kQueue::enqueue(int qno, int ele) {

    if(free == -1){
        cout<<"Overflow\n";
        return;
    }

    arr[free] = ele;
    if(front[qno] == -1) { // first element
        front[qno]= free;

    } else {
        next[rear[qno]] = temp;
    }
    int temp = free;
    free = next[free] ;

    rear[qno] = temp;
    next[temp] = -1;

}


int kQueue::deque(int qno) {

    if(front[qno] == -1) {
        cout<<"Stack underflow";
        return;
    }

    int ind = front[qno];
    int ele = arr[ind];
    front[ind] = next[ind];

    next[free ]= ind;
    free = ind;

    return ele;
}

int main() {

    
    kQueue obj(3, 20);
    // perfoem 
    obj.push(0, 20);
    obj.pop(0);
    // and bla bla
}

