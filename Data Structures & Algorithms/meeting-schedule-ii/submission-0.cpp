/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& iv) {
        map<int,int>mpp;
        for(auto x:iv){
            mpp[x.start]++;
            mpp[x.end]--;
        }
        int prev=0,ans=0;
        for(auto [k,v]:mpp){
            prev+=v;
            ans=max(ans,prev);
        }
        return ans;
    }
};
