class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // use a minHeap that only maintains K values at each given time
        // store the min heap full of int pairs for dist/index
        // sort of by dist
        // when finished iterating through points vector, maintaining only K 
        // elements in the heap, iterate through the minheap adding the indices to 
        // res vector 
        priority_queue<pair<int,int>> maxHeap;
        vector<vector<int>> res;
        for (int i = 0; i < points.size(); i++)
        {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if (maxHeap.size() < k)
                maxHeap.push({dist, i});
            else if (maxHeap.size() == k && dist < maxHeap.top().first)
            {
                maxHeap.pop();
                maxHeap.push({dist, i});
            }
        } 
        for (int i = 0; i < k; i++)
        {
            res.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return res;
    }
};
