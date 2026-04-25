class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // the upper bound of K is the size of the largest pile as 
        // h >= piles.size()
        int largest = 0;
        for (int i =0; i < piles.size(); i++)
        {
            if (piles[i] > largest) largest = piles[i];
        }
        // binary search values of 1 through K 
        int left = 1;
        int right = largest;
        int res = right;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int hours = 0;
            for (int i = 0; i < piles.size(); i++)
            {
                hours += ceil((double)piles[i] / mid); 
            }

            if (hours > h) // if the number of hours taken for this K value is greater
            {
                left = mid + 1;
            } // than total alloted hours, search for a higher K 
            // we want to get hours as close to H
            else 
            {
                res = mid; 
                right = mid -1;
            }
        }
        return res;

       
        // we want to minimize K 
    }
};
