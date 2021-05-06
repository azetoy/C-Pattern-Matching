#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH BUFSIZ

//struct that going to store any motif
struct Occurence
{
    char *array;
    int pos_oc[LENGTH];
    int x;
    int nb_occ;
};
//struct of the pattern that can store multiple struct for multiple moitf
struct Occurences
{
    struct Occurence *oc;
    char patern[6];
    int nb_patern;
    int nb_oc_total;
};

//global var to know the number of loop round
int internal_loop;
int external_loop;


void print_oc(struct Occurences *);
void print_uni(struct Occurences *);
void search(char [],struct Occurences *,struct Occurences *);
int find(char [],int,struct Occurences *);
void union_s (struct Occurences *,struct Occurences *,struct Occurences *);
void tri(struct Occurences *);
void fill(char []);
void test_array(struct Occurences *);


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

//this method is to check if the prog is working properly
void test_array(struct Occurences *patern)
{
    printf("\ntest for the pattern %s the motif that have passed the test are \n\n",patern->patern);
    int test = 0;
    for(int i = 0;i < patern->nb_patern;i++)
    {
        if(strcmp("bci",patern->oc[i].array) == 0) 
            test++,printf("waiting for bci and get %s \n",patern->oc[i].array);
        else if(strcmp("brci",patern->oc[i].array) == 0)
            test++,printf("waiting for brci and get %s \n",patern->oc[i].array);
        else if(strcmp("brrci",patern->oc[i].array) == 0)
            test++,printf("waiting for brrci and get %s \n",patern->oc[i].array);
        else if(strcmp("brrcci",patern->oc[i].array) == 0)
            test++,printf("waiting for brrcci and get %s \n",patern->oc[i].array); 
        else if(strcmp("bc",patern->oc[i].array) == 0)
            test++,printf("waiting for bc and get %s \n",patern->oc[i].array);
        else if(strcmp("brcii",patern->oc[i].array) == 0)
            test++,printf("waiting for brcii and get %s \n",patern->oc[i].array);   
    }

    if(test == 4)
    {
        printf("\ntest for the pattern %s is succesfull \n\n",patern->patern);
    }
    else
    {
        printf("error %d \n",test);
    }   
}
//this is to fill the array with random char between brci
void fill(char array[])
{
    srand(time(0));
    char letter [4] = "brci";
    for(int i = 0;i < LENGTH - 1;i++)
    {
        int random_number = (rand() %(3-0 + 1)) + 0;
        array[i] = letter[random_number];
    }
    array[LENGTH] = '\0';
}

//method to print the uni struct
void print_uni(struct Occurences *uni)
{
    printf("for the union \n");
    printf("the number of occurences found is %d \n",uni->nb_patern);
    for(int i = 0;i != uni->nb_patern;i++)
    {
        printf("patern found in the first and second motif and are now in the union are %s \n",uni->oc[i].array);
    }
    printf("\n");
}

//method to print the pattern struct
void print_oc(struct Occurences *ocs)
{
    int all = 0;
    printf("for the patern %s \n \n",ocs->patern);
    for(int i = 0;i < ocs->nb_patern;i++)
    {
        printf("the occurences %s appear %d \n",ocs->oc[i].array,ocs->oc[i].nb_occ);
        printf("\n");

        all += ocs->oc[i].nb_occ;        
        for(int j = 0;j != ocs->oc[i].x;)
        {
            printf("start = %d ",ocs->oc[i].pos_oc[j]);
            j++;
            printf("end = %d \n",ocs->oc[i].pos_oc[j]);
            j++;
        }
        printf("\n");
    }
    printf("and the number total of occurence for the pattern %s is %d and the number of motif found for this pattern is %d \n",ocs->patern,all,ocs->nb_patern);
    printf("=============================================================================\n");
    ocs->nb_oc_total = all;
}

//method to make the union between patern 1 and 2 if they are the same
void union_s (struct Occurences *patern1,struct Occurences *patern2,struct Occurences *uni)
{
    int k = 0;
    for(int i = 0;i < patern1->nb_patern;i++)
    {
        for(int j = 0;j < patern2->nb_patern;j++)
        {
            if(strcmp(patern1->oc[i].array,patern2->oc[j].array) == 0)
            {
                uni->oc[k].array = patern1->oc[i].array;
                uni->nb_patern ++;
                k++;
            }
        }
    }
}

