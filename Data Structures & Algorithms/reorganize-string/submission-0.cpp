class Solution {
public:
    string reorganizeString(string s) {
        // put frequencies of characters into hash map
        // always choose the next most frequent char
        string res = ""; 
        vector<int> counts(26,0); 
        for (int i = 0; i < s.size(); i++) //
            counts[s[i] - 'a']++;  
        priority_queue<pair<int, char>> pq; // maxHeap of freq, char
        for (int i = 0; i < counts.size(); i++)
            if (counts[i] > 0)
                pq.push({counts[i], 'a'+i});
        
        pair<int, char> prev = {-1, '\0'};

        for (int i = 0; i < s.size(); i++){
            auto temp = pq.top();
            pq.pop();
            if (prev.second == temp.second) return "";  
            if (prev.first > 0) pq.push(prev);          
            res += temp.second;
            prev = {temp.first - 1, temp.second};      
        }

        return res; 
    }
};