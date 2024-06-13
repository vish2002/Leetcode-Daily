// 2037. Minimum Number of Moves to Seat Everyone
// LeetCode: Easy 13-06-2024

// Sorting + Greedy 
int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n=students.size();
        sort(begin(seats),end(seats));
        sort(begin(students),end(students));
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=abs(seats[i]-students[i]);
        }
        return sum;
    }
