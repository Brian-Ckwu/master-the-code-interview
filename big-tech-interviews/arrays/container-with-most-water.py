from typing import List

class Solution:
    # Time complexity: O(n^2) / Space complexity: O(1)
    def maxAreaBruteForce(self, height: List[int]) -> int:
        max_area = 0
        for i in range(0, len(height) - 1):
            for j in range(i, len(height)):
                hi = height[i]
                hj = height[j]
                area = min(hi, hj) * (j - i)
                max_area = max(area, max_area)

        return max_area
    
    # Time complexity: O(n) / Space complexity: O(1)
    def maxAreaTwoPointer(self, height: List[int]) -> int:
        # set the two pointers to the ends
        i = 0
        j = len(height) - 1
        max_area = 0
        while (j > i):
            hi = height[i]
            hj = height[j]
            area = min(hi, hj) * (j - i)
            max_area = max(area, max_area)
            if hi < hj:
                i += 1
            else:
                j -= 1
        return max_area