// treat the array like a linked list
// where the value at an index is the index it points to
// since the numbers are in the range 1,n and there are n+1 integers
// the 0th index will not be pointed at and one of the indices from 1 to n 
// will be pointed at twice 
// thus there is a cycle which can be solved with Floyd's 

// let fast and slow be ints represetning the index they point to
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0; 
        int fast = 0; 
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        int slow2 = 0;
        while (true)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) return slow;
        }
    }
};
