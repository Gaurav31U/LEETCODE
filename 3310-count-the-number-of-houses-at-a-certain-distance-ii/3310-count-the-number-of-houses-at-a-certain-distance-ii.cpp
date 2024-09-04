class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        if(x>y) swap(x,y);
        vector<long long> v(n,0);
        int left=x-1,right=n-y;
        //Base Case
        if(x==y || abs(x-y)==1){
            for(int i=n-2;i>=0;i--)
                v[i] = v[i+1]+2; 
        }else{
            //m = length of path without houses inside loop
            //loop = length of the loop
            //Part I
            int m=n+1-(y-x),loop=y-x+1;
            for(int i=m-2;i>=0;i--)
                v[i] = v[i+1]+2;

            //If l is odd
            if(loop&1){
                //Part II
                v[0]+=(loop-1)*2;
                for(int i=1;i<loop/2;i++)
                    v[i] += loop*2;
                
                //Part III
                for(int i=0;i<left;i++)
                    v[i+1]+=2;
                int mini=min(loop/2-1,left),maxi=loop/2+left;
                for(int i=2;i<maxi;i++)
                    v[i] += 4*min(min(i-1,maxi-i),mini);
                
                for(int i=0;i<right;i++)
                    v[i+1]+=2;
                mini=min(loop/2-1,right),maxi=loop/2+right;
                for(int i=2;i<maxi;i++)
                    v[i] += 4*min(min(i-1,maxi-i),mini);
            }
            //If l is even
            else{
                //Part II
                v[0]+=(loop-1)*2;
                for(int i=1;i<loop/2-1;i++)
                    v[i] += loop*2;
                v[loop/2-1] += loop;

                //Part III
                for(int i=0;i<left;i++)
                {
                    v[i+1]+=2;
                    v[i+loop/2]+=2;
                }
                int mini=min(loop/2-2,left),maxi=loop/2+left-1;
                for(int i=2;i<maxi;i++)
                    v[i] += 4*min(min(i-1,maxi-i),mini);
                
                for(int i=0;i<right;i++)
                {
                    v[i+1]+=2;
                    v[i+loop/2]+=2;
                }
                mini=min(loop/2-2,right),maxi=loop/2+right-1;
                for(int i=2;i<maxi;i++)
                    v[i] += 4*min(min(i-1,maxi-i),mini);
            }
        }
        return v;
    }
};