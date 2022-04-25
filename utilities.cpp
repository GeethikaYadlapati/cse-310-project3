vertex* sortArray(vertex* array, int size);
int arrayLength(int[] array);
vertex findEdgeNode(int label, int size, vertex* array);

struct vertex{
    int label;
    int year;
    struct label *next;
    int edges[500]; //random number 
}
vertex* sortArray(vertex* array, int size){
vertex temp;
for(i = 0; i<size; i++) {
   for(j = i+1; j<size; j++)
   {
      if(array[j].label < array[i].label) {
         temp = array[i];
         array[i] = array[j];
         array[j] = temp;
      }
   }
}

return array;
}

int arrayLength(int[] array){
   int i = 0;
   if(array[i] != 0){
      i++
   }
   return i;
}

vertex findEdgeNode(int label, int size, vertex* array){
   for(int i = 0; i < size; i++){
      if(array[i].label == label){
         return array[i];
      }
   }
}