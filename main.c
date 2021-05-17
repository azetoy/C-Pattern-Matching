#include "patternmatching.h"

int main()
{
    //that char array below is for the test function
    //char array[LENGTH] = "bcibrcibrrcibrrccibcbrciibibriri";

    char array[LENGTH];
    //method to fill the array with random letter between brci
    fill(array);
    
    //====================================================================================

    // //malloc of struct
    struct Occurences *pattern1 = (struct Occurences*)malloc(sizeof(struct Occurences));
    pattern1->oc = (struct Occurence *)malloc(LENGTH *sizeof(struct Occurence));

    //add the patern to the struct
    strcpy(pattern1->patern,"br*c+i");

    //set the var to 0 
    pattern1->nb_patern = 0;
    pattern1->nb_oc_total = 0;

    //====================================================================================
    
    //malloc of struct
    struct Occurences *pattern2 = (struct Occurences*)malloc(sizeof(struct Occurences));
    pattern2->oc = (struct Occurence *)malloc(LENGTH *sizeof(struct Occurence));
    
    //add the patern to the struct
    strcpy(pattern2->patern,"br?ci*");
    
    //set the var to 0 
    pattern2->nb_patern = 0;
    pattern2->nb_oc_total = 0;
    //start the algo with the array of random char and my two struct for my two pattern
    search(array,pattern1,pattern2);
    //====================================================================================

    //malloc of struct
    struct Occurences *uni = (struct Occurences*)malloc(sizeof(struct Occurences));
    uni->oc = (struct Occurence *)malloc(LENGTH *sizeof(struct Occurence));

    //this pattern is juste to know that we are talking about the union and not a pattern
    strcpy(uni->patern,"union");

    //init var
    uni->nb_patern = 0;

    //this method will check if in the pattern 1 and 2 are some same motif and if yes the uni struct will copy it
    union_s(pattern1,pattern2,uni);
    //this will sort the motif
    tri(uni);
    //print the motif in the uni struct
    print_uni(uni);

    printf("\nthe number of total occurence from the patern1 and the patern2 are %d and the number total of occurence from each motif is %d\n\n",pattern1->nb_patern + pattern2->nb_patern,pattern1->nb_oc_total + pattern2->nb_oc_total);
    printf("\nfor the complexity the lenght of the array is %d, the total number of loop is = %d , the number of internal loop = %d , external loop = %d \n",LENGTH,internal_loop + external_loop,internal_loop,external_loop);
    //test_array(pattern1);
    //test_array(pattern2);

}