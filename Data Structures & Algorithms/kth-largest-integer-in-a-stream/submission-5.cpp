class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int kth = 0; 
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int i = 0; i < nums.size(); i++)
        {
            if (minHeap.size() == k && nums[i] > minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            else if (minHeap.size() < k) minHeap.push(nums[i]);
            else if (minHeap.size() == k && nums[i] < minHeap.top())
            {
            }
            
        }
    }
    
    int add(int val) {
         if (minHeap.size() == kth && val > minHeap.top())
            {
                    minHeap.pop();
                    minHeap.push(val);
            }
        else if (minHeap.size() < kth)
            minHeap.push(val);
        return minHeap.top(); 
    }
};

// find the K largest elements, put them in a min heap
// when a new value is found that is larger than the min of min heap
// remove smallest element and add the new value