// 2582. Pass the Pillow
// LeetCode : Easy 06-07-2024

int passThePillow(int n, int time) {
        int i=1;
        bool flag=false;
        while(time!=0)
        {
            if(i==n && !flag)
            {
                flag=true;
                continue;
            }
            if(i==1 && flag)
            {
                flag=false;
                continue;
            }
            if(!flag)
            {
                i++;
                time--;
            }
            if(flag)
            {
                i--;
                time--;
            }
        }
        return i;
    }
