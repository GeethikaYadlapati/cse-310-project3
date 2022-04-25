#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define INF 999
#include "DFS.cpp"
#include "floyd.cpp"
#include "graph.cpp"
#include "utilities.cpp"

void readCommands(int size, vertex* vertexTable, int numOfEdges, char* argv[]);
void startGraph(int year1, int year2, int size, int numOfEdges);
void outDegree(int size, vertex* vertexArray, int numOfEdges);
void diameter(int size, vertex* vertexArray);
void scc(int size, vertex* vertexArray);

int main(int argc, char* argv[]){
    int vertexSize;
    int numOfEdges;
vertex* vertexArray;
vertex* vertexTable;
readCommands(vertexSize, vertexTable, numOfEdges, argv)
return 0;
}
void readCommands(int size, vertex* vertexTable, int numOfEdges, char* argv[]){
ifstream input;
while(input.eof() == false){
    string linestring;
    getline(input, linestring, '\n');
    if(linestring.compare("start-graph") == 0){
    char *linestring2 = &linestring[0];
    boolean spaceCrossed = false;
        int i = 12;
        string year1string;
        string year2string;
        while(linestring2[i]!= '\0' && linestring2[i] != '\n'){

            if(linestring2[i]! = ' ' && spaceCrossed == false){
                year1string = year1string + linestring2[i];
            }
            if(linestring2[i] == ' '){
                spaceCrossed = true;
            }
            if(linestring2[i]!= ' ' && spaceCrossed == true){
                year2string = year2string + linestring2[i];
            }
            
            i++;
            
        }
        int year1 = std::stoi(year1string);
        int year2 = std::stoi(year2string);

    vertexArray = constructVertexArray(argv[2], &size, year1 , year2);
    vertexTable = constructVertexTable(sortArray(vertexArray, size), argv[1], &size, &numOfEdges, year1, year2);
    startGraph(year1, year2, size, numOfEdges)
    }else if(linestring.compare("out-degree") == 0){
    outDegree(size, vertexTable, numOfEdges);
    }else if(linestring.compare("diameter") == 0){
    diameter(size, vertexTable);
    }else if(linestring.compare("scc") == 0){
    scc(size, vertexTable);
    }else if(linestring.compare("end-graph") == 0){
    return 0;
    }else{
        cout << "Invalid input";
    }
}
}


void startGraph(int year1, int year2, int size, int numOfEdges){
cout << "Command: start-graph " << year1 << year2 << "\n\n";
cout << "The graph G for the years " << year1 << "-" << year2 << " has:\n";
cout << "\t|V| = " << size << " vertices\n";
cout << "\t|E| = " << numOfEdges << "edges\n";
}

void outDegree(int size, vertex* vertexArray, int numOfEdges){
 cout << "Command: out-degree \n\n";
 cout << "The graph G has average out-degree 18/11 = " << numOfEdges/size << ".\n";
 cout << "The out-degree distribution is:\n";
 cout << "\tOut-degree : Number of vertices\n";
 int outDegree[numOfEdges];
 for(int p = 0; p < size; p++){
   outDegree[arrayLength(vertexArray[p].edges)] = outDegree[arrayLength(vertexArray[p].edges)] + 1;
 }
 for(int q = 0; q < numOfEdges; q++){
     if(outDegree[q] !=0){
         cout << "\tq : " << outDegree[q] << "\n";
     }
 }
 cout << "\n";

}

void diameter(int size, vertex* vertexArray){
int result = floydWarshall(buildGraphMatrix(size, vertexArray));
cout << "Command: diameter \n\n";
cout << "The graph G has diameter " << result << "\n";
}

void scc(int size, vertex* vertexArray){
  cout << "Command: scc\n\n"
  DFSvariables DFS(size, vertexArray);
  int[] array = g.DFS(vertexArray[0], vertexArray);
  int count = g.getNumOfSCC();
  cout << "The graph G has " << count << " strongly connected components:\n";
  cout << "Size : Number\n";
  for(int i = 0; i < size; i++){
      cout << i << " : " << array[i] << "\n";
  }
}
