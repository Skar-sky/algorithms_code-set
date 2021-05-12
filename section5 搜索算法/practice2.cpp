// 如何使用回溯算法进行搜索，摘自leet-code题目
// leet-code题号：46
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
// 该题实际上是一个全排列问题，因此我们可以运用回溯算法进行解答。该题最终使用不是我们能够显而易见的方法：即利用一个向量visited，表示当前的数是否被选中。而是选取了利用swap函数来将改向量分成两半，左边表示被选取的，而右边则是未被选取的
void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
    // 所有数都填完了
    if (first == len) {
        res.emplace_back(output);
        return;
    }
    for (int i = first; i < len; ++i) {
        // 动态维护数组
        swap(output[i], output[first]);
        // 继续递归填下一个数
        backtrack(res, output, first + 1, len);
        // 撤销操作
        swap(output[i], output[first]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > res;
    backtrack(res, nums, 0, (int)nums.size());
    return res;
}


// leet-code题号：47
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列
// 与上题不同之处在于本题有一个对数组的限制，即数组中的元素是可以重复的，因此我们就就需要对visited数组进行一个判断
class Solution {
    vector<int>visited;
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int first, vector<int> perm){
        if(first == nums.size()){
            res.emplace_back(perm);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(visited[i] ||(i > 0 && nums[i] == nums[i-1] && !visited[i-1])){      //注意：这里对!visited[i-1]的理解：表示第i-1位已经被visited
                continue;                  
            }
            perm.push_back(nums[i]);
            visited[i] = 1;
            backtrack(nums, res, first+1,perm);
            visited[i] = 0;
            perm.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>perm;
        visited.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, res, 0,perm);
        return res;
    }
};