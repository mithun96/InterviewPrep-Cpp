//Find all the prime values below n

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;

                }    
            }    
        }
        int count = 0;
        for (int i =0; i < n; i++){
        	if(prime[i]==true){
        		count++;
        	}
        }
        return count;
    }
};
