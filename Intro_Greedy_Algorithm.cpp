#include<iostream>
#include<limits.h>
using namespace std;

/*
Greedy algorithm does not produce an optimal solution, but can yield locally optimal
solutions that approxiamte a globally optimal solution in a reasonable amount of time

The choice made by a greedy algorithm may depend on choices made so far,
but not on future choices or all the solutions to the subproblem.
It iteratively makes one greedy choice after another. (Not like dynamic programming
which makes decisions based on all the decisions made in previous stage)
*/


//Example: Dijkstra's Algorithm: Find the shortest path from a source vertex to all other vertices in a weighted graph

//define the number of vertices in the graph
#define V 9

int min_distance(int dist[], bool sptSet[]){//dist[] represents the distances from the source vertex to all other vertices, sptSet[]: boolean array to indicate whether a vertex is included in the shortest path tree(true) or not(false)
    int min = INT_MAX, min_index;//min is initialized as an infinitely infinite distance

    for (int v = 0; v < V; v++)
    {//iterate over all vertices in the graph (from 0 to v-1)
        if(sptSet[v] == false && dist[v] <= min){
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}


//this function is used to print the results
void print_solution(int dist[], int n){
    cout<<"Vertex   Distance From Source"<<endl;
    for (int i = 0; i < V; i++)
    {
        cout<<i<<"              "<<dist[i]<<endl;
    }
}



void dijkstra(int graph[V][V], int src){
    //dist[] represents the distances from the source vertex to all other vertices, sptSet[]: boolean array to indicate whether a vertex is included in the shortest path tree(true) or not(false)
    int dist[V];
    bool sptSet[V];

    //initialize all distances as infinity and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;//distance of source vertex from itself is always 0

    //start to find the shortest path for all vertices
    for (int i = 0; i < V-1; i++)
    {
        int temp = min_distance(dist, sptSet);//find the minimum distance
        sptSet[temp] = true;//then include it in the shortest path tree
        
        //update dist value
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[temp][v] && dist[temp]!=INT_MAX && dist[temp]+graph[temp][v]<dist[v])
            {
                dist[v] = dist[temp] + graph[temp][v];
            }   
        }
    }
    print_solution(dist, V);
    
}




int main(){


    /*create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}