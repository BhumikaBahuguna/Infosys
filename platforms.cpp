#include<bits/stdc++.h>
using namespace std;
int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int n=Arrival.size();
        sort(Arrival.begin(),Arrival.end());
        sort(Departure.begin(),Departure.end());
        int i=0,j=0,cnt=0,maxcount=0;
        while(i<n){
            if(Arrival[i]<=Departure[j]){
                cnt++;
                i++;
            }else{
                cnt--;
                j++;
            }
        maxcount=max(maxcount,cnt);
        }
    return maxcount;
    }
int main(){
    int n;
    cin>>n;
    vector<int>Arrival(n),Departure(n);
    for(int i=0;i<n;i++){
        cin>>Arrival[i];
    }
    for(int i=0;i<n;i++){
        cin>>Departure[i];
    }
    cout<<findPlatform(Arrival,Departure);
}