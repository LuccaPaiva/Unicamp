// A C++ program to check if a given graph is Eulerian or not
#include<iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

// A class that represents an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
    vector<int> in;
    vector<int> out;
public:
	// Constructor and destructor
	Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        for(int i = 0; i < V; i++) {
            in.push_back(0);
            out.push_back(0);
        }
    }

	~Graph() {
        delete [] adj;
        } // To avoid memory leak

	// function to add an edge to graph
	void addEdge(int v, int w);

	// Method to check if this graph is Eulerian or not
	int isEulerian();

	// Method to check if all non-zero degree vertices are connected
	bool isConnected();

	// Function to do DFS starting from v. Used in isConnected();
	void DFSUtil(int v, bool visited[]);

    void printGraph();

    void printCircuit(int start);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	out[v]++;
    in[w]++;
}

void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

// Method to check if all non-zero degree vertices are connected.
// It mainly does DFS traversal starting from
bool Graph::isConnected()
{
	// Mark all the vertices as not visited
	bool visited[V];
	int i;
	for (i = 0; i < V; i++)
		visited[i] = false;

	// Procura vertice nao conectado
	for (i = 0; i < V; i++)
		if (in[i] == 0 || out[i] == 0) {
            cout << " Vertice " << i << " é nao conexo\n";
			return false;
        }

	// Start DFS traversal from a vertex with non-zero degree
	DFSUtil(0, visited);

	// Check if all non-zero degree vertices are visited
	for (i = 0; i < V; i++)
	if (visited[i] == false && adj[i].size() > 0)
			return false;

	return true;
}

/* The function returns one of the following values
0 --> If graph is not Eulerian
2 --> If graph has an Euler Circuit (Eulerian) */
int Graph::isEulerian()
{
    // Se tiver um vertice com grau entrada != saida retorna 0
	for (int i = 0; i < V; i++)
		if (in[i] != out[i]) {
            cout << " Vertice " << i << " tem in != out\n";
			return 0;
        }
    cout << "Pra tds saida = entrada\n";
	// Check if all non-zero degree vertices are connected
	if (isConnected() == false) {
        cout << "È nao conexo\n";
		return 0;
    }
    cout << "È conexo\n";
	// If odd count is 2, then semi-eulerian.
	// If odd count is 0, then eulerian
	// Note that odd count can never be 1 for undirected graph
	return 1;
}

// A utility function to print the adjacency list
// representation of graph
void Graph::printGraph()
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
        cout << " in: " << in[v] << "\n out: " << out[v] << "\n";
    }
}

void Graph::printCircuit(int start)
{
	// adj represents the adjacency list of
	// the directed graph
	// edge_count represents the number of edges
	// emerging from a vertex
	unordered_map<int,int> edge_count;

	for (int i=0; i < V; i++)
	{
		//find the count of edges to keep track
		//of unused edges
		edge_count[i] = out[i];
	}

	if (!V)
		return; //empty graph

	// Maintain a stack to keep vertices
	stack<int> curr_path;

	// vector to store final circuit
	vector<int> circuit;

	// start from any vertex
	int curr_v = start; // Current vertex
    curr_path.push(start);

	while (!curr_path.empty())
	{
		// If there's remaining edge
		if (edge_count[curr_v])
		{
			// Push the vertex
			curr_path.push(curr_v);

			// Find the next vertex using an edge
			int next_v = adj[curr_v].back();

			// and remove that edge
			edge_count[curr_v]--;
			adj[curr_v].pop_back();

			// Move to next vertex
			curr_v = next_v;
		}

		// back-track to find remaining circuit
		else
		{
			circuit.push_back(curr_v);

			// Back-tracking
			curr_v = curr_path.top();
			curr_path.pop();
		}
	}

	// we've got the circuit, now print it in reverse
	for (int i = circuit.size() - 1; i >= 0; i--)
	{
		cout << circuit[i];
		if (i)
		cout<<" -> ";
	}
    cout << "\n";
}

void printLine()
{
    cout << "\n-----------------------------------------------------\n";
}


// Function to run test cases
int test(Graph &g)
{
	int res = g.isEulerian();
	if (res == 0) {
		cout << " graph is not Eulerian\n";
        return 0;
    }
	else {
		cout << " graph has a Euler cycle\n";
        return 1;
    }
    printLine();
}




// Driver program to test above function
int main()
{
	// Let us create and test graphs shown in above figures
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);
	g1.addEdge(3, 4);
	g1.addEdge(4, 0);
    g1.addEdge(4, 2);
    g1.addEdge(0, 4);
    g1.addEdge(2, 0);
    g1.printGraph();
    cout << "\n";
	int euler = test(g1);
    if(euler){
        g1.printCircuit(3);
    }

	return 0;
}
