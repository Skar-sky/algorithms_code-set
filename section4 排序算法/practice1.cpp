// 1.(leet-code题号：215)数组中的第K个最大元素
// 为了便于回顾选择排序，该题我们选择直接对序列进行选择排序以得到一个完整的排序向量，然后再找到向量中第K个最大元素；该题比较简单的解法是通过选取枢(也即我们这里用的pivot)，将其于K进行比较，用二分法来计算；
int findKthLargest(vector<int>& nums, int k) {
    quicksort(nums, 0, nums.size()); //这里为何为num.size()，主要是考虑到两个元素的情况，具体原因可以参加代码执行结果
    return nums[nums.size() - k];
}
void quicksort(vector<int>& nums, int start, int end){
    if(start+1 >= end){
        return;
    }
    int l = start, r = end - 1, pivot = nums[start];
    while(l < r){
        while((l < r) && (nums[r] >= pivot)){
            r--;
        }
        nums[l] = nums[r];
        while((l < r) && (nums[l] <= pivot)){
            l++;
        }
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    quicksort(nums, start, l);
    quicksort(nums, l+1, end);
}



// 2.(leet-code题号：347)前K个高频元素
