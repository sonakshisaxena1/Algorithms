//This theorem is used to calculate the number of spanning trees possible

#include<bits/stdc++.h>
#define V 4
#define N 3
using namespace std;



void kirchoff(int G[V][V])
{
	int degree[V];

	memset(degree, 0, V);

	for(int i = 0 ; i < V ; i++)
		for(int j = 0; j < V; j++)
		{
			degree[i] = degree[i] + G[i][j];

		}

	int L[V][V];
	for(int i =0 ; i < V ; i++)
		for(int j = 0 ; j < V ; j++)
			if(i == j)
				L[i][j] = degree[i];
			else
				L[i][j] = -1;
 	
 	int M[V-1][V-1];
 	for(int i = 1 ; i < V ; i++)
 		for(int j = 1; j < V; j++)
 			M[i][j] = L[i][j];

 	cout<<  determinantOfMatrix(M[V-1][V-1]);
 	//Find the determinant of the Matrix m and that would be the result.
 	// Refer the following for finding the determinant of a given matrix
 	// https://www.geeksforgeeks.org/determinant-of-a-matrix/ 

 	
 	
} 

int main()
{
	int G[V][V]= {{0, 0, 1, 1},
			{0, 0, 1, 1},
			{1, 1, 0, 1},
			{1, 1, 1, 0}
		   };

	bool flag = true;
	for(int i =0 ; i < V ; i++)
		{
			if(flag == true)
				{for(int j = 0 ; j < V ; j++)
									if(G[i][j] != 1)
									{
										flag = false;
										break;
									}}
			else
				break;
		}

	if(flag == true)
		cout << "Number of spanning trees is: " << pow(V, V-2);

	else
		kirchoff(G);
	return 0;

}