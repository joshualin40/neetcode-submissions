class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
          sort(people.begin(), people.end());
        int res = 0; 
        int l = 0;
        int r = people.size() - 1;

        while (l <= r)
        {
            int remaining = limit - people[r];
            r--;
            res++;

            if (remaining >= people[l]) l++;
        }

        return res;
    }
};