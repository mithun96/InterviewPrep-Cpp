#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        //for (char& c : s) 
        for (int i =0; i < s.length(); i++){
            switch (s[i]) {
                case '(': paren.push(s[i]); break;
                case '{': paren.push(s[i]); break;
                case '[': paren.push(s[i]); break;
                case ')': 
                        {if (paren.empty() || paren.top()!='(') 
                            return false; 
                        else 
                            paren.pop(); 
                        break;}
                case '}':  
                        {if (paren.empty() || paren.top()!='{') 
                            return false; 
                        else 
                            paren.pop(); 
                        break;}
                case ']': 
                        {if (paren.empty() || paren.top()!='[') 
                            return false; 
                        else 
                            paren.pop(); 
                        break;}
                default: ; // pass
            }
        }
        if (paren.empty())
            return true;
        else 
            return false;
    }
};