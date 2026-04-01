class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i>=0){
            int j=n-1;
            while(nums[j]<=nums[i]) j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
    string getPermutation(int n, int k) {
        string s="";
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        for(int i=1;i<k;i++){
            nextPermutation(nums);
        }
        for(auto &x : nums){
            s+=to_string(x);
        }
        return s;
    }
};
