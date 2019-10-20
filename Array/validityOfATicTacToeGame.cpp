#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(i=a;i<b;i++)

bool checkWinner(char a, char arr[]){
    
    if(arr[0]== a && arr[1]== a && arr[2]== a)
        return true;
    if(arr[3]== a && arr[4]== a && arr[5]== a)
        return true;
    if(arr[6]== a && arr[7]== a && arr[8]== a)
        return true;
    if(arr[0]== a && arr[3]== a && arr[6]== a)
        return true;
    if(arr[1]== a && arr[4]== a && arr[7]== a)
        return true;
    if(arr[2]== a && arr[5]== a && arr[8]== a)
        return true;
    if(arr[0]== a && arr[4]== a && arr[8]== a)
        return true;
    if(arr[2]== a && arr[4]== a && arr[6]== a)
        return true;
    return false;
}

bool func(char arr[]){
    
    int countx=0;
    int counto=0,i;
    for(i=0;i<9;i++)
        arr[i]=='O'?counto++ : countx++;
        
    if(countx == counto || countx==counto+1){
            
            if(checkWinner('O',arr)){
                //cout<<"I m";
                if(checkWinner('X',arr))
                    return false;
                if(countx==counto+1)
                    return false;
            }
            
            else{
               // cout<<" I am";
                if(checkWinner('X',arr)){
                    if(countx==counto)
                    return false;
                }
            }
            
        return true;
    }
    return false;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        char arr[9];
        int i;
        f(i,0,9)
            cin>>arr[i];
        if(func(arr))
        cout<<"Valid\n";
        else
            cout<<"Invalid\n";
        
    }
}
