#include<bits/stdc++.h>
using namespace std;
string gcdOfStrings(string str1, string str2) {
        int len1=str1.length();
        int len2=str2.length();
        for(int i=min(len1,len2);i>=1;i--){
            if(len1%i==0 && len2%i==0){
                string prefix=str1.substr(0,i);
                string build1="";
                for(int j=0;j<len1/i;j++)
                    build1+=prefix;
                string build2="";
                for(int j=0;j<len2/i;j++)
                    build2+=prefix;
                if(build1==str1 &&build2==str2)
                    return prefix;
        }
    }
    return "";
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