// 4.(leet-code题号：154)寻找旋转排序数组中的最小值
// 此题思路实质上是借鉴了前者关于旋转数组的思想
int findMin(vector<int>& nums) {
    int pos = 0;
    if(nums.size() == 1){
        return nums[0];
    }
    if(nums[0] > nums[1]){
        return nums[1];
    }
    for(int i = 1;i<nums.size()-1;i++){
        if(nums[i] >= nums[i-1] && nums[i] > nums[i+1]){
            pos = i;
            break;
        }
    }
    if(pos == 0){
        return nums[0];
    }
    else{
        return nums[pos + 1];
    }
}



// 5.(leet-code题号：540)