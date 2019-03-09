#include<bits/stdc++.h>

using namespace std;

int main()
{
	// ------------------U/U graph input---------------
	int node, query;
	scanf("%d%d", &node, &query);

	//Adjacency List for U/U graph
	vector<vector<int>> adjacencyList(node+1);

	//Adjacency Matrix for U/U graph
	int adjacencyMatrix[node+1][node+1];
	memset(adjacencyMatrix,0, sizeof(adjacencyMatrix));

	//Edge List for U/U graph
	vector<pair<int,int>> edgeList;

	//--------------------------------------------------
	
	for(int i=0;i<query;i++)
	{
		int n1, n2;
		scanf("%d%d", &n1, &n2);

		//Adjacency List input
		adjacencyList[n1].push_back(n2);
		adjacencyList[n2].push_back(n1);

		//Adjacency Matrix input
		adjacencyMatrix[n1][n2]=1;
		adjacencyMatrix[n2][n1]=1;

		//Edge List input
		edgeList.push_back({n1,n2});

	}

	//--------------------------------------------------

	for(int i=0;i<adjacencyList.size()-1;i++)
	{
		printf("%d: ", i);
		for(int j=0;j<adjacencyList[i].size();j++) printf("%d ", adjacencyList[i][j]);
		printf("\n");
	}

	printf("\n");

	for(int i=0;i<node;i++)
	{
		for(int j=0;j<node;j++) printf("%d ", adjacencyMatrix[i][j]);
		printf("\n");
	}

	printf("\n");

	for(int i=0;i<edgeList.size();i++) printf("(%d, %d)\n", edgeList[i].first, edgeList[i].second);

}