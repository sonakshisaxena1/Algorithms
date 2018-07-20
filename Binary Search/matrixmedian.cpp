#include<bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int> > &A) {
    int min = A[0][0], max = A[0][0];
    int n = A.size(), m = A[0].size();
    for (int i = 0; i < n; ++i) {
        if (A[i][0] < min) min = A[i][0];
        if (A[i][m-1] > max) max = A[i][m-1];
    }

    int element = (n * m + 1) / 2;
    while (min < max) {
        int mid = min + (max - min) / 2;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += upper_bound(&A[i][0], &A[i][m], mid) - &A[i][0];
        if (cnt < element)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main()
{
	vector<int> A;
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			A[i].push_back(x);
		}

	findMedian(A);
	return 0;
}