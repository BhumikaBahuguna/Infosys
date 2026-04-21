#include<bits/stdc++.h>
using namespace std;
vector<int> maxMeetings(vector<int>&start , vector<int>&end){
    vector<tuple<int,int,int>>meetings;
    for(int i=0;i<start.size();i++){
        meetings.push_back({end[i],start[i],i+1});
    }
    sort(meetings.begin(),meetings.end());
    vector<int>ans;
    int lastend=-1;
    for(auto&m : meetings){
        int e=get<0>(m);
        int s=get<1>(m);
        int idx=get<2>(m);
        if(s>lastend){
            ans.push_back(idx);
            lastend=e;
        }
    }
    return ans;
} 
int main(){
    int n;
    cin>>n;
    vector<int>start(n),end(n);
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    vector<int>ans=maxMeetings(start,end);
    for(int i:ans){
        cout<<i<<" ";
    }
}