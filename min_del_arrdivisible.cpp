#include<bits/stdc++.h>
using namespace std;
int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int target_gcd=numsDivide[0];
        for(int i=0;i<numsDivide.size();i++){
            target_gcd=std::gcd(target_gcd,numsDivide[i]);
            if(target_gcd==1)
                break;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>target_gcd)
                return -1;
            if(target_gcd % nums[i]==0)
                return i;
        }
    return -1;
    }
int main(){
    int n,m;
    cout<<"Enter the number of elements in the first array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the first array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Enter the number of elements in the second array: ";
    cin>>m;
    vector<int> numsDivide(m);
    cout<<"Enter the elements of the second array: ";
    for(int i=0;i<m;i++){
        cin>>numsDivide[i];
    }
    int result=minOperations(nums,numsDivide);
    if(result==-1){
        cout<<"It is not possible to make all elements of the second array divisible by any element of the first array."<<endl;
    }else{
        cout<<"The minimum number of operations required is: "<<result<<endl;
    }
    return 0;
}