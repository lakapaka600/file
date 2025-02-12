#include <stdio.h>

int main(void) {
    int i;
    int j;
    FILE *myFile;
    myFile = fopen("C:\\Users\\10263\\Desktop\\text2.txt", "r");
    if (myFile == NULL) {
        printf("errore durante apertura");
        return 0;
    }
    int dim;

    fscanf(myFile,"%d",&dim);
    printf("%d  ",dim);
    float array[dim];
    for ( i = 0; i < dim; i++) {
        fscanf(myFile, "%f", &array[i]);
    }

    for ( i = 0; i < dim; i++) {
        printf("%f\n", array[i]);
    }

    float temporanea;
    for (i = 1; i <dim - 1; i++) {
        for (j = 1; j < dim - 1; j++) {
            if (array[j] > array[j + 1]) {
                temporanea = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temporanea;
            }
        }
    }
    myFile = fopen("C:\\Users\\10263\\Desktop\\scritto.txt", "w");
    fprintf(myFile,"%d\n",dim);
    printf("\n");

    for (i = 1; i < dim; i++){
        fprintf(myFile,"%.1f\n",array[i]);
    }

    return 0;
}
