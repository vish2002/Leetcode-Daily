// 1395. Count Number of Teams
// LeetCode : Medium 29-07-2024

// Intuitive Approach 
int numTeams(vector<int>& rating) {
        int teams=0;
        int n=rating.size();
        for(int i=1;i<n-1;i++)
        {
            int countsmallerleft=0;
            int countlargerleft=0;
            int countsmallerright=0;
            int countlargerright=0;

            for(int j=0;j<i;j++)
            {
                if(rating[j]<rating[i])
                {
                    countsmallerleft++;
                }
                else countlargerleft++;
            }
            for(int j=n-1;j>i;j--)
            {
                if(rating[j]<rating[i])
                {
                    countsmallerright++;
                }
                else countlargerright++;
            }
            teams+=countsmallerleft*countlargerright+countlargerleft*countsmallerright;
        }
        return teams;
    }


// Recursive Approach (gave TLE)

class Solution {
public:
int ans;
    void solve(int i,int prev,vector<int>& arr,int count,bool flag)
    {
        if(i>=arr.size())
        {
            if(count==3)
            {
                ans++;
            }return;
        }
        if(count == 3)
        {
            ans++;
            return;
        }
        if(arr[i]>prev)
        {
            if(!flag)
            {
                solve(i+1,arr[i],arr,count+1,flag);
            }
        }
        else
        {
            if(flag == 1 || count==1)
            solve(i+1,arr[i],arr,count+1,1);
        }
        
        solve(i+1,prev,arr,count,flag);

    }
    int numTeams(vector<int>& rating) {
        // subsequence problem
        ans=0;
        solve(0,-1,rating,0,0);
        return ans;
    }
};
