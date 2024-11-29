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
	int n = 11; //Number of nodes
	vector<vector<pair<int, int>>> graph(n);

	//Example graph
	graph[0] = { {1,12}, {2,15}, {3, 4} }; // first - node, second value is the distance
	graph[1] = { {0,12},{2,13},{4,6} };
	graph[2] = { {0,15},{1,13},{5,20},{6,7} };
	graph[3] = { {0,4},{7,2} };
	graph[4] = { {1,6},{5,25},{8,10} };
	graph[5] = { {2,20},{4,25},{8, 8} };
	graph[6] = { {2,7},{7,1},{9,19} };
	graph[7] = { {3,2},{6,1},{10,13} };
	graph[8] = { {4,10},{5,8},{9,30} };
	graph[9] = { {6,19},{8,30},{10,23} };
	graph[10] = { {7,13},{9,23} };

	dijkstra(graph, 0); // start from node 0...

	return 0;
}