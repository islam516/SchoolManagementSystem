#include <Stdio.h>
#include <stdlib.h>
#include <string.h>
#include "System_Functions.h"
#include "DublyLinkedList.h"



/* System Features */
void StartProgram(void)
{   //This Program is to made to be called in the main menu and show the main menu then ask for the process that the user want to make and call it's function
    /* Function Creations */
    LinkedList School_Students_List;    //Create School List
    int Answer;                         //int variable to take the input of the user of the process that he wants to make
    char Onflag = 1;
    /* Function Code */
    Main_Menu(&School_Students_List);   //send the School List to Make it a linked list
//    {   //Adding
//        LLEntry Ahmed = {{30,10,1996},{80,0,0},1002102343,221001,"Zayed","Ahmed Adel"};
//        LLEntry Islam = {{28,2,1998},{90,0,0},1002102349,221002,"Mohandseen","Islam Adel"};
//        LLEntry Kareem = {{1,1,2001},{60,0,0},1002102342,221003,"Downtown","Kareem Adel"};
//        DublyAddToTheLastLLNode(Ahmed,&School_Students_List);
//        DublyAddToTheLastLLNode(Kareem,&School_Students_List);
//        DublyAddToTheLastLLNode(Islam,&School_Students_List);
//        School_Students_List.LastID = 221003;
//    }
    while(Onflag)
    {
        /* print the main menu screen */
        printf("\n\n");
        printf("\t\t\t\t      ******************************\n");
        printf("\t\t\t\t      |          Main Menu         |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |1. Add Student              |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |2. Modify Student Info      |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |3. Show All Students        |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |4. Individual View          |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |5. Remove Student           |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |6. Score Students           |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |7. Sort According to Names  |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |8. Sort According to Scores |\n");
        printf("\t\t\t\t      |----------------------------|\n");
        printf("\t\t\t\t      |9. Sort According to ID     |\n");
        printf("\t\t\t\t      |============================|\n");
        printf("\t\t\t\t      |10. Exit                    |\n");
        printf("\t\t\t\t      ******************************\n\n");

        printf("Enter your choice :--> ");
        scanf("%d",&Answer);    //Scan the user's input of the process then switch it to the function of the process
        fflush(stdin);
        switch(Answer)
        {
        case 1:
            New_Student(&School_Students_List);
            printf("Hi");
            break;
        case 2:
            Student_Edit(&School_Students_List);
            break;
        case 3:
            PrintStudentList(&School_Students_List);
            break;
        case 4:
            PrintSpecificStudentInfo(&School_Students_List);
            break;
        case 5:
            Delete_Student(&School_Students_List);
            break;
        case 6:
            Student_Score(&School_Students_List);
            break;
        case 7:
            SortAccordingToName(&School_Students_List);
            break;
        case 8:
            SortAccordingToScore(&School_Students_List);
            break;
        case 9:
            SortAccordingToID(&School_Students_List);
            break;
        case 10:
            Onflag = 0;
            break;
        default:
            printf("\nthis is not in the list\n\n");
            break;
        }
        printf("Press Enter to Continue\n");
        fflush(stdin);
        getchar();  //Wait for the user to press enter to clear the screen and loop again from the beginning
        system("cls");
    }
    system("cls");
    printf("Press Enter to Shutdown");  //shutting down screen
}

void Main_Menu(LinkedList *Pll)
{    //Main_Menu function is made to take the school list and make it linked list and print first the welcome screen
    //Welcome Screen
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t      *******************************************************\n");
    printf("\t\t\t      *                                                     *\n");
    printf("\t\t\t      *       Welcome to the School Management System       *\n");
    printf("\t\t\t      *                                                     *\n");
    printf("\t\t\t      *******************************************************\n");
    printf("\t\t\t      -------------------By : Islam Adel---------------------\n\n");
    CreateLinkedList(Pll);      //create the list
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nPress (Enter) to go to the main menu");
    getchar();
    system("cls");
}

