/*
  Welcome to the "[w]hat is a structure" instructional file.
  This file will talk about what a structure is and the syntax used to implement it.

  So, what is a structure? 
    A structure is a keyword in C that allows the programmer to create a custom data type.
    This has some effects, a structure defines the memory layout of the created type.
*/
#include <stdio.h>

/*
  Lets take a look at a contrived concrete example.
*/
typedef struct {
  unsigned int aggregate;
  unsigned int cement;
  unsigned int water;
} ConcreteMaterials;

/*
  We will combine some parts aggregate, cement, and water which produces some parts concrete.
  Here is a function that does so without structures.
*/
unsigned int make_concrete(unsigned int p_aggregate, unsigned int p_cement, unsigned int p_water) 
{
  return (p_aggregate + p_cement + p_water); // This is not currently an accurate model of the real world.
}

/*
  If we use a structure, the calling function must know the internals of the structure. 
  This allows us to keep information that is frequently accessed together together; exploiting locality of reference.
*/
unsigned int make_concrete(ConcreteMaterials const* p_materials) {
  return (p_materials->aggregate + p_materials->cement + p_materials->water);
}



int main(int argc, char** argv) 
{
  



  return (0);
}
