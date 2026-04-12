class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
if (intervals.empty()) return 0;

        // Step 1: Sort intervals based on their end times (ascending)
        // This ensures we always pick the interval that finishes earliest
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int removals = 0;
        // Step 2: Track the end time of the last interval we kept
        int last_end = intervals[0][1];

        // Step 3: Iterate through the rest of the intervals
        for (size_t i = 1; i < intervals.size(); ++i) {
            // If current interval starts before the last one ends, it's an overlap
            if (intervals[i][0] < last_end) {
                removals++;
            } else {
                // No overlap, update the last_end to current interval's end
                last_end = intervals[i][1];
            }
        }

        return removals;
           }
};