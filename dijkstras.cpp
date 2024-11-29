#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int INF = INT_MAX;

void dijkstra(const vector<vector<pair<int, int>>>& graph, int start)
{
	int n = graph.size();
	vector<int> distances(n, INF); // Initializing distances to INF
								   // it has n elements in it
	
	distances[start] = 0;


	priority_queue<pair<int, int>, vector<pair<int, int>>, 
	greater<pair<int, int>>> pq;

	pq.push({ 0, start }); // first value is distance, second is the node...


	while (!pq.empty())
	{
		int distance = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (distance > distances[node]) continue;
		
		for (auto neighbor : graph[node])
		{
			int next_node = neighbor.first;
			int weight = neighbor.second;
			int new_dist = weight + distance;

			if (new_dist < distances[next_node])
			{
				distances[next_node] = new_dist;
				pq.push({ new_dist, next_node });
			}
		}
	}

	cout << "Shortest distances from node " << start << " :\n";
	for (int i = 0; i < n; i++)
	{
		cout << " Node " << i << " : " << distances[i] << '\n';
	}
}

int main() {
	int n = 4; //Number of nodes
	vector<vector<pair<int, int>>> graph(n);

	//Example graph
	graph[0] = { {1,1}, {2,4} }; // first - node, second value is the distance

	graph[1] = { {0,1},{2,2},{3,5} };

	graph[2] = { {0,4},{1,2},{3,1} };

	graph[3] = { {1,5},{2,1} };

	dijkstra(graph, 0); // start from node 0...

	return 0;
}