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
// 该题主要利用的是排序算法，因为算法时间复杂度要求为o(logn)，所以我们采取堆排序或者桶排序，下面我采用的算法主要是桶排序，具体的数据结构还需要进一步研究
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    int max_count = 0;
    for (const int & num : nums) {
        max_count = max(max_count, ++counts[num]);
    }
    vector<vector<int>> buckets(max_count + 1);
    for (const auto & p : counts) {
        buckets[p.second].push_back(p.first);
    }
    vector<int> ans;
    for (int i = max_count; i >= 0 && ans.size() < k; --i) {
        for (const int & num : buckets[i]) {
            ans.push_back(num);
            if (ans.size() == k) {
                break;
            }
        }
    }
    return ans;
}



// 3.(leet-code题号：451)根据字符出现频率排序
// 方法一：利用两次桶排序得到顺序，然后输出
string frequencySort(string s) {
    unordered_map<char, int> map;
    int maxCount(0);
    for (char c: s)
        maxCount = max(maxCount, ++map[c]);

    vector<vector<int>> buckets(maxCount + 1);
    for (auto i(map.begin()); i != map.end(); i++)
        buckets[i->second].push_back(i->first);

    string ans;
    for (int i(maxCount); i >= 1; i--)
        for (int j(0); j < buckets[i].size(); j++) {
            for (int z(0); z < i; z++)
                ans.push_back(buckets[i][j]);
        }
    return ans;
}

// 方法二：进行一次桶排序，然后利用易于理解的方法进行比较和输出
string frequencySort(string s) {
    unordered_map<char, int> mp;
    string res = "";
    for (auto ch : s) {
        mp[ch]++;
    }
    while (!mp.empty()) {
        int max = 0;
        char temp;//这个用来保存key值，
        for (unordered_map<char,int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            if (max < it->second) {
                max = it->second;//找到最大的值
                temp = it->first;//找到其对应的key，便于后面删除
            }
        }
        while (max) { //重复的次数
            res += temp;
            --max;
        }
        mp.erase(temp);//把这个key删除
    }
    return res;
}

