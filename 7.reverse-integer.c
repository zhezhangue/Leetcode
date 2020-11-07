/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

// @lc code=start

#define  upperbound 2147493647
#define  lowerbound -2147483648

int reverse(int x){
    int result = 0;
    int low = 0,high = 0;
    int tag = 0, digit = 0, count = 0;

    // inverse the digit, via dividing the input into upper and lower partition
    tag = x>0 ? 1 : -1;

    while(x!=0){
        digit = x % 10;
        count ++;
        if(count < 6)
            high = high*10 + digit;
        else
            low = low*10 + digit;
        x /= 10;
    }

    //calculate the value of result
    if(high == -21474 && low == -83648)
        return -2147483648;

    if(high>21474 && low >= 10000)
        {
            printf("%d",high);
            return 0;
        }
    else{
        result = high;
        digit = low;
        count = 0;
        while(digit!=0)
        {
            digit /= 10;
            count++;
        }
        for(int i=0;i<count;i++)
            high *= 10;
        result = high + low;
    }
    printf("%d %d \n",result, tag);
    printf("%d",result);
    return result;
}
// @lc code=end

