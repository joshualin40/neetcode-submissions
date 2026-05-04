class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // coudl store all distances 
        // minHeap -> pair<int,int> distance, val 
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap; 
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] >= x) minHeap.push({arr[i] - x, arr[i]});
            else minHeap.push({x - arr[i], arr[i]});
        }
        for (int i = 0; i < k; i++)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop(); 
        }
        sort(res.begin(), res.end());
        return res; 
    }
};