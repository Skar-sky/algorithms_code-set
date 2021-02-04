// 贪心算法即是利用贪心的策略，保证每次操作都是局部最优的，从而使得最终得到的结果是全局最优的
#include<iostream>
// 1.分发饼干问题：有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃最多一个饼干，且只有饼干的大小大于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩子可以吃饱。
// leet_code题号：455
// 暴力解法：
int findContentChildren(vector<int>& g, vector<int>& s) {
    int num=0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    for(int i = 0;i<g.size();i++){
        for(int j = 0;j<s.size();j++){
            if(s[j]>=g[i]){
                s[j]=0;
                g[i]=0;
                break;
            }
        }
        if(g[i]==0){
            num++;
        }
    }
    return num;
}

// 降低时间复杂度为o(log(m)+log(n))
int findContentChildren(vector<int>& g, vector<int>& s){
    int num=0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    for(int i=0,j=0;i<g.size() && j<s.size();i++,j++){
        while(j < s.size() && s[j] < g[i]){
            j++;
        }
        if(j < s.size()){
            num++;
        }
    }
    return num;
}


// 2.(leet-code题号：135)一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所有孩子至少要有一个糖果。求解最少需要多少个糖果。
// 解题思路：从左到右，再从右至左，通过两次比较，得到满足要求的最小序列
int candy(vector<int>& ratings) {
    int size = ratings.size();
    if(size < 2){
        return size;
    }
    vector<int>num(size, 1);
    for(int i = 1;i<size;i++){
        if(ratings[i] > ratings[i-1]){
            num[i] = num[i-1] + 1;
        }
    }
    for(int j =size-1;j>=1;j--){
        if(ratings[j-1] > ratings[j]){
            num[j-1] = max(num[j-1],num[j]+1);
        }
    }
    return accumulate(num.begin(),num.end(),0);
}

// 3.(leet-code题号：435)给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
