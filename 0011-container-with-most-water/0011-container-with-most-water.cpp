class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // Calculate current area
            int current_height = min(height[left], height[right]);
            int width = right - left;
            int area = current_height * width;
            
            // Update the maximum area found
            max_area = max(max_area, area);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
