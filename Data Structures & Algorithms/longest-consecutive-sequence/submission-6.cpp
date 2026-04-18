

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        // sort it and get rid of dups
         unordered_set<int> seen(nums.begin(), nums.end()); 
         vector<int> myVec(seen.begin(), seen.end());
         sort(myVec.begin(), myVec.end());
        vector<int> lengths;
         for (int i =0; i < myVec.size(); i++)
         {
            int length = 1;
            for (int j =i + 1; j < myVec.size(); j++)
                {
                    if (myVec[j] == myVec[j-1] + 1) length++;
                    else break;
                }
            lengths.push_back(length);
         }
        int max = 0;
         for (int i =0; i < lengths.size(); i++)
         {
            if (lengths[i] > max) max = lengths[i];
         }
         return max;

        


        // two for loops to find the largest sequence that can be found start at 
        // index 0, 1, 2, 3, 4.. etc
        // add each length to a vector, then find the sequence with the 
        // longest legnth adn return the length
    }
};
