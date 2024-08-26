# Lab Assignment 3
We are going to create a custom structure that stores an array along with the size in a single data type.  The size of the array will be chosen by the user using command line arguments. We will then pass this array to various functions that operate on the data inside.

# Step 1
Create a structure data type in a header file called array.h.  Define the structure containing two variables: size and data

```
struct _my_array
{
  int size;
  double *data;
};
typedef struct _my_array Array;
```

# Step 2
Create a main.c file.  Include the array.h file in your main.c file.  Dynamically allocate a single structure of type _my_array.  The user will run the program as follows:

`
./main 1024
`

where the second argument is the size of the array to make inside the structure.  Check to make sure the value exists and is valid.  Taking this value, allocate more space for the data inside the structure.  Fill this array with values of your choice.  

# Step 3
Write three functions:
- `void output_array(Array *a);`
- `void shift_array(Array *a);`
- `Array *average_adjacent(Array *a);`

`output_array` will output the array in it's entirety.  

`shift_array` will shift all elements to the left by 1.  That is, the value at index 1 will become the value at index 0, the value at index 2 will become the value at index 1, etc.  The value at index 0 should become the last element in the array.

`average_adjacent` will average two elements next to each other.  Create a new array using the custom struct data type in array.h. This array should be half the size of the original.  If the original array was odd sized, ignore the last element (i.e. if the array was size 5, the new array should be size 2).  You will average elements 0 and 1, store the value in the new array at index 0.  Average elements 2 and 3, store the average in the new array at index 1 and so on.  Return the new array from your function (it will not be a void return type).

# Step 4
Using the original array, call the `output_array`, `shift_array`, and `output_array` function again to verify that it is shifting the values.  Then, call `average_adjacent` on the original array and use `output_array` for your new array that was returned from your average_adjacent function.

Free all of your allocated memory.

# Grading scale
Push to your repository all .h and .c files.
- Command line arguments: 10%
- Three implemented functions: 60%
- Calling all functions: 10%
- Code produces expected output: 20%
