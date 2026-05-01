class KthLargest {
    priority_queue<int> maxHeap; 
    int kth = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            maxHeap.push(nums[i]);
        kth = k;   
    }
    
    int add(int val) {
        // adds a val to the stream and then returns the kth largest
        // int in the stream 
        priority_queue<int> copy; 
        copy = maxHeap; 
        copy.push(val);
        maxHeap.push(val);
        for (int i = 0; i < kth - 1; i++)
        {
            copy.pop();
        }
        return copy.top();
    }
};
