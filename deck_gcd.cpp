#include<bits/stdc++.h>
using namespace std;
bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()<=1) return false;
        unordered_map<int,int> freqmap;
        for(int card:deck){
            freqmap[card]++;
        }
        int currentGCD=freqmap.begin()->second;
        for(auto const& [card,count]:freqmap){
            currentGCD=std::gcd(currentGCD,count);
            if(currentGCD==1){
                return false;
            }
        }
        return currentGCD>=2;
    }
int main(){
    int n;
    cout<<"Enter the number of cards in the deck: ";
    cin>>n;
    vector<int> deck(n);
    cout<<"Enter the values of the cards in the deck: ";
    for(int i=0;i<n;i++){
        cin>>deck[i];
    }
    bool result=hasGroupsSizeX(deck);
    if(result)
        cout<<"It is possible to group the deck into groups of X cards with the same integer."<<endl;
    else
        cout<<"It is not possible to group the deck into groups of X cards with the same integer."<<endl;
    return 0;
}