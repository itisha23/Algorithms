//FOR SQUARE MATRICES
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        
        int m=A.size();
        int n=A[0].size(),i,j;
       for(i=0;i<m;i++)
        {
            for(j=i;j<n;j++)
                swap(A[i][j],A[j][i]);
        }
        return A;
    }
};

// FOR RECTNAGULAR MATRICES-NOT IN PLACE
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        
        int m=A.size();
        int n=A[0].size(),i,j,count=0;
    
        vector<vector<int> >vec;
        vec.resize(n);
        for(i=0;i<n;i++)
            vec[i].resize(m);
            
       // NOW M IS THE NUMBER OF COLUMNS ANN N IS THE NUMBER OF ROWS.
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                vec[count%n][count/n]=A[i][j];
                //IN SIMPLE YOU DO[Count/no of colum][count%number of columns].SEE ACCORDINGY WHAT WILL GIVE THE CORRECT ANSWER
                count++;
            }
        }
        return vec;
    }
};
