#include<bits/stdc++.h>
using namespace std;
bool canMeasureWater(int x, int y, int target) {
        if(target > x+y) return false;
        if(target == 0)
            return true;
        return target % std::gcd(x,y)==0;
    }
int main(){
    int x,y,target;
    cout<<"Enter the capacity of the first jug: ";
    cin>>x;
    cout<<"Enter the capacity of the second jug: ";
    cin>>y;
    cout<<"Enter the target amount of water to measure: ";
    cin>>target;
    bool result=canMeasureWater(x,y,target);
    if(result)
        cout<<"It is possible to measure exactly "<<target<<" liters of water using the two jugs."<<endl;
    else
        cout<<"It is not possible to measure exactly "<<target<<" liters of water using the two jugs."<<endl;
    return 0;
}