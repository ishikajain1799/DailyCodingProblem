#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int dp[100][100][100];

bool go(int l, int r, int k){
    if(k < 0){
        return 0;
    }
    if(l > r)   return 1;

    if(l == r){
        if(k >= 0)   return 1;
        return 0;
    }
    int &ans = dp[l][r][k];
    if(ans != -1){
        return ans;
    }

    if(s[l] == s[r]){
        return ans = go(l+1,r-1,k);
    }
    else{
        return ans = go(l,r-1,k-1) || go(l+1,r,k-1);
    }

}

int main(){
    memset(dp,-1,sizeof dp);
    
    cin>>s;
    n = s.size();
    int k;
    cin>>k;
    cout<<go(0,n-1,k);
}