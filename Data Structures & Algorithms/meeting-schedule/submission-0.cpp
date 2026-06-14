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
    bool canAttendMeetings(vector<Interval>& iv) {
        int n=iv.size();
        for(int i=0;i<n;i++){
            auto a=iv[i];
            for(int j=i+1;j<n;j++){
                auto b=iv[j];
                if(min(a.end,b.end)>max(a.start,b.start)) return false;
            }
        }
        return true;
    }
};
