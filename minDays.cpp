// 1482. Minimum Number of Days to Make m Bouquets
// Leetcode : Medium 19-06-2024

// Intution : Binary Search on answer 
// TC: O(NLog(Max(Bloomday)))
bool canmake(vector<int>& bloomDay, int mid, int m, int k) {
    int Ccount = 0;
    int Bcount = 0;
    for (int i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] <= mid) {
            Ccount++;
        } else {
            Ccount = 0;
        }
        if (Ccount == k) {
            Bcount++;
            Ccount = 0;
        }
    }
    return Bcount >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
  if (bloomDay.size() < static_cast<long long>(m) * k) return -1;

    int low = 1; // Ensure days start from 1
    int high = *max_element(begin(bloomDay), end(bloomDay));
    int mincount = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canmake(bloomDay, mid, m, k)) {
            mincount = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return mincount;
}
