#include <bits/stdc++.h>
using namespace std;
    bool isPrime(int x) {
        if(x <= 1) return false;
        if(x == 2) return true;
        if(x % 2 == 0) return false;
        for(int i = 3; i * i <= x; i += 2) {
            if(x % i == 0) return false;
        }
        return true;
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            for(int p = 2; p * p <= x; p++) {
                if(x % p == 0) {
                    mp[p].push_back(i);
                    while(x % p == 0) x /= p;
                }
            }
            if(x > 1) mp[x].push_back(i);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int i = q.front(); q.pop();
                if(i == n - 1) return steps;
                if(i + 1 < n && !visited[i+1]) {
                    visited[i+1] = true;
                    q.push(i+1);
                }
                if(i - 1 >= 0 && !visited[i-1]) {
                    visited[i-1] = true;
                    q.push(i-1);
                }
                if(isPrime(nums[i])) {
                    int p = nums[i];
                    for(int j : mp[p]) {
                        if(!visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                    mp[p].clear(); 
                }
            }
            steps++;
        }
        return -1;
    }
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << minJumps(nums) << endl;
}