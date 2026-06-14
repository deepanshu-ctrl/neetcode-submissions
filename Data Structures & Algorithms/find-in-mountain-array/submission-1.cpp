/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int t, MountainArray &ma) {
        int le=ma.length();
        int l=1,r=le-2,p=0;
        while(l<=r){
            int m=l+(r-l)/2;
            int le=ma.get(m-1);
            int mi=ma.get(m);
            int ri=ma.get(m+1);
            if(le<mi && mi<ri) l=m+1;
            else if(le>mi && mi>ri) r=m-1;
            else {p=m; break;}
        }
        l=0;
        r=p-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int val=ma.get(m);
            if(val<t) l=m+1;
            else if(val>t) r=m-1;
            else return m;
        }
        l=p;
        r=ma.length()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int val=ma.get(m);
            if(val<t) r=m-1;
            else if(val>t) l=m+1;
            else return m;
        }
        return -1;
    }
};