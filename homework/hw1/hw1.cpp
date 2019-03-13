#include <bits/stdc++.h>
using namespace std;
#define max_nodes 300
int node, link;
int capacity[max_nodes][max_nodes], load[max_nodes][max_nodes]; // capacity = adjacency matrix
double cost[max_nodes][max_nodes];
struct Node // for dijkstra
{
    int b;
    double d; // b是點，d是可能的最短路徑長度。
};
struct Flows_path // for store the flow's path
{
    int id;
    vector<int> flow_path_node;
};
bool operator<(Node n1, Node n2) { return n1.d > n2.d; }
void dijkstra(int source, int *parent)
{
    double d[node];
    bool visit[node];
    priority_queue<Node> pq;
    memset(visit, false, sizeof(visit)); // initialize the visit and d
    for (int i = 0; i < node; i++)       // initialize the d
        d[i] = DBL_MAX;
    d[source] = 0;
    parent[source] = source;
    pq.push((Node){source, d[source]}); // push the source into priority_queque
    for (int i = 0; i < node; i++)
    {
        // 找出下一個要加入到最短路徑樹的點。
        int a = -1;
        while (!pq.empty() && visit[a = pq.top().b])
            pq.pop();
        if (a == -1)
            break;
        visit[a] = true;
        for (int b = 0; b < node; b++)
        {
            if (!visit[b] && d[a] + cost[a][b] < d[b])
            {
                d[b] = d[a] + cost[a][b];
                parent[b] = a;
                // 交由Priority Queue比較大小
                pq.push((Node){b, d[b]});
            }
        }
    }
}
int main()
{
    int linkId, firstNode, secondNode, cap;          // for adjacency matrix
    int requestFlow, flowId, source, dest, flowSize; // for requested flows
    int acceptedFlows = 0, totalThroughput = 0;
    int parent[max_nodes]; // store the parent node of each node
    bool accepted;         // for accepted or not
    vector<Flows_path> flows;
    freopen("request.txt", "r", stdin); // open input and output files
    freopen("result.txt", "w", stdout);
    cin >> node >> link;
    memset(capacity, INT_MAX, sizeof(capacity)); // initialize capacity, load and cost
    memset(load, 0, sizeof(load));
    for (int i = 0; i < node; i++)
        for (int j = 0; j < node; j++)
            cost[i][j] = DBL_MAX;
    for (int i = 0; i < link; i++) // input the adjacency matrix
    {
        cin >> linkId >> firstNode >> secondNode >> cap;
        capacity[firstNode][secondNode] = cap;
        capacity[secondNode][firstNode] = cap;
        cost[firstNode][secondNode] = DBL_MIN;
        cost[secondNode][firstNode] = DBL_MIN;
    }
    cin >> requestFlow;
    for (int i = 0; i < requestFlow; i++)
    {
        cin >> flowId >> source >> dest >> flowSize;
        // find the shortest path
        dijkstra(source, parent);
        accepted = 1;
        for (int vertex = dest; vertex != source; vertex = parent[vertex])
            if (load[vertex][parent[vertex]] + flowSize > capacity[vertex][parent[vertex]])
            {
                accepted = 0;
                break;
            }
        if (accepted == 0) // if reject the flow
            continue;
        acceptedFlows++;
        totalThroughput += flowSize;
        // store the flow's path
        vector<int> nodes;
        for (int vertex = dest; vertex != source; vertex = parent[vertex])
        {
            nodes.push_back(vertex); // store the nodes of the flow's path
            // update the load and cost
            load[vertex][parent[vertex]] += flowSize;
            load[parent[vertex]][vertex] += flowSize;
            if (capacity[vertex][parent[vertex]] <= load[vertex][parent[vertex]])
                cost[vertex][parent[vertex]] = DBL_MAX;
            else
                cost[vertex][parent[vertex]] = (double)load[vertex][parent[vertex]] / (capacity[vertex][parent[vertex]] - load[vertex][parent[vertex]]);
            cost[parent[vertex]][vertex] = cost[vertex][parent[vertex]];
        }
        nodes.push_back(source);                             // store the source in the path
        flows.push_back((struct Flows_path){flowId, nodes}); // push the full path into vector
    }
    // print out the result
    cout << acceptedFlows << "\t" << totalThroughput << "\n";
    for (int i = 0; i < flows.size(); i++)
    {
        cout << flows[i].id;
        for (int j = flows[i].flow_path_node.size() - 1; j >= 0; j--)
            cout << "\t" << flows[i].flow_path_node[j];
        cout << "\n";
    }
    return 0;
}