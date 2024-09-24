class node{
    public:
    int cnt;
    node* next[2];
    node(){
        cnt=0;
        next[0]=NULL;
        next[1]=NULL;
    }
};
class Trie{
    public:
    node* trie;
    Trie(){
        trie=new node;
    }
    void insert(int val){
        node* tmp=trie;
        for(int i=20;i>=0;i--){
            int p=(val&(1<<i))>0;
            if(tmp->next[p]==NULL){
                tmp->next[p]=new node;
            }
            tmp=tmp->next[p];
            tmp->cnt++;
        }
    }
    int findmax(int num){
        int ans=0;
        node* temp=trie;
        for(int i=20;i>=0;i--){
            int k=(num&(1<<i))?1:0;
            if(temp->next[k^1]!=NULL && temp->next[k^1]->cnt>0){
                ans|=(1<<i);
                temp=temp->next[k^1];
            }else{
                temp=temp->next[k];
            }
            if(temp==NULL){
                return -1;
            }
        }
        return ans;
    }
    void remove(int val){
        node* tmp=trie;
        for(int i=20;i>=0;i--){
            int p=(val&(1<<i))>0;
            tmp=tmp->next[p];
            tmp->cnt--;
        }
    }
};
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int i=n-1,j=n-1;
        sort(nums.begin(),nums.end());
        Trie trie;
        while(i>=0){
            while(nums[j]>2*nums[i]){
                trie.remove(nums[j]);
                j--;
            }
            ans=max(ans,trie.findmax(nums[i]));
            trie.insert(nums[i]);
            i--;
        }
        return ans;
    }
};