/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
*/





class Solution {
public:
    vector<int> grayCode(int n) {

        int len = n*n;     // max value with n number of bits

        vector<int> res(len,0);
        
        for(int i = 0; i < len; i++){
            res[i] =i ^ (i >> 1);      // Right shift of bits// ^ = XOR (exclusive OR) to turn on bits
        }
        return res;
    }
};



// Second solution. (little more confusing)

class Solution {
public:
vector<int> grayCode(int n) 
{         
    vector<int> result(1, 0);        
    for (int i = 0; i < n; i++) {
        int curCount = result.size();
        // push back all element in result in reverse order
        while (curCount) {
            curCount--;
            int curNum = result[curCount];
            curNum += (1<<i);
            result.push_back(curNum);
        } 
    }
    return result;
}
};

