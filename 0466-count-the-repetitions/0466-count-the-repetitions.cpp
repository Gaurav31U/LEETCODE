class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1=s1.size();
        int l2=s2.size();
        unordered_map<int,int> inc;
        for(int i=0;i<l2;i++){
            int ptr1=0;
            int ptr2=i;
            while(ptr1!=l1){
                if(s1[ptr1]==s2[ptr2%l2]){
                    ptr1++;
                    ptr2++;
                }else{
                    ptr1++;
                }
            }
            inc[i]=ptr2-i;
        }
        int ptr=0;
        int ans=0;
        for(int i=0;i<n1;i++){
            ans+=inc[ptr];
            ptr+=inc[ptr];
            ptr%=l2;
        }
        return ans/(l2*n2);

    }
};