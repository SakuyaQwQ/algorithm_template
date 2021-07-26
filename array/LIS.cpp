class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        for(auto&num:nums){
            if(res.empty()||res.back()<num){
                res.push_back(num);
            }else{
                *lower_bound(begin(res),end(res),num)=num;
            }
        }
        return res.size();
    }
};