void New_Student(LinkedList *Pll)
{   //New_Student Function is made to take the data of the student that the user want to add then link it to the school list
    /* Under Develop */
    /* Function Missing Scanning the Student info */
    system("cls");	//System Clear screen

    /* Function DataTypes Creations */
    char choice;			//char for entering the answer of any choice with Y/N
    int score;				//int for getting the score and check if it is correct or not first before saving to the student info
    LLEntry studentinfo;	//LLEntry type to save the student info on it first then send it to the list
	int BirthDateInfo;		//Int for getting the birthdate info and check if it is correct or not first before saving the to student info

    /* Function Code */
	//request and scan the student name
    printf("Enter The Student data : \n");
    printf("1. Name : ");
    fflush(stdin);
    gets(studentinfo.Name);
	//request and scan the student address
    printf("2. Address : ");
    gets(studentinfo.Address);
	//request and scan then check Birthdate of the student
    /* There is no BirthDate Checking yet */
    printf("3. BirthDate : \n");

	//request and scan the year
    do{
        printf("   year  : ");
        scanf("%d",&studentinfo.BirthDate.Year);
        fflush(stdin);
    }while(studentinfo.BirthDate.Year < 1962 || studentinfo.BirthDate.Year >2012);

	//request and scan then check the month
    do{
		printf("   Month : ");
		scanf("%d",&BirthDateInfo);
		fflush(stdin);
	}while(BirthDateInfo > 12 || BirthDateInfo <= 0);
	studentinfo.BirthDate.Month = BirthDateInfo;        //Add the Month info entered to the student info
	BirthDateInfo =0;   //Reset BirthDateInfo

	//request and scan then check the day
	do{ //DoWhile loop to check if the month is 31 day or not and the day is in range or not
		BirthDateInfo = 0;  //Reset BirthDateInfo
		do{     //DoWhile loop to scan the day input and check if it is in range 1->31 or not
			printf("   Day   : ");
			scanf("%d",&BirthDateInfo);
			fflush(stdin);
			if(studentinfo.BirthDate.Month == 2 && BirthDateInfo > 29)
                BirthDateInfo =0;
		}while(BirthDateInfo >31 || BirthDateInfo <= 0); //Check if the day is in range or not (1->31)
	}while(((studentinfo.BirthDate.Month/8) + studentinfo.BirthDate.Month)%2 == 0 && BirthDateInfo >30); //check if the day is in range relative to the month
	studentinfo.BirthDate.Day = BirthDateInfo;      //Save the day info to the student day info
	BirthDateInfo = 0;      //reset BirthDateInfo

	printf("Enter the Phone number (+20)");
	scanf("%d",&studentinfo.PhoneNumber);
	fflush(stdin);

	/* Check if user want to add scores of the student */
    printf("want to add subjects scores ? Y/N");
    scanf(" %c",&choice);
    if(choice == 'y')       //Check if the user want to add Student's Grades or not
    {
        do{     //DoWhile loop to add the score of the ComputerScience and check if it is in range 1->100 or not
        printf("Enter the score of Computer Science : ");
        scanf("%d",&score);
        if(score > 100 || score <0)
            printf("\nScore are in range of 0->100\n\n");
        }while(score > 100 || score <0);
        studentinfo.Subjects[ComputerScience] = score;

        do{     //DoWhile loop to add the score of the Physics and check if it is in range 1->100 or not
        printf("Enter the score of Physics          : ");
        scanf("%d",&score);
        if(score > 100 || score <0)
            printf("\nScore are in range of 0->100\n\n");
        }while(score > 100 || score <0);
        studentinfo.Subjects[Physics] = score;

        do{     //DoWhile loop to add the score of the Mathematics and check if it is in range 1->100 or not
        printf("Enter the score of Mathematics      : ");
        scanf("%d",&score);
        if(score > 100 || score <0)
            printf("\nScore are in range of 0->100\n\n");
        }while(score > 100 || score <0);
        studentinfo.Subjects[Mathematics] = score;
    }
    else        //IF the user doesn't want to add student's score. Initialize all the subject's score with 0
    {
        studentinfo.Subjects[ComputerScience] = 0;
        studentinfo.Subjects[Physics] = 0;
        studentinfo.Subjects[Mathematics] = 0;
    }

    studentinfo.ID = Pll->LastID+1;
    Pll->LastID++;
//    /* Adding Student ID */
//    /* This function still need sorting */
//    studentinfo.ID = 221001;            //initialize the student ID
//    SortAccordingToID(Pll);             //First Sort it according to the array
//    if(P1)
//    {   //If function to check if there is student info in the List or not
//        while(P1->Next)
//        {   //While loop to Get to the bottom of the list
//            P1 = P1->Next;
//        }
//
//        for(int Iteration=Pll->SIZE; Iteration>0 ; Iteration--)     //For loop to loop over the whole list
//        {
//            if(P1->data.ID == studentinfo.ID)   //check if there is student with this ID or not
//            {
//                P1 = P1->Previous;          //if True go to the next student
//            }
//            else
//            {
//                break;                      //if this ID is free Leave the loop
//            }
//            studentinfo.ID++;
//        }
//    }
    DublyAddToTheLastLLNode(studentinfo,Pll);   //Send The Entered Student's Data to the LinkedList DataBase
}

