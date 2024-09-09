// 2326. Spiral Matrix IV
// Leetcode : Medium 09-09-2024

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int startrow=0;
        int startcol=0;
        int endrow=m-1;
        int endcol=n-1;
        ListNode *temp=head;
        while(startrow<=endrow && startcol<=endcol){
            for(int i=startcol;i<=endcol;i++){
                if(temp){
                    ans[startrow][i]=temp->val;
                    temp=temp->next;
                }
            }
            startrow++;
            for(int i=startrow;i<=endrow;i++){
                if(temp){
                    ans[i][endcol]=temp->val;
                    temp=temp->next;
                }
            }
            endcol--;
            for(int i=endcol;i>=startcol;i--){
                if(temp){
                    ans[endrow][i]=temp->val;
                    temp=temp->next;
                }
            }
            endrow--;
            for(int i=endrow;i>=startrow;i--){
                if(temp){
                    ans[i][startcol]=temp->val;
                    temp=temp->next;
                }
            }
            startcol++;
        }
        return ans;
    }
};
