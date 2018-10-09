/* Method 1: By comparator function */
int myfunc(int a,int b)
{
   if(a%2==0 && b%2==1)
       return 1;
    return 0;
}

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& vec) {
        
        int n=vec.size(),i,j;
       sort(vec.begin(),vec.end(),myfunc);
        return vec;
    }
};

/*Method 2: By pointers*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& vec) {
        
        int n=vec.size(),i,j;
        i=0;j=n-1;
        while(i<j)
        {
            if(vec[i]%2==1)
            {
                while( j>i&& vec[j]%2==1)
                    j--;
                swap(vec[i],vec[j]);
                
            }
            i++;
        }
        return vec;
    }
};
