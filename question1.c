#include <stdio.h>
#include <string.h>

struct student_record
{
    char name[50];
    int roll;
    int marks[3];
    float percentage;
    char grade[3];
};


void check_grade(char choice[], struct student_record students[], int size){
           int found = 0;
           for(int i = 0; i < size; i++){
               if(strcmp(students[i].grade, choice) == 0){
                   printf("Name: %s\n", students[i].name);
                   printf("Roll Number: %d\n", students[i].roll);
                   printf("Percentage: %.2f\n", students[i].percentage);
                   printf("Grade: %s\n\n", students[i].grade);
               }
            }
            if(!found){
                printf("\n No student found with grade %s\n", choice);
            }
}


int main()
{
    int size;
    float total_percent = 0;
    int std_total = 0;
    float average;

    printf("How Many Students? \n");
    scanf("%d", &size);

    struct student_record students[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d Student's Name \n", i + 1);
        scanf(" %[^\n]", students[i].name);

        printf("Enter the %d Student's Roll Number \n", i + 1);
        scanf("%d", &students[i].roll);
        while(students[i].roll <= 0){
            printf("Invalid Roll Number Entered \n");
            scanf("%d", &students[i].roll);
        }
     
        std_total = 0;
        for (int j = 0; j < 3; j++)
        {
            printf("Enter the %d Student's %d Marks \n", i + 1, j + 1);
            scanf("%d", &students[i].marks[j]);

            while (students[i].marks[j] < 0 || students[i].marks[j] > 100)
            {
                printf("Invalid Marks Entered \n");
                scanf("%d", &students[i].marks[j]);
            }

            std_total += students[i].marks[j];
        }

        students[i].percentage = ((float)std_total / 300) * 100;
        total_percent += students[i].percentage;
      

        if (students[i].percentage < 50)
        {
            strcpy(students[i].grade, "F");
        }

        if (students[i].percentage >= 50 && students[i].percentage < 60)
        {
            strcpy(students[i].grade, "C");
        }

        if (students[i].percentage >= 60 && students[i].percentage < 70)
        {
            strcpy(students[i].grade, "B");
        }

        if (students[i].percentage >= 70 && students[i].percentage < 80)
        {
            strcpy(students[i].grade, "B+");
        }

        if (students[i].percentage >= 80 && students[i].percentage < 90)
        {
            strcpy(students[i].grade, "A");
        }

        if (students[i].percentage >= 90 && students[i].percentage <= 100)
        {
            strcpy(students[i].grade, "A+");
        }
    }
  printf("\n--- Student Records ---\n");
    for (int i = 0; i < size; i++)
    {
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].roll);
        printf("Percentage: %.2f\n", students[i].percentage);
        printf("Grade: %s\n", students[i].grade);
        printf("\n");
    }

    average = total_percent / size;
    printf("Class Average Percentage: %.2f\n", average);

    char choice[3];
    printf("Enter Grade to Search For (e.g., A+, A , B , B+, C, F): \n");
    scanf(" %2s", choice);

    check_grade(choice, students, size);

    printf("students above average \n");
    for(int i = 0; i < size; i++){
        if(students[i].percentage > average){
            printf("Name: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].roll);
            printf("Percentage: %.2f\n", students[i].percentage);
            printf("Grade: %s\n", students[i].grade);
            printf("\n");
        }
    }

    printf("students below average \n");
    for(int i = 0; i < size; i++){
        if(students[i].percentage < average){
            printf("Name: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].roll);
            printf("Percentage: %.2f\n", students[i].percentage);
            printf("Grade: %s\n", students[i].grade);
            printf("\n");
        }
    }

    return 0;



}