class CustomStack {
public:
    vector<int> ans;
    int n;
    CustomStack(int maxSize) {
        ans.clear();
        n=maxSize;
    }
    
    void push(int x) {
        if(ans.size()<n)
        ans.push_back(x);
    }
    
    int pop() {
        if(!ans.empty()){
        int temp=ans.back();
        ans.pop_back();  
        return temp;
        } 
        return -1;
    }
    void increment(int k, int val) {
        for(int i=0;i<min(k,(int)ans.size());i++){
            ans[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */