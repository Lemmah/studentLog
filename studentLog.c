// The Student Log
// Done by James Lemayian
// This program simply logs students to get a class attendance list.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char studentName[32];
    char admNumber[32];
    int time;
}SCTStudent;

int main(void){
    // The backUp file will just be a copy of the attendance list.
    FILE *attendanceList, *backUp;
    // Append mode creates a new file if it does not exist.
    attendanceList = fopen("attendanceList.txt", "a");
    printf("Please Student details, enter BACKUP in Student Name to backUp the file.\n\n");
    printf("Student Name: ");
    scanf(" %s", SCTStudent.studentName);
    if(strcmp(SCTStudent.studentName, "BACKUP")){
        printf("Admission Number: ");
        scanf(" %s", SCTStudent.admNumber);
        printf("Time (24hr mode): ");
        scanf("%d", &SCTStudent.time);
        // Appending data to file
        fprintf(attendanceList, "%s %s %d\n",SCTStudent.studentName,SCTStudent.admNumber,SCTStudent.time);
        printf("Thanks %s, you just arrived for this class at %dhrs.", SCTStudent.studentName,SCTStudent.time);
    }else{
        // Now, copying attendanceList to backUp
        fclose(attendanceList);
        attendanceList = fopen("attendanceList.txt", "r");
        backUp = fopen("backUp.txt", "w");
        printf("Backing up your attendanceList...\n");
        do{
            printf("... \n");
            // Retriving from attendanceList
            fscanf(attendanceList, "%s %s %d\n", SCTStudent.studentName, SCTStudent.admNumber, &SCTStudent.time);
            // Appending to backUp
            fprintf(backUp, "%s %s %d\n",SCTStudent.studentName,SCTStudent.admNumber,SCTStudent.time);

        }while( !feof(attendanceList) );
        printf("Done: copy of attendanceList now in backUp.txt\n");
        fclose(backUp);
    }

    fclose(attendanceList);

    return 0;
} 
