class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // for each coordinate in points calculate the distance
        // create an unordered map with key, value as [distance, index]
        // store the distances in a min heap, return the K top distances
        // from the distances return K indices, which we add to result vector
        vector<vector<int>> res; 
        unordered_map<int, vector<int>> mp; 
        priority_queue<int, vector<int>, greater<int>> minheap; 
        for (int i = 0; i < points.size(); i++)
        {
            int dist = pow(pow(points[i][0],2) + (pow(points[i][1],2)), 2);
            mp[dist].push_back(i);
            minheap.push(dist);
        }

        for (int i =0; i < k; i++)
        {
            int dist = minheap.top(); minheap.pop(); 
            int index = mp[dist].front(); mp[dist].erase(mp[dist].begin());
            res.push_back(points[index]);
        }

        return res;
    }
};
