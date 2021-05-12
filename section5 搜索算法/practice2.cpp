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
