int Solution::repeatedNumber(const vector<int> &vec) {
    
    int slow=0;
    int fast=0,n=vec.size();
    
    // finding any element of the cycle.
    while(1)
    {
        slow=vec[slow];
        fast=vec[vec[fast]];
        if(slow==fast)
           break;
    }
    
    // finding the first node of cycle.
    slow = 0;
    while(slow!=fast)
    {
        slow = vec[slow];
        fast = vec[fast];
    }

return slow;
    
}
