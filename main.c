#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int8_t isBalancedParanthethes(uint8_t *expression){

    ST_stack_t newstk;//stack
    int8_t i = 0;//counter
    int8_t flag = -2;
    // check if expression is empty or not
    if (sizeof(*expression) == 0)
        return flag;


    createEmptyStack(&newstk);
    // loop for each expression and append parentheses only and ignore operand
    while (expression[i]!= '\0') {

        // check for parentheses
        if(expression[i] == '{' || expression[i] == '('){
            push(&newstk, expression[i]);
            flag = -1;// there is parentheses but not balanced
        }
        if(expression[i] == '}' || expression[i] ==')'){
            int8_t stackStatus;
            uint8_t temp;
            stackStatus = pop(&newstk, &temp);
            if((stackStatus != -2) && (((temp+1) == expression[i])||((temp+2) == expression[i]))){
                flag = 0;
            }else{
                flag = -1;
            }

        }
        i++;
    }
    return flag;
}

int main()
{
   char expression[10];
    printf("enter  expression : ");
    scanf(" %s",&expression);
    printf(" expression : %d \n",isBalancedParanthethes(&expression));

    return 0;
}
