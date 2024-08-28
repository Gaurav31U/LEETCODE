class Solution {
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& num) {
    int n=num.size();
    vector<int> res(n,1);
    vector<int> lis;
    lis.push_back(num[0]);
    for(int i=1;i<n;i++){
      if(lis.back()<=num[i]){
        lis.push_back(num[i]);
        res[i]=lis.size();
      }else{
        int idx=(upper_bound(lis.begin(),lis.end(),num[i])-lis.begin());
        lis[idx]=num[i];
        res[i]=idx+1;
      }
    }
    return res;
  }
};