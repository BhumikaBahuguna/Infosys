#include<bits/stdc++.h>
using namespace std;
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes={2,3,5,7,11,13,17,19};
        int result=0;
        for(int n=left;n<=right;n++){
            int setbits=__builtin_popcount(n);
            if(primes.count(setbits))
                result+=1;
        }
        return result;
    }
int main(){
    int left, right;
    cin >> left >> right;
    cout << countPrimeSetBits(left, right) << endl;
}