#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Additional functions:
char toUpper(char);
int stringCompare(char s1[], char s2[]);
void stringCopy(char src[], char dest[]);
int aStrcmp(char s1[], char s2[]);
//STRUCT EMPTY (USEFUL IN THE CODE)


// subject structure
struct subject {
    int subjID;
    char subjCode[10];
    char subjTitle[100];
}def = {0, "none", " "}, deft = {0, " ", " "};
struct subject data = {};;

struct subject subj[70];

// statistics structure
struct statistics{
    int highest;
    int lowest;
    float avg;
    float sd;
}studentstatistics[4];


//student structure
struct student {
    int studID;
    char firstN[25];
    char lastN[25];
    char section[10];
    int ex1;
    int ex2;
    int ex3;
    struct subject *s1;
    struct subject *s2;
    struct subject *s3;
    int numSubjects;
    int total; //temporary, see if it works to add total
    char grade[5];
}deb, debault = {0, " ", " ", " ", 0, 0, 0, &deft, &deft, &deft, 0, " "};
struct student studentPlace[70];

//Struct-related functions:
// FOR STUDENTS
struct student create(struct student studentPlace, struct student studentStock[]);

void displayStud(struct student *studentPlace,int x);
void searchStud(char x[25]);
void singleStudDis(int ind);
struct student totalGrade(struct student grades);
void updateStud(struct student studentPlace[]);
void deleteStud(int ind);
void displayStudent(int num);

void alphaStudents(int n);

int toInteger(char st[]);

//import stuff
void inputToText(char file[20]);
void writeToText(char file[15]);
void inputSubj(char file[15]);
void structToFile();
void fileToStruct();
int findSubj1(char a[10]);
int stringCompare1(char s1[], char s2[]);
char toLower(char ch);
/*void filetoStructSubj();*/

// FOR SUBJECTS
//struct subject createSubj(struct subject *);
void enrollSubj(int idNum, char code[20]);
int findSubj(char a[10]);
void displaySubj(struct subject *SubjPtr);
void deleteSubj(char a[]);
void dropSubj(int n);


// FOR EXAM STATS
struct statistics statisticsEx1(struct statistics st);
struct statistics statisticsEx2(struct statistics st);
struct statistics statisticsEx3(struct statistics st);
struct statistics statTotal(struct statistics st);
struct student inputKey(struct student inputStudent);
struct student updateInfo(struct student inputStudent);
struct subject createSubj(struct subject *inputSubj);
struct student grade(struct student iS);


