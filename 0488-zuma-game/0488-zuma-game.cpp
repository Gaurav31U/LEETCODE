class Solution {
public:
    string removeConsecutiveTriplets(string str) {
        bool changed;
        do {
            changed = false;
            int n = str.length();
            string temp;

            for (int i = 0; i < n;) {
                int j = i;
                while (j < n && str[j] == str[i]) j++;
                if (j - i >= 3) {
                    changed = true;
                } else {
                    temp.append(str.substr(i, j - i));
                }
                i = j;
            }

            str = temp;
        } while (changed);

        return str;
    }

    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());

        queue<pair<string, string>> boardQueue;
        queue<int> stepQueue;
        unordered_set<string> visited;

        boardQueue.push({board, hand});
        stepQueue.push(0);
        visited.insert(board + "+" + hand);

        while (!boardQueue.empty()) {
            auto [curBoard, curHand] = boardQueue.front();
            int curStep = stepQueue.front();
            boardQueue.pop();
            stepQueue.pop();

            for (int i = 0; i <= curBoard.size(); ++i) {
                for (int j = 0; j < curHand.size(); ++j) {
                    if (i > 0 && curBoard[i - 1] == curHand[j]) continue;

                    bool shouldTry = (i < curBoard.size() && curBoard[i] == curHand[j]) ||
                                     (i > 0 && curBoard[i - 1] == curBoard[i] && curBoard[i] != curHand[j]);

                    if (shouldTry) {
                        string newBoard = removeConsecutiveTriplets(curBoard.substr(0, i) + curHand[j] + curBoard.substr(i));
                        string newHand = curHand.substr(0, j) + curHand.substr(j + 1);

                        if (newBoard.empty()) return curStep + 1;

                        string stateKey = newBoard + "+" + newHand;
                        if (visited.insert(stateKey).second) {
                            boardQueue.push({newBoard, newHand});
                            stepQueue.push(curStep + 1);
                        }
                    }
                }
            }
        }
        return -1;
    }
};