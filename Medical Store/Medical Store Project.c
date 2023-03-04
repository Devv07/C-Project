#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<stdlib.h>

struct medicine {
  int id, price, quantity;
  char MedicineName[100], Company[100], info[5000], mfd[50], exp[50];

}
m;
void owner_Login();
void owner_Create();
void owner_LoginSystem();
void user_Login();
void user_Create();
void user_LoginSystem();
void Available_Medicine();
void Search_Medicine();
void Delete_Medicine();
void Update_Medicine();
void Purchase_Medicine();
void Store_Medicine();

void main() {
  system("color a");
  printf("\n----------------------------------------------Wel-Come To Our Medical Store-----------------------------------------------\n\n");
  int choice, d;
  do {
    printf("Enter  :-\n1- OWNER \n2- CUSTOMER\n");
    scanf("\t%d", & choice);
    switch (choice) {
    case 1: {
      printf("\n\n====================================================OWNER===================================================\n\n");
      owner_LoginSystem();
      system("cls");
      printf("\n\n====================================================OWNER===================================================\n\n");

      int choice, c, num = 0;
      do {
        printf("\nEnter\n1- To See Available Medicine and Add Medicine.\n2- To Search Medicine.\n3- To Delete Medicine\n4- To Update Medicine.\n");
        scanf("%d", & choice);
        switch (choice) {
        case 1: {
          system("cls");
          int choice3, f;
          do {
            printf("\n\nEnter \n1-Store Medicine\n2-To see the Available Medicine\n");
            scanf("%d", & choice3);
            switch (choice3) {
            case 1: {
              Store_Medicine();
              break;
            }
            case 2: {
              Available_Medicine();
              break;
            }
            }
            printf("\nEnter 1 for 'GO BACK' or Press any number for MENU OPTION :");
            scanf("%d", & f);
            system("cls");
          }
          while (f == 1);
          break;
        }
        case 2: {
          system("cls");
          Search_Medicine();
          break;
        }
        case 3: {
          system("cls");
          Available_Medicine();
          Delete_Medicine();
          break;
        }
        case 4: {
          system("cls");
          Available_Medicine();
          Update_Medicine();
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
      printf("\n\n===========================================================CUSTOMER========================================================\n\n");
      user_LoginSystem();
      system("cls");
      printf("\n\n===========================================================CUSTOMER========================================================\n\n");
      int i, j, choice, num = 0, c;
      do {
        printf("Enter 1 for Purchase\nEnter 2 for Search Medicine.\n");
        scanf("%d", & choice);
        switch (choice) {
        case 1: {
          Available_Medicine();
          Purchase_Medicine();
          break;
        }
        case 2: {
          system("cls");
          Search_Medicine();
          Purchase_Medicine();
          break;
        }
        }
        printf("\nPress 1 for 'MENU' and Press any  number for 'Login System'.\n");
        fflush(stdin);
        scanf("%d", & c);
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
    system("color a");
  }
  while (d == 1);
}
//Owner login System
void owner_LoginSystem() {
  char ans[10];
  printf("Type :-\n\tYes -Login\n\tNo -Create\n");
  fflush(stdin);
  scanf("%s", & ans);
  if (strcmp(ans, "yes") == 0 || strcmp(ans, "YES") == 0 || strcmp(ans, "Yes") == 0) {
    owner_Login();
  } else {
    owner_Create();
  }
}
void owner_Login() {
  FILE * fp;
  char username[50], fusername[50];
  int pin, fpin;
  do {
    fp = fopen("ownersLogin.txt", "r");
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
      printf("You are gaven Incorrect information. Try Agin...\n\n");
    }
  }
  while ((strcmp(username, fusername) != 0) || (pin != fpin));
}
void owner_Create() {
  FILE * fp;
  char username[50];
  int pin;
  fp = fopen("ownersLogin.txt", "w");
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
  owner_Login();
}
//User Login System
void user_LoginSystem() {
  char ans[10];
  printf("Type :-\n\tYes -Login\n\tNo -Create\n");
  fflush(stdin);
  scanf("%s", & ans);
  if (strcmp(ans, "yes") == 0 || strcmp(ans, "YES") == 0 || strcmp(ans, "Yes") == 0) {
    user_Login();
  } else {
    user_Create();
  }
}
void user_Login() {
  FILE * fp;
  char username[50], fusername[50];
  int pin, fpin;
  do {
    fp = fopen("usersLogin.txt", "r");
    printf("Enter UserName :");
    scanf(" %s", & username);
    printf("Enter PIN :");
    scanf(" %d", & pin);
    getchar();
    fscanf(fp, "%s %d", & fusername, & fpin);
    if ((strcmp(username, fusername) == 0) && (pin == fpin)) {
      printf("You have successfully Log-In. \n\n");
      fclose(fp);
    } else {
      printf("You are gaven Incorrect information. Try Agin...\n");
    }
  }
  while ((strcmp(username, fusername) != 0) || (pin != fpin));
}
void user_Create() {
  FILE * fp;
  char username[50];
  int pin;
  fp = fopen("usersLogin.txt", "w");
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
  user_Login();
}
//available medicine
void Available_Medicine() {
  struct medicine m;
  FILE * fp;
  fp = fopen("StoreMedicine.txt", "rb");
  printf("***********************************************************All Available Medicine*********************************************************************\n");
  printf("\nID\tPARTICULARS\t\tPRICE\t\tQUANTITY\tCOMPANY-NAME\t\tMANUFACTURE-DATE\tEXPIRED-DATE\n");
  while (fread( & m, sizeof(struct medicine), 1, fp)) {
    printf("\n%d\t%s\t\t%d\t\t%d\t\t%s\t\t%s\t\t%s\n", m.id, m.MedicineName, m.price, m.quantity, m.Company, m.mfd, m.exp);
  }
  printf("\n*******************************************************************************************************************************************************\n");
  fclose(fp);
}

//delete Medicine
void Delete_Medicine() {
  struct medicine m;
  int id, i;
  FILE * fp1, * fp2;
  printf("Enter Id to be deleted\n");
  fflush(stdin);
  scanf("%d", & id);
  fp1 = fopen("StoreMedicine.txt", "rb");
  fp2 = fopen("TempFile.txt", "wb");
  if (fp1 == NULL) {
    printf("File are Empty !");
  }
  while (fread( & m, sizeof(struct medicine), 1, fp1)) {
    if (m.id != id) {
      fwrite( & m, sizeof(struct medicine), 1, fp2);
    }
  }
  fclose(fp1);
  fclose(fp2);
  remove("StoreMedicine.txt");
  rename("TempFile.txt", "StoreMedicine.txt");
  printf("Medicine of %d was Deleted Successfully\n", id);

}

//Search Medicine 
void Search_Medicine() {
  struct medicine m;
  char name[100];
  printf("\n\nEnter the Medicine Name you want to search  :");
  fflush(stdin);
  gets(name);
  FILE * fp;
  fp = fopen("StoreMedicine.txt", "rb");
  while (fread( & m, sizeof(struct medicine), 1, fp)) {
    if (strcmp(name, m.MedicineName) == 0) {
      printf("***************************************************** Search Items **************************************************************\n");
      printf("\nID\tPARTICULARS\t\tPRICE\t\tQUANTITY\tCOMPANY-NAME\t\tMANUFACTURE-DATE\tEXPIRED-DATE\n");
      printf("\n%d\t%s\t\t%d\t\t%d\t\t%s\t\t%s\t\t%s\n", m.id, m.MedicineName, m.price, m.quantity, m.Company, m.mfd, m.exp);
      printf("\n***************************************************************************************************************************************\n");
      break;
    }
  }
  fclose(fp);
}

//Purchase Medicine
void Purchase_Medicine() {
  struct medicine m;
  FILE * fp;
  fp = fopen("StoreMedicine.txt", "rb");
  int Id, check, i, quantity, c;
  printf("Enter Id to Purchase Medicine :");
  fflush(stdin);
  scanf("%d", & Id);
  while (fread( & m, sizeof(struct medicine), 1, fp)) {
    if (Id == m.id) {
      printf("***********************************************************Purchase Medicine*********************************************************************\n");
      printf("\nID\tPARTICULARS\t\tPRICE\t\tQUANTITY\tCOMPANY-NAME\t\tMANUFACTURE-DATE\tEXPIRED-DATE\n");
      printf("\n%d\t%s\t\t%d\t\t%d\t\t%s\t\t%s\t\t%s\n", m.id, m.MedicineName, m.price, m.quantity, m.Company, m.mfd, m.exp);
      printf("\n****************************************************************************************************************************************\n");
      printf("\nDo you want to purchase %s.\n\nTo Buys Medicine press 1.\nTo Cancle press any other number.\n", m.MedicineName);
      fflush(stdin);
      scanf("%d", & c);
      if (c == 1) {
        printf("Enter Quantity to Purchase :");
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

//Store or Add Medicine
void Store_Medicine() {
  struct medicine m;
  FILE * fp;
  fp = fopen("StoreMedicine.txt", "ab");
  printf("Enter the Medicine ID :");
  scanf("%d", & m.id);
  printf("Enter the Medicine Name :");
  fflush(stdin);
  gets(m.MedicineName);
  printf("Enter the Medicine Price :");
  scanf("%d", & m.price);
  printf("Enter the Quantity :");
  scanf("%d", & m.quantity);
  printf("Enter the Company Name :");
  fflush(stdin);
  gets(m.Company);
  printf("Enter the Manufacture-Date(yyyy-mm-dd) :");
  fflush(stdin);
  gets(m.mfd);
  printf("Enter the Expired-Date(yyyy-mm-dd) :");
  fflush(stdin);
  gets(m.exp);
  fwrite( & m, sizeof(struct medicine), 1, fp);
  printf("\nMedicine are Successfully stored.\n");
  fclose(fp);
}

//Update Medicine
void Update_Medicine() {
  struct medicine m;
  FILE * fpr1;
  FILE * fpr2;
  int c, num;
  char Med_Name[100];
  fpr1 = fopen("StoreMedicine.txt", "rb");
  fpr2 = fopen("copyMedicine.txt", "wb");
  printf("Enter Id do you went to Update Medicine : ");
  fflush(stdin);
  scanf("%d", & num);
  while (fread( & m, sizeof(struct medicine), 1, fpr1)) {
    if (num == m.id) {
      int choice1;
      printf("Enter\n1 - Change Id\n2 - Change Medicine Name\n3 - Change Quantity\n4 - Change Price\n5 - Change Company\n6 - Change MFD_DATE\n7 - Change EXP_DATE\n8 - Change Info\n");
      scanf("%d", & choice1);
      switch (choice1) {
      case 1: {
        printf("Enter Id to be changed : ");
        fflush(stdin);
        scanf("%d", & m.id);
        printf("Id changed Successfully\n");
        break;
      }
      case 2: {
        printf("Enter Medicine Name to be changed : ");
        fflush(stdin);
        gets(m.MedicineName);
        printf("Product Name changed Successfully\n");
        break;
      }
      case 3: {
        printf("Enter Quantity to be changed : ");
        fflush(stdin);
        scanf("%d", & m.quantity);
        printf("Quantity changed Successfully\n");
        break;
      }
      case 4: {
        printf("Enter Price to be changed : ");
        fflush(stdin);
        scanf("%d", & m.price);
        printf("Price changed Successfully\n");
        break;
      }
      case 5: {
        printf("Enter company to be changed : ");
        fflush(stdin);
        gets(m.Company);
        printf("Company changed Successfully\n");
        break;
      }
      case 6: {
        printf("Enter the Manufacture-Date(yyyy-mm-dd) : ");
        fflush(stdin);
        gets(m.mfd);
        break;
      }
      case 7: {
        printf("Enter the Expired-Date(yyyy-mm-dd) : ");
        fflush(stdin);
        gets(m.exp);
        break;
      }
      default: {
        printf("You are choose wrong number! Please choose Right Number.\n");
        break;
      }
      }
      fwrite( & m, sizeof(struct medicine), 1, fpr2);
    } else {
      fwrite( & m, sizeof(struct medicine), 1, fpr2);
    }
  }
  fclose(fpr1);
  fclose(fpr2);
  remove("StoreMedicine.txt");
  rename("copyMedicine.txt", "StoreMedicine.txt");
}