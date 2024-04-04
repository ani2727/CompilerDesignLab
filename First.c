#include<stdio.h>
#include<ctype.h>

int n,count;
char prodn[10][10];
char first[20];
void FIRST(char,int,int);

void main()
{
    char c,ch;
    int choice;
    printf("Enter no:of Productions: ");
    scanf("%d",&count);

    for(int i = 0 ; i < count ; i ++) {
        printf("Enter production No: %d \n",(i+1));
        scanf("%s%c",prodn[i],&ch);
    }

    do{
        n = 0;
        printf("Find the First of: ");
        scanf(" %c",&c);

        FIRST(c,0,0);

        printf("First(%c): {",c);
        for(int i = 0 ; i < n ; i ++) {
            printf(" %c ",first[i]);
        }
        printf("} \n");

        printf("Press 1 to continue or 0 to exit...");
        scanf("%d",&choice);
    }while(choice);
}

void FIRST(char c,int q1,int q2) {
    if(islower(c)) first[n ++] = c;

    for(int j = 0 ; j < count ; j ++) {
        if(prodn[j][0] == c) {
            if(prodn[j][2] == '$') {
                if(prodn[q1][q2] == '\0') first[n ++] = '$';
                else if(prodn[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) FIRST(prodn[q1][q2],q1,q2+1);
                else first[n ++] = '$';
            }
            else if(islower(prodn[j][2])) first[n ++] = prodn[j][2];
            else FIRST(prodn[j][2],j,3);
        }
    }
}



void FIRST(char c,int q1,int q2) {
    if(islower(c)) first[n ++] = c;

    for(int j = 0 ; j < count ; j ++) {
        if(prodn[j][0] == c) {
            if(prodn[j][2] == '$') {
                if(prodn[q1][q2] == '\0') first[n ++] = '$';
                else if(prodn[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) FIRST(prodn[q1][q2],q1,q2+1);
                else first[n ++] = '$';
            }
            else if(islower(prodn[j][2])) first[n ++] = prodn[j][2];
            else FIRST(prodn[j][2],j,3);
        }
    }
}
















// #include<stdio.h>
// #include<ctype.h>

// void FIRST(char[], char);
// void addToResultSet(char[],char);
// int numOfProductions;
// char productionSet[10][10];

// void main()
// {
//     int i;
//     char choice;
//     char c;
//     char result[20];
//     printf("How many productions:");
//     scanf("%d",&numOfProductions);
//     for(i = 0 ; i < numOfProductions ; i ++) 
//     {
//         printf("Enter the production No:%d :",i+1);
//         scanf("%s",productionSet[i]);
//     }

//     do{
//         printf("Find the First of: ");
//         scanf(" %c",&c);

//         FIRST(result,c);
//         printf("\n FIRST(%c): {",c);
//         for(i = 0 ; result[i] != '\0' ; i ++) {
//             printf(" %c ",result[i]);
//         }
//         printf("}\n");
//         printf("Press 'y' or 'Y' to Continue: ");
//         scanf(" %c",&choice);
//     }
//     while(choice == 'y' || choice == 'Y');
// }

// void FIRST(char *Result,char c) {
//     int i,j,k;
//     char subResult[20];
//     int foundEpsilon;

//     subResult[0] = '\0';
//     Result[0] = '\0';

//     if(islower(c))
//     {
//         addToResultSet(Result,c);
//         return ;
//     }

//     for(i = 0 ; i < numOfProductions ; i ++) {
//         if(productionSet[i][0] == c) {
//             if(productionSet[i][2] == '$') {
//                 addToResultSet(Result,'$');
//             }
//             else {
//                 j = 2;
//                 while(productionSet[i][j] != '\0') {
//                     foundEpsilon = 0;
//                     FIRST(subResult,productionSet[i][j]);
//                     for(k = 0 ; subResult[k] != '\0' ; k ++) {
//                         addToResultSet(Result,subResult[k]);
//                         if(subResult[k] == '$') foundEpsilon = 1;
//                     }
//                     if(foundEpsilon == 0) break;
//                     j ++;
//                 }
//             }
//         }
//     }
//     return ;
// }

// void addToResultSet(char Result[],char val) {
//         int k;
//         for(k = 0 ; Result[k] != '\0' ; k ++) {
//             if(Result[k] == val) return ;
//         }
//         Result[k] = val;
//         Result[k+1] = '\0';
// }