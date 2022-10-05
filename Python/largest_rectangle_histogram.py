class Solution:
    # @param height, a list of integer
    # @return an integer
    def largestRectangleArea(self, height):
        n = len(height)

        # left[i], right[i] represent how many bars are >= than the current bar

        left = [1] * n
        right = [1] * n
        max_rect = 0

        # calculate left
        for i in range(0, n):
            j = i - 1
            while j >= 0:
                if height[j] >= height[i]:
                    left[i] += left[j]
                    j -= left[j]
                else: break

        # calculate right
        for i in range(n - 1, -1, -1):
            j = i + 1
            while j < n:
                if height[j] >= height[i]:
                    right[i] += right[j]
                    j += right[j]
                else: break

        for i in range(0, n):
            max_rect = max(max_rect, height[i] * (left[i] + right[i] - 1))

        return max_rect
