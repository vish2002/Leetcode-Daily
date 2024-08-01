// 2678. Number of Senior Citizens
// LeetCode : Easy 01-08-2024

  int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0;i<details.size();i++)
        {
            string temp="";
            temp=details[i].substr(11,2);
            int x=stoi(temp);
            if(x>60)count++;
        }
        return count;
    }
