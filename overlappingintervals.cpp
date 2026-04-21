#include<bits/stdc++.h>
using namespace std;
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int count=1;
        int lastEnd = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastEnd) {
                count++;
                lastEnd = intervals[i][1];
            }
        }
        return n - count;
    }
int main(){
    int n;
    cin>>n;
    vector<vector<int>>intervals(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }
    cout<<eraseOverlapIntervals(intervals);
}