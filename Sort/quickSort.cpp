#include <vector>
#include <ctime>
#include <iostream>
using namespace std;

void sortArray(vector<int>& nums);
int partition(vector<int>& nums, int start, int end);
int randomized_partition(vector<int>& nums, int start, int end);
void quickSort(vector<int>& nums, int start, int end);

int partition(vector<int>& nums, int start, int end){
    int pivot = nums[end];
    int i = start - 1;
    for(int j=start; j<end; j++){
        if(nums[j] < pivot){
            i++;
            swap(nums[j], nums[i]);
        }
    }
    swap(nums[i+1], nums[end]); // sort pivot to the right position
    return i+1;
}
    
int randomized_partition(vector<int>& nums, int start, int end){
    int p = rand() % (end - start + 1) + start;
    swap(nums[p], nums[end]);
    return partition(nums, start, end);
}

void quickSort(vector<int>& nums, int start, int end){
    if(start < end){
        int p = randomized_partition(nums, 0, end);
        quickSort(nums, 0, p-1);
        quickSort(nums, p+1, end);
    }
}

void sortArray(vector<int>& nums){
    srand((unsigned)time(NULL));    // random the time seed
    quickSort(nums, 0, nums.size()-1);
}

void bubbleSort(vector<int>& nums){
    int size = nums.size();
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }
    
}

int main()
{
    vector<int> nums = {1, 3, 7, 2, 9, 1, 33, 2, 643, 22, 12, 2};
    bubbleSort(nums);
    cout << "hello" << endl;
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }

    return 0;
}