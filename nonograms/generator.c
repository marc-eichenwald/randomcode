#include <stdlib.h>
#include <stdio.h>
#define BLACK 1
#define WHITE 0
/*TODO: some code to read in png's or some sort of file
*/
typedef struct nonogram{
    int **rows;
    int **cols;
}nonogram;

nonogram generate_nonogram(int **picture, int max_row, int max_col){
    nonogram non;
    non.rows = malloc(max_row * sizeof(int*));
    non.cols = malloc(max_col * sizeof(int*));
    int *current;
    int i,j,k,l;
    int dirty;
    //row generation
    for(i=0; i<max_row; i++){
        current = picture[i];
        k=0;
        non.rows[i] = malloc(sizeof(int));
        for (j=0; j<max_col; j++){
            l=0;
            if (current[j] == WHITE){
                if(k == 0){
                    continue;
                }
                else{
                    non.rows[i][l] = k;
                    k = 0;
                    non.rows[i] = realloc(non.rows[i], sizeof(int)*(++l));
                }
            }
            else{
                k++;
                dirty++;
            }
        }
        if (dirty == 0){
            non.rows[i][l]=0;
        }

    }


return non;
}

int main(int argc, char *argv[]){
    int i,j,k;
    int **picture;
    int max_row, max_col;
    FILE *output;
    nonogram noni;

    //arg check
    if (argc != 3){
        printf("Usage %s [input file] [output file]\n", argv[0]);
        return 2;
    }

    //read the file in here


    generate_nonogram(picture, max_row, max_col);

    write_file(noni);
    
    return 0;
}
