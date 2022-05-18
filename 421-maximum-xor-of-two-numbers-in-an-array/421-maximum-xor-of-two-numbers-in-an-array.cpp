struct Node{

   Node* links[2];
   
   bool containsKey(int index){
       return (links[index]!=NULL);
   }
    
    void insert(int index, Node* node){
        links[index] = node;
    }
    
    Node* next(int index){
        return links[index];
    }
}; 

class Trie{

 private: Node* root;

 public:
    
    Trie(){
       root = new Node();     
    }
    
    public:
    void insert(int num){
        Node* node = root;
        
        for(int i=31; i>=0; i--){
            int bit = (num >>i) & 1;
            if(!node->containsKey(bit)){
                node->insert(bit, new Node());
            }
            node = node->next(bit);
        }
    }
    
    public:
    int findMaxXor(int num){
    Node* node = root;
    int maxVal = 0;
        
    for(int i=31; i>=0; i--){
        
        int bit =(num>>i) & 1;
        if(node->containsKey(!bit)){
            maxVal = maxVal | (1<< i);
            node = node -> next(!bit);
        }else {
            node = node -> next(bit);
        }
     }
        
     return maxVal;   
    }
    
    
};


class Solution {
public:
    Trie trie;
    
    int findMaximumXOR(vector<int>& nums) {
        
        for(auto it: nums) trie.insert(it);
        
        
        int ans=0;
        
        for(auto it : nums){
            ans = max(ans, trie.findMaxXor(it));
        }
       
        return ans;
    }
};