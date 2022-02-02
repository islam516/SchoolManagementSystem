#ifndef SYSTEM_FUNCTIONS_H_INCLUDED
#define SYSTEM_FUNCTIONS_H_INCLUDED


/* Student Data */
typedef enum STUDENTSUBJECTS {ComputerScience = 0 , Physics = 1, Mathematics = 2}StudentSubjects;
#define SubjectsSize sizeof(StudentSubjects)

typedef struct Date
{
    int Day;
    int Month;
    int Year;
}DateOfBirth;

typedef struct S
{
    DateOfBirth BirthDate;
    int Subjects[SubjectsSize]; //Computer Science - Physics - Math
    int PhoneNumber;
    int ID;
    char Address[100];
    char Name[50];
}Student;


/* System Features */
void Main_Menu();       //this function displays the welcome screen and targeted activates.
void New_Student();     // this function creates a new student account. it asks about details of the student such as name, date of birth, ID, address and phone number.
void Delete_Student();  //This function is for deleting a customer account
void Student_List();    //This function, you can view the Students information such as name, date of birth, ID, Address and phone number in table from (alphabetically ascending).
void Student_Edit();    //This function has been used for updating a particular student account.
void Rank_Student();    //This function can sort all students according to computer science score.
void Student_Score();   //this function has been used for updating score of all students.

void StartProgram(void);
int Get_Position_Using_ID();
void PrintStudentList();//This Function Print the whole student list
void PrintSpecificStudentInfo();//Print only 1 student info
void PrintStudentInfo();
int GetPosition();
void SortAccordingToName();
void SortAccordingToScore();
void SortAccordingToID();
#endif // SYSTEM_FUNCTIONS_H_INCLUDED
