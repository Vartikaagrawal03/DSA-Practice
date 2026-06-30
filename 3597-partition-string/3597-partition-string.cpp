class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        vector<string> result;

        string curr = "";

        for (char c : s) {
            curr += c;

            // If current substring is already seen, continue extending
            if (seen.count(curr)) continue;

            // Otherwise, finalize this segment
            result.push_back(curr);
            seen.insert(curr);
            curr = "";
        }

        return result;
    }
};