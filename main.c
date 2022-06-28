#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
int find_the_loan(int p,int t,float r){
    float a;
    a=(p*t*r/100)+p;
return a;
};
int CI(int p,int t,float r){
    float ci;
ci = p* (pow((1 + r / 100), t));
return ci;
};

int main()
{   char fname[100],lname[100];
    int  i, num,dd,mm,yy;
    char s[10],phonenumber[100],accno[100];
    float w=0;
    char yesorno[10];
    int bankno,principle,t;
    float r;

    FILE *fptr;

    printf("##############################");
    printf("\n::: Loan Management System :::\n");
    printf("##############################\n");
      printf("\nEnter date in dd mm yy format : ");
    scanf("%d %d %d",&dd,&mm,&yy);
    printf("Enter number of people: ");
    scanf("%d", &num);

   fptr = (fopen("Record.txt", "a+"));
   fprintf(fptr,"\nDate : %d/%d/%d",dd, mm, yy);

   for(i = 0; i < num; ++i)
   {
      printf("\n\nFor Customer %d\nEnter first name : ", i+1);
      scanf("%s", fname);
      printf("Enter last name : ", i+1);
      scanf("%s", lname);
      printf("Enter 6 digit account no. : ");
     goto sub;
      sub:scanf("%s", &accno);
      if (strlen(accno)!=6)
        {
          printf("Please enter proper account no. : ");
          goto sub;
        }
        
     else{
      printf("Enter your phone no. : ");
       goto money;
      money:scanf("%s", &phonenumber);
       
        if (strlen(phonenumber)!=10)
        {
          printf("Please enter the correct no. : ");
          goto money;
        }
          
        else{
          
      printf("\nDo you require any loan(y/n) : ");
      scanf("%s",yesorno);
        if (yesorno[0]=='y')
      {
     
        printf("\nWhat type of loan do you require?\nSelect your option-\n\n1. House Loan\n2. Car Loan\n3. Property Loan\n4. Student Loan\n5. Small Business Loan\n6. Home Innovation Loans\n7. Agriculture Loans\n8. Gold Loan\n9. Personal Loan\n10. Credit Card Loan\n11. Payday Loan\n\nPlease enter your option no. : ");
        goto banks;
        banks: scanf("%d",&bankno);
        

        switch(bankno){
            case 1: r=8.65;
                break;  
            case 2: r=10.75;
                break;        
            case 3: r=9.35;
                break;  
            case 4: r=15.5;
                break;        
            case 5: r=13.0;
                break;  
            case 6: r=8.0;
                break;        
            case 7: r=7.5;
                break;  
            case 8: r=8.4;
                break;        
            case 9: r=9.0;
                break;  
            case 10: r=11.30;
                break;        
            case 11: r=7.5;
                break;  
           
            default: printf("Please choose appropriate number  :");
              goto banks;
                break;  
        }

        printf("\nNote: If your required amount is more than 10 lakhs, \nthen the intrest will be shifted to compound intrest.\n\nEnter the amount required : ");
        scanf("%d",&principle);
        printf("Enter the time in year : ");
        scanf("%d",&t);
        
    if(principle<1000000){
        w=find_the_loan(principle,t,r);
        printf("\n The amount you need to pay in total \nby the end of your term : Rs %.2f",w);}
       
    else{
       w=CI(principle,t,r);
        printf("\n The amount you need to pay in total \nby the end of your term : Rs %.2f",w);}
        
    }
    else{
        printf("\nYour loan amount will be set to Rs 0.00");
        w=0;
    }
    fprintf(fptr,"\nAccount No. : %s\nName: %s %s \nPhone No. : %s \nLoan : %.2f\n",accno, fname,lname, phonenumber, w);
   } }}

   fclose(fptr);
   
    return 0;
}
