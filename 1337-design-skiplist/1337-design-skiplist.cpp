class Skiplist {
public:
    multiset<int> st;
    Skiplist() {
        
    }
    
    bool search(int target) {
        auto tp=st.lower_bound(target);
        if(tp==st.end())return false;
        return *tp==target;
    }
    
    void add(int num) {
        st.insert(num);
    }
    
    bool erase(int num) {
        auto tp=st.find(num);
        if(tp==st.end())return false;
        st.erase(tp);
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */