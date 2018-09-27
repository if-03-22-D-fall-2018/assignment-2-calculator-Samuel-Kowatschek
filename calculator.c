#include <stdio.h>
#include <stdbool.h>

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

int main(int argc, char *argv[]){
  int operationNumber;
  char operation;
  double firstOperand;
  double secondOperand;
  bool isNotAllowed=false;
  bool shouldEnd=false;
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
  }
  return 0;

}
