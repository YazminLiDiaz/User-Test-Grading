#include <iostream>
IPO CHART:
/*
INPUT
        Applicant name
        Entering letters from A through D on 20 multiple choice questions
PROCESSING
        The program should allow a test taker to enter 20 answers on the multiple choice
        Stores the test taker's exam answers in a 20-character array (or string)
        Calls the setkey function and the grade function to grade the exam.
        Compares the test taker's answers to the correct exam answers
        Count the number of questions the test takers got right and wrong
        Determine if the test taker pass or fail the exam
        Display the test grading results
OUTPUT
        Display if the test taker pass or fail the exam
        Total number of correctly answered questions
        Total number of incorrectly answered questions
        List of the question numbers for all incorrectly answered questions
Ask if the user wants to have additional tests to be entered and graded

*/


#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

class TestGrader

{

private:

//Creating answers array (or string) of 20 characters
//that holds the correct test answers.
    string answers[20];


public:

//Two public member functions that enable user programs
// to interact with the class: setKey and grade

    void setKey(string[]);
    void grade(string[]);


};


//Having the setKey function to receive a 20-character string that
//holds the correct exam answers and copies that information into its answers array

void TestGrader::setKey(string correct_test_answers[])

{

    for (int Question_Number = 0; Question_Number < 20; Question_Number++)

    {
        answers[Question_Number] = correct_test_answers[Question_Number];

    }

}


//The Grading function receives a 20-character string holding
//the test taker's answers and compares each of their answers to the correct ones.

void TestGrader::grade(string Test_Takers_answers[])

{

    int Right_Answer = 0;
    int Wrong_Answer = 0;
    int Count = 0;

    //Setting up a loop that counts up to 20 multiple choice questions
    for (int Question_Number = 0; Question_Number < 20; Question_Number++)

    {

        //Counting the number of right answers on the exam
        if (Test_Takers_answers[Question_Number] == answers[Question_Number])

        {
            Right_Answer += 1;
            Count += 1;

        }

            //Counting the number of wrong answers on the exam
        else if (Test_Takers_answers[Question_Number] != answers[Question_Number])

        {
            Wrong_Answer += 1;

        }

    }


    //Determine if the test taker (or appilcant) has pass or fail the driver's license exam
    //The test taker must have 15 or more correct answers in order to pass the exam
    if (Count >= 15)

    {
        cout << "\n";
        cout << "Congratulations. You passed the exam." << "\n";
        cout << endl;

    }

    else

    {
        cout << "\n";
        cout << "Sorry. You failed the exam." << "\n";
    }

    //Displaying the total number of right answered questions
    cout << "You got " << Right_Answer << " questions correct." << "\n";


    //Displaying the total number of wrong answered questions
    cout << "You missed the following " << Wrong_Answer << " questions: ";


    for (int Question_Number = 0; Question_Number < 20; Question_Number++)

    {

        //Displaying the list of all incorrectly answered question numbers
        //By counting through the array list to see what question numbers the test taker got wrong
        if (Test_Takers_answers[Question_Number] != answers[Question_Number])


        {
            cout << Question_Number + 1 << " ";

        }

    }

    cout << "\n";

}



int main()

{
    string choice;
    string name;

    //String that holds 20 characters of correct test answers
    string answers[20] = {"B", "D", "A", "A", "C", "A", "B", "A", "C", "D",

                          "B", "C", "D", "A", "D", "C", "C", "B", "D", "A"};

    TestGrader License_Exam;

    //Calling the setKey function to pass a string that contains the 20 correct test answers
    License_Exam.setKey(answers);

    //Setting up an empty array (or string) for test takers
    //to fill in a 20-character array when answering the questions on the exam
    string Test_Takers_Answers[20];


    do

    {

        cout << "Applicant name: ";
        getline(cin, name);

        cout << "Enter answers for " << name << ".";
        cout << endl;

        cout << "Use only letters A, B, C, and D." << "\n";
        cout << endl;


        for (int Question_Number = 0; Question_Number < 20; Question_Number++)

        {
            //Allowing the test taker to enter in 20 answers
            cout << "Q " << Question_Number + 1 << ": ";
            cin >> Test_Takers_Answers[Question_Number];


            //Determine if the test taker enter in A, B, C, and D for test answers
            //When I try to use the toupper from <cctype>, it gives me errors. I couldn't figure out why
            // it won't let me use toupper from <cctype>. So I did it a different way by comparing not equal signs with lower and upper case letters

            while (! ((Test_Takers_Answers[Question_Number] >= "a" && Test_Takers_Answers[Question_Number] <= "d")
                      || (Test_Takers_Answers[Question_Number] >= "A" && Test_Takers_Answers[Question_Number] <= "D")))
            {
                cout << "Error! Please enter letters from A - D: ";
                cin >> Test_Takers_Answers[Question_Number];

            }

        }

        cout << endl;

        //Calling the grade function to grade the exam
        cout << "Results for " << name;
        License_Exam.grade(Test_Takers_Answers);

        cout << "\n";

        //Asking if the user wants to have additional tests to be entered and graded
        cout << "Grade another exam (Y/N)?: ";
        cin >> choice;

        cin.ignore();
        cout << "\n";


    } while (choice == "Y" || choice == "y");


    return 0;

}
