#include<bits/stdc++.h>
using namespace std;
    long long primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = 2;
        for(int num : nums) {
            maxVal = max(maxVal, num);
        }
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i <= maxVal; i++){
            if(isPrime[i]){
                for(int j = i * i; j <= maxVal; j += i){
                    isPrime[j] = false;
                }
            }
        }
        vector<pair<int,int>> primes;
        for(int i = 0; i < n; i++){
            if(isPrime[nums[i]]){
                primes.push_back({i, nums[i]});
            }
        }
        long long ans = 0;
        multiset<int> window;
        int left = 0;    
        for(int right = 0; right < primes.size(); right++){
            window.insert(primes[right].second);         
            while(!window.empty() && (*window.rbegin() - *window.begin() > k)){
                window.erase(window.find(primes[left].second));
                left++;
            }         
            int cnt = right - left + 1;
            if(cnt >= 2){
                int prevIdx = (left == 0 ? -1 : primes[left-1].first);
                long long validStarts = primes[right-1].first - prevIdx;
                int nextPrimeIdx = (right + 1 < primes.size() ? primes[right+1].first : n);
                long long validEnds = nextPrimeIdx - primes[right].first;
                ans += validStarts * validEnds;
            }
        }
        return ans;
    }
int main(){
    int n, k;
    cin >> n; 
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cin >> k; 
    cout << primeSubarray(nums, k) << endl;
    return 0;
}