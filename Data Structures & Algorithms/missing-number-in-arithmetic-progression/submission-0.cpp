class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n=arr.size();
        int d=(arr.back()-arr.front())/n;
        int l=0;
        int h=n-1;
        while(l<h){
            int m=l+(h-l)/2;
            if(arr[m]==arr.front()+m*d) l=m+1;
            else h=m;
        }
        return arr.front()+d*l;
    }
};
