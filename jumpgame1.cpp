#include<bits/stdc++.h>
using namespace std;
        bool canJump(vector<int>& nums) {
        int maxidx=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxidx) return false;
            maxidx=max(maxidx,i+nums[i]);
        }
        return true;
    }
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<canJump(nums);
}