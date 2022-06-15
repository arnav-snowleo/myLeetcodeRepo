class Solution {
private:
    bool isStringPalindrome(string s){
        int n = s.length();
        
        for(int i=0;i<n/2;i++){
            
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {

        string temp = "";
        for(int i=0;i<s.length(); i++){
            
            if(s[i]>= 'A' && s[i] <= 'Z') {
                temp += s[i] +32 ;            //add 32 for ASCII or use tolower()
            }
            // if(s[i] >= 'a' && s[i] <=  'z' || s[i]>=48 && s[i]<=57) {
            //     temp += s[i];
            // }
            if(s[i] >= 'a' && s[i] <=  'z' || s[i] - '0'>=0 && s[i]-'0'<=9) {
                temp += s[i];
            }            
        }

        return isStringPalindrome(temp);        
    }
};





        // ADD 32 TO ASCII to change it to lowercase
//         for(int i=0;i<s.length();i++){
            
//             //if capital, then convert
//             if(s[i]>=65 && s[i]<=95) s[i] +=32;

//         }