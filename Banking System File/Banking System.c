#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<stdlib.h>

struct account {
  char name[50], AccountNum[50], Per_address[100], Tem_address[100];
  int Amount;
  double number;
}
r;
void Deposit(void);
void Withdraw(void);
void CheckAccount(void);
void CreateAccount(void);
void DeleteAccount(void);
void SearchAccount(void);
void ownerLoginSystem(void);
void ownerCreate(void);
void ownerLogin(void);
void main() {
  system("color 9");
  int choice;
  char c;
  printf("\n**********************************************Wel-Come to Our Bank*******************************************************\n\n");
  ownerLoginSystem();
  system("cls");
  do {
    printf("Enter :-\n1- Create Account\n2- Check Account\n3- Search Account\n4- WithDraw Amount\n5- Deposit Amount\n6- Delete Account\n");
    scanf("%d", & choice);
    if (choice == 1) {
      int d;
      do {
        CreateAccount(); 
        break;
        printf("Press 1 for Back\n");
        fflush(stdin);
        scanf("%d", & d);
      }
      while (d == 1);
    }
    if (choice == 2) {
      int e;
      do {
        CheckAccount(); 
        break;
        printf("Press 1 for Back\n");
        fflush(stdin);
        scanf("%d", & e);
      }
      while (e == 1);
    }
    if (choice == 3) {
      int j;
      do {
        SearchAccount();
        break;
        printf("Press 1 for back\n");
        fflush(stdin);
        scanf("%d", & j);
      }
      while (j == 1);
    }
    if (choice == 4) {
      int f;
      do {
        Withdraw();
        break;
        printf("Press 1 for Back\n");
        fflush(stdin);
        scanf("%d", & f);
      }
      while (f == 1);
    }
    if (choice == 5) {
      int g;
      do {
        Deposit();
        break;
        printf("Press 1 for back\n");
        fflush(stdin);
        scanf("%d", & g);
      }
      while (g == 1);
    }
    if (choice == 6) {
      int h;
      do {
      	 CheckAccount();
        DeleteAccount();
        break;
        printf("Press 1 for back\n");
        fflush(stdin);
        scanf("%d", & h);
      }
      while (h == 1);
    }
    printf("\nTo Continue with MENU Press 'Y' else any letter\n");
    fflush(stdin);
    scanf("%c", & c);
    	system("cls");
  }
  while (c == 'y' || c == 'Y');
  printf("\nThanks for using our ATM\n");
}
//Owner login System
void ownerLoginSystem(void) {
  char ans[10];
  printf(" Type 'yes' for Login Or Type 'no' for Create New Account.......\n");
  fflush(stdin);
  scanf("%s", & ans);
  if (strcmp(ans, "yes") == 0) {
    ownerLogin();
  } else {
    ownerCreate();
  }
}
void ownerLogin(void) {
  FILE * fp;
  char username[50], fusername[50];
  int pin, fpin;
  do {
    fp = fopen("Login.txt", "r");
    printf("Enter UserName :");
    scanf(" %s", & username);
    printf("Enter PIN :");
    scanf(" %d", & pin);
    getchar();
    fscanf(fp, "%s %d", & fusername, & fpin);
    if ((strcmp(username, fusername) == 0) && (pin == fpin)) {
      printf("You have successfully Log-In.\n\n");
      fclose(fp);
    } else {
      printf("You are gaven Incorrect information. Try Agin...\n");
    }
  }
  while ((strcmp(username, fusername) != 0) || (pin != fpin));
}
void ownerCreate(void) {
  FILE * fp;
  char username[50];
  int pin;
  fp = fopen("Login.txt", "w");
  printf("Enter your Username :");
  fflush(stdin);
  gets(username);
  fprintf(fp, "%s\n", username);
  printf("Create PIN :");
  scanf("%d", & pin);
   getchar();
  fprintf(fp, "%d", pin);
  printf("Your New Account are created. !\n");
  fclose(fp);
  ownerLogin();
}
//Creating Customer Account
void CreateAccount(void) {
  struct account r;
  FILE * fptr;
  fptr = fopen("StoreRecord.txt", "ab");
  printf("\n\n==============================================DATA-ENTRY=================================================================\n\n");
  printf("Create Account Number (Combination of Number and Letter) more then 8 or less then 10 digits : ");
  scanf(" %[^\n]", & r.AccountNum);
  printf("\nEnter Username (Full-Name) : ");
  scanf(" %[^\n]", & r.name);
  printf("Enter Customer Address (Permanent Address) : ");
  scanf(" %[^\n]", & r.Per_address);
  printf("Enter Customer Address (Temporary Address) : ");
  scanf(" %[^\n]", & r.Tem_address);
  printf("Enter Customer Mobile Number : ");
  scanf("%lf", & r.number);
  printf("Enter Amount more than 500 : ");
  scanf("%d", & r.Amount);
  fwrite( & r, sizeof(struct account), 1, fptr);
  fclose(fptr);
}