void Delete_Student(LinkedList *Pll)
{   //Delete_Student is a function made to take the ID of the student that the user want to remove and remove him from the school list
    system("cls");  //Clear CMD
    /* Function Creation */
    LLEntry data;    //LLEntry type to copy the data that the user want to remove it first to make some process then send it again
    int Position;    //int type to know in which position this student is in the school list
    int ID;          //int type to scan the id
    char Action;     //char type to scan the Y/N Question's answers
    /* Function Code */
    if(Pll->SIZE)
    {   //First Check if there is students in the school list or not
        do{ /* Get the Position using the ID and loop till either get right ID or Leave without doing anything */
            printf("Enter The ID : ");
            scanf("%d",&ID);
            Position = Get_Position_Using_ID(ID,Pll);   //Call Get_Position_Using_ID to get the position of the student in the school list using his ID then save it to the variable Position
            if(!Position)
            {   //if function that check if the position is still '0' so there is no compatible ID, if so ask the user to leave or not first before getting another ID
                printf("Exit? Y/N  ");
                scanf(" %s",&Action);
                if(Action == 'y')   /* if you didn't find the ID ask him to leave or not */
                {
                    break;
                }
            }
        }while(Position==0 || Position > Pll->SIZE);
        if(Position != 0)
            {   //if the previous code reached the student location in the list copy his data into the "data" then print it first to check if this data is the correct data that the user want to remove or not
                DublyCopyData(&data,Pll,Position);
                /* Printing The Student Data */
                printf("*************************************\n");
                printf("Student Info :\nName : %s\n",data.Name);
                printf("ID : %d\n",data.ID);
                printf("Address : %s\n",data.Address);
                printf("Date of Birth : %d/%d/%d\n\n",data.BirthDate.Day,data.BirthDate.Month,data.BirthDate.Year);
                printf("Computer Science : %d\n",data.Subjects[0]);
                printf("Physics          : %d\n",data.Subjects[1]);
                printf("Mathematics      : %d\n",data.Subjects[2]);
                printf("*************************************\n\n");
            }
        printf("Are you Sure u want to Remove this student ? Y/N\n");
        scanf(" %c",&Action);
        if(Action == 'y')       //Check if the user want to remove these data or not
            DublyRemoveLLNode(&data,Pll,Position);     //if True then remove it from the School List
        else
            printf("Data has not removed \n");  //if False then print that the data didn't change and leave the function
    }
    else
    {       //if the size is 0 then there is no students in the list
        printf("\nTHE LIST IS EMPTY .. ADD STUDENTS FIRST\n\n");
    }
}

int Get_Position_Using_ID(int ID,LinkedList *Pll)
{   //Get_Position_Using_ID is a function that take the ID and search for it in the list then return it's position in the list if found or 0 if not found
    /* Function Creations */
    LLNode *P1 = Pll->top;  //Node Pointer to move with in the list freely
    int iteration;          //int type for the iterations of the for loop   (the iteration here represent the Position of the student)
    /* Function Code */
    if(Pll->SIZE)
    {   //if condition to check that there is students in the list
        for(iteration=Pll->SIZE ; iteration>0; iteration--)
        {   //for loop to check each position in the school list and compare the id in this node with he given id and break if found
            if(ID == P1->data.ID)
            {   //if the ID is equal to student's node ID then break the function and return the position (the iteration here represent the Position of the student)
                return iteration;
            }
            P1 = P1->Next;  //if the ID does not match then go to the next student
        }
        iteration --;   //the loop will stop the iteration in 1 if it is not found then make it 0
        if(iteration == 0)
        {   //if the ID is not found in the whole list then print that the id do not match any of student's ids and return 0
            printf("\n!!!!!There is no student with this ID!!!!!\n\n");
            return 0;
        }
    }
    else
    {   //if the loop is empty return 0
        return 0;
    }
    return 0;
}

