#ifdef HEADER_H
#define HEADER_H

void generateName(const char *labNo)
{
    // check if the labNo is "0" if yes then don't print the labNo
    printf("\n\n");
    printf("***************************\n");
    if (strcmp(labNo, "0") != 0)
        printf("** Lab No: %s\t\t **\n", labNo);
    printf("** Name: Suyash Shrestha **\n");
    printf("** Roll No: 22  \t **\n");
    printf("** Section: B   \t **\n");
    printf("***************************\n");
}

#endif