#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
  What is a pointer?
    A pointer is a data type that is designed to store memory locations.
*/

int main(int argc, char** argv) {
  /*
    Create an integer a
  */
  int a;
  /*
    Assign an integer value of 0 to a.
  */
  a = 65;
  assert(a == 65);
  printf("The value of a is %d.\n", a);

  /*
    The value of a is stored in memory at a location &a.
  */
  printf("The value of a is stored in memory at the location %p.\n", &a);

  /*
    A pointer stores these memory locations which is synonymous with many forms of combinations with address.
  */

  /*
    Lets declare a pointer! 
    The keyword for pointer types is '*'. 
   */
  int *b;
   /*
    In C you read variable types right to left, for example: b is of type pointer to an integer.
    This is accurate but deceiving.
    By declaring the type as a pointer to an integer you are giving the compiler information that can be used to implement static analyses such as bounds checking.
    Let's look at what this means after the following assignment.
  */
  /*
    The memory location of a is stored in b.
  */
  b = &a;
  assert(b = &a);

  printf("The value of b is %p.\n", b);
  printf("Lets verify that b = &a.\nb=%p, &a=%p, &a - b = %p\n", b, &a, &a - b);
  assert((&a - b) == 0);

  /*
    A pointer can be thought of as a base value for memory access.
    We can access the value in a by doing the following, &a = b = b + 0
  */
  printf("&a = b = b + 0 = %p\n", b + 0);
  assert((b + 0) == &a);

  /*
    Now lets take a look at the values of a and b.
    To do so we will _de-reference_ b using the '*' operator as follows.
    De-reference uses the type declaration for b, int, to determine how to access the memory location.
  */
  printf("a = %d, *b = %d\n", a, *b);
  assert(a == *b);

  printf("The size of int is %d.\n", sizeof(int)); // 4
  printf("The size of char is %d.\n", sizeof(char)); // 1

  /*
    Lets make a char* c and look at &a.
  */
  char *c = &a; // This line might cause a warning or an error depending on compiler and options.

  /*
    Lets check out those addresses.
  */
  printf("c == &a == b, %p == %p == %p\n", c, &a, b);
  assert((c == &a) && (c == b));

  /*
    Recall, the sizeof(int) = 4 and sizeof(char) = 1.

    a = 0000 0000 0000 0000 0000 0000 0000 0000    // 4 bytes * 8 bits/byte = 32 bits
    *b = [ 0000 0000 0000 0000 0000 0000 0000 0000 ]
    *c = [ 0000 0000, 0000 0000, 0000 0000, 0000 0000]    

    The data-type assigned to a pointer determines how the memory location is accessed.

    Consider a structure
  */
  struct S
  {
    int a;
    char b;
    int c;
    char d;
  };
  /*
    In program space memory could be layed out as follows.
    
    0 0 0 0  0 X X X  0 0 0 0  0 X X X 
    int a    char b   int c    char d

    The memory layout is not guarenteed in any manner.
    What this means to you is that \code{A->a} is guarenteed at compile time to point to the value of a.
    You could be potentially try to access the value of a as follows, \code{*(A + 0)}.
    Memory layout is not guarenteed.

    Therefore, another compiler could end up with the following as the layout

    0 X X X  0 X X X  0 0 0 0  0 0 0 0
    char b   char d   int a    int c

    Now \code{*(A + 0)} accesses an undefined value.  
  */

  struct S *s = malloc(1 * sizeof(struct S));
  assert(s);

  s->a = 0;
  s->b = 1;
  s->c = 2;
  s->d = 3;

  printf("s->a = %d\n", s->a);
  printf("s->b = %c\n", s->b);
  printf("s->c = %d\n", s->c);
  printf("s->d = %d\n", s->d);


  /*
    A pointer is only a memory location.
    The attached type determines how the memory is accessed starting at the given memory location.    
  */
  int *j = s;
  char *k = s;

  /*
    Note that values for *(j + 0) and *(j + 2) correspond to the values of s->a and s->c respectively.    
   */
  printf("\n// Iterate over structure as integer.\n");
  int i = 0;
  for (i = 0; i < sizeof(struct S) / sizeof(int); ++i)
  {
    printf("*(j + %d) = %d\n", i, *(j + i));
  }


  printf("\n// Iterate over structure as character.\n");
  for (i = 0; i < sizeof(struct S) / sizeof(char); ++i)
  {
    printf("*(k + %d) = %d\n", i, *(k + i));
  }
  
  /*
    A pointer is a memory location.
    The type assigned to the pointer determines how memory is accessed, not what is stored in memory. 
  */

  return (0);
}