void Student_List(LinkedList *Pll)
{   //Function to Sort and print the list according to the name
    SortAccordingToName(Pll);
}

void Student_Edit(LinkedList *Pll)
{   //Function get the id and edit the node's data of this ID
    system("cls");
    if(Pll->SIZE) /* Check if there is student info in the list or not */
    {
        /* Function DataTypes Creations */
        LLNode *EditData = GetStudentNode(Pll);   //creating EditData with Student Data type to Copy the node data on it
        int choice;         //Creating Choice "int" To receive numbers answer from the user
        int BirthDateInfo;  //Creating BirthDateInfo "int" to receive data of the birthdate
        /* Function code */
        if(EditData)
        {   //If the Position is valid
//            DublyCopyData(&EditData,Pll,Position);  //Copy data of the required node to EditData
            PrintStudentInfo(EditData->data);    //Print the student info
            {   /* Get data */
                do{
                    printf("What data you want to edit\n");
                    printf("1. Name\n");
                    printf("2. Address\n");
                    printf("3. Subject\n");
                    printf("4. Date Of Birth \n");
                    printf("5. Phone number\n");
                    printf("6. Exit the process\n");
                    printf("Choice : ");
                    scanf("%d",&choice);
                    fflush(stdin);
                    if(choice > 6 || choice == 0)   //if the choice is not in the list
                        printf("\nThis is not in the list\n\n");
                }while(choice > 6 || choice ==0);
                switch(choice)
                {
                case 1:     //if answer is 1 then edit name
                    printf("Enter the New name : ");
                    fflush(stdin);
                    gets(EditData->data.Name);
                    fflush(stdin);
                    break;

                case 2:     //if answer is 2 then edit address
                    printf("Enter the New Address : ");
                    fflush(stdin);
                    gets(EditData->data.Address);
                    fflush(stdin);
                    break;

                case 3:     //if answer is 3 then edit one of the subjects
                    choice = 0;     //reset the answer of choice
                    printf("what Subject do you want to edit : \n");
                    printf("1. Computer Science\n");
                    printf("2. Physics\n");
                    printf("3. Mathematics\n");
                    do{     //receive the choice
                        printf("choice -> ");
                        scanf(" %d",&choice);
                        fflush(stdin);
                        switch(choice)
                        {
                        case 1:     //if choice is 1 then edit computer science
                            printf("Enter The new score of Computer Science : ");
                            scanf("%d",&EditData->data.Subjects[0]);
                            break;
                        case 2:     //if choice is 2 then edit physics
                            printf("Enter the new score of Physics : ");
                            scanf("%d",&EditData->data.Subjects[1]);
                            break;
                        case 3:     //if choice is 3 then edit mathematics
                            printf("Enter the new score of Mathematics : ");
                            scanf("%d",&EditData->data.Subjects[2]);
                            break;
                        default:        //just for safety
                            printf("Wrong choice \n");
                            break;
                        }
                    }while(choice > 3 || choice ==0);  //Loop till a valid choice is entered
                    break;

                case 4:     //if choice is 4 then edit birthdate
                    //request and scan the year
                    do{
                        printf("   year  : ");
                        scanf("%d",&EditData->data.BirthDate.Year);
                        fflush(stdin);
                    }while(EditData->data.BirthDate.Year < 1962 || EditData->data.BirthDate.Year >2012);

                    //request and scan then check the month
                    do{
                        printf("   Month : ");
                        scanf("%d",&BirthDateInfo);
                        fflush(stdin);
                    }while(BirthDateInfo > 12 || BirthDateInfo <= 0);
                    EditData->data.BirthDate.Month = BirthDateInfo;        //Add the Month info entered to the student info
                    BirthDateInfo =0;   //Reset BirthDateInfo

                    //request and scan then check the day
                    do{ //DoWhile loop to check if the month is 31 day or not and the day is in range or not
                        BirthDateInfo = 0;  //Reset BirthDateInfo
                        do{     //DoWhile loop to scan the day input and check if it is in range 1->31 or not
                            printf("   Day   : ");
                            scanf("%d",&BirthDateInfo);
                            fflush(stdin);
                            if(EditData->data.BirthDate.Month == 2 && BirthDateInfo > 29)
                                BirthDateInfo =0;
                        }while(BirthDateInfo >31 || BirthDateInfo <= 0); //Check if the day is in range or not (1->31)
                    }while(((EditData->data.BirthDate.Month/8) + EditData->data.BirthDate.Month)%2 == 0 && BirthDateInfo >30); //check if the day is in range relative to the month
                    EditData->data.BirthDate.Day = BirthDateInfo;      //Save the day info to the student day info
                    BirthDateInfo = 0;      //reset BirthDateInfo
                    break;
                case 5:     //if the choice is 5 then edit phone number
                    printf("Enter the Phone Number : (+20)");
                    scanf("%d",&EditData->data.PhoneNumber);
                    fflush(stdin);
                    break;
                case 6:     //if the choice is 6 then exit
                    printf("Exit\n");
                    break;
                default:    //Just for safety
                    break;
                }
            }
            printf("\n");
        }
        else
        {
            printf("\nNothing has been done\n\n");
        }
    }
    else
    {
        printf("\nTHE LIST IS EMPTY .. ADD STUDENTS FIRST\n\n");
    }
}