int number = 0;
int numbSub = 1;
//MAIN DISPLAY:
int main(void){
    int m_choice = 1;
    //last minute color change
    system("COLOR F0");
    printf(" To make use of a more efficient display, please use a fullscreen window.\n ");
    system("pause");
    system("cls");

    int init;
    for(init = 0; init < 70; init++){
        studentPlace[init].s1 = &def;
        studentPlace[init].s2 = &def;
        studentPlace[init].s3 = &def;
    }subj[0] = (struct subject){1111, "CMSC11", "Computer Science"};

    while(m_choice>=1&&m_choice<=13){
    char x[25];
    int a;

    checkerlast:
    printf("\n\n\t");
//HEADER BLOCK
    printf("%c",201);
   for(int i=0; i < 87; i++){
    printf("%c",205);
   }
    printf("%c\n\t%c                               STUDENT REGISTRATION SYSTEM                             %c\n\t%c",187,186,186,204);
   for(int i=0; i < 87; i++){
    printf("%c",205);
   }
    printf("%c\n\t%c            STUDENT RECORD OPTIONS                     SUBJECT RECORD OPTIONS          %c\n",185,186,186);
    printf("\t%c",204);
   for(int i=0; i < 43; i++){
    printf("%c",205);
   }
   printf("%c",203);
   for(int i=0; i < 43; i++){
    printf("%c",205);
   }
    printf("%c\n\t%c                                           %c                                           %c",185,186,186,186);
    printf("\n\t%c         1) Create  student record         %c         6) Create  subject record         %c",186,186,186);
    printf("\n\t%c         2) Update  student record         %c         7) Update  subject record         %c",186,186,186);
    printf("\n\t%c         3) Delete  student record         %c         8) Delete  subject record         %c",186,186,186);
    printf("\n\t%c         4) Search  student record         %c         9) Search  subject record         %c",186,186,186);
    printf("\n\t%c         5) Display all student records    %c         10) Display all subject records   %c",186,186,186);
    printf("\n\t%c                                           %c                                           %c",186,186,186);
    printf("\n\t%c",204);
   for(int i=0; i < 43; i++){
    printf("%c",205);
   }
   printf("%c",202);
   for(int i=0; i < 43; i++){
    printf("%c",205);
   }
    printf("%c\n\t%c                                                                                       %c",185,186,186);
    printf("\n\t%c                                       MORE OPTIONS                                    %c",186,186);
    printf("\n\t%c                              11) Enroll a student to a subject                        %c",186,186);
    printf("\n\t%c                              12) Drop a subject                                       %c",186,186);
    printf("\n\t%c                              13) Export file Masterlist                               %c",186,186);
    printf("\n\t%c                            Any other number to exit the program                       %c",186,186);
    printf("\n\t%c                                                                                       %c",186,186);
   printf("\n\t%c",200);
   for(int i=0; i < 87; i++){
    printf("%c",205);
   }
   printf("%c",188);
//END HEADER BLOCK
	printf("\n\t%c Enter a choice: ",175);
//catches if its outside boundary
	scanf("%d",&m_choice);
		if(m_choice>13||m_choice<1){
            int lastchance;
            printf("Are you sure you want to end using the SRS?\n 1. Yes\n 2. No\n Enter choice: ");
            scanf(" %d", &lastchance);
                if(lastchance == 1 || lastchance != 2){
                    printf("\n\n\tThank you for using the SRS!\n");
                    break;
                }
                if(lastchance == 2){
                    printf(" Okay. Redirecting. ");
                    goto checkerlast;
                }
		}
//end of catch

//finds the placement of current student record so that immediate updating sequence
    int tindex;
    for(tindex = 0; studentPlace[tindex].studID!= '\0'; tindex++){
    }


//##### START OF SWITCH CASE #####
    switch(m_choice){
    //CREATE STUDENT RECORD
        case 1:

		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		int c_choice;
		char file[20];
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf(" \t\t\t CHOICES TO f A STUDENT PROFILE \n");
            printf(" 1. Manually \n 2. Input csv file name\n ");
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
            printf("\n Enter Choice: ");
            scanf(" %d", &c_choice);
            if(c_choice == 1){
                studentPlace[number]=create(studentPlace[number],studentPlace);
                enrolldef(&studentPlace[number]);
                number++;
                alphaStudents(number);
                break;
            }
            if(c_choice == 2){
                printf("Import a .csv file.\n Enter file name: ");
                scanf(" %19[^\n]s", file);
                inputToText(file);
                // inputToText(file);

                break;
            }
		/*	studentPlace[tail].sub=&Sub[1];
			studentPlace[tail].subs2=&Sub[0];
			studentPlace[tail].subs3=&Sub[0];    */
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

            break;
   //UPDATE STUDENT
        case 2:
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                updateStud(studentPlace);
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

            break;
   //DELETE STUDENT
        case 3:
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                printf(" Enter the Student ID number to Delete: ");
                int given;
                scanf("%d", &given);
                deleteStud(given);
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

            break;
   //SEARCH STUDENT
        case 4:
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf(" Enter Last Name of Student: ");
            scanf(" %24[^\n]s", &x);
            searchStud(x);
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            break;
    // DISPLAY ALL STUDENT RECORDS
        case 5:
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            if(tindex == 0){
                printf("There are no students in the registry.");
                break;
            }
            printf("ID No.\tLast Name\t\tFirst Name\t\tSection\t\tSubjects\t\tExam 1\tExam 2\tExam 3\t Total\t Grade\n");
            printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            /*for(int i = 1; i <= number+1; i++){
				displayStud(&studentPlace[i],i);
				//display(&studentPlace[i]);
			}*/
			display(number);
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\tLowest Score:    %d\t   %d\t   %d\t    %d\n",studentstatistics[0].lowest, studentstatistics[1].lowest ,studentstatistics[2].lowest,studentstatistics[3].lowest);
            printf("\t\t\t\t\t\t\t\t\t\t      Highest Score:    %d\t   %d\t   %d\t    %d\n",studentstatistics[0].highest, studentstatistics[1].highest ,studentstatistics[2].highest,studentstatistics[3].highest);
            printf("\t\t\t\t\t\t\t\t\t\t      Average:  %.3f\t %.3f\t %.3f   %.3f\n",studentstatistics[0].avg, studentstatistics[1].avg ,studentstatistics[2].avg,studentstatistics[3].avg);
            printf("\t\t\t\t\t\t\t\t\t    Standard Deviation:  %.3f\t %.3f\t %.3f    %.3f\n",studentstatistics[0].sd, studentstatistics[1].sd ,studentstatistics[2].sd,studentstatistics[3].sd);


			//display(number);
            printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            break;
    // CREATE SUB
        case 6:
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            int s_choice;

            printf(" \t\t\t CHOICES TO A SUBJECT RECORD \n");
            printf(" 1. Manually \n 2. Input txt/csv file name\n ");
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
            printf("\n Enter Choice: ");
            scanf(" %d", &s_choice);
            if(s_choice == 1){
                subj[numbSub] = createSubj(&subj[numbSub]);
                numbSub++;
            }
            if(s_choice == 2){
             printf("\n\tInput .csv file name: ");
                scanf(" %100[^\n]s", file);
                inputSub(file);
                /*inputToText(file);*/
                /*fileToStructSubj();*/
            }
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            break;

   // UPDATE SUB
        case 7:
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\tEnter the Subject Code to be Updated: ");
            scanf("%s", x);
            printf("\n");
            int n;
            int found = 0;
                for (n = 0; n <= numbSub; n++){
                    if(stringCompare(subj[n].subjCode, x) == 0){
                        found = 1;
                        break;
                    }
                }
                if(found == 1){
                    createSubj(&subj[n]);
                }else{
                    printf("No records found");
                }
		printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            break;
   //DELETE SUB
        case 8:
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\n\tEnter Subject Code to Deleted: ");
            scanf("%s", file);
            deleteSubj(file);
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

            break;
  //SEARCH
        case 9:
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\tInput Subject Code: ");
            scanf(" %s", &file);
            findSubj(file);
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

            break;
  //DISPLAY ALL
        case 10:
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\tID Number\t\tSubject Code\t\tSubject Title\n");
            for (int i = 0; i < numbSub; i++){
                if(stringCompare(subj[i].subjCode, "none") != 0){
                    displaySubj(&subj[i]);
                }
            }

		printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            break;
  //ENROLL STUDENT
        case 11:
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\tEnter Student 3-Digit ID number: ");
            scanf("%d", &n);
            printf("\tEnter Subject Code: ");
            scanf("%s",a);
            enrollSubj(n, a);
		printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            break;
  //DROP SUB
        case 12:
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\tEnter Student 3-Digit ID number: ");
            scanf("%d", &n);
            dropSubj(n);
		printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            break;
// Export Into Text File
        case 13:
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\n What do you want to name the file?: ");
            scanf(" %s", &file);
            writeToText(file);
		printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            break;


    }
// ##### END OF SWITCH CASE #####
        int i;
		for (i = 0; i <= number; i++){
        studentPlace[i] = grade(studentPlace[i]);
        }alphaStudents(number);
    //Exam statisticsistcs
    studentstatistics[0] = statisticsEx1(studentstatistics[0]);
    studentstatistics[1] = statisticsEx2(studentstatistics[1]);
    studentstatistics[2] = statisticsEx3(studentstatistics[2]);
    studentstatistics[3] = statTotal(studentstatistics[3]);
    }
//END MAIN WHILE LOOP
    return 0;
}

