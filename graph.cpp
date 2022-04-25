vertex* constructVertexArray(string fileName, int* size, int year1 , int year2);
vertex* constructVertexTable(vertex* A, string fileName, int* size, int* numOfEdges, int year1, int year2);

vertex* constructVertexArray(string fileName, int* size, int year1 , int year2){
    ifstream input;
    input.open(fileName);
    string linestring;
    int counter = 0;
    while(getline(input, linestring)){
        counter++;
    }
    *size = counter;
    vertex *V = (vertex*) malloc(sizeof(vertex)*counter);
    input.close();
    input.open(fileName);
    
    int index = 0;
    while(getline(input, linestring)){
        char *linestring2 = &linestring[0];
        string label = "";
        string year = "";
        boolean tabCrossed = false;
        int i = 0;
        while(linestring2[i]!= '\0' && linestring2[i] != '\n'){

            if(linestring2[i]! = '\t' && tabCrossed == false){
                label = label + linestring2[i];
            }
            if(linestring2[i] == '\t'){
                tabCrossed = true;
            }
            if(linestring2[i]!= '\t' && tabCrossed == true){
                year = year + linestring2[i];
            }
            
            i++;
            
        }
        if(year < year2 && year >= year1){
        V[index].label = std::stoi(label);
        V[index].year = std::stoi(year);
        }
        index++;
        linestring = "";
        
    }
    input.close();
    return V;
}
vertex* constructVertexTable(vertex* A, string fileName, int* size, int* numOfEdges, int year1, int year2){
  
ifstream input;
    input.open(fileName);
    string linestring;
    int counter = 0;
    while(getline(input, linestring)){
        counter++;
    }
    *numOfEdges = counter;
    std::string edges1[counter];
    std::string edges2[counter];

    input.close();
    input.open(fileName);
    int index = 0;
    while(getline(input, linestring)){
        char *linestring2 = &linestring[0];
        boolean tabCrossed = false;
        int i = 0;
        while(linestring2[i]!= '\0' && linestring2[i] != '\n'){
             if(linestring2[i]! = '\t' && tabCrossed == false){
                edges1[index] = edges1[index] + linestring2[i];
            }
            if(linestring2[i] == '\t'){
                tabCrossed = true;
            }
            if(linestring2[i]!= '\t' && tabCrossed == true){
                edges2[index] = edges2[index] + linestring2[i];
            }
             i++;
        }
        index++;
        linestring = "";
        
    }
    
    for(int j = 0; j < size; j++){
        int countEdges = 0;
    for(int i = 0; i < counter; i++){
        if (std::stoi(edges1[i]) > year1 && std::stoi(edges1[i]) <= year2 && std::stoi(edges2[i]) > year1 && std::stoi(edges2[i]) <= year2 && A[j].label == std::stoi(edges1[i]))
        {
            countEdges++;
            A[j].edges[countEdges] = std::stoi(edges2[i]);
        }
        
    }
    }
    for(int p = 0; p < size; p++){
        struct vertex currentNode = A[p];
        for(int q = 0; q < arrayLength(A[p].edges); q++){
            currentNode->next = findEdgeNode(A[p].edges[q], size, A);
            currentNode = findEdgeNode(A[p].edges[q], size, A);
        }
    }
    return A;
}










   