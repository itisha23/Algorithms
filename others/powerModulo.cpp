

int power(int a, int b) {
    
    int res = 1;
    while(b) {

        if(b & 1)
            res = res * a;

        b = b >>1;
        a = a * a;
    }
}

// For modulp

int p = 109+7

int power(int a, int b) {
    
    int res = 1;
    a = a % p;
    while(b) {

        if(b & 1)
            res = (res * a)%p;

        b = b >>1;
        a = (a * a)%p;
    }
}