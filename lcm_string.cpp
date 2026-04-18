#include<bits/stdc++.h>
using namespace std;
string lcmstrings(string str1, string str2) {
        if(str1+str2!=str2+str1)
            return "";
        long long len1=str1.length();
        long long len2=str2.length();
        long long lcmlength=std::lcm(len1,len2);
        long long repeatcount=lcmlength/len1;
        string result="";
        result.reserve(lcmlength);
        for(long long i=0;i<repeatcount;i++)
            result+=str1;
        return result;
    }
int main(){
    string str1,str2;
    cout<<"Enter the first string: ";
    cin>>str1;
    cout<<"Enter the second string: ";
    cin>>str2;
    string result=lcmstrings(str1,str2);
    if(result!="")
        cout<<"The LCM of the two strings is: "<<result<<endl;
    else
        cout<<"There is no common multiple string."<<endl;
    return 0;
}