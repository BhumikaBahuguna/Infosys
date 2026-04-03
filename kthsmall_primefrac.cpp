#include<bits/stdc++.h>
using namespace std;
    typedef vector<double> V;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
         int n = arr.size();
        priority_queue<V, vector<V>, greater<V>> pq;
        for(int i = 0; i < n; i++) {
            pq.push(vector<double>{1.0 * arr[i] / arr[n-1], (double)i, (double)(n-1)});
        }
        int smallest = 1;
        while(smallest < k) {
            V vec = pq.top();
            pq.pop();
            int i = vec[1];
            int j = vec[2] - 1;
            pq.push(vector<double>{1.0 * arr[i] / arr[j], (double)i, (double)j});
            smallest++; 
        }
        V vec = pq.top();
        int i = vec[1];
        int j = vec[2];
        return {arr[i], arr[j]};
    }
int main(){
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> k;
    vector<int> result = kthSmallestPrimeFraction(arr, k);
    cout << result[0] << " " << result[1] << endl;
}