//STRUCTURE PROPER

//creates a student profile manually
struct student create(struct student studentPlace, struct student studentStock[]){
//CHECKER IF VALID ID NUMBER
check1:
    printf("Note: Student ID's must be a 3 digit number.\nEnter the student's ID: ");
    scanf(" %d", &studentPlace.studID);
    if(studentPlace.studID >=1000 || studentPlace.studID <= 99){
        printf("Invalid Student ID.\n");
        goto check1;
    }
    //FINDS LAST PLACEMENT IN THE STOCK ARRAY
    int tindex;
    for(tindex = 0; studentStock[tindex].studID!= '\0'; tindex++){
    }
    for(int i=0; i < tindex; i++){
        if(studentPlace.studID==studentStock[i].studID){
            printf("This student ID is unavailable.\n");
            goto check1;
        }
    }
//END OF CHECKER1 LOOP

    //PRINTING PROPER
    //Assumes that all user inputs must be correct
    printf("Last Name: ");
    scanf(" %24[^\n]s", &studentPlace.lastN);
    printf("First Name: ");
    scanf(" %24[^\n]s", &studentPlace.firstN);
    printf("Section: ");
    scanf(" %9[^\n]s", &studentPlace.section);
    ex1:
    printf("Score in HandsOn Exam 1: ");
    scanf(" %d", &studentPlace.ex1);
        if(studentPlace.ex1>50 ){
            printf(" Invalid score.\n");
            goto ex1;
        }
        if(studentPlace.ex1<1 ){
            printf(" Invalid score.\n");
            goto ex1;
        }
    ex2:
    printf("Score in HandsOn Exam 2: ");
    scanf(" %d", &studentPlace.ex2);
        if(studentPlace.ex2>50 ){
            printf(" Invalid score.\n");
            goto ex2;
        }
        if(studentPlace.ex2<1 ){
            printf(" Invalid score.\n");
            goto ex2;
        }
    ex3:
    printf("Score in HandsOn Exam 3: ");
    scanf(" %d", &studentPlace.ex3);
        if(studentPlace.ex3>50 ){
            printf(" Invalid score.\n");
            goto ex3;
        }
        if(studentPlace.ex3 < 1 ){
            printf(" Invalid score.\n");
            goto ex3;
        }
    //total
    studentPlace.total = studentPlace.ex1 + studentPlace.ex2 + studentPlace.ex3;
    return studentPlace;
}

//incomplete
void displayStud(struct student *studentPlace, int x){
    int index1, index2, index3;

    int i;
	for (i=0; i<number; i++){
    printf("\n\n\t\t\t%03d", studentPlace[i].studID);
    printf("\t\t\t%s, %s", studentPlace[i].lastN, studentPlace[i].firstN);
    printf("\t\t%s", studentPlace[i].section);
    printf("\t\t%s ", studentPlace[i].s1);
    printf("\t\t%s", studentPlace[i].s2);
    printf("\t\t%s", studentPlace[i].s3);
    printf("  %.3f", studentPlace[i].ex1);
    printf("  %.3f", studentPlace[i].ex2);
    printf("  %.3f", studentPlace[i].ex3);
    printf("\t %s,", studentPlace[x].s1->subjCode);
        index1 = strcspn(studentPlace[x].s1->subjCode, "\n");
    printf("%s,", studentPlace[x].s2->subjCode);
        index2 = strcspn(studentPlace[x].s2->subjCode, "\n");
    printf("%s", studentPlace[x].s3->subjCode);
        index3 = strcspn(studentPlace[x].s3->subjCode, "\n");
    printf("\t%d", studentPlace->ex1);
    printf("\t%d", studentPlace->ex2);
    printf("\t%d", studentPlace->ex3);
    //insert the subjects here
    printf("\t\t\t\t\t");
    printf("\t%d",studentPlace->total);
   // printf("\t %s\n",studentPlace->grade);
    if(studentPlace->total >= 135){
        printf("\t HD\n");
    }else if(studentPlace->total >= 120){
        printf("\t D\n");
    }else if(studentPlace->total >= 100){
        printf("\t P\n");
    }else if(studentPlace->total >= 75){
        printf("\t C\n");
    }else{
        printf("\t F\n");
    }
	}
}

