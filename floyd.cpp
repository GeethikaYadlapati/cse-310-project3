int** buildGraphMatrix(int size, vertex* array);
void floydWarshall(int graph[size][size]);
int findMaxShortestLength(int graph[size][size]);

int** buildGraphMatrix(int size, vertex* array){
    int matrix[size][size];
for(int i = 0; i < size; i++){
for(int j = 0; j < size; j++){
    for(int p = 0; p < arrayLength(array[i].edges); p++){
        if(array[i].edges[p] == array[j].label){
            matrix[i][j] = 1;
        }else if(array[i].label == array[j].label){
            matrix[i][j] = 0;
        }else matrix[i][j] = INF;
    }
}
}
return matrix;
}
void floydWarshall(int graph[size][size]) {
  int matrix[size][size], i, j, k;

  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < size; k++) {
    for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  findMaxShortestLength(matrix);
}

int findMaxShortestLength(int graph[size][size]){
    int max = 0;
for(int p = 0; p < size; p++){
    for(int q = 0; q < size; q++){
       if(graph[i][j] >= max){
           max = graph[i][j];
       }
    }
}
return max;
}