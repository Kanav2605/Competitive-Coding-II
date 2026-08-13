class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mpp;
        int n = fruits.size();
        int low = 0;
        int size = 0;

        for(int high = 0;high<n;high++) {
            mpp [fruits[high]]++;
            while(mpp.size()>2) {
                mpp[fruits[low]]--;

                if(mpp[fruits[low]]== 0) {
                    mpp.erase(fruits[low]);
                }
                low++;
            }
            size = max(size, high-low+1);
        }
        return size;
    }
};