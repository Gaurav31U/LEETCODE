 static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class MyCalendar {
public:
    vector<pair<int,int>> vi;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<vi.size();i++){
            if(start>vi[i].first && vi[i].second>start){
                return false;
            }
            if(end>vi[i].first && vi[i].second>end){
                return false;
            }
            if(start<=vi[i].first && end>=vi[i].second){
                return false;
            }
        }
        vi.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */