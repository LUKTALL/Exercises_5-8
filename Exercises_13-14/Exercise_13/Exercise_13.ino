/*
 * 13a)
 * The address of the data that the pointer is pointing to
 * 
 * 13b)
 * The code runs through the array, while printing the address of the data in HEX, and
 * the value of the data. This is done through a pointer, getting the array values with *pointer.
 */

/*
 * 13c)
 * After the first five iterations, the pointer exceeds the values defined in the array,
 * and just continues to the next address in memory
 */
 
/* 16d)
  int var = 2;
  int *pointer = &var;
  *pointer = 3;
 */

// 13e)
void swap(int *pointer_a, int *pointer_b){
  int a = *pointer_a;
  *pointer_a = *pointer_b;
  *pointer_b = a;
}