//method to sort the struct passed in arg
void tri(struct Occurences *ocs)
{
	struct Occurence tmp;
	for(int i = 0;i < ocs->nb_patern - 1;i++)
    {
        for(int j = 0;j < ocs->nb_patern - i - 1;j++)
        {
            if(ocs->oc[j].nb_occ < ocs->oc[j + 1].nb_occ)
            {
                //make the swap with my struct
                tmp = ocs->oc[j];
                ocs->oc[j] = ocs->oc[j + 1];
                ocs->oc[j + 1] = tmp;
            }
        }
    }
}
//this method will search if the array[i] is the same as the first char of the patern then call the find method
void search(char array[],struct Occurences *ocs,struct Occurences *ocs2)
{
    int i = 0;
    
    while(array[i] != '\0')
    {
        external_loop ++;
        if(array[i] == ocs->patern[0])
        {
            find(array,i,ocs);
        }
        if(array[i] == ocs2->patern[0])
        {
            find(array,i,ocs2);
        }
        i++;
    }
    //sort my two struct
    tri(ocs);
    tri(ocs2);
    //print the struct with the more number of occurence
    if(ocs->nb_oc_total > ocs2->nb_oc_total)
        print_oc(ocs);
    else
    {
        print_oc(ocs2);
        print_oc(ocs);
    }
}
//this method will take the array the start of the possible motif and the struct
int find(char array[],int i,struct Occurences *ocs)
{
    
    int start = i,c = 0,find = 0;
    //create and malloc a char result that will store the motif
    char *result = (char *)malloc(sizeof(char));
    //struct to store the pattern
    struct Occurence occ;
    occ.x = 0;
    //to store the first char
    result[c] = array[i];
    c++;
    i++;
    //main loop
    for(int j = 1;j<=5;j++)
    {
        internal_loop ++;
        //check if the next char is a *
        if(ocs->patern[j + 1] == '*')
        {
            //if the char at the array[i] is the same as the patern[j] in the struct 
            if(array[i] == ocs->patern[j])
            {
                //as long as the char are the same go to the next char and store the char in result
                while(array[i] == ocs->patern[j])
                {
                    internal_loop++;
                    result[c] = array[i];
                    c++;
                    i++;
                }
                j++;
            }
            else
            {
                j++;
            }
        }
        //check if the next char is a +
        else if(ocs->patern[j + 1] == '+')
        {   
            //if the char array is not same the the motif is wrong so return 0 to stop it 
            if(array[i] != ocs->patern[j])
            {
                return 0;
            }
            else
            {
                //else check the char as long as its the same and store it in result
                while(array[i] == ocs->patern[j])
                {
                    internal_loop++;
                    result[c] = array[i];
                    c++;
                    i++;
                }
                j ++;
            }
        }

        //if the next char is a ?
        else if(ocs->patern[j + 1] == '?')
        {
            //and if the char is the same as the char of patern the store the char into result
            if (array[i] == ocs->patern[j]) 
            {
                result[c] = array[i];
                c++;
                i++;
            }
            j++;

        }
        //if all the previous if are false that mean they are not special char and we will check if the actual char is the same as the pattern if yes then store it to result
        else if(array[i] == ocs->patern[j])
        {
            result[c] = array[i];
            c++;
            i++;
        }
        //if not that mean the actual motif is wrong the return 0 and dont store the motif into the struct 
        else
        {
            return 0;
        }
    }

    //check if the acutal motif is in the struct then incremente the number of occurence of this motif
    for(int l = 0; l < ocs->nb_patern;l++)
    {
        internal_loop ++;
        if(strcmp(result,ocs->oc[l].array) == 0)
        {
            ocs->oc[l].nb_occ ++;
            find = 1;
        }
    }
    //store the actual motif in the local struct occ    
    occ.array = result;
    occ.nb_occ = 1;
    //that mean the actual motif is not in the struct of the pattern so we add it
    if(find == 0)
    {
        ocs->oc[ocs->nb_patern] = occ;
        ocs->nb_patern ++;
    }
    //here we are storing the position of the motif in an array of int so we can find it later 
    for(int l = 0;l < ocs->nb_patern;l++)
    {
        internal_loop ++;
        if(strcmp(result,ocs->oc[l].array) == 0)
        {
            ocs->oc[l].pos_oc[ocs->oc[l].x] = start;
            ocs->oc[l].x ++;
            ocs->oc[l].pos_oc[ocs->oc[l].x] = i - 1;
            ocs->oc[l].x ++;
        }
    }
    return 0;
}
