class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int comp=target-nums[i];
            if(seen.count(comp)){
                return{seen[comp],i};
            }
            seen[nums[i]]=i;
        }
        return {};
    }
};
