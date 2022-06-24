#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    // Time: O(n^2) / Space: O(1)
    int maxAreaBruteForce(vector<int>& height) {
        int max_area = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = 0; j < height.size(); j++) {
                int area = min(height[i], height[j]) * (j - i);
                max_area = max(area, max_area);
            }
        }
        return max_area;
    }

    // Time: O(nlogn) / Space: O(n)
    int maxAreaBST(vector<int>& height) {
        // initialize containers
        vector<pair<int, int>> h_idx; // height-index pairs
        set<int> bst; // BST for storing indices (for calculating width)
        // push values into the containers
        for (int i = 0; i < height.size(); i++) {
            h_idx.push_back(make_pair(height[i], i));
            bst.insert(i);
        }
        sort(h_idx.begin(), h_idx.end()); // sort (ascending)
        int max_area = 0;
        for (int i = 0; i < height.size(); i++) {
            int h = h_idx[i].first;
            int idx = h_idx[i].second;
            int leftmost = *(bst.begin());
            int rightmost = *(bst.rbegin());
            max_area = max(h * max(idx - leftmost, rightmost - idx), max_area);
            bst.erase(idx);
        }
        return max_area;
    }

    // Time: O(n) / Space: O(1)
    int maxAreaTwoPointers(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;
        while (j > i) {
            int hi = height[i];
            int hj = height[j];
            int area = min(hi, hj) * (j - i);
            max_area = max(area, max_area);
            if (hi < hj) {
                i++;
            } else {
                j--;
            }
        }
        return max_area;
    }
};