class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
      if(n==0){
        return;
      }  
      if(m==0){
        a=b;
        return;
      }
      int i=m-1, j=n-1, k=n+m-1;
      while(i>=0 && j>=0){
        if(a[i]>b[j]){
            a[k]=a[i];
            i--;
        }
        else{
            a[k]=b[j];
            j--;
        }
        k--;
      }
      while(j>=0){
        a[k]=b[j];
        j--;
        k--;
      }
      return;
    }
};