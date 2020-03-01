string multiplyStrings(string s1, string s2) {
   
   if(s1== "0" || s2=="0")
        return "0";
   int m = s1.size(), ind1, ind2,flag1=0, flag2=0;
   int n = s2.size();
   
   ind1=0;
   if(s1[0]=='-'){
       ind1=1;
       flag1=1;
   }
   ind2=0;
   if(s2[0]=='-') {
       ind2=1;
       flag2=1;
   }
   string ans="";
   
   int i,j,k,carry,x;
   
   vector<int>vec(m+n,0);
   k=0;
   for(i=s2.size()-1; i>=ind2;i--){
       carry=0;
       k=s2.size()-i-1;
       for(j=s1.size()-1;j>=ind1; j--){
            x = (s2[i]-'0') * (s1[j]-'0');ff
              vec[k]+=x+carry;
              carry = vec[k]/10;
              vec[k]= vec[k]%10;
              k++;
       }
       if(carry) {
        vec[k]+=carry;
       }
        
   }
   

    i=vec.size()-1;
    while(vec[i]==0){
        i--;
    }
   for( ;i>=0;i--){
       
       ans = ans+(char)(vec[i]+'0');
       
   }
  
   if((flag1 == 0 && flag2==1) ||(flag1==1 && flag2==0)){
       ans = "-"+ans;
   }
   return ans;
}
