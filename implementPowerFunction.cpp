

int Solution::pow(int a, int y, int p) {
    if(a==0)
    return 0;
     long long int res = 1L, x;
     x=a;      // Initialize result
 
   //res=func(x,y,p);
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res=(res*x)%p;
 
        // y must be even now
        y = y/2; // y = y/2
        x=(x*x)%p;
    }
    if(res<0)
    res=(res+p)%p;
    return res;
}

