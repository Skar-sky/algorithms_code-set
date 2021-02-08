// 5.(leet-code题号：76)滑动窗口
// 该题的主题思路就是利用一个滑动窗口，也即r和l两个指针来确定最短字符串，但是关于临界值的问题有面向用例编程的嫌疑
string minWindow(string s, string t) {
    vector<int>nums(128,0);  //计算t中每个字符的次数
    vector<bool>flag(128,false);   //nums与flag的连用类似于哈希表，flag指示是否有该字符
    for(int i = 0;i<t.size();i++){
        flag[t[i]] = true;
        nums[t[i]]++;
    }
    int count = 0, l = 0, min_l = 0, min_size = s.size()+1;
    for(int r = 0;r<s.size();r++){
        if(flag[s[r]]){
            if(--nums[s[r]] >= 0){
                count++;
            }
            //若我们已经找到完全覆盖字符串t的部分，那么我们接下来的工作就是通过右移l指针，找到最短的部分
            while(count == t.size()){
                if(r-l+1 <= min_size){
                    min_l = l;
                    min_size = r-l+1;
                }
                if(flag[s[l]] && ++nums[s[l]] > 0){ //关于该条件的解释，只有当我们在l右移时，右移的字符是t中所含有的，同时不是多余的字符，我们才进行计数的减一
                    count--;
                }
                l++;
            }
        }
    }
    return min_size > s.size() ? "":s.substr(min_l, min_size);
}



// 6.(leet-code题号：633)平方数之和
// 利用双指针进行计算即可，类比于前面我们介绍的有序数组之和
bool judgeSquareSum(int c) {
    int i = 0, j = (int)(sqrt(c));
    long sum = 0;
    while(i <= j){
        sum = pow(i,2) + pow(j,2);
        if(sum < c){
            i++;
        }
        else if(sum > c){
            j--;
        }
        else{
            return true;
        }
    }
    return false;
}



// 8.(leet-code题号：680)验证回文字符串
// 该题需要考虑到时间复杂度的问题，不能单纯考虑o(n^2)的算法，下面就是o(n)算法的主要步骤
bool validPalindrome(string s) {
    int flag=0;
    if(Palindrome(s,0,s.size()-1)){
        return true;
    }
    for(int i = 0,j = s.length()-1;i < j;i++,j--){
        if(s[i] != s[j]){
            return (Palindrome(s,i,j-1) || Palindrome(s,i+1,j)); //因为我们只删去一个字符，所以我们只需要考虑i到j-1，i+1到j两种情况即可
        }
    }
    return true;
}

//构造判断回文字符串的函数
bool Palindrome(string s, int low, int high){
    for(int i = low, j = high; i<j;i++, j--){
        if(s[i] != s[j]){
            return false;
        }
    }
    return true;
}



// 9.(leet-code题号：524)通过删除字母匹配到字典中最长的单词
// 该题主要是采用三步，第一步：判断字典中的单词是否可以通过源字符串的删减得到；第二步：找到相匹配的最长的字符串；第三步：在最长的字符串中找到字典顺序最小的一个
string findLongestWord(string s, vector<string>& d) {
    int counter = 0;
    int max_index = 0;
    vector<int>max;
    for(int i = 0; i<d.size(); i++){
        counter = findword(s, d[i]);
        if(counter == d[i].size()){
            max.push_back(counter);
        }
        else{
            max.push_back(0);
        }
    }
    if(count(max.begin(),max.end(),0) == max.size()){
        return "";
    }
    else{
        max_index = max_element(max.begin(),max.end()) - max.begin();
        for(int i =0;i < max.size();i++){
            if(max[i] == max[max_index]){
                if(d[i]<d[max_index]){
                    max_index= i;
                }
            }
        }
        return d[max_index];
    }
}
int findword(string s, string d){
    int count=0;
    int index;
    for(int i = 0;i<d.size();i++){
        index = s.find(d[i]);
        if(index != s.npos){
            s = s.substr(index+1);
            count++;
        }
        else{
            count = 0;
            break;
        }
    }
    return count;
}
