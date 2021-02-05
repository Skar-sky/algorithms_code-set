// 1.(leet-code题号：605)种花问题
// 该种解法有面向用例编程的诟病之处，但是其算法时间复杂度和空间复杂度都比较小，且比较容易想到。
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if(n == 0 || (flowerbed.size() == 1 && flowerbed[0] == 0)){
        return true;
    }
    if(flowerbed.size() == 1 && flowerbed[0] == 1){
        return false;
    }
    if(flowerbed[0] == 0 && flowerbed[1] == 0){
        flowerbed[0] = 1;
        n--;
    }
    for(int i = 1;i < flowerbed.size()-1;i++){
        if(flowerbed[i] == 0 && flowerbed[i-1] ==0 && flowerbed[i+1] == 0){
            flowerbed[i] = 1;
            n--;
        }
    }
    if(flowerbed[flowerbed.size()-2] == 0 && flowerbed[flowerbed.size()-1] == 0){
        flowerbed[flowerbed.size()-1] = 1;
        n--;
    }
    if(n <= 0){
        return true;
    }
    else{
        return false;
    }
}



// 2.(leet-code题号：452)用最少数量的箭引爆气球
// 此题与leet-code中435题思路类似，只不过两者在区间排序上存在着一定差别
int findMinArrowShots(vector<vector<int>>& points) {
    if(points.size() == 1){
        return 1;
    }
    if(points.size() == 0){
        return 0;
    }
    sort(points.begin(), points.end(), [](const vector<int>u, const vector<int>v){
        return u[0] < v[0];
    });
    int num = 1, p = points[0][1];
    for(int i = 1;i< points.size();i++){
        if(points[i][0] > p){
            num++;
            p = points[i][1];
        }
        else{
            p = min(p, points[i][1]);
        }
    }
    return num;
}



// 3.(leet-code题号：763)划分字母区间
// 思路：可以利用双指针的形式，首先找到每个字母对应的最后一次出现的位置，然后利用start和end两个指针来指示位置，得到我们的目标字符串
vector<int> partitionLabels(string S) {
    int last[26];
    int start = 0, end = 0;
    vector<int>num; 
    for(int i = 0;i<S.length();i++){
        last[S[i] - 'a'] = i;
    }
    for(int i = 0;i<S.length();i++){
        end = max(end, last[S[i] - 'a']);
        if(i == end){
            num.push_back(end-start+1);
            start = end + 1;
        }
    }
    return num;
}



// 4.(leet-code题号：406)根据身高重建序列
// 应对这种问题，我们经常使用的方法就是对其中一个元素进行升序，另外一个进行降序处理；根据题目要求设置相应的元素插入的方法。
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int>u, const vector<int>v){
        return (u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]));
    });
    vector<int>index;
    vector<vector<int>>res;
    for(int i = 0;i<people.size();i++){
        index.insert(index.begin()+people[i][1], i);  //这里我们根据第二个元素进行相应排列插入。
    }
    for(int i = 0;i<people.size();i++){
        res.push_back(people[index[i]]);
    }
    return res;
}