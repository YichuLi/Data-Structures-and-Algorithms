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
        int p = randomized_partition(nums, start, end);
        quickSort(nums, start, p-1);
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
    vector<int> nums = {-74,48,-20,2,10,-84,-5,-9,11,-24,-91,2,-71,64,63,80,28,-30,-58,-11,-44,-87,-22,54,-74,-10,-55,-28,-46,29,10,50,-72,34,26,25,8,51,13,30,35,-8,50,65,-6,16,-2,21,-78,35,-13,14,23,-3,26,-90,86,25,-56,91,-13,92,-25,37,57,-20,-69,98,95,45,47,29,86,-28,73,-44,-46,65,-84,-96,-24,-12,72,-68,93,57,92,52,-45,-2,85,-63,56,55,12,-85,77,-39};
    sortArray(nums);
    cout << "hello" << endl;
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }

    return 0;
}