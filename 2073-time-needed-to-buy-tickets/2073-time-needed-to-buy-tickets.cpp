class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
      queue<int> q;
      for(int i=0;i<tickets.size();i++){
        q.push(i);
      }  
      int count=0;
      while(tickets[k]>0){
        int p=q.front();
        q.pop();
        tickets[p]--;
        count++;
        if(tickets[p]!=0)
        q.push(p);
      }
      return count;
    }
};