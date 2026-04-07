#include <bits/stdc++.h>
using namespace std;
    bool isPrime(long long x) { 
        if(x <= 1) return false;
        if(x == 2) return true;
        if(x % 2 == 0) return false;
        for(long long i = 3; i * i <= x; i += 2) {
            if(x % i == 0) return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.size();   
        unordered_set<long long> primes; 
        for(int i = 0; i < n; i++) {
            long long num = 0;
            for(int j = i; j < n; j++) {
                num = num * 10 + (s[j] - '0');
                if(isPrime(num)) {
                    primes.insert(num);
                }
            }
        }
        vector<long long> v(primes.begin(), primes.end()); 
        sort(v.begin(), v.end(), greater<long long>());
        long long sum = 0;
        for(int i = 0; i < min(3, (int)v.size()); i++) {
            sum += v[i];
        }
        return sum;
    }
int main(){
    string s;
    cin >> s;
    cout << sumOfLargestPrimes(s) << endl;  
}
