class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push({freq[i], char(i + 'a')});
        }

        string ans;

        while (pq.size() >= 2) {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();

            ans += first.second;
            ans += second.second;

            if (--first.first > 0)
                pq.push(first);
            if (--second.first > 0)
                pq.push(second);
        }

        if (!pq.empty()) {
            if (pq.top().first > 1)
                return "";
            ans += pq.top().second;
        }

        return ans;
    }
};