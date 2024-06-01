// Score of a String 
// EASY
// 01-06-2024

int scoreOfString(string s) {
        int score=0;
        for(int i=0;i<s.length()-1;i++)
        {
            score+=abs(s[i]-s[i+1]);
        }
        return score;
    }
