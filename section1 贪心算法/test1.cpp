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


// 2.   