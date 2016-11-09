#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Constructor that initializes matrix in a sensible way
MATRIX new_matrix(const MINDEX rows, const MINDEX cols) {
  MATRIX m;
  m.rows = rows;
  m.cols = cols;
  // This is the first point at which it becomes clear
  // what is stored at m.mat
  // Enough memory is allocated for a 2-dimensional
  // array of MVALUEs, of total size (rows * cols)
  // Note, however, this it is still not specified
  // whether this is a 1D array of size (rows * cols)
  // or whether it is a multidimensional array
  // As far as C is concerned, in memory there is no
  // difference
  //
  // calloc zeroes out the memory that is allocated
  m.mat = (MVALUE *)calloc(rows * cols, sizeof(MVALUE));
  if (m.mat == NULL) {
    fprintf(stderr, "Failed to allocate new_matrix\n");
  }
  return m;
}

void delete_matrix(MATRIX m) {
  // Free memory that was allocated, to avoid memory leak
  free(m.mat);
}

void mset(MATRIX *m, const MINDEX row, const MINDEX col, const MVALUE v) {
  if (row < 0 || col < 0 || row >= m->rows || col >= m->cols) {
    fprintf(stderr, "ERROR: indexing matrix outside bounds");
    return;
  }
  // Find the pointer to the block of memory containing 
  // the matrix mat, then jump forward row number of rows
  // and col number of columns.  Inside that block of memory
  // insert the value v.
  //
  // Be sure to understand the following line of code well
  *(m->mat + (m->cols * row) + col) = v;
  // 
  // Question: is this the same as the following?
  //   (m->mat)[row][col] = v;
  // 
  //
  // This is called "row-major ordering" for matrices, since
  // the memory is arranged with each row being contiguous,
  // and columns spread out in memory (write out the memory 
  // on the board if you are confused about what this means)
  //
  // Languages that use row-major ordering:
  //   C, C++, Python, Mathematica
  //
  // The alternative is "column-major ordering", where the
  // columns are stored contiguously in memory instead
  // (write this out on the board for comparison)
  // 
  // Languages that use column-major ordering:
  //   FORTRAN, MATLAB, R, Julia
  //
}

// ------------ Edited
MVALUE mget(const MATRIX *m, const MINDEX row, const MINDEX col) {
  MVALUE n;
  n = *(m->mat + (m->cols * row) + col);
  return n;
}

// Abstraction layer in case implementation of VALUE changes later
void print_value(const MVALUE v) {
  printf("%Lf", v);
}

// ------------ Edited
void print_matrix(const MATRIX *m) {
  MINDEX maxr, maxc;
  maxr = m->rows;
  maxc = m->cols;

  // print values of matrix separated by tabs
  // with each row on a separate line
  printf("Matrix (rows: %d, cols: %d) \n", maxr, maxc);
  int i,j;
  for (i=0; i < maxr; i++){
    for(j=0; j < maxc; j++){
      MVALUE n = mget(m, i, j);
      print_value(n);
      printf(" ");
    }
    printf("\n");
  }
}

// ------------- Edited
MATRIX add_matrix(const MATRIX *x, const MATRIX *y){
  MINDEX matr, matc;
  matr = x->rows;
  matc = x->cols;

  MATRIX z;
  z = new_matrix(matr, matc);

  int i, j, num1, num2, numval;
  for (i=0; i<matr; i++){
    for (j=0; j < matc; j++){
        num1 = mget(x, i, j);
        num2 = mget(y, i, j);
        numval = num1 + num2;
        mset(&z, i, j, numval);
        }
    }
 return z;
}








