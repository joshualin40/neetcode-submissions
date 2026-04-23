class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // iterate through array, considering the current index as the selling price
        // for each iteration, the smallest avlue to the left of the index is the buying price
        // store the profits in another array return the largest of the array
        vector<int> profits(prices.size()-1);
        int smallest = INT_MAX;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i-1] < smallest) smallest = prices[i-1];
            profits.push_back(prices[i] - smallest);
        }
        int profit = 0;
        for (int i = 0; i < profits.size(); i++)
        {
            if (profits[i] > profit) profit = profits[i];
        }

        return profit;
    }
};
