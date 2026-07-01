class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int count = 1;

        // Keep repeating until temp length >= b length
        while (temp.size() < b.size()) {
            temp += a;
            count++;
        }

        // Check if b is substring
        if (temp.find(b) != string::npos) return count;

        // One more repeat for overlap case
        temp += a;
        count++;

        if (temp.find(b) != string::npos) return count;

        return -1;
    }
};