//checking account 
void CheckAccount(void) {
  struct account r;
  FILE * fpr;
  fpr = fopen("StoreRecord.txt", "rb");
  if (fpr == NULL) {
    printf("File are Empty...!\n");
  }
  printf("\n===============================================CUSTOMER-LIST================================================================\n\n");
  printf("Account-Number\t\tCustomer-Name\tPer-Address\t\tTem-Address\t\tMobileNumber\tAmount\n\n");
  while (fread( & r, sizeof(struct account), 1, fpr)) {
    printf("%s\t\t%s\t%s\t%s\t%.0lf\t%d\n\n", r.AccountNum, r.name, r.Per_address, r.Tem_address, r.number, r.Amount);
  }
  fclose(fpr);
}
//WithDrawing Amount
void Withdraw(void) {
  struct account r;
  int withdraw, count = 0;
  char Id[50];
  FILE * fptr, * fpr;
  fptr = fopen("StoreRecord.txt", "rb");
  fpr = fopen("DubAccount.txt", "wb");
  printf("\n==============================================WITHDRAW-ACCOUNT=================================================================\n\n");
  printf("Enter Account Number for WithDraw :");
  fflush(stdin);
  gets(Id);
  while (fread( & r, sizeof(struct account), 1, fptr)) {

    if (strcmp(Id, r.AccountNum) == 0) {
      count++;
      printf("\nBalance:%d", r.Amount);
      printf("\nEnter Amount to withdraw :");
      scanf("%d", & withdraw);

      if (withdraw % 100 == 0) {
        if (r.Amount >= withdraw) {
          r.Amount -= withdraw;
          printf("Current Amount is : %d\n", r.Amount);

        } else {
          printf("You don't have enough Amount to Withdraw.\n\tPlease Deposit Amount\n");
        }
      } else {
        printf("Enter Withdrawl Amount in 100's\n");
      }
    }

    fwrite( & r, sizeof(struct account), 1, fpr);
  }
  if (count == 0) {
    printf("Record not found!");
  }
  fclose(fptr);
  fclose(fpr);
  remove("StoreRecord.txt");
  rename("DubAccount.txt", "StoreRecord.txt");
}
//Deposit amount
void Deposit(void) {
  struct account r;
  FILE * fptr;
  FILE * fptemp;
  fptr = fopen("StoreRecord.txt", "rb");
  fptemp = fopen("tempAccount.txt", "wb");
  char userID[50];
  printf("\n==============================================DEPOSIT-ACCOUNT=================================================================\n\n");
  printf("Enter ID to Deposit Amount =");
  scanf("%s", userID);
  while (fread( & r, sizeof(struct account), 1, fptr)) {
    if (strcmp(userID, r.AccountNum) == 0) {
      printf("Deposit Balance :");
      scanf("%d", & r.Amount);
    }
    fwrite( & r, sizeof(struct account), 1, fptemp);

  }
  fclose(fptr);
  fclose(fptemp);
  remove("StoreRecord.txt");
  rename("tempAccount.txt", "StoreRecord.txt");
}
//Delete Account
void DeleteAccount(void) {
  struct account r;
  FILE * fptr;
  FILE * fptemp;
  char userId[50]; 
  printf("\n==============================================DELETE-ACCOUNT=================================================================\n\n");
  printf("Enter Account ID to delete record=");
  scanf("%s", userId);
  fptr = fopen("StoreRecord.txt", "rb");
  fptemp = fopen("tempDelete.txt", "wb");
   while (fread( & r, sizeof(struct account), 1, fptr)) {
    if (strcmp(userId, r.AccountNum) != 0) {
      fwrite( & r, sizeof(struct account), 1, fptemp);
      printf("\n Delete Successful...");
    }
  }
  fclose(fptr);
  fclose(fptemp);
  remove("StoreRecord.txt");
  rename("tempDelete.txt", "StoreRecord.txt");
}
//Search Account
void SearchAccount(void) {
  struct account r;
  FILE * fptr;
  
  fptr = fopen("StoreRecord.txt", "rb");
  char Name[50];
  printf("\n==============================================SEARCH-ACCOUNT=================================================================\n\n");
  printf("Enter Customer Name :");
  fflush(stdin);
  gets(Name);
  while (fread( & r, sizeof(struct account), 1, fptr)) {
    if (strcmp(Name, r.name) == 0) {
      printf("\nAccount-Number\t\tCustomer-Name\tPer-Address\t\tTem-Address\t\tMobileNumber\tAmount\n\n");
      printf("%s\t\t%s\t%s\t%s\t%.0lf\t%d\n", r.AccountNum, r.name, r.Per_address, r.Tem_address, r.number, r.Amount);
    }
  }
  fclose(fptr);
}