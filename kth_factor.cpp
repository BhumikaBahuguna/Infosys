#include<bits/stdc++.h>
using namespace std;
int kthFactor(int n, int k) {
        int i=1;
        for(; i*i<=n ; i++){
            if(n%i ==0){
                k--;
            if(k==0) return i;
        }
    }
    i--;
    if(i*i==n)
        i--;
    for(; i>=1;i--){
        if(n%i==0){
            k--;
            if(k==0) return n/i;
        }
    }
    return -1;
    }
int main(){
    int n,k;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the value of k: ";
    cin>>k;
    int result=kthFactor(n,k);
    if(result!=-1)
        cout<<"The "<<k<<"-th factor of "<<n<<" is: "<<result<<endl;
    else
        cout<<"There are less than "<<k<<" factors of "<<n<<"."<<endl;
    return 0;
}