//alternate; wont work
    //note to self: remember to switch the n for the last na jd
void display(int s){

    int i;
	for (i = 0; i < s; i++){
        int index1, index2,index3, index4;
        printf("%03d\t %s", studentPlace[i].studID, studentPlace[i].lastN);
        index1 = strcspn(studentPlace[i].lastN, "\n");
        int j;
		for (j = 1; j <= 23-index1; j++){
            printf(" ");
        }
        printf("%s", studentPlace[i].firstN);
        index1 = strcspn(studentPlace[i].firstN, "\n");
        for (j = 1; j <= 23-index1; j++){
            printf(" ");
        }
        printf("%s", studentPlace[i].section);
        index1 = strcspn(studentPlace[i].section, "\n");
        for (j = 1; j <= 10-index1; j++){
            printf(" ");
        }
        printf("%s,", studentPlace[i].s1->subjCode);
        index1 = strcspn(studentPlace[i].s1->subjCode, "\n");
        printf("%s,", studentPlace[i].s2->subjCode);
        index2 = strcspn(studentPlace[i].s2->subjCode, "\n");
        printf("%s", studentPlace[i].s3->subjCode);
        index3 = strcspn(studentPlace[i].s3->subjCode, "\n");
        for (j = 1; j <= 30-index1-index2-index3-2; j++){
            printf(" ");
        }
        printf("%d      %d      %d      %d     %s\n", studentPlace[i].ex1, studentPlace[i].ex2, studentPlace[i].ex3,studentPlace[i].total,studentPlace[i].grade);
    }

}
void alphaStudents(int n){
    int i;
	for (i = 0; i < n - 1; i++){
        int c;
		for (c = i; c < n - 1; c++){
            if (stringCompare(studentPlace[c].lastN,studentPlace[c+1].lastN) == 1){
                deb = studentPlace[c + 1];
                studentPlace[c + 1] = studentPlace[c];
                studentPlace[c] = deb;
            }
        }
    }

    for (i = 0; i < n - 1; i++){
        int c;
		for (c = i; c < n - 1; c++){
            if (stringCompare(studentPlace[c].lastN,studentPlace[c+1].lastN) == 1){
                deb = studentPlace[c + 1];
                studentPlace[c + 1] = studentPlace[c];
                studentPlace[c] = deb;
            }
        }
    }
}

void singleStudDis(int ind){
    printf("ID No.\tLast Name\t\tFirst Name\t\tSection\tExam 1\tExam 2\tExam 3\t Subject1\t\t Subject2\t\tSubject3\t Total\t Grade\n");
    printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("[%d]", studentPlace[ind].studID);
    printf("\t%s", studentPlace[ind].lastN);
    printf("\t\t%s", studentPlace[ind].firstN);
    printf("\t\t%s", studentPlace[ind].section);
    printf("\t%d", studentPlace[ind].ex1);
    printf("\t%d", studentPlace[ind].ex2);
    printf("\t%d", studentPlace[ind].ex3);
    //insert the subjects here
    printf("\t\t\t\t\t");
    printf("\t%d",studentPlace[ind].total);
   // printf("\t %s\n",studentPlace->grade);
    if(studentPlace[ind].total >= 135){
        printf("\t HD\n");
    }else if(studentPlace[ind].total >= 120){
        printf("\t D\n");
    }else if(studentPlace[ind].total >= 100){
        printf("\t P\n");
    }else if(studentPlace[ind].total >= 75){
        printf("\t C\n");
    }else{
        printf("\t F\n");
    }

}

//update student information
void updateStud(struct student studentPlace[]){
    int tindex;
    int u_choice = 1;
    int u_ID, found = 0;
    printf("Enter a student ID: ");
    scanf(" %d", &u_ID);
    for(tindex = 0; studentPlace[tindex].studID!= '\0'; tindex++){
            if(u_ID == studentPlace[tindex].studID){
                found = 1;
                break;
            }
    }
    if(found == 0){
        printf(" There are no student records to modify.\n");
    }
    if(found == 1) {
        while(u_choice >= 1 && u_choice <= 6){
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf(" \t\t\t CHOICES TO UPDATE \n");
            printf(" 1. Last Name \n 2. First Name \n 3. Section \n 4. Score in Exam 1 \n 5. Score in Exam 2 \n 6. Score in Exam 3\n 0 to go back.\n ");
            printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
            printf("\n Enter Choice: ");
            scanf(" %d", &u_choice);
            switch(u_choice){
                case 1:
                    printf("New Last Name: ");
                    scanf(" %24[^\n]s", &studentPlace[tindex].lastN);
                    break;
                case 2:
                    printf("New First Name: ");
                    scanf(" %24[^\n]s", &studentPlace[tindex].firstN);
                    break;
                case 3:
                    printf("New Section: ");
                    scanf(" %9[^\n]s", &studentPlace[tindex].section);
                    break;
                case 4:
                    upex1:
                    printf("New Score in HandsOn Exam 1: ");
                    scanf(" %d", &studentPlace[tindex].ex1);
                        if(studentPlace[tindex].ex1>50 ){
                            printf(" Invalid score.\n");
                            goto upex1;
                        }
                        if(studentPlace[tindex].ex1<1 ){
                            printf(" Invalid score.\n");
                            goto upex1;
                        }
                    break;
                case 5:
                    upex2:
                    printf("New Score in HandsOn Exam 2: ");
                    scanf(" %d", &studentPlace[tindex].ex2);
                        if(studentPlace[tindex].ex2>50 ){
                            printf(" Invalid score.\n");
                            goto upex2;
                        }
                        if(studentPlace[tindex].ex2<1 ){
                            printf(" Invalid score.\n");
                            goto upex2;
                        }
                    break;
                case 6:
                    upex3:
                    printf("New Score in HandsOn Exam 3: ");
                    scanf(" %d", &studentPlace[tindex].ex3);
                        if(studentPlace[tindex].ex3>50 ){
                            printf(" Invalid score.\n");
                            goto upex3;
                        }
                        if(studentPlace[tindex].ex3<1 ){
                            printf(" Invalid score.\n");
                            goto upex3;
                        }
                    break;
                case 0:
                    printf(" Going Back To Main Menu \n");
                    break;
            }
            studentPlace[tindex].total = studentPlace[tindex].ex1 + studentPlace[tindex].ex2 + studentPlace[tindex].ex3;
        }
    }

}
void searchStud(char x[25]){

    int follow = 0;
    int tindex;
    for(tindex = 0; studentPlace[tindex].studID!= '\0'; tindex++){
    }

    for(int i = 0; i <= tindex; i++){
        if(stringCompare(x, studentPlace[i].lastN)== 0){
            singleStudDis(i);
            follow--;
        }else{
            follow++;
        }
        if(follow == tindex){
            printf("This student does not exist.\n");
        }
    }
}

