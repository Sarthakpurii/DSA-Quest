class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int taskFreqMp[26] = {0};
        for (char c : tasks) {
            taskFreqMp[c - 'A']++;
        }
        
        sort(taskFreqMp, taskFreqMp + 26);
        
        int batchCnt = taskFreqMp[25];
        int vacantSlots = (--batchCnt) * n;
        for (int indx = 0; indx < 25; indx++) {
            vacantSlots -= min(taskFreqMp[indx], batchCnt);
        }
        
        return (vacantSlots > 0) ? tasks.size() + vacantSlots : tasks.size();
    }
};