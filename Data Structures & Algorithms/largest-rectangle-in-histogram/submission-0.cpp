class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int ma=0;
        for(int i=0;i<n;i++){
            int he=h[i];
            int rm=i+1;
            while(rm<n && h[rm]>=he) rm++;
            int lm=i;
            while(lm>=0 && h[lm]>=he) lm--;
            rm--;
            lm++;
            ma=max(ma,he*(rm-lm+1));
        }
        return ma;
    }
};
