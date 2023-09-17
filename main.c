#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, argv[0]);
        return 1;
    }

    char* inputFileName = argv[1];
    char* outputFileName = "arq_palavras_ordenado.txt";

    FILE* inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Falha na abertura do arquivo");
        return 1;
    }

    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Falha na abertura do arquivo");
        fclose(inputFile);
        return 1;
    }

    char** words = NULL;
    char line[256];
    int numWords = 0;

    while (fgets(line, sizeof(line), inputFile)) {
        line[strcspn(line, "\n")] = 0;
        words = (char**)realloc(words, (numWords + 1) * sizeof(char*));
        words[numWords] = strdup(line);
        numWords++;
    }

    bubbleSort(words, numWords);
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]);
    }

    free(words);
    fclose(inputFile);
    fclose(outputFile);

    printf("Palavras ordenadas no arquivo: %s\n", outputFileName);

    return 0;
}