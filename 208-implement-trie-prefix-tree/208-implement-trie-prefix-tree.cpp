struct Node{
    Node* links[26];
    bool flag = false;
    
    // insert char 
    void insert(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    //go to the next REFERENCE TRIE < NODE >
    Node* next(char ch){
        return links[ch - 'a'];
    }
    
    bool containsKey(char ch){
        return ( links[ch - 'a'] != NULL );
    }
    
    // if reached the LAST REFERENCE TRIE, (re)SET flag to true
    void setEnd(){
        flag = true;
    }
    
    //check if we reached the end of the word or not
    bool isEnd(){
        return flag;
    } 
    
};


class Trie {
private:
    Node* root;
public:
    Trie() {
        //creating a new object
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        
        for(int i=0;i<word.size();i++){
            
            if(!node->containsKey(word[i])){
                
                //does not contain, then insert
                node->insert(word[i] , new Node());          
                
            }
            //go to the next REFERENCE TRIE
            node = node->next(word[i]); 
        }
        node->setEnd();
        
    }
    
    bool search(string word) { 
        Node* node = root;
        
        for(int i=0;i<word.size();i++){
            
            if(!node->containsKey(word[i])){                
                //does not contain, return false
                return false;               
            }
            //go to the next REFERENCE TRIE
            node = node->next(word[i]); 
        }        
        //we looped, and if it did not return false from inside loop, check if end and return
        return node->isEnd();
        
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        
        for(int i=0;i<prefix.size();i++){
            
            if(!node->containsKey(prefix[i])){                
                //does not contain, return false
                return false;               
            }
            //go to the next REFERENCE TRIE
            node = node->next(prefix[i]); 
        }        
        //we looped, and if it did not return false from inside loop, it contains
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */