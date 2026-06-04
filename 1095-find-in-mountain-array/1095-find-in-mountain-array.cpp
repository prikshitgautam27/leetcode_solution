/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 * public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    // Finds the index of the highest element using minimal API calls
    int peakElement(MountainArray &mountainArr) {
        int lo = 0;
        int hi = mountainArr.length() - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                lo = mid + 1; // Peak must be to the right
            } else {
                hi = mid;     // Peak could be mid or to the left
            }
        }
        return lo;
    }

    // Binary search on the strictly increasing portion
    int findasc(int target, MountainArray &mountainArr, int lo, int hi) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;
            else if (val < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1; // Fixed: returned integer instead of string
    }

    // Binary search on the strictly decreasing portion
    int finddsc(int target, MountainArray &mountainArr, int lo, int hi) {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;
            else if (val > target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1; // Fixed: returned integer instead of string
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int hi = mountainArr.length() - 1;
        int index = peakElement(mountainArr);
        
        // Always search the left (ascending) side first to find the minimum index
        int left = findasc(target, mountainArr, 0, index);
        if (left != -1) return left;
        
        // Search the right (decreasing) side if not found on the left
        return finddsc(target, mountainArr, index + 1, hi);
    }
};
