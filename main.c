#include <stdio.h>
#include <stdlib.h>

void search(char [],char []);
int find(char [],char [],int);


int main()
{
    char array[150] ="brcbciiiiibcibrciiiibc";
    char patern[6] = "br?ci*";
    //brc bciiiii bci brciiii bc
    search(array,patern);
}

void search(char array[],char patern[])
{   
    int i = 0,j = 0;

    while(array[i] != '\0')
    {
        if(array[i] == patern[0])
        {
            find(array,patern,i);
            i++;
        }
        else 
        {
            i++;
            j++;
        }
    }
}

int find(char array[],char patern[],int i)
{

    int start = i,c = 0;
    char *result = (char *)malloc(sizeof(char));
    result[c] = array[i];
    c++;
    i++;

    for(int j = 1;j<=5;j++)
    {
        //printf("array[%d] == %c && patern[%d] == %c \n",i,array[i],j,patern[j]);
        if(patern[j + 1] == '*')
        {
            if(array[i] == patern[j])
            {
                while(array[i] == patern[j])
                {
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

        else if(patern[j + 1] == '+')
        {
             if(array[i] != patern[j])
            {
                return 0;
            }
            else
            {
                while(array[i] == patern[j])
                {
                    result[c] = array[i];
                    c++;
                    i++;
                }
                j ++;
            }
        }

        else if(patern[j + 1] == '?')
        {
            if (array[i] == patern[j]) 
            {
                result[c] = array[i];
                c++;
                i++;
            }
            j++;

        }

        else if(array[i] == patern[j])
        {
            result[c] = array[i];
            c++;
            i++;
        }
        else
        {
            return 0;
        }
    }

    printf("patern start at %d =  %s and end at %d \n",start,result,i);
}
