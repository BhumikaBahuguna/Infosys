#include<bits/stdc++.h>
using namespace std;
vector<bool> prime;
void seive(int n){
    for(int p=2;p*p<=n;p++){
        if(prime[p]){
            for(int i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
}
int distinctPrimeFactors(vector<int>& nums) {
int count=0;
prime.resize(1001,1);
seive(1000);
unordered_set<int> s;
vector<int>primes;
for(int p=2;p<=1000;p++){
    if(prime[p]){
        primes.push_back(p);
    }
}
for(int i=0;i<nums.size();i++){
    int n=nums[i];
    int j=0;
    while(n>1){
        while(n>1 && j<primes.size() && n%primes[j]==0){
            s.insert(primes[j]);
            n/=primes[j];
        }
        j++;
    }
}
return s.size();
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int result = distinctPrimeFactors(nums);
    cout << result << endl;
}
