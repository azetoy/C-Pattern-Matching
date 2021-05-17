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