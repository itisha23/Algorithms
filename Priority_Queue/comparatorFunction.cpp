struct compare {

    bool operator()(pair<int, string>p1, pair<int, string>p2) {
        return p1.first > p2.first;
    }
    
}; 

//comaprator functions in C++ are easy.
// You can just define this opertaor function n strcut and use the name of struct everywhere
// how do we pass functions pointers in C++

bool compare(int a, int b) {
    return a<b;
}

void func(int a, int b, bool(&compare)(int a, int b)) {

    if(a > b) {
        if(compare(a, b)){
            cout<<"Yes"
        }
    }
}

// How do we call a func now
 func(a, b, compare);