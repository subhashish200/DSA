/******************* Right Rotation of Array **********************/
/************************ T.C = O(n) & Space complexity = O(1) *********************/
class Solution {
public:
    void Reverse_helper(vector<int> &nums,int st,int en){
        //st = index of start pounter
        //en = index of end pointer..
        int i = st, j = en;
        while(i<j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        Reverse_helper(nums,0,nums.size()-1);
        Reverse_helper(nums,0,k-1);
        Reverse_helper(nums,k,nums.size()-1);
    }
};