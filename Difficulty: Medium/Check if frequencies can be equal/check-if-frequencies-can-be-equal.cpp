class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
            // code here
        unordered_map<char, int> freq;
        for (char ch : s) 
            freq[ch]++;
    
        //if all freq are equal (no need to delete)
        unordered_map<int, int> freqCount;
        for (auto cnt : freq) 
            freqCount[cnt.second]++;
            
        if (freqCount.size() == 1) return true;
        
        // Try removing one character at a time
        for (auto it : freq) {
            freq[it.first]--;  // remove one occurrence
    
            unordered_map<int, int> freqCount;
            for (auto cnt : freq) {
                if (cnt.second > 0) freqCount[cnt.second]++;
            }
    
            if (freqCount.size() == 1) return true; // all frequencies same
    
            freq[it.first]++;  // backtrack
        }
    
        return false;
    }
};