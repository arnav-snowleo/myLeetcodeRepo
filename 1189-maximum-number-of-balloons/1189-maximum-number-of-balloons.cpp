class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        string s  = "balloon";
        unordered_map<char, int> balloonmap;        
        for(auto it: s){
            balloonmap[it]++;
        }        
        
        //balloonmap -> b-1,a-1,l-2,o-2,n-1
        
        unordered_map<char, int> textmap;        
        for(auto it: text){
            
            if(balloonmap.count(it)){
                
                textmap[it]++;                
            }            
        }
        //for text "nlaebolko",
        //textmap -> b-1,a-1,l-2,o-2,n-1
        
        
        int ans = INT_MAX;
        
        for(auto [character, freq ] : balloonmap){
            ans = min(ans, textmap[character]/freq);
            
            //if minimum is 0 anytime, ans is zero as the ratio has not been satisfied for some char
        }
        
        return ans;

        


        
    }
};