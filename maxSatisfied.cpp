// 1052. Grumpy Bookstore Owner
// Leetcode : Medium 21-06-2024

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        int n=grumpy.size();
        for(int i=0;i<customers.size();i++)
        {
            if(grumpy[i]==0)
            {
                sum+=customers[i];
            }
        }
        int maxi=sum;
        for(int i=0;i<=(n-minutes);i++)
        {
            int temp=sum;
            for(int j=i;j<i+minutes;j++)
            {
                if(grumpy[j]==1)
                {
                    temp+=customers[j];
                    maxi=max(maxi,temp);
                }
            }
        }
        return maxi;
    }
