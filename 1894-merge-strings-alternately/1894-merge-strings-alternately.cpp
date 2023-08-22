class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string res;
        int len1 = word1.length(), len2 = word2.length(), len = max(len1,len2);
        for(int i=0;i<len;i++){
            if(len1>i)
                res+= word1[i];
            if(len2>i)
                res+= word2[i];
        }
        return res;
    }
};