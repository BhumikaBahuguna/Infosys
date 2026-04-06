#include<bits/stdc++.h>
using namespace std;
    int getprimefactorsum(int n){
        int sum=0;
        while(n%2==0){
            sum+=2;
            n/=2;
        }
        for(int i=3;i*i<=n;i+=2){
            while(n%i==0){
                sum+=i;
                n/=i;
            }
        }
        if (n>1) sum+=n;
        return sum;
    }
    int smallestValue(int n) {
        while(true){
            int sum=getprimefactorsum(n);
            if(sum==n) return n;
            n=sum;
        }
    }
int main(){
    int n;
    cin >> n;
    cout << smallestValue(n) << endl;
}
