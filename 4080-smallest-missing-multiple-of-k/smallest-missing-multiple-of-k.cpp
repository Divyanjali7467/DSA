class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int x : nums){
            s.insert(x);
        }
        int i=1;
        while(s.count(k*i)){
            i++;
        }
        return k*i;
    }
};