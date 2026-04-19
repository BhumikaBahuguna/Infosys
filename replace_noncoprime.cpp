#include<bits/stdc++.h>
using namespace std;
vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
            while(ans.size()>1){
                long long top1=ans.back();
                long long top2=ans[ans.size()-2];
                if(std::gcd(top1,top2)==1)
                    break;
                ans.pop_back();
                ans.pop_back();
                long long new_lcm=std::lcm(top1,top2);
                ans.push_back(new_lcm);
            }
        }
        return ans;
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
    vector<int> result=replaceNonCoprimes(nums);
    cout<<"The resulting array after replacing non-coprimes is: ";
    for(int num : result){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}