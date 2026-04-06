#include<bits/stdc++.h>
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
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int,int>> dirs = {
            {0,1},{1,1},{1,0},{1,-1},
            {0,-1},{-1,-1},{-1,0},{-1,1}
        };
        unordered_map<int,int> freq;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(auto &d : dirs) {
                    int x = i, y = j;
                    int num = 0;
                    while(x >= 0 && x < m && y >= 0 && y < n) {
                        num = num * 10 + mat[x][y];
                        if(num > 10 && isPrime(num)) {
                            freq[num]++;
                        }
                        x += d.first;
                        y += d.second;
                    }
                }
            }
        }
        int ans = -1, maxFreq = 0;
        for(auto &p : freq) {
            int num = p.first, f = p.second;
            if(f > maxFreq || (f == maxFreq && num > ans)) {
                maxFreq = f;
                ans = num;
            }
        }
        return ans;
    }
int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    cout << mostFrequentPrime(mat) << endl;
}