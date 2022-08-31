#include "Matrix.h"

typedef struct t_mat{
    unsigned int n_rows;
    unsigned int n_cols;
    double ** data;
    int is_square;
} t_mat;

