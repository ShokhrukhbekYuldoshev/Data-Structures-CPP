#include <iostream>
#include <vector>

class Graph
{
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices)
    {
        adjacencyList.resize(numVertices);
    }

    void addEdge(int source, int destination)
    {
        adjacencyList[source].push_back(destination);
        // Uncomment the following line for an undirected graph
        // adjacencyList[destination].push_back(source);
    }

    void printGraph()
    {
        for (int i = 0; i < numVertices; ++i)
        {
            std::cout << "Vertex " << i << ": ";
            for (int j = 0; j < adjacencyList[i].size(); ++j)
            {
                std::cout << adjacencyList[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Graph graph(5); // Create a graph with 5 vertices

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the graph
    graph.printGraph();

    return 0;
}
