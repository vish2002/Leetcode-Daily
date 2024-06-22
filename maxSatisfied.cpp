// 1052. Grumpy Bookstore Owner
// Leetcode : Medium 21-06-2024

// Brute Force Approach 
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

// Optimised(Sliding Windows Approach)

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int unsat=0;
        int n=customers.size();
        for(int i=0;i<minutes;i++)
        {
            unsat+=customers[i]*grumpy[i];
        }
        int i=0;
        int j=minutes;
        int maxi=unsat;
        while(j<n)
        {
            unsat+=customers[j]*grumpy[j];
            unsat-=customers[i]*grumpy[i];
            
            maxi=max(maxi,unsat);
            j++;
            i++;
        }
        int ans=0;
        for(int i=0;i<customers.size();i++)
        {
            ans+=customers[i]*(1-grumpy[i]);
        }
        return ans+maxi;
    }
