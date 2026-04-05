#include<bits/stdc++.h>
using namespace std;
vector<int>closestprime(int left,int right){
    vector<bool> isprime(right+1,true);
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<=right;i++){
        if(isprime[i]){
            for(int j=i*i;j<=right;j+=i){
                isprime[j]=false;
            }
        }
    }
    vector<int> primes;
    for(int i=left;i<=right;i++){
        if(isprime[i]){
            primes.push_back(i);
        }
    }
    int a=0,b=INT_MAX;
    for(int i=1;i<primes.size();i++){
        if((b-a)>(primes[i]-primes[i-1])){
            b=primes[i];
            a=primes[i-1];
        }
    }
    vector<int> ans;
    if(a==0) ans={-1,-1};
    else ans={a,b};
    return ans;
}
int main(){
    int left, right;
    cin >> left >> right;
    vector<int> result = closestprime(left, right);
    cout << result[0] << " " << result[1] << endl;
}