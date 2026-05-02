class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // store K elements in a minHeap
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        for (int i = 0; i < nums.size(); i++)
        {
            if (minHeap.size() < k)
                minHeap.push(nums[i]);
            else if (minHeap.size() == k && minHeap.top() < nums[i])
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top(); 
    }
};
