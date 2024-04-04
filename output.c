#include<stdio.h>
#include<string.h>

struct productionRule
{
    char left[10];
    char right[10];
};

int main()
{
    char input[50],stack[50],temp[50],ch[2],*token1,*token2,*subString;
    int i,j,stackLength,subStringLength,stackTop,ruleCount = 0;

    struct productionRule rules[10];
    printf("Enter the No:of productionRules: ");
    scanf("%d",&ruleCount);

    printf("Enter the productionRules in the form of (left --> right): \n");
    for(i = 0 ; i < ruleCount ; i ++) {
        scanf("%s",temp);
        token1 = strtok(temp,"->");
        token2 = strtok(NULL,"->");

        strcpy(rules[i].left,token1);
        strcpy(rules[i].right,token2);
    }
    printf("Enter the input string: ");
    scanf("%s",input);

    i = 0;
    while(1)
    {
        if(i < strlen(input))
        {
            ch[0] = input[i];
            ch[1] = '\0';
            i ++;
            strcat(stack,ch);
            printf("%s\t",stack);

            for(int k = i ; k < strlen(input); k ++)
            {
                printf("%c",input[k]);
            }
            printf("\tShift %s\n",ch);

      }
      for(j = 0 ; j < ruleCount ; j ++)
      {
        subString = strstr(stack,rules[j].right);

        if(subString != NULL)
        {
            stackLength = strlen(stack);
            subStringLength = strlen(subString);
            stackTop = stackLength - subStringLength;
            stack[stackTop] = '\0';
            strcat(stack,rules[j].left);
            printf("%s\t", stack);

            for(int k = i ; k < strlen(input) ; k ++)
            {
                printf("%c",input[k]);
            }
            printf("\tReduce %s -> %s\n",rules[j].left,rules[j].right);
            j = -1;
        }

      }
      if(strcmp(stack,rules[0].left) == 0 && i == strlen(input))
        {
            printf("\nAccepted");
            break;
        }
        if(i == strlen(input))
        {
            printf("\nNot Accepted");
            break;
        }
    
    }
    return 0;


}