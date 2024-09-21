class Solution {
	public:
		using Freq = array<int, 26>;
		int countCompleteSubstrings(string word, int k) {
			int n = word.size();
			vector<Freq> freqs(n + 1);
			for(int i = 0; i < n; i++){
				freqs[i+1] = freqs[i];
				freqs[i+1][word[i] - 'a']++;
			}
			int l = 0;
			int res = 0;
			for(int i = 0; i < n; i++){
				if(i >= 1 && abs(word[i] - word[i-1]) > 2){
					l = i;
				}
				for(int c = 1; c <= 26; c++){
					int len = c * k;
					int start = i - len + 1;
					if(start < l) break;
					Freq diff_freq;
					int kcnt = 0;
					for(int j = 0; j < 26; j++){
						diff_freq[j] = freqs[i+1][j] - freqs[start][j];
						if(diff_freq[j] == k) kcnt++;
						if(diff_freq[j] >0 && diff_freq[j] != k) break;
					}
					if(kcnt == c) res++;
				}
			}
			return res;

		}
	};