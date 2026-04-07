#include <bits/stdc++.h>
using namespace std;
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> result;
        vector<bool> isPrime(n+1, true);
        if(n >= 0) isPrime[0] = false;
        if(n >= 1) isPrime[1] = false;
        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for(int x = 2; x <= n; x++) {
            if(isPrime[x]) {
                int y = n - x;
                if(y >= x && isPrime[y]) {
                    result.push_back({x, y});
                }
            }
        }
        return result;
    }
int main(){
    int n;
    cin >> n;

    vector<vector<int>> pairs = findPrimePairs(n);

    cout << "[";
    for(int i = 0; i < pairs.size(); i++){
        cout << "[" << pairs[i][0] << "," << pairs[i][1] << "]";
        if(i != pairs.size() - 1) cout << ",";
    }
    cout << "]";
}