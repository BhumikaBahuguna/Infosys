#include<bits/stdc++.h>
using namespace std;

using ll = long long;

static const int MAX = 1005;
bool prime[MAX];

void seive(){
    fill(prime, prime + MAX, true);
    prime[0] = prime[1] = false;

    for(int i = 2; i * i < MAX; i++){
        if(prime[i]){
            for(int j = i * i; j < MAX; j += i){
                prime[j] = false;
            }
        }
    }
}

bool primesubopr(vector<int> &nums){
    seive();

    // collect primes
    vector<int> primes;
    for(int i = 2; i <= 1000; i++){
        if(prime[i]) primes.push_back(i);
    }

    int n = nums.size();
    vector<int> newnums(n, -1);

    newnums[n-1] = nums[n-1];

    for(int i = n-2; i >= 0; i--){
        if(nums[i] < newnums[i+1]){
            newnums[i] = nums[i];
            continue;
        }

        // try subtracting prime
        for(auto p : primes){
            if(p < nums[i] && nums[i] - p < newnums[i+1]){
                newnums[i] = nums[i] - p;
                break;
            }
        }

        if(newnums[i] == -1) return false;
    }

    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    bool result = primesubopr(nums);
    cout << (result ? "YES" : "NO") << endl;
}