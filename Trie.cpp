#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Trie{
private:
    struct TrieNode{
        bool end = false;
        unordered_map<char,TrieNode*> abc;
    };

    TrieNode* root = new TrieNode();
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

public:

    //User Level Code
    void Insert_Trie(string abc)
    {
        insert(root,abc);
    }

    bool Search_Trie(string abc){
        return search(root,abc);
    }

    //End
    
    ~Trie(){
        delete root;
    }
};

int main()
{
    // freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test; 
	while(test--)
    	{
		Trie tr;
		int N,Q;
		cin >> N >> Q;
		for(int i=0;i<N;i++)
		{
		    string temp;
		    cin >> temp;   
		    tr.Insert_Trie(temp);
		}

		for(int i=0;i<Q;i++)
		{
		    string temp;
		    cin >> temp;
		    cout << tr.Search_Trie(temp) << '\n';
		}
   	}
	return 0;
}
