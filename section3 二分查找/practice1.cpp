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