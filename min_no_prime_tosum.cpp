#include<bits/stdc++.h>
using namespace std;
vector<int>getprimes(int m){
    vector<int> primes;
    int limit = 10000;
    vector<bool> isprime(limit,true);
    isprime[0]=isprime[1]=false;
    for(int i=2;i<limit && primes.size()<m;i++){
        if(isprime[i]){
            primes.push_back(i);
        for(int j=i*i;j<limit;j+=i){
            isprime[j]=false;
        }
    }
}
return primes;
}
int minprimesum(int n,int m){
    vector<int> primes=getprimes(m);
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int p:primes){
        for(int i=p;i<=n;i++){
            if(dp[i-p]!=INT_MAX){
                dp[i]=min(dp[i],dp[i-p]+1);
            }
        }
    }
    return dp[n]==INT_MAX?-1:dp[n];
}
int main(){
    int n,m;
    cin >> n >> m;
    int result = minprimesum(n,m);
    cout << result << endl;
}