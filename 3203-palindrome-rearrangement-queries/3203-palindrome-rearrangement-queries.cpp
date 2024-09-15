class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n=s.length();
        vector<vector<int>>pr(n+1, vector<int>(26,0));
        vector<int>psd(1,0);
        for(int i=0, j=n-1;i<n and j>=0;i++,j--)
            psd.push_back(psd.back()+(s[i] != s[j]));
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++)
                pr[i][j] = pr[i-1][j];
            pr[i][s[i-1]-'a']++;
        }
        int cnt=0;
        for(int i=0;i<26;i++)
            if(pr[n][i]%2)
                cnt++;
        vector<bool>v;
        for(auto q:queries){
            int a1=q[0]+1, b1=q[1]+1, c1=q[2]+1, d1=q[3]+1;
            int a2=n-a1+1, b2=n-b1+1, c2=n-c1+1, d2=n-d1+1;
            if(cnt){
                v.push_back(false);
                continue;
            }
            bool chk = true;
            if(a1 <= d2){
                // a1 d2 c2 b1
                // d2->c2 completely lies inside a1->b1
                if(d2>=a1 and c2<=b1){
                    if(psd[a1-1] or (psd[n/2]-psd[b1])){
                        chk=false;
                    }
                    for(int i=0;i<26;i++){
                        if(pr[b1][i]-pr[a1-1][i] != pr[a2][i]-pr[b2-1][i]){
                            chk=false;
                        }
                    }
                }
                // a1 b1 d2 c2
                // no intersection b/w 2 ranges
                if(d2>b1){
                    if(psd[a1-1] or (psd[d2-1]-psd[b1]) or (psd[n/2]-psd[c2]))
                        chk=false; 
                    for(int i=0;i<26;i++){
                        if(pr[b1][i]-pr[a1-1][i] != pr[a2][i]-pr[b2-1][i])
                            chk=false;
                        if(pr[c2][i]-pr[d2-1][i] != pr[d1][i]-pr[c1-1][i])
                            chk=false;
                    }
                }
                // a1 d2 b1 c2 | c1 b2 d1 a2
                // intersection b/2 2 ranges
                if(b1>=d2 and c2>=b1){
                    if(psd[a1-1] or (psd[n/2]-psd[c2])){
                        chk=false;
                    }
                    vector<int>cnt1(26), cnt2(26);
                    for(int i=0;i<26;i++){
                        cnt1[i] = pr[b1][i]-pr[a1-1][i];
                        cnt2[i] = pr[d1][i]-pr[c1-1][i];
                    }
                    for(int i=0;i<26;i++){
                        cnt1[i] -= (pr[a2][i]-pr[d1][i]);
                        cnt2[i] -= (pr[c2][i]-pr[b1][i]);
                    }
                    for(int i=0;i<26;i++){
                        if(cnt1[i]<0 or cnt2[i]<0 or cnt1[i]!=cnt2[i])
                            chk=false;
                    }
                }
            }
            else{
                // d2 c2 a1 b1
                // no intersection
                if(a1 > c2){
                    if(psd[d2-1] or (psd[a1-1]-psd[c2]) or (psd[n/2]-psd[b1]))
                        chk=false; 
                    for(int i=0;i<26;i++){
                        if(pr[b1][i]-pr[a1-1][i] != pr[a2][i]-pr[b2-1][i])
                            chk=false;
                        if(pr[c2][i]-pr[d2-1][i] != pr[d1][i]-pr[c1-1][i])
                            chk=false;
                    }
                }
                // d2 a1 c2 b1
                // intersection
                if(a1<=c2 and b1>=c2){
                    if(psd[d2-1] or (psd[n/2]-psd[b1]))
                        chk=false;
                    vector<int>cnt1(26), cnt2(26);
                    for(int i=0;i<26;i++){
                        cnt1[i] = pr[b1][i]-pr[a1-1][i];
                        cnt2[i] = pr[d1][i]-pr[c1-1][i];
                    }
                    for(int i=0;i<26;i++){
                        cnt1[i] -= (pr[c1-1][i]-pr[b2-1][i]);
                        cnt2[i] -= (pr[a1-1][i]-pr[d2-1][i]);
                    }
                    for(int i=0;i<26;i++){
                        if(cnt1[i]<0 or cnt2[i]<0 or cnt1[i]!=cnt2[i])
                            chk=false;
                    }
                }
                // d2 a1 b1 c2
                // completely lies
                if(b1<c2){
                    if(psd[d2-1] or (psd[n/2]-psd[c2]))
                        chk=false;
                    for(int i=0;i<26;i++){
                        if(pr[c2][i]-pr[d2-1][i] != pr[d1][i]-pr[c1-1][i]){
                            chk=false;
                        }
                    }
                }
            }
            v.push_back(chk);
        }
        return v;
    }
};