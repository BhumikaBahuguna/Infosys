#include<bits/stdc++.h>
using namespace std;
int subarrayLCM(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            long long current_lcm=1;
            for(int j=i;j<n;j++){
                if(k%nums[j]!=0){
                    break;
                }
                if(j==i){
                    current_lcm=nums[i];
                }else{
                    current_lcm=std::lcm(current_lcm,nums[j]);
                }
                if(current_lcm>k){
                    break;
                }
                if(current_lcm==k){
                    count++;
                }
            }
        }
        return count;
    }
int main(){
    int n,k;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    int result=subarrayLCM(nums,k);
    cout<<"The number of subarrays with LCM equal to "<<k<<" is: "<<result<<endl;
    return 0;
}