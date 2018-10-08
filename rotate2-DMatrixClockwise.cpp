void Solution::rotate(vector<vector<int> > &vec) {
    
    
    int m=vec.size(),n=vec[0].size(),i,j,j1,j2;
    
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<n;j++)
        {
            swap(vec[i][j],vec[j][i]);
        }
    }
    
    j1=0;j2=n-1;
    while(j1<j2)
    {
        i=0;
        while(i<m)
        {
            swap(vec[i][j1],vec[i][j2]);
            i++;
        }
        
        j1++;
        j2--;
    }
    
    
   /* for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        cout<<vec[i][j]<<" ";
        cout<<endl;
    }*/
    
}
