#include<bits/stdc++.h>
using namespace std;
vector<bool> prime;
void seive(){
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=104;i++){
        if(prime[i]){
            for(int j=i*i;j<=104;j+=i){
                prime[j]=false;
            }
        }
    }
}
int maxprimediff(vector<int> & nums){
    prime=vector<bool>(105,true);
    seive();
    int ans=0,firstid=-1;
    for(int i=0;i<nums.size();i++){
        if(prime[nums[i]]){
            if(firstid==-1){
                firstid=i;
            }
            else{
                ans=max(ans,i-firstid);
            }
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int result = maxprimediff(nums);
    cout << result << endl;
}