void Rank_Student(LinkedList *Pll)
{   //Function to Sort the students according to their scores
    SortAccordingToScore(Pll);
}

void Student_Score(LinkedList *Pll)
{   //Function to Score all the students at once in a specific subject
    system("cls");
    if(Pll->SIZE)
    {   //if the list is not empty
        /* Function Creation */
        int score;  //Saving Score in a datatype
        int Iteration;      //Iterations
        char choice;        //User's Choice
        LLNode *P1 = Pll->top;  //Node pointer P1 to move through the list
        int subject=0;      //user's subject score
        do{ //Check if the user want to add scores for another subject or not
            do{ //check if choice is correct or not
                printf("Which subject you want to add it's score : \n");
                printf("1. Computer Science\n2. Physics\n3. Mathematics\n");
                printf("Choice : ");
                scanf("%d",&subject);
                fflush(stdin);
                switch (subject)
                {
                case 1:
                    printf("Entering Scores of Computer Science :\n\n");
                    break;
                case 2:
                    printf("Entering Scores of Physics :\n\n");
                    break;
                case 3:
                    printf("Entering Scores of Mathematics :\n\n");
                    break;
                default:
                    printf("\nTHIS IS NOT IN THE LIST\n\n");
                    break;
                }
            }while(subject > 3 || subject == 0);
//            P1 = Pll->top;
            for(Iteration = Pll->SIZE; Iteration>0; Iteration-- )
            {   //loop on all the students
                do{ //loop till the user enter score in range
                printf("Student Name : %s \tID : %d\tScore : ",P1->data.Name,P1->data.ID);
                scanf("%d",&score);
                fflush(stdin);
                if(score >100 || score == 0)
                    printf("\nScore must be in range 1->100, Enter the score again !\n\n");
                }while(score > 100 || score == 0);
                P1->data.Subjects[subject-1] = score;  //add the score to the student's subject
                P1=P1->Next;    //go to the next student
            }
            printf("Want to Enter another subject's score ? Y/N\n");
            scanf(" %c",&choice);
        }while(choice == 'y');
    }
    else
    {
        printf("\nTHE LIST IS EMPTY .. ADD STUDENTS FIRST\n\n");
    }
}

void PrintStudentList(LinkedList *Pll)
{   //Function to print the student list
    system("cls");
    LLNode *Ptemp = Pll->top;
    printf("*********************\n");
    printf("The Student List is :\n");
    printf("*********************\n\n");
    if(Ptemp)
    {   //check if the list is not empty
        for(int Iteration = Pll->SIZE ; Iteration > 0; Iteration-- )
        {   //loop over the whole list
            PrintStudentInfo(Ptemp->data);  //print the student info
            Ptemp = Ptemp->Next;
        }
    }
    else
    {
        printf("Nothing in here\n");
    }
    printf("\n");
}

void PrintStudentInfo(Student *Pn)
{   //function that take pointer to node and print it's data
    if(Pn->ID)
    {   //check if the ID is valid
        /* Printing The Student Data */
        printf("*************************************\n");
        printf("Student Info :\nName : %s\n",Pn->Name);
        printf("ID : %d\n",Pn->ID);
        printf("Adress : %s\n",Pn->Address);
        printf("Phone Number : (+20)%d\n",Pn->PhoneNumber);
        printf("Date of Birth : %d/%d/%d\n\n",Pn->BirthDate.Day,Pn->BirthDate.Month,Pn->BirthDate.Year);
        printf("Computer Science : %d\n",Pn->Subjects[ComputerScience]);
        printf("Physics          : %d\n",Pn->Subjects[Physics]);
        printf("Mathematics      : %d\n",Pn->Subjects[Mathematics]);
        printf("*************************************\n\n");
    }
}

