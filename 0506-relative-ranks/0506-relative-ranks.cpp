class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<int>backupArr(n);
        copy(score.begin(), score.end(), backupArr.begin());
        unordered_map<int,int> historyTable;
        for(int i=0;i<n;i++){
            historyTable[backupArr[i]]=i;
        }
        sort(backupArr.begin(), backupArr.end(), greater<int>());
        vector<string>ansArr(n);
        for(int i=0;i<n;i++){
            int idx=historyTable[backupArr[i]];
            if(i==0){
                ansArr[idx]="Gold Medal";
            }
            else if(i==1){
                ansArr[idx]="Silver Medal";
            }
            else if(i==2){
                ansArr[idx]="Bronze Medal";
            }
            else{
                ansArr[idx]=to_string(i+1);
            }

         }
         return ansArr;

    }
};