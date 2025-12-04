#include <stdio.h>
#include <string.h>
#include <strings.h> //for string case camp

typedef struct
{
    int day;
    int month;
    int year;
} date_joined;

typedef struct
{

    float IT;
    float HR;
    float Finance;
    float Marketing;
    float Operations;

} department_performance;

typedef struct
{

    int ID;
    char name[30];
    char department[20];
    char designation[20];
    char phone[12];
    char email[50];
    int salary;
    date_joined date;
    int years_experienced;
    int promotion;

} employee_info;

void Search_Employee(employee_info employees[], int size, int years_experienced, char designation[], char department[])
{
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (employees[i].years_experienced == years_experienced)
        {
            printf("Employee Found! \n");
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Designation: %s\n", employees[i].designation);
            printf("Phone: %s\n", employees[i].phone);
            printf("Email: %s\n", employees[i].email);
            printf("Salary: %d\n", employees[i].salary);
            printf("Date Joined: %02d/%02d/%04d\n", employees[i].date.day, employees[i].date.month, employees[i].date.year);
            printf("Years of Experience: %d\n", employees[i].years_experienced);
            if (employees[i].promotion)
            {
                printf("Eligible for Promotion: Yes\n");
            }
            else
            {
                printf("Eligible for Promotion: No\n");
            }
            found = 1;
        }

        else if (strcmp(employees[i].designation, designation) == 0)
        {
            printf("Employee Found! \n");
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Designation: %s\n", employees[i].designation);
            printf("Phone: %s\n", employees[i].phone);
            printf("Email: %s\n", employees[i].email);
            printf("Salary: %d\n", employees[i].salary);
            printf("Date Joined: %02d/%02d/%04d\n", employees[i].date.day, employees[i].date.month, employees[i].date.year);
            printf("Years of Experience: %d\n", employees[i].years_experienced);
            if (employees[i].promotion)
            {
                printf("Eligible for Promotion: Yes\n");
            }
            else
            {
                printf("Eligible for Promotion: No\n");
            }
            found = 1;
        }

        else if (strcmp(employees[i].department, department) == 0)
        {
            printf("Employee Found! \n");
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Designation: %s\n", employees[i].designation);
            printf("Phone: %s\n", employees[i].phone);
            printf("Email: %s\n", employees[i].email);
            printf("Salary: %d\n", employees[i].salary);
            printf("Date Joined: %02d/%02d/%04d\n", employees[i].date.day, employees[i].date.month, employees[i].date.year);
            printf("Years of Experience: %d\n", employees[i].years_experienced);
            if (employees[i].promotion)
            {
                printf("Eligible for Promotion: Yes\n");
            }
            else
            {
                printf("Eligible for Promotion: No\n");
            }
            found = 1;
        }
    }
    if (!found)
    {
        printf("Employee with the follwing descrption not found.\n");
    }
};

