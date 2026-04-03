#include<bits/stdc++.h>
using namespace std;
    bool checkPrimeFrequency(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int x:nums) m[x]++;
        vector<bool> isprime(n+1,true);
        isprime[0]=isprime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        for(auto &p:m){
            if(isprime[p.second])
                return true;
        }
        return false;
    }
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << checkPrimeFrequency(nums) << endl;
}