void deleteStud(int ind){
    int i, checker = 0;
    for(i = 0; i <= number; i++){
            if(ind == studentPlace[i].studID){
                checker = 1;
                studentPlace[i].studID = 0;
                printf("\n Successfully deleted student record.\n");
                break;
            }
    }
    int b;
    for( b = i; b < number; b++){
        studentPlace[b] = studentPlace[b + 1];
    }
    --number;
    if(checker == 0){
        printf(" Student record doesn't exist.");
    }
}



// statistics for Hands On Exam 1
struct statistics statisticsEx1(struct statistics st){
    int scores[number];
    int min = studentPlace[0].ex1;
    int max = studentPlace[0].ex1;
    float avg = 0,stD = 0;
    int i;
	for (i = 0; i < number; i++){
        scores[i] = studentPlace[i].ex1;
        avg += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    avg = avg/number;
    for (i = 0; i < number; i++){
        stD += pow(studentPlace[i].ex1 - avg, 2);
    }
    st.sd = sqrt(stD/number);
    st.avg = avg;
    st.highest = max;
    st.lowest = min;
    return st;
}

// stats for ex 2
struct statistics statisticsEx2(struct statistics st){
    int scores[number];
    int min = studentPlace[0].ex2;
    int max = studentPlace[0].ex2;
    float avg = 0,stD = 0;
    int i;
	for (i = 0; i < number; i++){
        scores[i] = studentPlace[i].ex2;
        avg += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    avg /= number;
    for (i = 0; i < number; i++){
        stD += pow(studentPlace[i].ex2 - avg, 2);
    }
    st.sd = sqrt(stD/number);
    st.avg = avg;
    st.highest = max;
    st.lowest = min;
    return st;
}
//stats ex 3
struct statistics statisticsEx3(struct statistics st){
    int scores[number];
    int min = studentPlace[0].ex3;
    int max = studentPlace[0].ex3;
    float avg = 0,stD = 0;
    int i;
	for (i = 0; i < number; i++){
        scores[i] = studentPlace[i].ex3;
        avg += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    avg /= number;
    for (i = 0; i < number; i++){
        stD += pow(studentPlace[i].ex3 - avg, 2);
    }
    st.sd = sqrt(stD/number);
    st.avg = avg;
    st.highest = max;
    st.lowest = min;
    return st;
}
// total score
struct statistics statTotal(struct statistics st){
    int scores[number];
    int min = studentPlace[0].total;
    int max = studentPlace[0].total;
    float avg = 0,stD = 0;
    int i;
	for (i = 0; i < number; i++){
        scores[i] = studentPlace[i].total;
        avg += scores[i];
        if(scores[i] > max){
            max = scores[i];
        }
        if(scores[i] < min){
            min = scores[i];
        }
    }
    avg /= number;
    for (i = 0; i < number; i++){
        stD += pow(studentPlace[i].total - avg, 2);
    }
    st.sd = sqrt(stD/number);
    st.avg = avg;
    st.highest = max;
    st.lowest = min;
    return st;
}


//total grades for everyone
struct student grade(struct student iS){
    iS.total = iS.ex1 + iS.ex2 + iS.ex3;
    if(iS.total >= 135){
        strcpy (iS.grade, "HD");
    }else if (iS.total >= 120)
    {
        strcpy (iS.grade, "D");
    }else if (iS.total >= 100)
    {
        strcpy (iS.grade, "P");
    }else if (iS.total >= 75)
    {
        strcpy (iS.grade, "C");
    }else{
        strcpy (iS.grade, "F");
    }

