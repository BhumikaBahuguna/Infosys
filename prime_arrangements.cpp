#include<bits/stdc++.h>
using namespace std;
    int numPrimeArrangements(int n) {
        const int MOD=1e9+7;
        vector<bool> isprime(n+1,true);
        isprime[0]=isprime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        int count=0;
        for(int i=1;i<=n;i++){
            if(isprime[i]) count++;
        }
        long long primefact=1,nonprimefact=1;
        for(int i=2;i<=count;i++)
            primefact=(primefact*i)%MOD;
        for(int i=2;i<=n-count;i++)
            nonprimefact=(nonprimefact*i)%MOD;
        return (primefact*nonprimefact)%MOD;
    }
int main(){
    int n;
    cin >> n;
    cout << numPrimeArrangements(n) << endl;
}