#include<bits/stdc++.h>
using namespace std;
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        vector<bool> isprime(n,true);
        if(n>0) isprime[0]=false;
        if(n>1) isprime[1]=false;
        for(int i=2;i*i<n;i++){
            if(isprime[i]){
                for(int j=i*i;j<n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        long long sumA=0,sumB=0;
        for(int i=0;i<n;i++){
            if(isprime[i])
                sumA+=nums[i];
            else
                sumB+=nums[i];
        }
        return abs(sumA-sumB);
    }
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << splitArray(nums) << endl;
}