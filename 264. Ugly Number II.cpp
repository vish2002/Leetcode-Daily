// 264. Ugly Number II
// LeetCode : Medium 18-08-2024

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        int i2;
        int i3;
        int i5;

        i2=i3=i5=1;

        arr[1]=1;
        for(int i=2;i<=n;i++)
        {
            int i2uglynumber = arr[i2]*2;
            int i3uglynumber = arr[i3]*3;
            int i5uglynumber = arr[i5]*5;

            int minuglynumber=min({i2uglynumber,i3uglynumber,i5uglynumber});

            arr[i]=minuglynumber;

            if(minuglynumber==i2uglynumber)i2++;
            if(minuglynumber==i3uglynumber)i3++;
            if(minuglynumber==i5uglynumber)i5++;
        }
        return arr[n];
    }
};
