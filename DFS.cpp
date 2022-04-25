int findFirstNode();

class DFSvariables {
  int numVertices;
  bool *visited
  vertex* adjacentList
  int firstNode;
  int index; 
  int[] SCCarray;
  int numOfSCC;

   public:
  DFSvariables(int V, vertex* vertices);
  void DFS(vertex vertex, vertex* vertices);
  int getNumOfSCC();
};

DFSvariables::DFSvariables(int V, vertex* vertices){
    numVertices = V;
    visited = new bool[vertices];
    adjacentList = (vertex*) malloc(sizeof(vertex)*V);
    firstNode = vertices[0];
    index = 0; 
    SCCarray = new int[V];
    numOfSCC = 0;
}

int* DFSvariables::DFS(vertex vertex, vertex* vertices){
    visited[index] = true;
    vertex currentNode = vertex;
    int i = 0;
    while(currentNode != NULL){
    adjacentList[i] = currentNode->next;
    currentNode = currentNode->next;
    i++;
    }
    for(int p = 0; p < i + 1; p++){
        if(!visited[index + p]){
            DFS(adjacentList[p], index + p);
        }else{
            if(vertices[firstNode] == adjacentList[p]){
            prevFirstNode = firstNode;
            firstNode = findFirstNode();
            int countSCC = firstNode - prevFirstNode;
            SCCarray[countSCC] = SCCarray[countSCC] + 1;
            numOfSCC++;
            }
        }
    }
    index++;
    return SCCarray;
}
int findFirstNode(){
int index = 0;
while(visited[index])
index++;
return index;
}

int DFSvariables::getNumOfSCC(){
    return numOfSCC;
}