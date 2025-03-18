#include <iostream>
using namespace std;
class Graphs
{
private:
    int** Matrix;
    int vertices;// total number of vertices
    bool isDirected; // 0 for undirected, 1 for directed
public:
    Graphs(int Tvertices, bool dir)
    {
        vertices = Tvertices;
        isDirected = dir;
        Matrix = new int* [vertices];
        for (int i = 0; i< vertices; i++)
        {
            Matrix[i] = new int[vertices];
        }
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                 Matrix[i][j]=0;
            }
            cout << endl;
        }
    }
    Graphs(const Graphs& obj);
    Graphs(string fName);
    void addEdge(int x, int y)
    {
        if (isDirected == 0)
        {
            Matrix[x][y] = 1;
            Matrix[y][x] = 1;
        }
        else
        {
            Matrix[x][y] = 1;
        }
    }
    void removeEdge(int x, int y)
    {
        if (isDirected == 0)
        {
            Matrix[x][y] = 0;
            Matrix[y][x] = 0;

        }
        else
            Matrix[x][y] = 0;
    }
    bool isConnected(int x, int y)
    {
        if (Matrix[x][y] = 1)
            return true;
    }
    int getIndegree(int x)
    {
        //if (isDirected == 0)
        //{
            int count = 0;
            for (int i = 0; i < vertices; i++)
            {
                if (Matrix[x][i] == 1)
                {
                    count++;
                }
            }
            return count;
        //}
    }
    int getOutdegree(int x)
    {
        int count = 0;
        for (int i = 0; i < vertices; i++)
        {
            if (Matrix[i][x] == 1)
            {
                count++;
            }
        }
        return count;
    }
    void printAllAdjc(int x)
    {
        if (isDirected == 0)
        {
            cout << endl << "the adjacent vertices of " << x << "are :" << endl;
            for (int i = 0; i < vertices; i++)
            {
                if (Matrix[x][i] == 1)
                {
                    cout << i << endl;
                }
            }
        }
        else
        {
            for (int i = 0; i < vertices; i++)
            {
                if (Matrix[i][x] == 1)
                {
                     cout << i << endl;;
                }
            }
            for (int i = 0; i < vertices; i++)
            {
                if (Matrix[x][i] == 1)
                {
                    cout << i<< endl;;
                }
            }

        }
    }
    bool isComplete();// is every node connected to any other node
    void printGraph()// print the whole Matrix
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j< vertices; j++)
            {
                cout << Matrix[i][j];
            }
            cout << endl;
        }
    }
    ~Graphs()
    {
        for (int i = 0; i < vertices; i++)
        {
            delete Matrix[i];
        }
        delete[]Matrix;
    }
};
int main()
{
    Graphs g(5,0);
    g.addEdge(1, 2);
    g.addEdge(1, 0);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.printGraph();
    if (g.isConnected(1, 0) == true)
    {
        cout << endl << "they are connected" << endl;
    }

    return 0;
}
