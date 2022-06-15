SCRAP ALPHANUMERICS, AND SPACES FROM STRING
​
//ERASE ALPHANUMERICS:
​
//            if(s[i]< 'A' || s[i] > 'Z' && s[i]< 'a' || s[i]>  'z') {
//               s.erase(i,1);
//               i--;
//            }
ADD 32 TO ASCII to change it to lowercase: or use tolower('A')
if(s[i]>=65 && s[i]<=95) s[i] +=32;