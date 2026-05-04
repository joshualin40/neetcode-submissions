class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // make pairs that get as close to the limit as possible
        sort(people.begin(), people.end());
        int res = 0; 
        int l = 0;
        int r = people.size() - 1;

        while (l <= r)
        {
            if (people[l] + people[r] <= limit)
            {
                r--;
                l++;
                res++;
            }
            else if (people[l] + people[r] > limit)
            {
                r--; 
                res++;
            }
        }

        return res;
    }
};