#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a, b) for(i=a; i<b;i++)

int factorial[21];

int main() {

    string s;
    cin>>s;

    int k, n, i, rsum, j;

    cin>>k;

    factorial[0] = 1;
    for(i=1; i<=20; i++) {
        factorial[i] = i*factorial[i-1];
    }

    int hashi[26]={0};

    n = s.size();

    f(i,0,n) {
        hashi[s[i]-'a']++;
    }

    
    string ans =""; i=0;
    
    while(ans.size() != n){

        for(i=0; i<26; i++) {
            if(hashi[i]==0)
                continue;

            hashi[i]--;

            rsum = factorial[n-ans.size()-1];

            for(j=0;j<26;j++){
                rsum = rsum / (factorial[hashi[j]]);
            }


            if(k<=rsum){
                ans = ans + (char)(i + 'a');
                cout<<ans<<endl;
                break;
            }

            else{
                 k= k-rsum;
                hashi[i]++;
            }
        }
    }
}