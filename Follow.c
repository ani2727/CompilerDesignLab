#include<stdio.h>
#include<string.h>
#include<ctype.h>

int n,m=0,p,i=0,j=0;

char a[10][10],f[10];
void follow(char c);
void first(char c);

int main()
{
    char c,ch;
    int choice;
    printf("Enter the no:of productions: ");
    scanf("%d",&n);

    printf("Enter the productions: \n");
    for(i = 0 ; i < n ; i ++) {
        scanf("%s%c",a[i],&ch);
    }

    do{
        m = 0;
        printf("Find Follow of: ");
        scanf(" %c",&c);
        follow(c);
        printf("Follow(%c): {",c);
        for(i = 0 ; i < m ; i ++) {
            printf(" %c ",f[i]);
        }
        printf("} \n");

        printf("To continue press 1 or 0 to Discontinue: ");
        scanf("%d%c",&choice,&ch);
    }while(choice);

}

void follow(char c) {
    if(a[0][0] == c) f[m ++] = '$';

    for(i = 0 ; i < n ; i ++) {
        for(j = 2 ; j < strlen(a[i]); j ++)
        {
            if(a[i][j] == c) {
                if(a[i][j+1] != '\0') first(a[i][j+1]);
                if(a[i][j+1] == '\0' && c != a[i][0]) follow(a[i][0]); 
            }
        }
    }
}

void first(char c) {
    int k;
    if(!(isupper(c)))  f[m ++] = c;

    for(k = 0 ; k < n ; k ++) {
        if(a[k][0] == c) {
            if(a[k][2] == '$') follow(a[i][0]);
            else if(islower(a[k][2])) f[m ++] = a[k][2];
            else first(a[k][2]);
        }
    }   
}









void follow(char c) {
    if(a[0][0] == c) f[m ++] = '$';
    for(i = 0 ; i < n ; i ++) {
        for(j = 2 ; j < strlen(a[i]) ; j ++) {
            if(a[i][j] == c) {
                if(a[i][j+1] != '\0') first(a[i][j+1]);
                if(a[i][j+1] == '\0' && c != a[i][0]) follow(a[i][0]); 
            }
        }
    }
}

void first(char c)
{
    if(!(isupper(c))) f[m ++] = c;
    for(int k = 0 ; k < n ; k ++) {
        if(a[k][0] == c) {
            if(a[k][2] == '$') follow(a[i][0]);
            else if(!(isupper(a[k][2]))) f[m ++] = a[k][2];
            else first(a[k][2]);
        }
    }
}















// #include<stdio.h>
// #include<ctype.h>
// #include<string.h>

// int n,m = 0,p,i = 0,j = 0;

// char a[10][10],followResult[10];
// void follow(char c);
// void first(char c);
// void addToResult(char);
// int main()
// {
//     int i,choice;
//     char c;
//     printf("Enter the no:of Productions: ");
//     scanf("%d",&n);

//     for(i = 0 ; i < n ; i ++) {
//         printf("Enter the production no:%d: ",i+1);
//         scanf("%s",a[i]);
//     }

//     do{
//         m = 0;
//         printf("Find Follow of: ");
//         scanf(" %c",&c);
//         follow(c);

//         printf("Follow(%c): {",c);
//         for(i = 0 ; i < m ; i ++) {
//             printf(" %c ",followResult[i]);
//         }
//         printf("}\n");

//         printf("To continue press 1 or 0 to discontinue: ");
//         scanf("%d",&choice);
//     }
//     while(choice);
// }

// void follow(char c) {
//     if(a[0][0] == c) addToResult('$');

//     for(i = 0 ; i < n ; i ++) {
//         for(j = 2 ; j < strlen(a[i]) ; j ++) {
//             if(a[i][j] == c) {
//                 if(a[i][j+1] != '\0') first(a[i][j+1]);
//                 else if(a[i][j+1] == '\0') follow(a[i][0]);
//             }
//         }
//     }
// }

// void first(char c) {
//     int k;
//     if(islower(c)) {
//         addToResult(c);
//     }

//     for(k = 0 ; k < n ; k ++) {
//         if(a[k][0] == c) {
//             if(a[k][2] = '$') follow(a[k][0]);
//             else if(islower(a[k][2])) {
//                 addToResult(a[k][2]);
//             }
//             else {
//                 first(a[k][2]);
//             }
//         }
//     }
// }

// void addToResult(char c) {
//     int i;
//     for(int i = 0 ; i <= m ; i ++) {
//         if(followResult[i] == c) {
//             return ;
//         }
//     }
//     followResult[m ++] = c;
// }