void PrintSpecificStudentInfo(LinkedList *Pll)
{   //Function to take the position and print specific student's info
    system("cls");
    if(Pll->SIZE)
    {
        /* Function DataTypes Creations */
        LLNode *Pn = GetStudentNode(Pll);
        /* Function Code */
        if(Pn)
        {
            PrintStudentInfo(&Pn->data);
        }
        else
        {
            printf("ID not found\n");
        }
    }
    else
    {   //if the list is empty
        printf("\nTHE LIST IS EMPTY .. ADD STUDENTS FIRST\n\n");
    }
}

int GetPosition(LinkedList *Pll)
{   //Function to ask for the position and return the not equivalent to this position
    /* Function DataTypes Creations */
    int Position;
    int ID;
    char Action;

    /* Function Code */
    do{ /* Get the Position using the ID and loop till either get right ID or Leave without doing anything */
        printf("Enter The ID : ");
        scanf("%d",&ID);
        fflush(stdin);
        Position = Get_Position_Using_ID(ID,Pll);
        if(!Position)
        {
            printf("Exit? Y/N  ");
            scanf(" %s",&Action);
            fflush(stdin);
            if(Action == 'y')   /* if you don't find the ID ask him to leave or not */
            {
                break;
            }
        }
    }while(Position==0 || Position > Pll->SIZE);
    return Position;
}

void SortAccordingToName(LinkedList *Pll)
{   //Function sort and print student list according to their names using bubble sort
    system("cls");
    if(Pll->SIZE)
    {   //check if the list is not empty
        LLNode *P1 = Pll->top;
        for(int Iteration=1; Iteration<Pll->SIZE ; Iteration++)
        {
            for(int j=Pll->SIZE; j>1; j--)
            {
                if(strcmp(P1->data.Name,P1->Next->data.Name) > 0)
                {
                    printf("%d\n",strcmp(P1->data.Name,P1->Next->data.Name));
                    printf("P1->data ; %s 2:%s",P1->data.Name,P1->Next->data.Name);
                    MoveDownSwapLL(Pll,j);
                }
                else
                {
                    P1 = P1->Next;
                }
            }
            P1 = Pll->top;
        }
        printf("Exit\n");
    }
    PrintStudentList(Pll);
}

void SortAccordingToScore(LinkedList *Pll)
{   //function that sort and print student list according to their score using bubblesort
    system("cls");
    if(Pll->SIZE)
    {   //check if the list is not empty
        LLNode *P1 = Pll->top;
        int choice;
        printf("Subjects : \n");
        printf("1. Computer Science\n");
        printf("2. Physics \n");
        printf("3. Mathematics \n\n");
        do{
            printf("Which score do you want to sort with ?\n");
            printf("Choice -> ");
            scanf(" %d",&choice);
            fflush(stdin);
        }while(choice >3 || choice <=0);
        for(int Iteration=1; Iteration<Pll->SIZE ; Iteration++)
        {
            for(int j=Pll->SIZE; j>1; j--)
            {
                    if(P1->data.Subjects[choice-1] < P1->Next->data.Subjects[choice-1])
                    {
                        MoveDownSwapLL(Pll,j);
                    }
                    else
                    {
                        P1 = P1->Next;
                    }

            }
            P1 = Pll->top;
        }
    }
    PrintStudentList(Pll);
}

void SortAccordingToID(LinkedList *Pll)
{   //function to sort and print the student list according to their IDs
    system("cls");
    if(Pll->SIZE)
    {   //check if the list is not empty
        LLNode *P1 = Pll->top;  //Node pointer to P1 to move through the list
        for(int Iteration=1; Iteration<Pll->SIZE ; Iteration++)
        {       //loop over the whole list
            for(int j=Pll->SIZE; j>1; j--)
            {   //loop compare to the rest of the nodes
                if(P1->data.ID < P1->Next->data.ID)
                {   //if the data is greater than the other data then swap it
                    MoveDownSwapLL(Pll,j);
                }
                else
                {   //if not then got to next pointer
                    P1 = P1->Next;
                }
            }
            //return to the top again to check other nodes again
            P1 = Pll->top;
        }
    }

    PrintStudentList(Pll);
}
