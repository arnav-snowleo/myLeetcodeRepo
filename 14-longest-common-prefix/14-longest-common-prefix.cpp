// USING TRIES : check childCount at each node

// TC: O(m*n)
// SC: O(m*n) , ( worse than the brute approach )

// insert all strings into a TRIE
// at each node, check how many child nodes, <if one, increment counter (or add to string)>
//                                           <else return;>

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;
        
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }    
};

class Trie{
public:
    TrieNode* root;
    
    Trie(char ch){
        root = new TrieNode(ch);
    }
    
    void insertUtil(TrieNode* root, string word){
        
        //BASE CASE
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }
        
        //index
        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[index] != NULL){     //present
             child = root->children[index];
        }else{                                 //absent
             child = new TrieNode(word[0]);
             root->childCount++;
             root->children[index] = child;
        }
        
        //RECURSION
        insertUtil(child, word.substr(1));
    }
    
    void insertWord(string word){
        insertUtil(root, word);
    }
    
    void lcp(string str, string &ans){
        
        for(int i=0;i<str.length();i++){
            
            char ch = str[i];
            
            if(root->childCount ==1){            // childCount is 1
                ans += ch;
                
                //go ahead
                int index = ch - 'a';
                root = root->children[index];
            }else{                              
                break;
            }
            
            if(root->isTerminal) break;
        }
        
    }
    
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        Trie *t = new Trie('\0');
        
        for(int i=0;i<strs.size();i++){
            if(strs[i]=="") return "";
            t->insertWord(strs[i]);
        }
        
        string first = strs[0];
        string ans = "";
        
        t->lcp(first, ans);
        return ans;        
    }
};


/*
// 2 for loops

// BRUTE:  < Take the first string > compare it with the remaining strings
// TC: O(m*n) , SC: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";
        
        for(int i=0;i<strs[0].length();i++){   
            
            char ch = strs[0][i];
            
            bool match = true;
            
            for(int j=1;j<strs.size();j++){
                
                if(strs[j][i] != ch || strs[j].size() < i){
                    match = false;
                    break;
                }         
            } 
            
            if(match != false){
                ans +=ch;
            }else break;
        }
        return ans;       
    }
};
*/