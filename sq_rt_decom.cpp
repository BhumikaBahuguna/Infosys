#include<bits/stdc++.h>
using namespace std;

int *sqrtdecompose(int *arr,int n,int &block_size,int &num_blocks){
    block_size = sqrt(n);
    num_blocks = ceil((double)n / block_size);

    int *blocks = new int[num_blocks]();

    for(int i=0;i<n;i++){
        blocks[i/block_size] += arr[i];  
    }
    return blocks;
}

void update(int *arr,int *blocks,int block_size,int index,int key){
    int changevalue = key - arr[index];
    arr[index] = key;
    blocks[index/block_size] += changevalue;
}

int calculateSum(int *arr,int *blocks,int block_size,int l,int r){
    int sum = 0;

    while(l <= r && l % block_size != 0){
        sum += arr[l++];
    }

    while(l + block_size <= r){
        sum += blocks[l/block_size];
        l += block_size;
    }

    while(l <= r){
        sum += arr[l++];
    }

    return sum;
}

int main(){
    int n, Q, type, index, key, l, r;
    cin >> n;

    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int block_size, num_blocks;
    int *blocks = sqrtdecompose(arr,n,block_size,num_blocks);

    cin >> Q;

    while(Q--){
        cin >> type;
        switch(type){
            case 1:
                cin >> index >> key;
                update(arr,blocks,block_size,index,key);
                break;

            case 2:
                cin >> l >> r;
                cout << "sum=" << calculateSum(arr,blocks,block_size,l,r) << endl;
                break;
        }
    }
}