#include<bits/stdc++.h>
using namespace std;
    int diagonalPrime(vector<vector<int>>& nums) {
        int n=nums.size();
        int maxval=0;
        for(int i=0;i<n;i++){
            maxval=max(maxval,nums[i][i]);
            maxval=max(maxval,nums[i][n-i-1]);
        }
        vector<bool> isprime(maxval+1,true);
        if(maxval>=0) isprime[0]=false;
        if(maxval>=1) isprime[1]=false;
        for(int i=2;i*i<=maxval;i++){
            if(isprime[i]){
                for(int j=i*i;j<=maxval;j+=i){
                    isprime[j]=false;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(isprime[nums[i][i]])
                ans=max(ans,nums[i][i]);
            if(isprime[nums[i][n-i-1]])
                ans=max(ans,nums[i][n-i-1]);
        }
        return ans;
    }
    int main(){
        int n;
        cin >> n;
        vector<vector<int>> nums(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> nums[i][j];
            }
        }
        cout << diagonalPrime(nums) << endl;
    }