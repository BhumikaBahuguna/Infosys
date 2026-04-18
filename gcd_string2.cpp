#include<bits/stdc++.h>
using namespace std;
string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)
            return "";
        int gcdlength=std::gcd(str1.length(),str2.length());
        return str1.substr(0,gcdlength);
    }
int main(){
    string str1,str2;
    cout<<"Enter the first string: ";
    cin>>str1;
    cout<<"Enter the second string: ";
    cin>>str2;
    string result=gcdOfStrings(str1,str2);
    if(result!="")
        cout<<"The GCD of the two strings is: "<<result<<endl;
    else
        cout<<"There is no common divisor string."<<endl;
    return 0;
}