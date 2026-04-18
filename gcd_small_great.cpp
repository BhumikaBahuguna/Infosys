#include<bits/stdc++.h>
using namespace std;
int findGCD(vector<int>& nums) {
        int min=nums[0];
        int max=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min) min=nums[i];
            if(nums[i]>max) max=nums[i];
        }
        for(int i=min;i>=1;i--){
            if(min%i==0 && max%i==0)
                return i;
        }
        return 1;
    }
int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int result=findGCD(nums);
    cout<<"The GCD of the array is: "<<result<<endl;
    return 0;
}