    return iS;
}
// create sub manual
struct subject createSubj(struct subject *inputSubj){
    int temp;
    char huhu[10];
    check2:
    printf("Note: Subject ID Number must be a 4 digit number.\n Enter the Subject ID: ");
    scanf(" %d", &temp);
    if(temp >= 10000 || temp <= 999){
        printf(" Invalid Subject ID.\n");
        goto check2;
    }
    for(int i=0; i <= numbSub; i++){
        if(subj[i].subjID==temp){
            printf("This Subject ID number is unavailable.\n");
            goto check2;
        }
        if(i == numbSub){
            inputSubj->subjID = temp;
        }
    }
    //printf(" numbsub = %d", numbSub);
   check3:
    printf(" Subject Code: ");
    scanf(" %9[^\n]s", &huhu);
    for(int i=0; i <= numbSub; i++){
        if(aStrcmp(subj[i].subjCode, huhu) == 0){
            printf("This Subject code is taken.\n");
            goto check3;
        }
        if(i == numbSub){
            stringCopy(huhu, inputSubj->subjCode);
        }
    }
    printf(" Input Subject Title: ");
    scanf(" %49[^\n]s", inputSubj->subjTitle);
    return *inputSubj;
}
// IMPORT STUDENT POSSIBLE
void inputToText(char file[20]){
    //int id, x1, x2, x3;
    char id[10], x1[10], x2[10],x3[10];
    char a[50], b[50], c[50];
    int at;
    FILE * data;
    data = fopen(file, "r");
    if ((data = fopen(file, "r")) == NULL){
        printf(" Couldn't find a file.");

    }else{
        while(!feof(data)){
        fscanf(data, "%d, %[^,], %[^,], %[^,], %d, %d, %d, %[^,], %[^,], %[^\n]", &studentPlace[number].studID, &studentPlace[number].lastN, &studentPlace[number].firstN, &studentPlace[number].section, &studentPlace[number].ex1, &studentPlace[number].ex2, &studentPlace[number].ex3, &a, &b, &c);
        if(stringCompare1(a, "none") == 0){
            studentPlace[number].s1 = &def;
        }else if(findSubj1(a) == -1){
                at = 0;
                if(at == 1){
                    subj[numbSub] = createSubj(&subj[numbSub]);
                    studentPlace[number].s1 = &subj[findSubj1(a)];
                    ++numbSub;
                }
        }else{
            studentPlace[number].s1 = &subj[findSubj1(a)];

        }
        if(stringCompare1(b, "none") == 0){
            studentPlace[number].s2 = &def;
        }else if(findSubj1(b) == -1){
                at = 0;
                if(at == 1){
                    subj[numbSub] = createSubj(&subj[numbSub]);
                    studentPlace[number].s2 = &subj[findSubj1(b)];
                    ++numbSub;
                }
        }else{
            studentPlace[number].s2 = &subj[findSubj1(b)];
        }if(stringCompare1(c, "none") == 0){
            studentPlace[number].s3 = &def;
        }else if(findSubj1(c) == -1){
            at = 0;
                if(at == 1){
                    subj[numbSub] = createSubj(&subj[numbSub]);
                    studentPlace[number].s3 = &subj[findSubj1(c)];
                    ++numbSub;
                }
        }else{
            studentPlace[number].s3 = &subj[findSubj1(c)];
        }

        if(studentPlace[number].studID == 0){
            break;
        }

        ++number;
        }
       // printf(" Import successful.\n");
    }
}

// IMPORT SUBJECT
void inputSubj(char file[15]){
    char tempcode[10];
    FILE * data;
    data = fopen(file, "r");
    if ((data = fopen(file, "r")) == NULL){
        printf(" Could not find file.\n");
    }else{
    while(!feof(data) && numbSub <= 21){
    fscanf(data, "%d, %[^,], %[^\n]", &subj[numbSub].subjID, tempcode, subj[numbSub].subjTitle);
    for(int i= 0; i <= numbSub; i++){
        if(aStrcmp(subj[i].subjCode, tempcode)==0){
            subj[numbSub] = def;
            break;
        }
    }

    if(subj[numbSub].subjID == 0){
            break;
    }
     numbSub++;
    }
    }
}

void enrollSubj(int idNum, char code[20]){
    int found = 0, find = 0;

    int i;
	for(i = 0; i <= number; i++){
        if(studentPlace[i].studID == idNum){
            found = 1;
            if(stringCompare(code, studentPlace[i].s1->subjCode) == 0 || stringCompare(code, studentPlace[i].s2->subjCode) == 0 || stringCompare(code, studentPlace[i].s3->subjCode) == 0){
                printf("\t\tStudent is already enrolled in this subject.\n");
                break;
            }

            int j;
			for(j = 1; j <= numbSub; j++){
                if(stringCompare(code, subj[j].subjCode) == 0){
                    if(studentPlace[i].s2->subjID == 0){
                        studentPlace[i].s2 = &subj[j];
                        find = 1;
                        printf("\t\tSuccessfully Enrolled\n");
                        break;
                    }else if (studentPlace[i].s3->subjID == 0){
                        studentPlace[i].s3 = &subj[j];
                        find = 1;
                        printf("\t\tSuccessfully Enrolled\n");
                        break;
                    }else{
                        printf("\t\tStudent Enrolled in Maximum Subjects\n");
                        find = 1;
                        break;
                    }
                }
            }
            if(find == 0){printf("\t\tSubject Code Does Not Exists\n");}

            break;
        }
    }if(found == 0){printf("\t\tStudent ID Does Not Exists\n");}
}
void enrolldef(struct student *s){
    s->s1 = &subj[0];
}

void displaySubj(struct subject *SubjPtr){
    printf("\t%04d\t\t", SubjPtr->subjID);
    printf("\t%s\t\t", SubjPtr->subjCode);
    printf("\t%s\n", SubjPtr->subjTitle);
}

void deleteSubj(char a[]){
    int i;
    for(i = 0; i <= numbSub; i++){
        if(stringCompare(a, subj[0].subjCode) == 0){
            printf("You cannot delete this subject.\n");
            break;
        }
        if (stringCompare(subj[i].subjCode, a)== 0){
            subj[i] = def;
            printf(" Successful deletion.\n");
            break;
        }
    }
}

void dropSubj(int n){
    int i;
    char a[50];

    for(i = 0; studentPlace[i].studID != n; i++);
        printf("\n\tSubjects of Student            : %s, %s, %s\n\n", studentPlace[i].s1->subjCode, studentPlace[i].s2->subjCode, studentPlace[i].s3->subjCode);
        printf("\tEnter the Subject Code to be Dropped : ");
    scanf(" %s", a);

    if(stringCompare(a, subj[0].subjCode) == 0){
        printf("\t\t Can't drop subject\n");
    }else

    if(stringCompare(studentPlace[i].s2->subjCode, a) == 0){
        printf("\t\t%s is successfully dropped subject\n", studentPlace[i].s2->subjCode);
        studentPlace[i].s2 = studentPlace[i].s3;
        studentPlace[i].s3 = &def;
    }else

    if(stringCompare(studentPlace[i].s3->subjCode, a) == 0){
        printf("\t\t%s is successfully dropped subject\n", studentPlace[i].s3->subjCode);
        studentPlace[i].s3 = &def;
    }else{
        printf("\t\tThis subject does not exist.\n");
    }
}

void writeToText(char file[15]){
    FILE * data;
    data = fopen(file, "w");
    int i;
	for (i = 0; i < number; i++){
        fprintf(data, "%d, %s, %s, %s, %d, %d, %d, %s, %s, %s, %d, %s\n", studentPlace[i].studID, studentPlace[i].firstN, studentPlace[i].lastN, studentPlace[i].section, studentPlace[i].ex1, studentPlace[i].ex2, studentPlace[i].ex3, studentPlace[i].s1->subjCode, studentPlace[i].s2->subjCode, studentPlace[i].s3->subjCode, studentPlace[i].total, studentPlace[i].grade);
        if(studentPlace[i].studID == 0){
            break;
        }
    }
    fclose(data);
    printf(" Exported masterlist file.");
}


//ADDITIONAL FUNCTIONS
//toupper for sub code
char toUpper(char ch){
    char x;
    if(ch >='a'&& ch<='z'){
        x = (ch-32);
    }else{
        x = ch;
    }
    return x;
}

//string compare
int stringCompare(char s1[], char s2[]){
    int t=0;
//to catch the upper case letters
    for(int i=0;s1[i]!='\0';i++){
        if ((s1[i]>='A' && s1[i]<='Z')){
            s1[i] = s1[i] + 32;
        }

        if ((s2[i]>='A' && s2[i]<='Z')){
            s2[i] = s2[i] + 32;
        }
    }

    for(int i=0; s1[i]!='\0'; i++){
        //if one string is shorter than the other
       // printf(" s1 = %s s2 = %s \n", s1[i], s2[i]);
        if (s1[i+1] == '\0' && s2[i+1]!= '\0'){
            t = -1;
            break;
        }

        if(s1[i]>s2[i]){
            t = 1;
           break;
        }
        if(s1[i]<s2[i]){
           t = -1;
            break;
        }
        if(s1[i] == s2[i]){
          t = 0;
        }
    }
    return t;
}
//FILE TO STRUCT THAT MIGHT WORK
void fileToStruct(){
    FILE *fpointer,*pointer2;
    char getFile[50];

    printf("Input the file name: ");
    scanf(" %[^\n]s", &getFile);
	fpointer = fopen(getFile,"r+");
	fclose(fpointer);
    fpointer = fopen(getFile,"a+");
	int numOfdata=0;
	int i=0;

   if(fpointer == NULL){
       printf("Invalid");
   }
		do{

		    fscanf(fpointer," %d, %[^,], %[^,], %[^,], %f, %f, %f, %[^,], %[^,], %[^\n]\n",&studentPlace[i].studID,&studentPlace[i].lastN,&studentPlace[i].firstN,&studentPlace[i].section,&studentPlace[i].ex1,&studentPlace[i].ex2,&studentPlace[i].ex3,&studentPlace[i].s1,&studentPlace[i].s2,&studentPlace[i].s3);

            if(studentPlace[i].studID == 0){
                break;
            }
            numOfdata++;
            i++;

		}while (studentPlace[i-1].studID != 0);

         printf("\nTotal number of students enrolled = [%d]\n\n", numOfdata);


	fclose(fpointer);

    alphaStudents(i);

}
//DISPLAY STUDENT RECORDS
void displayStudent(int num){
    int i;
	for (i = 0; i < num; i++){
        int index1, index2,index3, index4;
        printf("\t%03d  %s", studentPlace[i].studID, studentPlace[i].lastN);
        index1 = strcspn(studentPlace[i].lastN, "\n");
        int j;
		for (j = 1; j <= 23-index1; j++){
            printf(" ");
        }
        printf("%s", studentPlace[i].firstN);
        index1 = strcspn(studentPlace[i].firstN, "\n");
        for (j = 1; j <= 23-index1; j++){
            printf(" ");
        }
        printf("%s", studentPlace[i].section);
        index1 = strcspn(studentPlace[i].section, "\n");
        for (j = 1; j <= 10-index1; j++){
            printf(" ");
        }
        printf("%s,", studentPlace[i].s1->subjCode);
        index1 = strcspn(studentPlace[i].s1->subjCode, "\n");
        printf("%s,", studentPlace[i].s2->subjCode);
        index2 = strcspn(studentPlace[i].s2->subjCode, "\n");
        printf("%s", studentPlace[i].s3->subjCode);
        index3 = strcspn(studentPlace[i].s3->subjCode, "\n");
        for (j = 1; j <= 30-index1-index2-index3-2; j++){
            printf(" ");
        }
        printf("%d      %d      %d      %d     %s\n", studentPlace[i].ex1, studentPlace[i].ex2, studentPlace[i].ex3,studentPlace[i].total,studentPlace[i].grade);
    }

}

//Search Subject
int findSubj(char a[10]){
    int follow = 0;
    int i, n;
    for(i = 0; i <= numbSub; i++){
        if(stringCompare(a, subj[i].subjCode)== 0){
            singleSubj(i);
            n=i;
            break;
        }else{
            follow++;
        }
        if(follow == numbSub){
            printf("This subject does not exist.\n");
        }
    }
    return n;
}

void singleSubj(int x){
    printf("\t%04d\t\t", subj[x].subjID);
    printf("\t%s\t\t", subj[x].subjCode);
    printf("\t%s\n", subj[x].subjTitle);
}

//IMPORT FILE
void structToFile(){
    int i;
    FILE *fPointer, *fPointer2;
    //fpointer reads the file with r+
    fPointer = fopen("database.txt","r+");
    //fpointer2 makes the file with w+
    fPointer2 = fopen("add.txt","w+");
    fclose(fPointer);
    fclose(fPointer2);
    //closes the file
    rename("temp.txt","database.txt");

    //a+ edits the file, you can add on it.
    int numOfdata;
    for(i=0;i<numOfdata;i++) {
        char array1[100]={};
        char input[100]={};

        sprintf(input, "%d", studentPlace[i].studID);
			strcat(array1,",");
		sprintf(input, "%s", studentPlace[i].lastN);
			strcat(studentPlace,input);
			strcat(array1,",");
		sprintf(input, "%s", studentPlace[i].firstN);
			strcat(array1,",");
		sprintf(input, "%s", studentPlace[i].section);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", studentPlace[i].s1);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", studentPlace[i].s2);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%s", studentPlace[i].s3);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", studentPlace[i].ex1);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", studentPlace[i].ex2);
			strcat(array1,input);
			strcat(array1,",");
		sprintf(input, "%f", studentPlace[i].ex3);
			strcat(array1,input);
				if(i==0) {
					fprintf(fPointer, "%s", array1);
				} else {
					fprintf(fPointer, "\n%s", array1);
				}
		}
	fclose(fPointer);


    };

//FOR FINDING SUBJECTS FUNCTION
 int findSubj1(char a[10]){
    int n, found = -1;

    for (n = 0; n <= numbSub; n++){
        if(stringCompare1(subj[n].subjCode, a) == 0){
            found = 1;
            break;
        }
    }

    if(found == -1){
        return -1;
    }else{
        return n;
    }
}

//STRING COMPARE FOR A function
int stringCompare1(char s1[], char s2[]){
    int num, i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
        i++;

    if(toLower(s1[i]) < toLower(s2[i])){
            printf(" heow?");
        return -1;
    }else if(toLower(s1[i]) > toLower(s2[i])){
        printf(" huhu ");
        return 1;
    }else{return 0;}
    }
}
char toLower(char ch){
    if(ch >= 'a' && ch<= 'z'){
        return ch;
    }else{
        return(ch + 32);
    }
}
void inputSub(char file[15]){
    FILE * data;
    data = fopen(file, "r");
    if ((data = fopen(file, "r")) == NULL){
        printf("\n\t                                                                     I N V A L I D    F I L E                                                        ");
        printf("\n\t=====================================================================================================================================================");
    }else{
    while(!feof(data) && numbSub <= 21){
    fscanf(data, "%d, %[^,], %[^\n]", &subj[numbSub].subjID, subj[numbSub].subjCode, subj[numbSub].subjTitle);
    if(subj[numbSub].subjID == 0){
            break;
    }
    ++numbSub;
    }
    printf("\n\t                                        S U C C E S S F U L L Y    I M P O R T E D    S U B J E C T    R E C O R D    F I L E                        ");
    printf("\n\t=====================================================================================================================================================");
    }
}

int toInteger(char st[]){
    int x=0, pos=1;
    //to check if number is negative or positive
    if(st[0]== '-'){
        pos= -1;
    }
    //minus 48 because 48 is ASCII for 0
    for(int i = 0; st[i]!='\0'; i++){
        if(st[i]!= '-'){
            //to only return an integer.
            if(st[i]!= '.'){
                x *= 10;
                x = x + st[i]-48;
            }else{
                break;
            }
        }
    }

    return x*pos;
}
void stringCopy(char src[], char dest[]){
    for(int i=0; src[i]!='\0' ;i++){
            dest[i]=src[i];
        }

}

int aStrcmp(char s1[], char s2[]){
    int i, compare;
    for (i = 0; s1[i] != '\0'; i++){
        if (toLower(s1[i]) == toLower(s2[i])){
            compare = 0;
        }else if (toLower(s1[i]) < toLower(s2[i])){
            compare = -1;
            break;
        }else{
            compare = 1;
            break;
        }
    }
    return(compare);
};
