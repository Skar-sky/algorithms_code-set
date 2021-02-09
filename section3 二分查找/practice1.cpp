// 1.(leet-code题号：69)x的平方根
// 我们使用二分法的思想来计算这个过程
int mySqrt(int x) {
    if(x == 0){
        return 0;
    }
    long l = 1, r = x, mid = 0, sqrt = 0;
    while(l <= r){
        mid = (l+r)/2;
        sqrt = x/mid;
        if(sqrt == mid){
            return mid;
        }
        else if(sqrt < mid){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return r;
}



// 2.(leet-code题号：34)查找区间
// 该题主要是利用二分法来解题，我们注意到下限(也即第一个目标元素位置的查找)和上限(也即最后一个目标元素的查找)的过程
vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.empty()){
        return vector<int>{-1, -1};
    }
    int lower = lower_bound(nums, target);
    int upper = upper_bound(nums, target) - 1;
    if(lower == nums.size() || nums[lower] != target){
        return vector<int>{-1,-1};
    }
    return vector<int>{lower, upper};
}
int lower_bound(vector<int>& nums, int target){
    int l = 0, r = nums.size() , mid = 0; //使得我们的方法能够遍历所有的元素
    while(l < r){
        mid = (l + r)/2;
        if(nums[mid] >= target){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}
int upper_bound(vector<int>& nums, int target){
    int l = 0, r = nums.size(), mid = 0;
    while(l < r){
        mid = (l + r)/2;
        if(nums[mid] > target){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}