class MyCalendarThree {
public:
    multiset<pair<int,bool>> kbook;
    int book(int start, int end) {
        kbook.insert({start , 1});
        kbook.insert({end, 0});
        int ans = 0,curr = 0;
        for(auto p : kbook){
            if(p.second == 1){
               curr++;
               ans = max(ans , curr);
            }
            else
                curr--;
        }
        return ans;
    }
};