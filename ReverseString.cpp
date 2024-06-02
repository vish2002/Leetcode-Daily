// 344. Reverse String
// Leetcode:Easy 02-06-2024

void swap(char &x,char &y)
    {
        char temp=y;
        y=x;
        x=temp;
    }
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            swap(s[i],s[n-i-1]);
        }
    }