int main()
{

    int size;
    int choice;
    int current_year;
    int HR_count = 0, Finance_count = 0, Marketing_count = 0, Operations_count = 0, IT_count = 0;
    char designation[20] = "";
    char department[20] = "";
    int total_salary = 0;
    int years_experienced = -1;

    department_performance performance = {0, 0, 0, 0, 0};

    printf("Enter the current year \n");
    scanf("%d", &current_year);

    printf("How many employees are there? \n");
    scanf("%d", &size);

    employee_info employees[size];

    for (int i = 0; i < size; i++)
    {

        printf("Enter the ID of Employee #%d \n", i + 1);
        scanf("%d", &employees[i].ID);

        printf("Enter the Name of Employee #%d \n", i + 1);
        scanf(" %[^\n]", employees[i].name);

        printf("Enter the department category of Employee #%d \n --> IT, HR, Finance, Marketing or Operations \n", i + 1);
        scanf("%s", employees[i].department);

        printf("Enter the designation of Employee #%d \n -->Intern, Junior, Senior, Manager or Director \n", i + 1);
        scanf("%s", employees[i].designation);

        printf("Enter the 12 digit phone number of Employe #%d \n", i + 1);
        scanf("%s", employees[i].phone);

        printf("Enter their Email address of Employee #%d \n", i + 1);
        scanf("%s", employees[i].email);

        printf("Laslty Enter the Employee's salary #%d \n", i + 1);
        scanf("%d", &employees[i].salary);

        printf("Enter the date of joining for Employe #%d \n Format: DD / MM / YYYY \n", i + 1);
        scanf("%d %d %d", &employees[i].date.day, &employees[i].date.month, &employees[i].date.year);

        // years of experience
        employees[i].years_experienced = current_year - employees[i].date.year;

        // check for employees salary or performance
        if (strcasecmp(employees[i].department, "HR") == 0)
        {
            performance.HR += employees[i].salary;
            HR_count++;
        }

        else if (strcasecmp(employees[i].department, "IT") == 0)
        {
            performance.IT += employees[i].salary;
            IT_count++;
        }

        else if (strcasecmp(employees[i].department, "Finance") == 0)
        {
            performance.Finance += employees[i].salary;
            Finance_count++;
        }

        else if (strcasecmp(employees[i].department, "Marketing") == 0)
        {
            performance.Marketing += employees[i].salary;
            Marketing_count++;
        }

        else if (strcasecmp(employees[i].department, "Operations") == 0)
        {
            performance.Operations += employees[i].salary;
            Operations_count++;
        }

        if (employees[i].years_experienced > 3)
        {
            employees[i].promotion = 1;
        }
        else
        {
            employees[i].promotion = 0;
        }
    }



    if (IT_count > 0)
        printf("IT Dept  - Total: %.2f | Average: %.2f\n", performance.IT, performance.IT / IT_count);
    if (HR_count > 0)
        printf("HR Dept  - Total: %.2f | Average: %.2f\n", performance.HR, performance.HR / HR_count);
    if (Finance_count > 0)
        printf("Finance Dept  - Total: %.2f | Average: %.2f\n", performance.Finance, performance.Finance / Finance_count);
    if (Marketing_count > 0)
        printf("Marketing  - Total: %.2f | Average: %.2f\n", performance.Marketing, performance.Marketing / Marketing_count);
    if (Operations_count > 0)
        printf("Operations  - Total: %.2f | Average: %.2f\n", performance.Operations, performance.Operations / Operations_count);

    int found_promo = 0;
    for (int i = 0; i < size; i++)
    {
        if (employees[i].promotion == 1)
        {
            printf("[ID: %d] %s - %s (%d years experience)\n",
                   employees[i].ID,
                   employees[i].name,
                   employees[i].department,
                   employees[i].years_experienced);
            found_promo = 1;
        }
    }

    if (found_promo == 0)
    {
        printf("No employees currently eligible for promotion.\n");
    }


    printf("===================================================\n");
    printf("           DEPARTMENT SALARY STATISTICS            \n");
    printf("===================================================\n");
    if (IT_count > 0)
        printf("IT Dept      - Total: %.2f | Average: %.2f\n", performance.IT, performance.IT / IT_count);
    if (HR_count > 0)
        printf("HR Dept      - Total: %.2f | Average: %.2f\n", performance.HR, performance.HR / HR_count);
    if (Finance_count > 0)
        printf("Finance Dept - Total: %.2f | Average: %.2f\n", performance.Finance, performance.Finance / Finance_count);
    if (Marketing_count > 0)
        printf("Marketing    - Total: %.2f | Average: %.2f\n", performance.Marketing, performance.Marketing / Marketing_count);
    if (Operations_count > 0)
        printf("Operations   - Total: %.2f | Average: %.2f\n", performance.Operations, performance.Operations / Operations_count);

    // PRINT PROMOTIONS 
    printf("===================================================\n");
    printf("        EMPLOYEES ELIGIBLE FOR PROMOTION          \n");
    printf("       (More than 3 years of experience)           \n");
    printf("===================================================\n");
    found_promo = 0;
    for (int i = 0; i < size; i++)
    {
        if (employees[i].promotion == 1)
        {
            printf("[ID: %d] %s - %s (%d years experience)\n",
                   employees[i].ID,
                   employees[i].name,
                   employees[i].department,
                   employees[i].years_experienced);
            found_promo = 1;
        }
    }

    if (found_promo == 0)
    {
        printf("No employees currently eligible for promotion.\n");
    }

    // --- SEARCH MENU ---
    printf("===================================================\n");
    printf("                   SEARCH MENU                     \n");
     printf("===================================================\n");
    printf("1. Search by Years of Experience\n");
    printf("2. Search by Department\n");
    printf("3. Search by Designation\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);


    // search employee
    printf("Enter Search Criteria: \n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter Years of Experience to Search For: \n");
        scanf("%d", &years_experienced);
        Search_Employee(employees, size, years_experienced, designation, department);
    }

    else if (choice == 2)
    {
        printf("Enter Employee Departments to search for \n");
        scanf("%s", department);
        Search_Employee(employees, size, years_experienced, designation, department);
    }

    else if (choice == 3)
    {
        printf("Enter Employee Designation to search for \n");
        scanf("%s", designation);
        Search_Employee(employees, size, years_experienced, designation, department);
    }

    else
    {
        printf("Invalid Choice \n");
    }

}