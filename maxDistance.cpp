// 1552. Magnetic Force Between Two Balls
// Leetcode : Medium 20-06-2024

// Intution: Binary Search on answer.
bool canform(vector<int>& position, int m,int mid)
    {
        int prev=position[0];
        int count=1;
        for(int i=1;i<position.size();i++)
        {
            if((position[i]-prev)>=mid)
            {
                prev=position[i];
                count++;
            }
            if(count == m)return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(begin(position),end(position));
        int low=1;
        int high=position[n-1];
        int Maxmin=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(canform(position,m,mid))
            {
                Maxmin=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return Maxmin;
    }
