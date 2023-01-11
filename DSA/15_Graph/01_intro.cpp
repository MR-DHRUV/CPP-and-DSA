#include<bits/stdc++.h>
using namespace std;



int main()
{
    // A graph is the collection of edges and vertices
    // G(V,E)

    // directied graph : a graph in which edges have direction
    // self loop : an edge b/w same vertex

    // parallel edge : edges b/w same set of vertices
    // in degree : no of edges comming towards an vetex
    // in degree : no of edges going outwards from an vetex

    // simple graph : A graph with no selp loop and parallel edge is called simple graph
    
    // Non directed graph : a graph in which edges have no direction
    // in non directed graph there is only degree. i.e no of nodes connected to a vertex

    // connected components : parts/graphs which are connected togher
    /*
    
        1--------2          5
        |        |          |\         
        |        |          | 7                       
        |        |          |/
        3--------4----------6
    
        these two components are connected by vertices 4 and 6
        // if we remove vertex 4 or 6 graph will become unconnected again
        // 4 and 6 are called articulation points

        1--------2----------5
        |        |          |\         
        |        |          | 7                       
        |        |          |/
        3--------4----------6
        // above graph have no articulation points
    */


    // strongly connected components : components of di-graphs in which we can reach every vertex from every other vertex 
    // cycle : circular path/ circuit

    // Directed Acyclic Graph(DAG) : A directed graph with no cycle present in it
    // Topological ordering of vertices : Vertices of DAG can be arranged in a such a way that all vertices u and v which have an edge from u->v, u will come before v in linear ordering . this linear order is called topological order


    return 0;
}