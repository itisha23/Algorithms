class Solution {
public:
    
    void findHistogram(int arr[],int &ans,int n){
        
        stack<int>st;
        int temp=0,i,prev;
        for(i=0;i<n;i++){
            
            if(st.size()==0){
                st.push(i);
            }
            else{
                
                if(arr[i]>=arr[st.top()])
                    st.push(i);
                else{
                    while(st.size()!=0 && arr[i]<arr[st.top()]){
                    prev=st.top();
                    st.pop();
                    if(st.size()!=0){
                        temp=arr[prev]*(i-st.top()-1);
                    }
                    else{
                        temp=arr[prev]*i;
                    }
                  //  cout<<temp<<endl;
                    ans=max(ans,temp);
                    
                }
                    st.push(i);
                }
                
            }
        }
        
         while(st.size()!=0){
                  
                    prev=st.top();
                    // cout<<prev<<"***"<<endl;
                    st.pop();
                    if(st.size()!=0){
                        temp=arr[prev]*(i-st.top()-1);
                    }
                    else{
                        temp=arr[prev]*i;
                    }
                    cout<<temp<<endl;
                    ans=max(ans,temp);
                    
                }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m=matrix.size(),i,j,ans;
        if(m==0)
            return 0;
        int n=matrix[0].size();
        
        ans=0;
        int arr[n];
        i=0;
        for(j=0;j<n;j++){
            arr[j]=0;
           // ans=max(arr[j],ans);
        }
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                   if(matrix[i][j]=='1'){
                     //  cout<<i<<" "<<j<<endl;
                   arr[j]=arr[j]+(matrix[i][j]-'0');
                      
                }
                 else
                           arr[j]=0;
            }
         
                
            for(j=0;j<n;j++)
               cout<<arr[j]<<" ";
           cout<<endl;
            findHistogram(arr,ans,n);
           cout<<ans<<endl;
        }
        
        return ans;
    }
};
