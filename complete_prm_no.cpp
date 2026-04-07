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
    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.size();
        int prefix = 0;
        for(int i = 0; i < n; i++) {
            prefix = prefix * 10 + (s[i] - '0');
            if(!isPrime(prefix)) return false;
        }
        int suffix = num;
        int divisor = 1;
        for(int i = n - 1; i >= 0; i--) {
            int digit = s[i] - '0';
            suffix = num % (int)pow(10, n - i);
            if(!isPrime(suffix)) return false;
        }
        return true;
    }
int main(){
    int num;
    cin >> num;
    cout << (completePrime(num) ? "true" : "false") << endl;
}