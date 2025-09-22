#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct p
{
    char patient_name[30];
    char disease[30];
    int room_no, age;
    char phone[10];
} v[100];
void patient_read();
void patient_add();
void patient_view();
void patient_search();
void patient_edit();
void delete_patient();

struct d
{
    char doctor_name[30];
    char address[50];
    int doctor_id, age;
    char phone[10];
} w[100];
void read_doctor();
void add_doctor();
void view_doctor();
void search_doctor(); 
void edit_doctor();
void delete_doctor();

struct s
{
    char staff_name[30];
    char job[50];
    int job_id, age;
    char phone[10];
} x[100];
void read_staff();
void add_staff();
void view_staff();
void search_staff();
void edit_staff();
void delete_staff();

struct m
{
    char medicine_name[30];
    char availability[50];
    int product_id, price, quantity;
} y[100];
void read_medicine();
void add_medicine();
void view_medicine();
void search_medicine();
void edit_medicine();
void delete_medicine();

struct items
{
    char item[20];
    float price;
    int qty;
};

struct orders
{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

void generateBillHeader(char name[50], char date[30])
{
    printf("\n\n");
    printf("\t          Invoice");
    printf("\n\t   -----------------");
    printf("\nDate:%s", date);
    printf("\nInvoice To: %s", name);
    printf("\n");
    printf("---------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n---------------------------------------");
    printf("\n\n");
}
void generateBillBody(char item[30], int qty, float price)
{
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", qty * price);
    printf("\n");
}
void generateBillFooter(float total)
{
    printf("\n");
    float dis = 0.1 * total;
    float netTotal = total - dis;
    float cgst = 0.09 * netTotal;
    float sgst = 0.09 * netTotal;
    float grandTotal = netTotal + cgst + sgst;
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
    printf("\nCGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\nSGST @9%s\t\t\t%.2f", "%", sgst);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n---------------------------------------\n");
}

int n, i, j = 0, a = 0, sum = 0, g, flag, num;

int main()
{
    int module = 1;
    printf("               ************\n");
    printf("                 ********\n");
    printf("                    **\n");
    printf("        Hospital Management System       \n");
    printf("                    **\n");
    printf("                 ********\n");
    printf("               ************\n");
    int ch;
    do
    {
        printf("1. Patient\n2. Doctor\n3. Staff\n4. Medicine\n5. Billing\n6. Exit\nPlease enter the module you want to access = ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            int n, i, j = 0, a = 0, sum = 0, g, flag, num;
            patient_read();
            int c, q;
            int m;

            while (c != 6)
            {

                printf("\n\nEnter your choice\n\n1. Add patient Information\n2. View patient Information\n3. Search patient\n4. Edit patient Information\n5. Delete patient Information\n6. Exit Patient\n\nOption=");
                scanf("%d", &c);
                fflush(stdin);
                if (c == 1)
                {
                    patient_add();
                }
                else if (c == 2)
                {
                    patient_view();
                }
                else if (c == 3)
                {
                    patient_search();
                }
                else if (c == 4)
                {
                    patient_edit();
                }
                else if (c == 5)
                {
                    delete_patient();
                }
                else if (c == 6)
                {
                    patient_write();

                }
                else
                {
                    printf("\n\nInvalid input , try again by using valid inputs");
                }
                printf("\n\n");
            }
        }

        else if (ch == 2)
        {
            int j = 0, a = 0, sum = 0, g, flag, num;
            read_doctor();
            int c, i, q;
            int m, n;

            while (c != 6)
            {

                printf("Enter your choice\n\n1. Add Doctor Information\n2. View Doctor Information\n3. Search Doctor Information\n4. Edit Doctor Information\n5. Delete Doctor Information\n6. Exit Doctor\n\nOption=");
                scanf("%d", &c);
                fflush(stdin);
                if (c == 1)
                {
                    add_doctor();
                }
                else if (c == 2)
                {
                    view_doctor();
                }
                else if (c == 3)
                {
                    search_doctor();
                }
                else if (c == 4)
                {
                    edit_doctor();
                }
                else if (c == 5)
                {
                    delete_doctor();
                }
                else if (c == 6)
                {
                    write_doctor();

                }
                else
                {
                    printf("\n\nInvalid input, try again by using valid inputs.");
                }
                printf("\n\n");
            }
        }

        else if (ch == 3)
        {
            int j = 0, a = 0, sum = 0, g, flag, num;
            read_staff();
            int c, i, q;
            int m, n;

            while (c != 6)
            {

                printf("Enter your choice\n\n1. Add Staff Information\n2. View Staff Information\n3. Search Staff\n4. Edit Staff Information\n5. Delete Staff Information\n6. Exit Staff\n\nOption=");
                scanf("%d", &c);
                fflush(stdin);
                if (c == 1)
                {
                    add_staff();
                }
                else if (c == 2)
                {
                    view_staff();
                }
                else if (c == 3)
                {
                    search_staff();
                }
                else if (c == 4)
                {
                    edit_staff();
                }
                else if (c == 5)
                {
                    delete_staff();
                }
                else if (c == 6)
                {
                    write_staff();
                    
                }
                else
                {
                    printf("\n\nInvalid input, try again by using valid inputs.");
                }
                printf("\n\n");
            }
        }

        else if (ch == 4)
        {
            int j = 0, a = 0, sum = 0, g, flag, num;
            read_medicine();
            int c, i, q;
            int m, n;

            while (c != 6)
            {

                printf("Enter your choice\n\n1. Add Medicine Information\n2. View Medicine Information\n3. Search Medicine Information\n4. Edit Medicine Information\n5. Delete Medicine Information\n6. Exit Medicine\n\nOption=");
                scanf("%d", &c);
                fflush(stdin);
                if (c == 1)
                {
                    add_medicine();
                }
                else if (c == 2)
                {
                    view_medicine();
                }
                else if (c == 3)
                {
                    search_medicine();
                }
                else if (c == 4)
                {
                    edit_medicine();
                }
                else if (c == 5)
                {
                    delete_medicine();
                }
                else if (c == 6)
                {
                    medicine_write();
                    
                }
                else
                {
                    printf("\n\nInvalid input, try again by using valid inputs.");
                }
                printf("\n\n");
            }
        }

        else if (ch == 5)
        {
            int opt, n;
            struct orders ord;
            struct orders order;
            char saveBill = 'y', contFlag = 'y';
            char name[50];
            FILE *fp;

            while (contFlag == 'y')
            {

                float total = 0;
                int invoiceFound = 0;
                printf("\t============  Patient/Customer's Invoice ============");
                printf("\n\nPlease select your prefered operation");
                printf("\n\n1.Generate Invoice");
                printf("\n2.Show all Invoices");
                printf("\n3.Search Invoice");
                printf("\n4.Exit");

                printf("\n\nYour choice:\t");
                scanf("%d", &opt);
                fgetc(stdin);
                switch (opt)
                {
                case 1:

                    printf("\nPlease enter the name of patient/customer:\t");
                    fgets(ord.customer, 50, stdin);
                    ord.customer[strlen(ord.customer) - 1] = 0;
                    strcpy(ord.date, __DATE__);
                    printf("\nPlease enter the number of fields :\t");
                    scanf("%d", &n);
                    ord.numOfItems = n;
                    for (int i = 0; i < n; i++)
                    {
                        fgetc(stdin);
                        printf("\n\n");
                        printf("Please enter the item %d:\t", i + 1);
                        fgets(ord.itm[i].item, 20, stdin);
                        ord.itm[i].item[strlen(ord.itm[i].item) - 1] = 0;
                        printf("Please enter the quantity:\t");
                        scanf("%d", &ord.itm[i].qty);
                        printf("Please enter the unit price:\t");
                        scanf("%f", &ord.itm[i].price);
                        total += ord.itm[i].qty * ord.itm[i].price;
                    }

                    generateBillHeader(ord.customer, ord.date);
                    for (int i = 0; i < ord.numOfItems; i++)
                    {
                        generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
                    }
                    generateBillFooter(total);

                    printf("\nDo you want to save the invoice [y/n]:\t");
                    scanf("%s", &saveBill);

                    if (saveBill == 'y')
                    {
                        fp = fopen("bill.txt", "a+");
                        fwrite(&ord, sizeof(struct orders), 1, fp);
                        if (fwrite != 0)
                            printf("\nSuccessfully saved");
                        else
                            printf("\nError saving");
                        fclose(fp);
                    }
                    break;

                case 2:

                    fp = fopen("bill.txt", "r");
                    printf("\n  *****Your Previous Invoices*****\n");
                    while (fread(&order, sizeof(struct orders), 1, fp))
                    {
                        float tot = 0;
                        generateBillHeader(order.customer, order.date);
                        for (int i = 0; i < order.numOfItems; i++)
                        {
                            generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                            tot += order.itm[i].qty * order.itm[i].price;
                        }
                        generateBillFooter(tot);
                    }
                    fclose(fp);
                    break;

                case 3:
                    printf("Enter the name of the patient/customer:\t");
                    fgets(name, 50, stdin);
                    name[strlen(name) - 1] = 0;

                    fp = fopen("bill.txt", "r");
                    printf("\t*****Invoice of %s*****", name);
                    while (fread(&order, sizeof(struct orders), 1, fp))
                    {
                        float tot = 0;
                        if (!strcmp(order.customer, name))
                        {
                            generateBillHeader(order.customer, order.date);
                            for (int i = 0; i < order.numOfItems; i++)
                            {
                                generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                                tot += order.itm[i].qty * order.itm[i].price;
                            }
                            generateBillFooter(tot);
                            invoiceFound = 1;
                        }
                    }
                    if (!invoiceFound)
                    {
                        printf("Sorry the invoice for %s doesnot exists", name);
                    }
                    fclose(fp);
                    break;

                case 4:
                    printf("\n\t\t Bye Bye :)\n\n");
                    break;

                default:
                    printf("Sorry invalid option");
                    break;
                }
                printf("\nDo you want to perform another operation in billing?[y/n]:\t");
                scanf("%s", &contFlag);
            }

            
        }




        else if (ch == 6)
        {
            exit(0);
        }

        else
            printf("\n\nInvalid Serial number\n");

        printf("\nIf you want to continue module press 1 \n");
        scanf("%d", &module);
    } while (module == 1);
}

void patient_add()
{
    printf("\n\n");
    printf("Already data inputed on the database =%d\n\n", num);
    printf("How many entry do you want to add=\n");
    scanf("%d", &n);
    sum = n + num;

    for (i = num, j = 0; i < sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter patient's name = ");
        gets(v[i].patient_name);
        fflush(stdin);
        printf("Enter disease = ");
        gets(v[i].disease);
        fflush(stdin);
        printf("Enter age = ");
        scanf("%d", &v[i].age);
        fflush(stdin);
        printf("Enter room number = ");
        scanf("%d", &v[i].room_no);
        fflush(stdin);
        printf("Enter phone number = ");
        gets(v[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}
void patient_view()
{
    for (i = 0; i < num; i++)
    {
        printf("\n");
        printf("Serial number = %d\n", i);
        printf("Patient_name = ");
        puts(v[i].patient_name);
        printf("Disease = ");
        puts(v[i].disease);
        printf("Phone number = ");
        puts(v[i].phone);
        printf("Room number = %d\nAge=%d", v[i].room_no, v[i].age);
        printf("\n\n");
    }
}
void patient_edit()
{
    int q, p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Patient name\n2.Disease\n3.Age\n4.Room number\n5.Phone no.\n");
    printf("Option=");
    scanf("%d", &q);
    if (q <= 5)
    {
        printf("Enter the serial no of that patient = (0 - %d)=", num - 1);
        scanf("%d", &p);
        if (p < num)
        {
            if (q == 1)
            {
                fflush(stdin);
                printf("Enter the new patient name = ");
                gets(v[p].patient_name);
            }
            else if (q == 2)
            {
                fflush(stdin);
                printf("Enter the new disease = ");
                gets(v[p].disease);
            }
            else if (q == 3)
            {
                fflush(stdin);
                printf("Enter the new age = ");
                scanf("%d", &v[p].age);
            }

            else if (q == 4)
            {
                fflush(stdin);
                printf("Enter the new room number = ");
                scanf("%d", &v[p].room_no);
            }

            else if (q == 5)
            {
                fflush(stdin);
                printf("Enter the new phone no = ");
                gets(v[p].phone);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}
void patient_search()
{
    int s, h, f;
    char u[100];
    printf("By what do you want to patient_search?\n");
    printf("1.Serial no.\n2.Patient name\n3.Disease\n4.Room number.\n5.Phone no.\n6.Age\n\nOption = ");
    scanf("%d", &h);
    if (h == 1)
    {
        printf("Enter Serial number of the patient=");
        scanf("%d", &s);
        if (s < num)
        {
            printf("\n");
            printf("Serial Number = %d\n", s);
            printf("Patient name = ");
            puts(v[s].patient_name);
            printf("Disease = ");
            puts(v[s].disease);
            printf("Phone number = ");
            puts(v[s].phone);
            printf("Room number = %d\nAge = %d", v[s].room_no, v[s].age);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if (h == 2)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter Patient's Name=");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, v[g].patient_name) == 0)
            {
                printf("\n");
                printf("Serial number = %d\n", g);
                printf("Patient name = ");
                puts(v[g].patient_name);
                printf("Disease = ");
                puts(v[g].disease);
                printf("Phone number = ");
                puts(v[g].phone);
                printf("Room number = %d\nAge = %d", v[g].room_no, v[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 3)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter Disease = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, v[g].disease) == 0)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Patient name = ");
                puts(v[g].patient_name);
                printf("Disease = ");
                puts(v[g].disease);
                printf("Phone number = ");
                puts(v[g].phone);
                printf("Room_no = %d\nAge = %d", v[g].room_no, v[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 4)
    {
        int f = 1;
        printf("Enter room_no = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == v[g].room_no)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Patient Name = ");
                puts(v[g].patient_name);
                printf("Disease = ");
                puts(v[g].disease);
                printf("Phone number = ");
                puts(v[g].phone);
                printf("Room number = %d\nAge = %d", v[g].room_no, v[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else if (h == 5)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter Phone number = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, v[g].phone) == 0)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Patient name = ");
                puts(v[g].patient_name);
                printf("Disease = ");
                puts(v[g].disease);
                printf("Phone number = ");
                puts(v[g].phone);
                printf("Room number = %d\nAge = %d", v[g].room_no, v[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found");
    }
    else if (h == 6)
    {
        int f = 1;
        printf("Enter Age = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == v[g].age)
            {
                printf("\n");
                printf("Serial number = %d\n", g);
                printf("Patient name = ");
                puts(v[g].patient_name);
                printf("Disease = ");
                puts(v[g].disease);
                printf("Phone number = ");
                puts(v[g].phone);
                printf("Room number = %d\nAge = %d", v[g].room_no, v[g].age);
                printf("\n\n");
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else
        printf("\n\nInvalid input\n\n");
}
void delete_patient()
{
    int f, h;
    printf("Enter the serial number of the patient that you want to delete = ");
    scanf("%d", &f);
    if (f < num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Patient name\n3.Remove Disease\n4.Remove Age\n5.Remove Room number\n6.Remove Phone number\nOption = ");
        scanf("%d", &h);
        if (h == 1)
        {
            while (f < num)
            {
                strcpy(v[f].patient_name, v[f + 1].patient_name);
                strcpy(v[f].disease, v[f + 1].disease);
                strcpy(v[f].phone, v[f + 1].phone);
                v[f].age = v[f + 1].age;
                v[f].room_no = v[f + 1].room_no;
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(v[f].patient_name, "Cleared");
        }
        else if (h == 3)
        {
            strcpy(v[f].disease, "Cleared");
        }
        else if (h == 4)
        {
            v[f].age = 0;
        }
        else if (h == 5)
        {
            v[f].room_no = 0;
        }
        else if (h == 6)
        {
            strcpy(v[f].phone, "Cleared");
        }
    }
    else
        printf("\n\nInvalid Serial Number\n");
}
void patient_read()
{
    FILE *fp = fopen("patient.txt", "r");
    if (fp == NULL)
    {

        fp = fopen("patient.txt", "w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }

    num = fread(v, sizeof(struct p), 100, fp);
    fclose(fp);
}
void patient_write()
{
    FILE *fp = fopen("patient.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(v, sizeof(struct p), num, fp);

    fclose(fp);
}

void add_doctor()
{
    printf("\n\n");
    printf("Already data inputed on the database = %d\n\n", num);
    printf("How many entry do you want to add = \n");
    scanf("%d", &n);
    sum = n + num;

    for (i = num, j = 0; i < sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter doctor's name = ");
        gets(w[i].doctor_name);
        fflush(stdin);
        printf("Enter address = ");
        gets(w[i].address);
        fflush(stdin);
        printf("Enter the age = ");
        scanf("%d", &w[i].age);
        fflush(stdin);
        printf("Enter doctor id = ");
        scanf("%d", &w[i].doctor_id);
        fflush(stdin);
        printf("Enter phone number = ");
        gets(w[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}
void view_doctor()
{
    for (i = 0; i < num; i++)
    {
        printf("\n");
        printf("Serial number = %d\n", i);
        printf("Doctor's name = ");
        puts(w[i].doctor_name);
        printf("Address = ");
        puts(w[i].address);
        printf("Phone number = ");
        puts(w[i].phone);
        printf("Doctor's id = %d\nAge = %d", w[i].doctor_id, w[i].age);
        printf("\n\n");
    }
}
void edit_doctor()
{
    int q, p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Doctor's name\n2.Address\n3.Age\n4.Doctor id\n5.Phone number\n");
    printf("Option=");
    scanf("%d", &q);
    if (q <= 5)
    {
        printf("Enter the serial no of that doctor = (0 - %d)=", num - 1);
        scanf("%d", &p);
        if (p < num)
        {
            if (q == 1)
            {
                fflush(stdin);
                printf("Enter the new Doctor name = ");
                gets(w[p].doctor_name);
            }
            else if (q == 2)
            {
                fflush(stdin);
                printf("Enter the new Address = ");
                gets(w[p].address);
            }
            else if (q == 3)
            {
                fflush(stdin);
                printf("Enter the new Age = ");
                scanf("%d", &w[p].age);
            }

            else if (q == 4)
            {
                fflush(stdin);
                printf("Enter the new Doctor id = ");
                scanf("%d", &w[p].doctor_id);
            }

            else if (q == 5)
            {
                fflush(stdin);
                printf("Enter the new Phone number =");
                gets(w[p].phone);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid Option\nTry Again!!\n\n");
    }
}
void search_doctor()
{
    int s, h, f;
    char u[100];
    printf("By what do you want to search_doctor ?\n");
    printf("1.Serial number\n2.Doctor name\n3.Address\n4.Doctor id.\n5.Phone number\n6.Age\n\nOption = ");
    scanf("%d", &h);
    if (h == 1)
    {
        printf("Enter serial number of the doctor = ");
        scanf("%d", &s);
        if (s < num)
        {
            printf("\n");
            printf("Serial number = %d\n", s);
            printf("Doctor name = ");
            puts(w[s].doctor_name);
            printf("Address = ");
            puts(w[s].address);
            printf("Phone number = ");
            puts(w[s].phone);
            printf("Doctor id = %d\nAge = %d", w[s].doctor_id, w[s].age);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if (h == 2)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter  Doctor's name = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, w[g].doctor_name) == 0)
            {
                printf("\n");
                printf("Serial number=%d\n", g);
                printf("Doctor name = ");
                puts(w[g].doctor_name);
                printf("Address = ");
                puts(w[g].address);
                printf("Phone number = ");
                puts(w[g].phone);
                printf("Doctor id = %d\nAge = %d", w[g].doctor_id, w[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 3)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter Address = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, w[g].address) == 0)
            {
                printf("\n");
                printf("Serial number = %d\n", g);
                printf("Doctor name = ");
                puts(w[g].doctor_name);
                printf("Address = ");
                puts(w[g].address);
                printf("Phone number = ");
                puts(w[g].phone);
                printf("Doctor id = %d\nAge = %d", w[g].doctor_id, w[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 4)
    {
        int f = 1;
        printf("Enter Doctor's id = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == w[g].doctor_id)
            {
                printf("\n");
                printf("Serial number = %d\n", g);
                printf("Doctor name = ");
                puts(w[g].doctor_name);
                printf("Address = ");
                puts(w[g].address);
                printf("Phone number = ");
                puts(w[g].phone);
                printf("Doctor id = %d\nAge = %d", w[g].doctor_id, w[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else if (h == 5)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter phone number = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, w[g].phone) == 0)
            {
                printf("\n");
                printf("Serial number = %d\n", g);
                printf("Doctor name = ");
                puts(w[g].doctor_name);
                printf("Address = ");
                puts(w[g].address);
                printf("Phone number = ");
                puts(w[g].phone);
                printf("Doctor id = %d\nAge = %d", w[g].doctor_id, w[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found");
    }
    else if (h == 6)
    {
        int f = 1;
        printf("Enter Age = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == w[g].age)
            {
                printf("\n");
                printf("Serial mumber = %d\n", g);
                printf("Doctor name = ");
                puts(w[g].doctor_name);
                printf("Address = ");
                puts(w[g].address);
                printf("Phone number = ");
                puts(w[g].phone);
                printf("Doctor id = %d\nAge = %d", w[g].doctor_id, w[g].age);
                printf("\n\n");
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else
        printf("\n\nInvalid input\n\n");
}
void delete_doctor()
{
    int f, h;
    printf("Enter the serial number of the doctor that you want to delete = ");
    scanf("%d", &f);
    if (f < num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Doctor's Name\n3.Remove Address\n4.Remove Age\n5.Remove Doctor Id.\n6.Remove Phone Number\nOption = ");
        scanf("%d", &h);
        if (h == 1)
        {
            while (f < num)
            {
                strcpy(w[f].doctor_name, w[f + 1].doctor_name);
                strcpy(w[f].address, w[f + 1].address);
                strcpy(w[f].phone, w[f + 1].phone);
                w[f].age = w[f + 1].age;
                w[f].doctor_id = w[f + 1].doctor_id;
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(w[f].doctor_name, "Cleared");
        }
        else if (h == 3)
        {
            strcpy(w[f].address, "Cleared");
        }
        else if (h == 4)
        {
            w[f].age = 0;
        }
        else if (h == 5)
        {
            w[f].doctor_id = 0;
        }
        else if (h == 6)
        {
            strcpy(w[f].phone, "Cleared");
        }
    }
    else
        printf("\n\nInvalid Serial Number\n");
}
void read_doctor()
{
    FILE *fp = fopen("doctor.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("doctor.txt", "w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }

    num = fread(w, sizeof(struct d), 100, fp);
    fclose(fp);
}
void write_doctor()
{
    FILE *fp = fopen("doctor.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(w, sizeof(struct d), num, fp);

    fclose(fp);
}

void add_staff()
{
    printf("\n\n");
    printf("Already data inputed on the database = %d\n\n", num);
    printf("How many entry do you want to add = \n");
    scanf("%d", &n);
    sum = n + num;

    for (i = num, j = 0; i < sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter Staff's name = ");
        gets(x[i].staff_name);
        fflush(stdin);
        printf("Enter Job = ");
        gets(x[i].job);
        fflush(stdin);
        printf("Enter the Age = ");
        scanf("%d", &x[i].age);
        fflush(stdin);
        printf("Enter Job id = ");
        scanf("%d", &x[i].job_id);
        fflush(stdin);
        printf("Enter Phone Number = ");
        gets(x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}
void view_staff()
{
    for (i = 0; i < num; i++)
    {
        printf("\n");
        printf("Serial Number = %d\n", i);
        printf("Staff Name = ");
        puts(x[i].staff_name);
        printf("Job = ");
        puts(x[i].job);
        printf("Phone Number = ");
        puts(x[i].phone);
        printf("Job id = %d\nAge=%d", x[i].job_id, x[i].age);
        printf("\n\n");
    }
}
void edit_staff()
{
    int q, p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Staff name\n2.Job\n3.Age\n4.Job id\n5.Phone number\n");
    printf("Option = ");
    scanf("%d", &q);
    if (q <= 5)
    {
        printf("Enter the serial no of that staff = (0 - %d)=", num - 1);
        scanf("%d", &p);
        if (p < num)
        {
            if (q == 1)
            {
                fflush(stdin);
                printf("Enter the new Staff Name = ");
                gets(x[p].staff_name);
            }
            else if (q == 2)
            {
                fflush(stdin);
                printf("Enter the new Job = ");
                gets(x[p].job);
            }
            else if (q == 3)
            {
                fflush(stdin);
                printf("Enter the new Age = ");
                scanf("%d", &x[p].age);
            }

            else if (q == 4)
            {
                fflush(stdin);
                printf("Enter the new Job id = ");
                scanf("%d", &x[p].job_id);
            }

            else if (q == 5)
            {
                fflush(stdin);
                printf("Enter the new Phone number = ");
                gets(x[p].phone);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}
void search_staff()
{
    int s, h, f;
    char u[100];
    printf("By what do you want to search staff ?\n");
    printf("1.Serial number \n2.Staff name\n3.Job\n4.Job id.\n5.Phone number\n6.Age\n\nOption = ");
    scanf("%d", &h);
    if (h == 1)
    {
        printf("Enter Serial number of the staff = ");
        scanf("%d", &s);
        if (s < num)
        {
            printf("\n");
            printf("Serial Number = %d\n", s);
            printf("Staff name = ");
            puts(x[s].staff_name);
            printf("Job = ");
            puts(x[s].job);
            printf("Phone number = ");
            puts(x[s].phone);
            printf("Job id = %d\nAge = %d", x[s].job_id, x[s].age);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if (h == 2)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter staff name =");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].staff_name) == 0)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Staff Name = ");
                puts(x[g].staff_name);
                printf("Job = ");
                puts(x[g].job);
                printf("Phone number = ");
                puts(x[g].phone);
                printf("Job id = %d\nAge = %d", x[g].job_id, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 3)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter job = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].job) == 0)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Staff name = ");
                puts(x[g].staff_name);
                printf("Job = ");
                puts(x[g].job);
                printf("Phone number = ");
                puts(x[g].phone);
                printf("Job id = %d\nAge = %d", x[g].job_id, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 4)
    {
        int f = 1;
        printf("Enter Job id = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].job_id)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Staff name = ");
                puts(x[g].staff_name);
                printf("Job = ");
                puts(x[g].job);
                printf("Phone number = ");
                puts(x[g].phone);
                printf("Job id = %d\nAge = %d", x[g].job_id, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else if (h == 5)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter Phone number = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].phone) == 0)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Staff name = ");
                puts(x[g].staff_name);
                printf("Job = ");
                puts(x[g].job);
                printf("Phone number = ");
                puts(x[g].phone);
                printf("Job id = %d\nAge = %d", x[g].job_id, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found");
    }
    else if (h == 6)
    {
        int f = 1;
        printf("Enter Age = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].age)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Staff name = ");
                puts(x[g].staff_name);
                printf("Job = ");
                puts(x[g].job);
                printf("Phone number =");
                puts(x[g].phone);
                printf("Job id = %d\nAge = %d", x[g].job_id, x[g].age);
                printf("\n\n");
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else
        printf("\n\nInvalid input\n\n");
}
void delete_staff()
{
    int f, h;
    printf("Enter the serial number of the staff that you want to delete=");
    scanf("%d", &f);
    if (f < num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record \n2.Remove Staff Name\n3.Remove Job\n4.Remove Age\n5.Remove Job id\n6.Remove Phone Number\nOption = ");
        scanf("%d", &h);
        if (h == 1)
        {
            while (f < num)
            {
                strcpy(x[f].staff_name, x[f + 1].staff_name);
                strcpy(x[f].job, x[f + 1].job);
                strcpy(x[f].phone, x[f + 1].phone);
                x[f].age = x[f + 1].age;
                x[f].job_id = x[f + 1].job_id;
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(x[f].staff_name, "Cleared");
        }
        else if (h == 3)
        {
            strcpy(x[f].job, "Cleared");
        }
        else if (h == 4)
        {
            x[f].age = 0;
        }
        else if (h == 5)
        {
            x[f].job_id = 0;
        }
        else if (h == 6)
        {
            strcpy(x[f].phone, "Cleared");
        }
    }
    else
        printf("\n\nInvalid serial number\n");
}
void read_staff()
{
    FILE *fp = fopen("staff.txt", "r");
    if (fp == NULL)
    {

        fp = fopen("staff.txt", "w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }

    num = fread(x, sizeof(struct s), 100, fp);
    fclose(fp);
}
void write_staff()
{
    FILE *fp = fopen("staff.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct s), num, fp);

    fclose(fp);
}

void add_medicine()
{
    printf("\n\n");
    printf("Already data inputed on the database = %d\n\n", num);
    printf("How many entry do you want to add = \n");
    scanf("%d", &n);
    sum = n + num;

    for (i = num, j = 0; i < sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("Enter Medicine's Name = ");
        gets(y[i].medicine_name);
        fflush(stdin);
        printf("Enter Availability = ");
        gets(y[i].availability);
        fflush(stdin);
        printf("Enter The Quantity = ");
        scanf("%d", &y[i].quantity);
        fflush(stdin);
        printf("Enter Product id = ");
        scanf("%d", &y[i].product_id);
        fflush(stdin);
        printf("Enter Price = ");
        scanf("%d", &y[i].price);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}
void view_medicine()
{
    for (i = 0; i < num; i++)
    {
        printf("\n");
        printf("Serial number = %d\n", i);
        printf("Name = ");
        puts(y[i].medicine_name);
        printf("Availability = ");
        puts(y[i].availability);
        printf("Product id = %d\nPrice = %d\nQuantity = %d", y[i].product_id, y[i].price, y[i].quantity);
        printf("\n\n");
    }
}
void edit_medicine()
{
    int q, p;
    fflush(stdin);
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Availability\n3.Quantity\n4.Product id\n5.Price\n");
    printf("Option=");
    scanf("%d", &q);
    if (q <= 5)
    {
        printf("Enter the serial no of that medicine = (0 - %d)=", num - 1);
        scanf("%d", &p);
        if (p < num)
        {
            if (q == 1)
            {
                fflush(stdin);
                printf("Enter the new medicine name = ");
                gets(y[p].medicine_name);
            }
            else if (q == 2)
            {
                fflush(stdin);
                printf("Enter the new availability = ");
                gets(y[p].availability);
            }
            else if (q == 3)
            {
                fflush(stdin);
                printf("Enter the new quantity = ");
                scanf("%d", &y[p].quantity);
            }

            else if (q == 4)
            {
                fflush(stdin);
                printf("Enter the new product id = ");
                scanf("%d", &y[p].product_id);
            }

            else if (q == 5)
            {
                fflush(stdin);
                printf("Enter the new price = ");
                scanf("%d", &y[p].price);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid Option\nTry Again!!\n\n");
    }
}
void search_medicine()
{
    int s, h, f;
    char u[100];
    printf("By what do you want to search medicine ?\n");
    printf("1.Serial no.\n2.Name\n3.Availability\n4.Product id.\n5.Price\n6.Quantity\n\nOption = ");
    scanf("%d", &h);
    if (h == 1)
    {
        printf("Enter Serial number of the medicine = ");
        scanf("%d", &s);
        if (s < num)
        {
            printf("\n");
            printf("Serial number = %d\n", s);
            printf("Name = ");
            puts(y[s].medicine_name);
            printf("Availability = ");
            puts(y[s].availability);
            printf("Product id = %d\nPrice = %d\nQuantity = %d", y[s].product_id, y[s].price, y[s].quantity);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if (h == 2)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter Medicine's Name = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, y[g].medicine_name) == 0)
            {
                printf("\n");
                printf("Serial number = %d\n", g);
                printf("Name = ");
                puts(y[g].medicine_name);
                printf("Availability = ");
                puts(y[g].availability);
                printf("Product_id = %d\nPrice = %d\nQuantity = %d", y[g].product_id, y[g].price, y[g].quantity);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 3)
    {
        int f = 1;
        fflush(stdin);
        printf("Enter Availability = ");
        gets(u);
        fflush(stdin);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, y[g].availability) == 0)
            {
                printf("\n");
                printf("Serial number = %d\n", g);
                printf("Name = ");
                puts(y[g].medicine_name);
                printf("Availability = ");
                puts(y[g].availability);
                printf("Product id = %d\nPrice = %d\nQuantity = %d", y[g].product_id, y[g].price, y[g].quantity);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 4)
    {
        int f = 1;
        printf("Enter Product id = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == y[g].product_id)
            {
                printf("\n");
                printf("Serial number = %d\n", g);
                printf("Name = ");
                puts(y[g].medicine_name);
                printf("Availability = ");
                puts(y[g].availability);
                printf("Product_id = %d\nPrice = %d\nQuantity = %d", y[g].product_id, y[g].price, y[g].quantity);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else if (h == 5)
    {
        int f = 1;
        printf("Enter Price = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == y[g].price)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Name = ");
                puts(y[g].medicine_name);
                printf("Availability = ");
                puts(y[g].availability);
                printf("Product id = %d\nPrice = %d\nQuantity = %d", y[g].product_id, y[g].price, y[g].quantity);
                printf("\n\n");
            }
        }
        if (f == 1)
            printf("Not Found");
    }
    else if (h == 6)
    {
        int f = 1;
        printf("Enter Quantity = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == y[g].quantity)
            {
                printf("\n");
                printf("Serial number = %d\n", g);
                printf("Name = ");
                puts(y[g].medicine_name);
                printf("Availability = ");
                puts(y[g].availability);
                printf("Product id = %d\nPrice = %d\nQuantity = %d", y[g].product_id, y[g].price, y[g].quantity);
                printf("\n\n");
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else
        printf("\n\nInvalid input\n\n");
}
void delete_medicine()
{
    int f, h;
    printf("Enter the serial number of the medicine that you want to delete=");
    scanf("%d", &f);
    if (f < num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Availability\n4.Remove Quantity\n5.Remove Product id\n6.Remove Price\nOption = ");
        scanf("%d", &h);
        if (h == 1)
        {
            while (f < num)
            {
                strcpy(y[f].medicine_name, y[f + 1].medicine_name);
                strcpy(y[f].availability, y[f + 1].availability);
                y[f].quantity = y[f + 1].quantity;
                y[f].product_id = y[f + 1].product_id;
                y[f].price = y[f + 1].price;
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(y[f].medicine_name, "       ");
        }
        else if (h == 3)
        {
            strcpy(y[f].availability, "         ");
        }
        else if (h == 4)
        {
            y[f].quantity = 0;
        }
        else if (h == 5)
        {
            y[f].product_id = NULL;
        }
        else if (h == 6)
        {
            y[f].price = NULL;
        }
    }
    else
        printf("\n\nInvalid Serial Number\n");
}
void read_medicine()
{
    FILE *fp = fopen("medicine.txt", "r");
    if (fp == NULL)
    {

        fp = fopen("medicine.txt", "w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }

    num = fread(y, sizeof(struct m), 100, fp);
    fclose(fp);
}
void medicine_write()
{
    FILE *fp = fopen("medicine.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(y, sizeof(struct m), num, fp);

    fclose(fp);
}
