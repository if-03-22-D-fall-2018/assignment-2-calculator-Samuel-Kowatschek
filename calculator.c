#include <stdio.h>
#include <stdbool.h>
#include <float.h>

int GetOperation(){
  int operationNumber;
  printf("Choose one of the following operations:\n%3s \n%3s \n%3s \n%3s \n%3s \n","Add(1)","Subtract(2)","Multiply(3)","Divide(4)","Stop Program(-1)");
  printf("Enter your choice: ");
  scanf("%d",&operationNumber);
  return operationNumber;
}
void TurnOperationNumberIntoOperation(int operationNumber, char *operation){
    switch (operationNumber){
      case 1:
        *operation = '+';
        break;
      case 2:
        *operation = '-';
        break;
      case 3:
        *operation = '*';
        break;
      case 4:
        *operation = '/';
        break;
      default:
        break;
    }
  }

  void GetOperands(double *firstOperand, double *secondOperand){
    printf("Please enter the first operand: ");
    scanf("%lf",firstOperand);
    printf("Please enter the second operand: ");
    scanf("%lf",secondOperand);
  }

void PerformOperation(double firstOperand, double secondOperand, char operation, double *result){
  switch (operation){
    case '+':
      if(firstOperand+secondOperand<=DBL_MAX && firstOperand+secondOperand>=DBL_MIN){
        *result=firstOperand+secondOperand;
      }else if(firstOperand+secondOperand<=DBL_MAX){
        printf("Number overflow\n");
        return false;
      }else{
        printf("Number underflow\n");
        return false;
      }
      break;
    case '-':
      if(firstOperand-secondOperand>=DBL_MIN&&firstOperand-secondOperand<=DBL_MAX){
          *result=firstOperand-secondOperand;
      }else if (firstOperand-secondOperand<=DBL_MAX) {
        printf("Number overflow\n");
        return false;
      }
      else{
        printf("Number underflow\n");
        return false;
      }

      break;
    case '*':
      if(firstOperand*secondOperand<=DBL_MAX&&firstOperand*secondOperand>=DBL_MIN){
        *result=firstOperand*secondOperand;
      }else if(firstOperand*secondOperand>DBL_MAX){
        printf("Number overflow\n");
        return false;
      }else{
        printf("Number underflow\n");
        return false;
      }
      break;

    case '/':
      if(secondOperand!=0&&firstOperand/secondOperand<=DBL_MAX&&firstOperand/secondOperand>=DBL_MIN){
        *result=firstOperand/secondOperand;
      }else if(secondOperand==0){
        printf("Division by 0\n");
        return false;
      }else if(firstOperand/secondOperand>DBL_MAX){
        printf("Number overflow\n");
        return false;
      }else{
        printf("Number underflow\n");
        return false;
      }
      break;
  }
  return true;
}

int main(int argc, char *argv[]){
  int operationNumber;
  char operation;
  double firstOperand;
  double secondOperand;
  double result;
  bool isNotAllowed=false;
  bool shouldEnd=false;
  bool shouldOutputResult;
  do {
    do{
        operationNumber=GetOperation();
        if(operationNumber<-1||operationNumber==0||operationNumber>4){
          isNotAllowed=true;
          printf("Input not allow, please try again\n");
        }
        if(operationNumber==-1){
          shouldEnd=true;
        }
    }while(isNotAllowed);
    if(!shouldEnd){
      GetOperands(&firstOperand, &secondOperand);
      TurnOperationNumberIntoOperation(operationNumber, &operation);
      shouldOutputResult=PerformOperation(firstOperand, secondOperand, operation, &result);
      if (shouldOutputResult) {
        printf("The result is: %.2lf\n\n",result);
      }
    }
  } while(!shouldEnd);

  return 0;

}
