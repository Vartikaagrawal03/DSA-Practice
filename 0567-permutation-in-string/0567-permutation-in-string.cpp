class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> count1(26, 0), count2(26, 0);

        // Fill frequency of s1 and first window of s2
        for (int i = 0; i < n1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        // Check first window
        if (count1 == count2) return true;

        // Sliding window
        for (int i = n1; i < n2; i++) {
            count2[s2[i] - 'a']++;              // add new char
            count2[s2[i - n1] - 'a']--;         // remove old char

            if (count1 == count2) return true;
        }

        return false;
    }
};