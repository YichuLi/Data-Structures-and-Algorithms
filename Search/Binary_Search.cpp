// LeetCode 704. Binary Search -Easy
// Given an array of integers nums which is sorted in ascending order, 
// and an integer target, write a function to search target in nums. 
// If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
//  

// Constraints:

// 1 <= nums.length <= 104
// -104 < nums[i], target < 104
// All the integers in nums are unique.
// nums is sorted in ascending order.

#include <vector>
using namespace std;

class Solution_704 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid;
        if(target >= nums[left] && target <= nums[right]){
            while(left <= right){
                mid = left + (right - left) / 2;
                if(target < nums[mid]){
                    right = mid - 1;
                }
                else if(target > nums[mid]){
                    left = mid + 1;
                }
                else{
                    return mid;
                }
            }
        }
        return -1;
    }
};

// LeetCode 34. Find First and Last Position of Element in Sorted Array -Medium
// Given an array of integers nums sorted in non-decreasing order, 
// find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109
class Solution_34 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPos = findFirstPos(nums, target);
        int lastPos = findLastPos(nums, target);
        
        if(lastPos - firstPos + 1 == 0) return {-1, -1};
        return  {firstPos, lastPos};
    }
    
private:
    int findFirstPos(vector<int>& nums, int target){
        int left = -1, right = nums.size();
        while(right - left != 1){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return right;
    }
    
    int findLastPos(vector<int>& nums, int target){
        int left = -1, right = nums.size();
        while(right - left != 1){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};