// 1518. Water Bottles
// LeetCode : Easy 07-07-2024

int numWaterBottles(int numBottles, int numExchange) {
        int sum=numBottles;
        while(numBottles>=numExchange)
        {
        int x=numBottles/numExchange;
        int r=numBottles%numExchange;
        sum+=x;
        numBottles=x+r;
        }
        return sum;
    }
