#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size() , m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0,r=0;
        while(l<m  && r<n){
            if(g[r]<=s[l]){
                r++;
            }
            l++;
        }
        return r;
    }
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>g(n),s(m);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    for(int i=0;i<m;i++){
        cin>>s[i];
    }
    cout<<findContentChildren(g,s);
}