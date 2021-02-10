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



// 3.(leet-code题号：81)旋转数组查找数字
// 该题主要还是利用二分查找的思想，对于旋转数组的分类，我们需要把握好相对应的准则和方法，但是该题的方法有面对用例编程之嫌
bool search(vector<int>& nums, int target) {
    int pos = 0;
    if(nums.size() == 1){
        if(nums[0] == target)
            return true;
        else
            return false;
    }
    if(nums[0] > nums[1]){
        pos = 0;
    }
    else{
        for(int i = 1;i<nums.size()-1;i++){
            if(nums[i] == nums[i-1] && nums[i] == nums[i+1]){
                pos = i;
            }
            else if((nums[i] > nums[i-1] && nums[i] > nums[i+1]) || (nums[i] >= nums[i-1] && nums[i] > nums[i+1])){
                pos = i;
                break;
            }
        }
    }
    vector<int>v0;
    for(int i = 0;i < (pos+1);i++){
        v0.push_back(nums[i]);
    }
    vector<int>v1;
    for(int i = pos+1;i < nums.size();i++){
        v1.push_back(nums[i]);
    }
    return (research(v0, target) || research(v1,target));    
}
bool research(vector<int>& number, int x){
    int l = 0, r = number.size(), mid = 0;
    while(l < r){
        mid = (l+r)/2;
        if(number[mid] > x){
            r = mid;
        }
        else if(number[mid] < x){
            l = mid + 1;
        }
        else{
            return true;
        }
    }
    return false;
}