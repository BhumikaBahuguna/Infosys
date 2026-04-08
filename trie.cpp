#include<bits/stdc++.h>
using namespace std;
struct node {
    bool isword;
    node *child[26];
};
node *root = NULL;
node* getNewNode() {
    node *temp = new node();
    temp->isword = false;
    for(int i = 0; i < 26; i++){
        temp->child[i] = NULL;
    }
    return temp;
}
void insert(node *curr , string word){
    int n = word.length();
    for(int i = 0; i < n; i++){
        if(!curr->child[word[i] - 'a']){
            curr->child[word[i] - 'a'] = getNewNode();
        }
        curr = curr->child[word[i] - 'a'];
    }
    curr->isword = true;
}
bool search(node *curr, string word){
    int n = word.length();
    for(int i = 0; i < n; i++){
        if(!curr->child[word[i] - 'a']){
            return false;
        }
        curr = curr->child[word[i] - 'a'];
    }
    return curr->isword;
}
bool softdelete(node *curr, string word){
    int n = word.length();
    for(int i = 0; i < n; i++){
        if(!curr->child[word[i] - 'a']){
            return false;
        }
        curr = curr->child[word[i] - 'a'];
    }
    if(curr->isword){
        curr->isword = false;
        return true;
    }
    return false;
}
bool isEmpty(node* curr) {
    for (int i = 0; i < 26; i++) {
        if (curr->child[i]) return false;
    }
    return true;
}
node* harddeleteHelper(node *curr, string word, int depth = 0) {
    if (!curr) return NULL;
    if (depth == word.length()) {
        if (curr->isword) curr->isword = false; 
        if (isEmpty(curr)) {
            delete curr;
            return NULL; 
        }
        return curr;
    }
    int index = word[depth] - 'a';
    curr->child[index] = harddeleteHelper(curr->child[index], word, depth + 1);
    if (isEmpty(curr) && curr->isword == false) {
        delete curr;
        return NULL;
    }
    return curr;
}
bool harddelete(node *curr, string word) {
    if (!search(curr, word)) return false; 
    root = harddeleteHelper(curr, word);
    return true;
}
int main(){
    root = getNewNode();
    int choice;
    string word;
    while(true){
        cout << "\n--- Trie Menu ---\n";
        cout << "1. Insert\n2. Search\n3. Soft Delete\n4. Hard Delete\n5. Exit\nChoice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter word to insert: ";
                cin >> word;
                insert(root, word);
                cout << "Inserted successfully.\n";
                break;
            case 2:
                cout << "Enter word to search: ";
                cin >> word;
                if(search(root, word)) cout << "Found\n";
                else cout << "Not Found\n";
                break;
            case 3:
                cout << "Enter word to soft delete: ";
                cin >> word;
                if(softdelete(root, word)) cout << "Soft Deleted successfully.\n";
                else cout << "Word not found for soft deletion.\n";
                break;
            case 4:
                cout << "Enter word to hard delete: ";
                cin >> word;
                if(harddelete(root, word)) cout << "Hard Deleted successfully.\n";
                else cout << "Word not found for hard deletion.\n";
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}