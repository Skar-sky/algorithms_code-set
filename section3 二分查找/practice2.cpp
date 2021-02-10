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



// 5.(leet-code题号：540)有序数组中的单一元素
// 该题思路主要还是二分思想，根据元素奇偶数的关系以及单元素的位置进行判定
int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid = 0;
    while(l < r){
        mid = (l + r)/2;
        bool areEven = (r - mid)%2 == 0;   //判断一侧的元素个数是否为偶数
        if(nums[mid] == nums[mid+1]){   //中间元素的相同元素在右边
            if(areEven){        //单个元素在右侧
                l = mid + 2;
            }
            else{
                r = mid - 1;
            }
        }
        else if(nums[mid] == nums[mid-1]){   //中间元素的相同元素在左边
            if(!areEven){        //单个元素在右侧
                l = mid + 1;
            }
            else{
                r = mid - 2;
            }
        }
        else{
            return nums[mid];
        }
    }
    return nums[l];
}