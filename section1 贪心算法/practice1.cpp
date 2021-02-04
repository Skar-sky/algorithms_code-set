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