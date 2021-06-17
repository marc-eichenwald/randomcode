#include <stdlib.h>
#include <stdio.h>
#define BLACK 1
#define WHITE 0
/*TODO: some code to read in png's or some sort of file
*/
typedef struct nonogram{
    rcstruct cols;
    rcstruct rows;
}nonogram;

typedef struct rcstruct{
    int **rc;
    int *count;
}rcstruct;

void malloc_check(void *p){
    if (p=NULL){
        err(EXIT_FAILURE, "failed to allocate a pointer");
    }
    return;
}

nonogram *generate_nonogram(int **picture, int max_row, int max_col){
    nonogram *non;
    int* current;
    int i,j,k,l;
    int dirty;
    int count;
    
    non = malloc(sizeof(nonogram));
    malloc_check(non);


    non->rows.rc = malloc(max_row * sizeof(int*));
    malloc_check(non->rows.rc);

    non->cols.rc = malloc(max_col * sizeof(int*));
    malloc_check(non->cols.rc);
    non->cols.count = malloc(max_col * sizeof(int));
    malloc_check(non->cols.count);
    for (i=0; i<max_row; i++){
        non->rows.rc[i] = malloc(sizeof(int) * ((max_col + 1) / 2)); //if odd makes n+1/2 if even just makes n/2
        malloc_check(non->rows.rc[i]);
    }
    for (i = 0; i < max_col; i++){
        non->cols.rc[i] = malloc(sizeof(int) * ((max_row + 1) / 2));
        malloc_check(non->rows.rc[i]);
    }


    
    //row generation
    for(i = 0; i < max_row; i++){
        dirty = 0;
        k = 0;
        for (j = 0; j < max_col; j++){
            non->rows.count[i] = 0;
            if (picture[i][j] == WHITE){
                if(k == 0){
                    continue;
                }
                else{
                    non->rows.rc[i][non->rows.count[i]] = k;
                    k = 0;
                    non->rows.count[i]++;
                }
            }
            else{
                k++;
                dirty++;
            }
        }
        if (dirty == 0){
            *(non->rows.rc[i]) = 0;
        }
        non->rows.count[i]++;
    }

    //column generation;
    for (i = 0; i < max_col; i++){
        dirty = 0;
        k = 0;
        for (j = 0; j < max_col; j++){
            non->cols.count[i] = 0;
            if (picture[j][i] == WHITE){
                if(k == 0){
                    continue;
                }
                else{
                    non->cols.rc[i][non->cols.count[i]] = k;
                    k = 0;
                    non->cols.count[i]++;
                }
            }
            else{
                k++;
                dirty++;
            }
        }
        if (dirty == 0){
            *(non->cols.rc[i]) = 0;
        }
        non->cols.count[i]++;
    }
return non;
}

write_file(nonogram *non){
    
}

int main(int argc, char *argv[]){
    int i,j,k;
    int **picture;
    int max_row, max_col;
    FILE *input, *output;
    nonogram *non;

    //arg check
    if (argc != 3){
        printf("Usage %s [input file] [output file]\n", argv[0]);
        return 2;
    }

    //read the file in here


    non = generate_nonogram(picture, max_row, max_col);

    write_file(non);
    
    return 0;
}
