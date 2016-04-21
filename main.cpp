    // vector<Edge> edges;
    // const int EDGES = edge_count;
    // for ( int i = 0; i < EDGES; i++ )
    //     edges.push_back( Edge(i) );
    // vector<Node> nodes;
    // const int NODES = vertices;
    // for ( int i = 0; i < NODES; i++ )
    //     nodes.push_back( Node(i) );


// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>

// using namespace std;


// int main() {

// 	/// order is first value.
// 	/// size is second value.


//     /// Open for reading and assert existence.
//     ifstream graph_file("graph.txt");
//     if ( !graph_file.good() ) {
//         cout << "Error opening file. Program ended." << endl;
//         exit(1);
//     }

//     /// Read file data into vector.
//     vector<char> file_data;
//     char token = ' ';
//     while ( graph_file >> token ) file_data.push_back(token);
//     const int ORDER = static_cast<int>(file_data.front()) - '0';
//     const int SIZE = static_cast<int>(file_data[1]-'0');
//     graph_file.close();

//     cout << "order: "

// 	return 0;
// }



/// node node weight

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
//#include "graphPack.h"

using namespace std;


// vector <int> minIncident(vector< vector<int> > edgeSet, int k, int m);
// int main() {

//   int vertices, edges;
//   int n;  // vertices
//   int m;  // edges

//   /// Get and display number of vertices and edges.
//   ifstream infile("graph.txt");
//   infile >> n >> m;
//   cout << endl << "The order of the graph is "<< n << endl;
//   cout <<"The size of the graph is " <<  m << endl << endl;

//   int edge;
//   vector <vector<int> > edgeSet;
//   for( int i = 0; i < m; i ++ ) {
//     vector<int> row;
//     for( int j = 0; j < 3; j++ ){
//       infile >> edge;
//       row.push_back(edge);
//     }
//     edgeSet.push_back(row);
//   }

//   int v = 0;          // Initialize Prims at vertex 0
//   vector <int> VH;    // VH is the vertex set of our tree
//   vector <int> T;     // 
//   VH.push_back(3);    // Initialize the vertex set of our tree
//   vector <int> edge1;
//   edge1 = minIncident(edgeSet, VH[0], m);

//   return 0;
// }

// vector <int> minIncident(vector<vector<int> > edgeSet, int k, int m){
//   int index = 0;
//   int cost = 0;
//   vector <int> edge;

//  //  cout << k << endl;
//  // for(int i = 0; i < m; i++)
//  //    if(k==edgeSet[i][0] || k == edgeSet[i][1])
//  //      edge.push_back(i);

//   cout << "The edges incident with VH are  " << endl;
//   for(int i = 0; i < edge.size(); i++)
//     cout << "edge " << edgeSet[edge[i]][0] << " " <<edgeSet[edge[i]][1] << " with cost "<< edgeSet[edge[i]][2] << endl;

//   cost = edgeSet[edge[0]][2];
//   for(int i = 1; i < edge.size(); i++){
//     if(edgeSet[edge[i]][2] < cost){
//       cost = edgeSet[edge[i]][2];
//       index = i;
//     }
//   }


//  cout << endl << "Edge " <<  edge[index] <<" with cost "<< cost << endl << endl;

//  // cout <<"We add vertex " << edgeSet[edge[index]][0]<< endl;

 

//  return edge;
// }


// Find minimum incident edge
int minIncident(vector< vector<int> > edgeSet, int k, int m);
// Once an edge has been added to T, find the corresponding new vertex
int addVertex(vector<vector<int> >edgeSet, vector<vector<int> > T, vector<int> VH);
int minIncidentSet(vector<vector<int> > edgeSet, vector<int> VH, int m);


ifstream infile("graph.txt");


