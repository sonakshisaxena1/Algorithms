//Length of the longest substring without repeating characters

#include<bits/stdc++.h>
using namespace std;

int longestUniqueSubsttr(string str)
{
	int start = 0;
	int end = 0;
	int n = str.size();

	int visited[27];
	
	for(int i = 1 ; i <= n; i++)
	{
		 visited[i] = -1;
	}

	int max_length = 0;
	int cur_length = 0;

	for(int i = 0; i < n; i++)
	{
		if(visited[(int)(str[i] - 'A' + 1)] != -1)
			{
				max_length = max(max_length, cur_length);

				start = visited[(int)(str[i] - 'A' + 1)] + 1;
				
				cur_length = end - start + 1;

				for(int i = 0; i < start; i++)
					visited[(int)(str[i] - 'A' + 1)] = -1;
			}

		else

			{
				visited[(int)(str[i] - 'A' + 1)] = i;
				cur_length++;
				end++;
			}

		

	}


	return (max_length);

}
int main()
{
	freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
	char str[] = "GEEKSFORGEEKS";
    
   	cout<<"The length of the longest non-repeating "
           "character substring is "<< longestUniqueSubsttr(str);
    return 0;
}