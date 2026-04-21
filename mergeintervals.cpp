#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;
        int i=0;
        if(n==0) return ans;
        sort(intervals.begin(),intervals.end());
        vector<int>tempinterval=intervals[0];
        for(auto it : intervals){
            if(it[0] <= tempinterval[1]){
                tempinterval[1]=max(it[1],tempinterval[1]);
            }else{
                ans.push_back(tempinterval);
                tempinterval=it;
            }
        }
        ans.push_back(tempinterval);
        return ans;
    }
int main(){
    int n;
    cin>>n;
    vector<vector<int>>intervals(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }
    vector<vector<int>>ans=merge(intervals);
    for(auto&v:ans){
        cout<<v[0]<<" "<<v[1]<<endl;
    }
}