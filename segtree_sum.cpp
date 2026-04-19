#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
vector<int>seg;
void buildseg(int node,int l,int r){
    if(l==r){
        seg[node]=arr[l];
        return ;
    }
    int mid=(l+r)/2;
    buildseg(2*node+1,l,mid);
    buildseg(2*node+2,mid+1,r);
    seg[node]=seg[2*node+1]+seg[2*node+2];
}
int query(int node,int l,int r,int ql,int qr){
    if(qr<l || ql>r) return 0;
    if(ql<=l && r<=qr) return seg[node];
    int mid=(l+r)/2;
    return query(2*node+1,l,mid,ql,qr)+query(2*node+2,mid+1,r,ql,qr);
}
void update(int node,int l,int r,int idx,int val){
    if(l==r)
    {
        seg[node]=val;
        arr[idx]=val;
        return ;
    }
    int mid=(l+r)/2;
    if(idx<=mid)
        update(2*node+1,l,mid,idx,val);
    else
        update(2*node+2,mid+1,r,idx,val);
    seg[node]=seg[2*node+1]+seg[2*node+2];
}
int main(){
    int n;
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    seg.resize(4*n);
    buildseg(0,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<query(0,0,n-1,l,r);
        }else if(type==2){
            int idx,val;
            cin>>idx>>val;
            update(0,0,n-1,idx,val);
        }
    }
    return 0;
}
