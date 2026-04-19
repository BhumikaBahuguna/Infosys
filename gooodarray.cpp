#include<bits/stdc++.h>
using namespace std;
bool isGoodArray(vector<int>& nums) {
        int current_gcd=nums[0];
        for(int i=1;i<nums.size();i++){
            if(current_gcd==1)
                return true;
            current_gcd=std::gcd(current_gcd,nums[i]);
        }
        return current_gcd==1;
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
    bool result=isGoodArray(nums);
    if(result){
        cout<<"The array is a good array."<<endl;
    }else{
        cout<<"The array is not a good array."<<endl;
    }
    return 0;
}