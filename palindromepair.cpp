#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct containing variables for Palindrome Pairs
struct node {
    bool isword;
    node *child[26];
    int idx;             
    vector<int> indices; 
};

// Global root pointer
node *root = NULL;

node* getNewNode() {
    node *temp = new node();
    temp->isword = false;
    temp->idx = -1; 
    for(int i = 0; i < 26; i++){
        temp->child[i] = NULL;
    }
    return temp;
}

bool isPalindrome(const string& word, int i, int j) {
    while (i < j) {
        if (word[i] != word[j]) return false;
        i++; 
        j--;
    }
    return true;
}

void insert(node *curr, string word, int idx){
    int n = word.length();
    
    for(int i = n - 1; i >= 0; i--){
        if (isPalindrome(word, 0, i)) {
            curr->indices.push_back(idx);
        }
        
        int charIdx = word[i] - 'a';
        if(!curr->child[charIdx]){
            curr->child[charIdx] = getNewNode();
        }
        curr = curr->child[charIdx];
    }
    curr->isword = true; 
    curr->idx = idx;     
    curr->indices.push_back(idx);
}

bool search(node *curr, string word, int idx){
    int n = word.length();
    
    for(int i = 0; i < n && curr != NULL; i++){
        if (curr->idx >= 0 && curr->idx != idx && isPalindrome(word, i, n - 1)) {
            return true;
        }
        
        int charIdx = word[i] - 'a';
        curr = curr->child[charIdx];
    }
    
    if (curr != NULL) {
        for (int i : curr->indices) {
            if (idx != i) {
                return true;
            }
        }
    }
    
    return false;
}

bool palindromePair(const vector<string>& arr) {
    root = getNewNode(); 
    
    for (int i = 0; i < arr.size(); i++) {
        insert(root, arr[i], i);
    }

    for (int i = 0; i < arr.size(); i++) {
        if (search(root, arr[i], i)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    
    // Check for valid integer input
    if (!(cin >> n)) {
        cout << "Invalid input. Exiting...\n";
        return 1;
    }
    
    vector<string> arr(n);
    cout << "Enter the " << n << " strings:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if (palindromePair(arr)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }
    
    return 0;
}