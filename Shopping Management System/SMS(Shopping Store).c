#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<stdlib.h>

struct Product {
  int id, price, quantity;
  char ProductName[100], Company[100], info[5000];

}
m;
void ownerLogin(void);
void ownerCreate(void);
void ownerLoginSystem(void);
void userLogin(void);
void userCreate(void);
void userLoginSystem(void);
void AvailableGoods(void);
void SearchProduct(void);
void DeleteProduct(void);
void EditProduct(void);
void PurchaseGoods(void);
void enterProduct(void);

void main() {
  system("color b");
  printf("\n----------------------------------------------------------------Wel-Come To Our Sopping Management System-------------------------------------------------------\n\n");
  int choice, d;
  do {
    printf("Press 1 for Ower :\n");
    printf("Press 2 for User :\n");
    scanf("\t%d", & choice);
    switch (choice) {
    case 1: {
      printf("\n***********************************OWNER**********************************\n\n");
      ownerLoginSystem();
      system("cls");
      printf("\n\n************************************************OWNER*****************************************************\n\n");
      int i, j, choice, num = 0, c;
      do {
        printf("Enter\n1- To See Available Items and Add Items.\n2- To Search Product.\n3- To Delete Product\n4- To Edit Product.\n");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
          system("cls"); {
            int choice3, f;
            do {
              printf("\nEnter \n1-Add Products/Items\n2-To see the Available Product\n");
              scanf("%d", & choice3);
              switch (choice3) {
              case 1: {
                num++;
                enterProduct();
                break;
              }
              case 2: {
                AvailableGoods();
                break;
              }
              }
              printf("\nEnter 1 for 'GO BACK' or Press any number for MENU OPTION :");
              scanf("%d", & f);
            }
            while (f == 1);
            break;
          }
        case 2: {
          system("cls");
          SearchProduct();
          break;

        }
        case 3: {
          system("cls");
          AvailableGoods();
          DeleteProduct();
          break;
        }
        case 4: {
          system("cls");
          AvailableGoods();
          EditProduct();
          break;
        }
        }
        printf("\nPress 1 for 'MENU' and Press any  number for 'Login System'.\n");
        scanf("%d", & c);
        system("cls");
      } while (c == 1);
      break;
    }
    case 2: {
      printf("\n******************************************************USER********************************************************\n\n");
      userLoginSystem();
      system("cls");
      printf("\n\n******************************************************USER********************************************************\n");
      int i, j, choice, num = 0, c;
      do {
        printf("\n\nEnter 1 for Purchase\nEnter 2 for Search Product.\n");
        scanf("%d", & choice);
        switch (choice) {
        case 1: {
          system("cls");
          AvailableGoods();
          PurchaseGoods();
          break;
        }
        case 2: {
          system("cls");
          SearchProduct();
          PurchaseGoods();
          break;
        }
        }
        printf("\nPress 1 for 'MENU' and Press any  number for 'Login System'.\n");
        fflush(stdin);
        scanf("%d", & c);
        system("cls");
      }
      while (c == 1);
      break;
    }
    default:
      printf("Your are Enter Invalied Number.!");
    }
    printf("\nGo to 'LOGIN SYSTEM' press 1 or Press any number to exit!.\n");
    fflush(stdin);
    scanf("%d", & d);
    system("cls");
    system("color b");
  }
  while (d == 1);
}
//Owner login System
void ownerLoginSystem(void) {
  char ans[10];
  printf(" Type 'yes' for Login Or Type 'no' for Create New Account......\n\n");
  fflush(stdin);
  scanf("%s", & ans);
  if (strcmp(ans, "yes") == 0 || strcmp(ans, "YES") == 0 || strcmp(ans, "Yes") == 0) {
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
    fp = fopen("ownerLogin.txt", "r");
    printf("Enter UserName :");
    scanf(" %s", & username);
    printf("Enter PIN :");
    scanf(" %d", & pin);
    getchar();
    fscanf(fp, "%s %d", & fusername, & fpin);
    if ((strcmp(username, fusername) == 0) && (pin == fpin)) {
      printf("\nYou have successfully Log-In.\n\n");
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
  fp = fopen("ownerLogin.txt", "w");
  printf("\nEnter your Username :");
  fflush(stdin);
  gets(username);
  fprintf(fp, "%s\n", username);
  printf("Create PIN :");
  scanf("%d", & pin);
  getchar();
  fprintf(fp, "%d", pin);
  printf("\nYour New Account are created. !\n");
  fclose(fp);
  ownerLogin();
}
//User Login System
void userLoginSystem(void) {
  char ans[10];
  printf(" Type 'yes' for Login Or Type 'no' for Create New Account.....\n\n");
  fflush(stdin);
  scanf("%s", & ans);
  if (strcmp(ans, "yes") == 0 || strcmp(ans, "YES") == 0 || strcmp(ans, "Yes") == 0) {
    userLogin();
  } else {
    userCreate();
  }
}
void userLogin(void) {
  FILE * fp;
  char username[50], fusername[50];
  int pin, fpin;
  do {
    fp = fopen("userLogin.txt", "r");
    printf("Enter UserName :");
    scanf(" %s", & username);
    printf("Enter PIN :");
    scanf(" %d", & pin);
    getchar();
    fscanf(fp, "%s %d", & fusername, & fpin);
    if ((strcmp(username, fusername) == 0) && (pin == fpin)) {
      printf("\nYou have successfully Log-In. \n\n");
      fclose(fp);
    } else {
      printf("\nYou are gaven Incorrect information. Try Agin...\n");
    }
  }
  while ((strcmp(username, fusername) != 0) || (pin != fpin));
}
void userCreate(void) {
  FILE * fp;
  char username[50];
  int pin;
  fp = fopen("userLogin.txt", "w");
  printf("\nEnter your Username :");
  fflush(stdin);
  gets(username);
  fprintf(fp, "%s\n", username);
  printf("Create PIN :");
  scanf("%d", & pin);
  getchar();
  fprintf(fp, "%d", pin);
  printf("\nYour New Account are created. !\n");
  fclose(fp);
  userLogin();
}
//Owner Working area
void AvailableGoods(void) {
  struct Product m;
  FILE * fp;
  fp = fopen("addProducts.txt", "rb");
  printf("******************************************************************All Available Items***************************************************************************\n");
  printf("\nID\tPARTICULARS\t\t\tPRICE\t\tQUANTITY\tCOMPANY-NAME\t\tINFO.\n");
  while (fread( & m, sizeof(struct Product), 1, fp)) {
    printf("\n%d\t%s\t\t\t%d\t\t%d\t\t%s\t\t%s\n", m.id, m.ProductName, m.price, m.quantity, m.Company, m.info);
  }
  printf("\n***************************************************************************************************************************************************************\n");
  fclose(fp);
}
void DeleteProduct(void) {
  struct Product m;
  int id, found = 0;
  FILE * fp1, * fp2;
  fp1 = fopen("addProducts.txt", "rb");
  fp2 = fopen("CopyFile.txt", "wb");
  if (fp1 == NULL) {
    printf("File are Empty !");
  }
  printf("\n\n********************************************************** Now Are You Working With Delete Function *****************************************************************\n");
  printf("Enter Id to be Deleted : ");
  fflush(stdin);
  scanf("%d", & id);
  while (fread( & m, sizeof(struct Product), 1, fp1)) {
    if (m.id != id) {
      found = 1;
      fwrite( & m, sizeof(struct Product), 1, fp2);
    }
  }
  if (found) {
    printf("Product of %d was Deleted Successfully\n", id);
  }
  fclose(fp1);
  fclose(fp2);
  remove("addProducts.txt");
  rename("CopyFile.txt", "addProducts.txt");
}
void SearchProduct(void) {
  struct Product m;
  char name[100];
  int flag = 0;
  printf("\n\n********************************************************** Now Are You Working With Search Function *****************************************************************\n");
  printf("Enter the Product Name you want to search : ");
  fflush(stdin);
  gets(name);
  FILE * fp;
  fp = fopen("addProducts.txt", "rb");
  while (fread( & m, sizeof(struct Product), 1, fp)) {
    if (strcmp(name, m.ProductName) == 0) {
      flag == 1;
      printf("\n**************************************************************** Searching Items *************************************************************************\n");
      printf("\nID\tPARTICULARS\t\t\tPRICE\t\tQUANTITY\tCOMPANY-NAME\t\tInfo\n");
      printf("\n%d\t%s\t\t\t%d\t\t%d\t\t%s\t\t%s\n", m.id, m.ProductName, m.price, m.quantity, m.Company, m.info);
      printf("\n************************************************************************************************************************************************************\n");
    }
  }
  if (!flag) {
    printf("Product Are Not Found....!\n");
  }
  fclose(fp);
}
void PurchaseGoods(void) {
  struct Product m;
  FILE * fp;
  fp = fopen("addProducts.txt", "rb");
  int Id, check, i, quantity, c;
  printf("\n\n********************************************************** Now Are You Working With Purchase Function *****************************************************************\n");

  printf("\nEnter Id to Purchase Product :");
  fflush(stdin);
  scanf("%d", & Id);
  while (fread( & m, sizeof(struct Product), 1, fp)) {
    if (Id == m.id) {
      printf("\n\n***************************************************************** Purchase Items ***********************************************************************\n");
      printf("\nID\tPARTICULARS\t\t\tPRICE\t\tQUANTITY\tCOMPANY-NAME\t\tINFO\n");
      printf("\n%d\t%s\t\t\t%d\t\t%d\t\t%s\t\t%s\n", m.id, m.ProductName, m.price, m.quantity, m.Company, m.info);
      printf("\n******************************************************************************************************************************************************\n");
      printf("\nDo you want to purchase %s.\n\nTo Buys Items press 1.\nTo Cancle press any other number.\n", m.ProductName);
      fflush(stdin);
      scanf("%d", & c);
      if (c == 1) {
        printf("\nEnter Quantity to Purchase :");
        scanf("%d", & quantity);
        if (m.quantity >= quantity) {
          printf("------------------------------------------\n");
          printf("Total Price to be paid\t\t: %d\n", quantity * m.price);
          printf("------------------------------------------\n");
        } else {
          printf("Please Enter quantity below Available Quantity\n");
        }
      }
    }
  }
  fclose(fp);
}
void enterProduct(void) {
  struct Product m;
  FILE * fp;
  fp = fopen("addProducts.txt", "ab");
  printf("\n\n********************************************************** Now Are You Working With Add Items Function *****************************************************************\n");
  printf("Enter the Product ID :");
  scanf("%d", & m.id);
  printf("Enter the Product Name :");
  fflush(stdin);
  gets(m.ProductName);
  printf("Enter the Product Price :");
  scanf("%d", & m.price);
  printf("Enter the Quantity Product :");
  scanf("%d", & m.quantity);
  printf("Enter the Company Name :");
  fflush(stdin);
  gets(m.Company);
  printf("Enter the Info of Product :");
  fflush(stdin);
  gets(m.info);
  fwrite( & m, sizeof(struct Product), 1, fp);
  printf("\nData are Successfully stored.\n");
  fclose(fp);
}
void EditProduct(void) {
  struct Product m;
  FILE * fpr1;
  FILE * fpr2;
  int c;
  char Pro_Name[50];
  fpr1 = fopen("addProducts.txt", "rb");
  fpr2 = fopen("copyProducts.txt", "wb");
  printf("\n\n********************************************************** Now Are You Working With Edit Function *****************************************************************\n");
  printf("Enter Product Name do you went to Edit : ");
  fflush(stdin);
  gets(Pro_Name);
  while (fread( & m, sizeof(struct Product), 1, fpr1)) {
    if (strcmp(Pro_Name, m.ProductName) == 0) {
      c == 1;
      int choice;
      printf("Enter\n1 - Change Id\n2 - Change Product Name\n3 - Change Quantity\n4 - Change Price\n5 - Change Company\n6 - Change Info\n");
      scanf("%d", & choice);
      if (choice == 1) {
        int id;
        printf("Enter Id : ");
        fflush(stdin);
        scanf("%d", & id);
        m.id = id;
        printf("Id changed Successfully\n");
      }
      if (choice == 2) {
        char name[100];
        printf("Enter Product Name : ");
        fflush(stdin);
        gets(name);
        strcpy(m.ProductName, name);
        printf("Product Name changed Successfully\n");
      }
      if (choice == 3) {
        int quantity;
        printf("Enter Quantity : ");
        fflush(stdin);
        scanf("%d", & quantity);
        m.quantity = quantity;
        printf("Quantity changed Successfully\n");
      }
      if (choice == 4) {
        int price;
        printf("Enter Price : ");
        fflush(stdin);
        scanf("%d", & price);
        m.price = price;
        printf("Price changed Successfully\n");
      }
      if (choice == 5) {
        char company[100];
        printf("Enter Company : ");
        fflush(stdin);
        gets(company);
        strcpy(m.Company, company);
        printf("Company changed Successfully\n");
      }
      if (choice == 6) {
        char info[100];
        printf("Enter info (Less than 100 Characters) : ");
        fflush(stdin);
        gets(info);
        strcpy(m.info, info);
        printf("Review changed Successfully\n");
      }
      if (choice <= 0 && choice > 7) {
        printf("You are choose wrong number! Please choose Right Number.\n");
      }
      fwrite( & m, sizeof(struct Product), 1, fpr2);
    } else {
      fwrite( & m, sizeof(struct Product), 1, fpr2);
    }
   }
		fclose(fpr1);
  fclose(fpr2);
  remove("addProducts.txt");
  rename("copyProducts.txt", "addProducts.txt");
}