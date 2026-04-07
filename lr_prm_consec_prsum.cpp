#include<bits/stdc++.h>
using namespace std;
    int largestPrime(int n) {
        vector<bool> isprime(n+1,true);
        isprime[0]=isprime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        vector<int>primes;
        for(int i=2;i<=n;i++){
            if(isprime[i]) primes.push_back(i);
        }
        int sum=0,ans=0;
        for(int p:primes){
            sum+=p;
            if(sum>n) break;
            if(isprime[sum]){
                ans=sum;
            }
        }
        return ans;
    }
int main(){
    int n;
    cin >> n;
    cout << largestPrime(n) << endl;
}