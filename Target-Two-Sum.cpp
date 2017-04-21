

// WITHOUT THE USE OF HASH MAP

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ns=nums;

        sort(ns.begin(), ns.end());

        int a=0;
        int b=ns.size()-1;
        
        while (a < b){
            if (ns[a]+ns[b] > target) 
                b--;
            else if (ns[a]+ns[b] < target) 
                a++;
            else {
                vector<int> ans;
                for (int i=0; i<nums.size(); i++) {
                    if (nums[i]==ns[a]) 
                        ans.push_back(i);
                    else if (nums[i]==ns[b]) 
                        ans.push_back(i);
                }
            }
        }


        if (ans[0]>ans[1])
            swap(ans[0], ans[1]);
        return ans;
            
    }
};





// WITH THE USE OF HASH MAP

vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;

    for (int i = 0; i < numbers.size(); i++) {
        int numberToFind = target - numbers[i];

        if (hash.find(numberToFind) != hash.end()) {

            result.push_back(hash[numberToFind]);
            result.push_back(i);            
            return result;
        }

        //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;
}










