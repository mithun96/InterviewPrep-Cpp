//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.




class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;

        int len = s.size()
        int max_left = 0;
        int max_len = 1;
        int left;
        int right;

        for (int start = 0; start < len && len - start > max_len / 2;) {
            
            left = right = start;

            //to check if the first few are the same. it sets the right at 
            //the start of the different value
            while (right < len - 1){
                if(s[right + 1] == s[right])
                    ++right;
            }


            start = right + 1;

            while (right < len - 1 && left > 0 ){
                if (s[right + 1] == s[left - 1]) {
                    ++right;
                    --left;
                }
            }

            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        
        return s.substr(max_left, max_len);
    }
};






