int main() {
  
  int n;// Number of vertices.
  int m;// Number of edges.
  int edge;

  infile >> n; // Reads in the number of vertices. 
  infile >> m; // Reads in the number of edges. 
 
  // Check that the order of the graph is correct
  cout <<"The order of the graph is "<< n << endl;

  // Check that the size of the graph is correct
  cout <<"The size of the graph is " <<  m << endl;

  vector <vector<int> > edgeSet;// 2-D vector that stores the edges
  // [[row 1], [row 2], ..., [row m]]


  for(int i = 0; i < m; i ++){
    vector<int> row; // The i-th row vector will be the i-th row of .txt
    for(int j = 0; j < 3; j++){
      infile >> edge;
      row.push_back(edge);
    }
    edgeSet.push_back(row); // Places row in the i-th entry of edgeSet
  }

  vector <int> VH; // VH is the vertex set of our tree
  vector<vector<int> > T; // T is the edge set of the tree
  VH.push_back(0); // Initialize the vertex set of our tree (in this case 
  // vertex 3)
  int edge1; // Min incident edge index to our initial vertex 
  edge1 = minIncident(edgeSet, VH[0], m);
  T.push_back(edgeSet[edge1]);
  int vertex;

  vertex = addVertex(edgeSet, T, VH);
  VH.push_back(vertex);

  /////////////////////////////////////////////////////////////////////////////////
  for(int i = 0; i < VH.size(); i++){
    cout << VH[i] << endl;
   }

  int vertex1;

  vertex1 = minIncidentSet(edgeSet, VH, m);
  return 0;

}


int minIncident(vector<vector<int> > edgeSet, int k, int m){

  vector <int> edge;
  int index = 0;
  int cost;
  
 for(int i = 0; i < m; i++)
    if( k==edgeSet[i][0] || k == edgeSet[i][1] )
      edge.push_back(i);

  cout << "The edges incident with VH are  " << endl;


  for(int i = 0; i < edge.size(); i++){
    cout << "edge " << edgeSet[edge[i]][0] << " " <<edgeSet[edge[i]][1] << " with cost "<< edgeSet[edge[i]][2] << endl;
  }

  cost = edgeSet[edge[0]][2];


  for(int i = 1; i < edge.size(); i++){
    if(edgeSet[edge[i]][2] < cost){
      cost = edgeSet[edge[i]][2];
      index = i;
    }
  }


 cout <<"Edge " <<  edge[index] <<" with cost "<< cost << endl;

 // cout <<"We add vertex " << edgeSet[edge[index]][0]<< endl;
 index = edge[index];

 return index;
}


int addVertex(vector<vector<int> >edgeSet, vector<vector<int> > T, vector<int> VH){
  int addVertex;
  int dontAdd = VH[0];

  if(dontAdd == T[0][0]){
    addVertex = T[0][1];
  }
  else if(dontAdd == T[0][1]){
      addVertex = T[0][0];
  }
  // cout << addVertex << endl;


  return addVertex;
}

 

 

int minIncidentSet(vector<vector<int> > edgeSet, vector<int> VH, int m){

  vector <int> edge;
  int index = 0;
  int cost;
  
  for(int j = 0; j < VH.size();j++)
  {
    for(int i = 0; i < m; i++)
    {
      /*cout << "VH[ " << j <<" ] == edgeSet[" << i<< " ][0] && VH[j] != edgeSet[i][1]" << endl;*/
      if((VH[j] == edgeSet[i][0] && VH[j] != edgeSet[i][1]) ||
     (VH[j] != edgeSet[i][0] && VH[j] == edgeSet[i][1]))
    {
      edge.push_back(i);
    }
    }
  }


  cout << "The edges incident with VH are  " << endl;


  for(int i = 0; i < edge.size(); i++){
    cout << "edge " << edgeSet[edge[i]][0] << " " <<edgeSet[edge[i]][1] << " with cost "<< edgeSet[edge[i]][2] << endl;
  }

  cost = edgeSet[edge[0]][2];


  for(int i = 1; i < edge.size(); i++){
    if(edgeSet[edge[i]][2] < cost){
      cost = edgeSet[edge[i]][2];
      index = i;
    }
  }


 cout <<"Edge " <<  edge[index] <<" with cost "<< cost << endl;

 // cout <<"We add vertex " << edgeSet[edge[index]][0]<< endl;
 index = edge[index];

 return index;
}

