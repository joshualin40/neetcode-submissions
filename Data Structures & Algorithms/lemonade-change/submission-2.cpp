class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0; 
        int tens = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                fives++; 
            }
            else if (bills[i] == 10)
            {
                if (fives == 0) return false;
                tens++; 
                fives--; 
            }
            else 
            {
                if (fives == 0) return false;
                if (tens == 0)
                {
                    if (fives < 3) return false;
                    fives -= 3;
                }
                else if (tens > 0)
                {
                    fives--; 
                    tens--; 
                }
                
            }
        }

        return true; 
    }
};