#include<bits/stdc++.h>
using namespace std;
int nthUglyNumber(int n, int a, int b, int c) {
        long long A=a,B=b,C=c;
        long long lcm_ab=std::lcm(A,B);
        long long lcm_bc=std::lcm(B,C);
        long long lcm_ac=std::lcm(A,C);
        long long lcm_abc=std::lcm(lcm_ab,C);
        long long low=1;
        long long high=2e9;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long count=(mid/A)+(mid/B)+(mid/C)-(mid/lcm_ab)-(mid/lcm_bc)-(mid/lcm_ac)+(mid/lcm_abc);
            if(count>=n){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }   
        }
        return ans;
    }
int main(){
    int n,a,b,c;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Enter the values of a, b, and c: ";
    cin>>a>>b>>c;
    int result=nthUglyNumber(n,a,b,c);
    cout<<"The "<<n<<"-th ugly number is: "<<result<<endl;
    return 0;
}