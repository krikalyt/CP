//Trie using unordered_map
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
struct TrieNode{
    bool end = false;
    unordered_map<char,TrieNode*> abc;
};

bool search(TrieNode* root,string key)
{
    TrieNode* curr = root;
    for(int i=0;i<key.size();i++)
    {
        if(curr->abc.find(key[i]) == curr->abc.end())
            return false;
        curr = curr->abc[key[i]];
    }
    return curr->end;
}

void insert(TrieNode* root,string key){
    TrieNode* curr = root;
    for(int i=0;i<key.size();i++)
    {
        if(curr->abc.find(key[i]) == curr->abc.end())
            curr->abc.insert({key[i],new TrieNode()});
        curr  = curr->abc[key[i]];
    }
    curr->end = true;
}

int main()
{
    // freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test; 
	while(test--)
    {
        TrieNode* root = new TrieNode();
        int N,Q;
        cin >> N >> Q;
        for(int i=0;i<N;i++)
        {
            string temp;
            cin >> temp;   
            insert(root,temp);
        }

        for(int i=0;i<Q;i++)
        {
            string temp;
            cin >> temp;
            cout << search(root,temp) << '\n';
        }
        delete root;
    }
	return 0;
}
