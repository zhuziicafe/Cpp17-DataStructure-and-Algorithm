/*******************************************************************
* https://leetcode.com/problems/koko-eating-bananas/
* Medium
* 
* Conception: 
*  1. 
*
* Koko loves to eat bananas.
* There are N piles of bananas, the i-th pile has piles[i] bananas.
* The guards have gone and will come back in H hours.
*
* Koko can decide her bananas-per-hour eating speed of K.
* Each hour, she chooses some pile of bananas, and eats K bananas from that pile.
* If the pile has less than K bananas, she eats all of them instead,
* and won't eat any more bananas during this hour.
*
* Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
* Return the minimum integer K such that she can eat all the bananas within H hours.
*
* Example:
*
* Key:
*  1.
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1, hi = pow(10, 9);
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (!possible(piles, H, mi))
                lo = mi + 1;
            else
                hi = mi;
        }

        return lo;
    }

    // Can Koko eat all bananas in H hours with eating speed K?
    bool possible(vector<int>& piles, int H, int K) {
        int time = 0;
        for (int p: piles)
            time += (p - 1) / K + 1;
        return time <= H;
    }
};