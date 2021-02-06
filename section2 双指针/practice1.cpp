// 1.(leet-code题号：167)两数之和：输入有序数组
// 利用双指针的思想，在区间(i,j)内进行讨论
vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size()-1;
    int res;
    while(i < j){
        res = numbers[i] + numbers[j];
        if(res < target){
            i++;
        }
        else if(res > target){
            j--;
        }
        else{
            break;
        }
    }
    return vector<int>{i+1,j+1};
}



// 2.(leet-code题号：88)合并两个有序数组
// 该题可以使用传统的算法实现，即先合并，后排序，但是其时间复杂度和空间复杂度略高；我们这里可以使用三个指针，分别指示两个数组（大于0的部分）的末端以及第一个数组全体的末端
// 法一：传统的向量插入和排序
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i = 0, j = 0;i<nums1.size() && j<nums2.size();i++){
        if(nums1[i] == 0){
            nums1[i] = nums2[j];
            j++;
        }
    }
    sort(nums1.begin(),nums1.end());
}

// 法二：三个指针来标示位置
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int p1 = m-1;
    int p2 = n-1;
    int p3 = m+n-1;
    while(p2 >= 0){
        if(p1 >= 0){
            if(nums1[p1] >= nums2[p2]){
                nums1[p3--] = nums1[p1--];
            }
            else{
                nums1[p3--] = nums2[p2--];
            }
        }
        else{
            nums1[p3--] = nums2[p2--];
        }
    }
}



// 3.(leet-code题号：142)快慢指针
// 两种方法：第一个是最容易想到的：将地址写入到哈希表中
ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> visited;
    while (head != nullptr) {
        if (visited.count(head)) {
            return head;
        }
        visited.insert(head);
        head = head->next;
    }
    return nullptr;
}

// 利用环形指针，也即快慢指针(Floyd判圈法)，即最开始设置fast和slow指针，fast每次向前走两步，slow向前走1步，若fast向前走到nullptr，则没有环状链表；fast和slow第一次相遇表示有环状；此时设置fast指针为head，再与slow一同向前走一步，最后第二次相遇时的节点即为环状入口.
// 具体数学公式的推导参见附件
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    do{
        if(fast == nullptr || fast->next == nullptr){
            return nullptr;
        }
        fast = fast->next->next;
        slow = slow->next;
    }while(fast != slow);
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

