#include<bits/stdc++.h>
using namespace std;
int findGCD(vector<int>& nums) {
        auto [min_it,max_it]=minmax_element(nums.begin(),nums.end());
        return std::gcd(*min_it,*max_it);
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