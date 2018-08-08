//Largest area rectangle after column permutations

#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 5
int A[100][100];

int maxArea()
{

	int hist[R+1][C+1];
    for (int i=0; i<C; i++)
    {
      
        hist[0][i] = A[0][i];
 
        for (int j=1; j<R; j++)
            hist[j][i] = (A[j][i]==0)? 0: hist[j-1][i]+1;
    }
 
 
    
    for (int i=0; i<R; i++)
    {
        int count[R+1] = {0};
 
     
        for (int j=0; j<C; j++)
            count[hist[i][j]]++;
 
       
        int col_no = 0;
        for (int j=R; j>=0; j--)
        {
            if (count[j] > 0)
            {
                for (int k=0; k<count[j]; k++)
                {
                    hist[i][col_no] = j;
                    col_no++;
                }
            }
        }
    }
 
   	int curr_area, max_area = 0;
    for (int i=0; i<R; i++)
    {
        for (int j=0; j<C; j++)
        {
            curr_area = (j+1)*hist[i][j];
            if (curr_area > max_area)
                max_area = curr_area;
        }
    }
    return max_area;
}

int main()
{
	ios::sync_with_stdio(false);
	
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	bool A[R][C] = { {0, 1, 0, 1, 0},
                       {0, 1, 0, 1, 1},
                       {1, 1, 0, 1, 0}
                     };
    cout << "Area of the largest rectangle is " << maxArea();
    return 0;
	return 0;
}