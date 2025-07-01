#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "TriviaUCA.h"
#include "../util/IntValidation.h"

// Define the Struct that each question will have
struct TriviaQuestion
{
    string question;
    string options[3];
    int correctAnswer;
};

void ShowTriviaUCATitle()
{
    cout << R"(
    
                    ________         __             __                  __    __   ______    ______  
                   /        |       /  |           /  |                /  |  /  | /      \  /      \ 
                   $$$$$$$$/______  $$/  __     __ $$/   ______        $$ |  $$ |/$$$$$$  |/$$$$$$  |
                      $$ | /      \ /  |/  \   /  |/  | /      \       $$ |  $$ |$$ |  $$/ $$ |__$$ |
                      $$ |/$$$$$$  |$$ |$$  \ /$$/ $$ | $$$$$$  |      $$ |  $$ |$$ |      $$    $$ |
                      $$ |$$ |  $$/ $$ | $$  /$$/  $$ | /    $$ |      $$ |  $$ |$$ |   __ $$$$$$$$ |
                      $$ |$$ |      $$ |  $$ $$/   $$ |/$$$$$$$ |      $$ \__$$ |$$ \__/  |$$ |  $$ |
                      $$ |$$ |      $$ |   $$$/    $$ |$$    $$ |      $$    $$/ $$    $$/ $$ |  $$ |
                      $$/ $$/       $$/     $/     $$/  $$$$$$$/        $$$$$$/   $$$$$$/  $$/   $$/ 
    

)";
}

// This function will verify that the question isn't repeated
bool isTheQuestionRepeated(int askedQuestions[], int numberOfAskedQuestions, int indexOfRandomQuestion)
{
    for (int i = 0; i < numberOfAskedQuestions; i++)
    {
        // Verify that the asked question isn't on the array of the random asked questions.
        if (askedQuestions[i] == indexOfRandomQuestion)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Main function, it will handle the trivia's logic. This mini-game will just ask 3 random questions btw
void TriviaUCA()
{

    srand(time(0));

    // Variables
    int NUMBER_OF_QUESTIONS = 13; // The number of questions i've added to the trivia
    int score = 0;
    int userAnswer;
    int askedQuestions[3]; // This array will store the indexes of the asked questions
    int usedQuestions = 0; // This variable will tell how many questions have been used

    /* 2D array with the questions
    The max length of it will be the number of questions that i've added to the trivia
    */
    TriviaQuestion questions[NUMBER_OF_QUESTIONS] = {
        {"En que anio fue fundada la UCA?", {"1963", "1975", "1965"}, 2},
        {"Que dia fue fundada la UCA?", {"2 de febrero", "14 de septiembre", "15 de septiembre"}, 2},
        {"Cuales son los tres pilares de la UCA?", {"Docencia, Investigacion y Proyeccion Social", "Trabajo, Fe e Investigacion", "Trabajo, Fe y Conocimiento"}, 0},
        {"Cuantos auditorios tiene la UCA?", {"1", "2", "3"}, 2},
        {"El campus de la UCA tiene un tamanio aproximado de ...", {"18 manzanas", "21 manzanas", "24 manzanas"}, 1},
        {"Cuantos salones de clase tiene la UCA?", {"110", "115", "120"}, 1},
        {"Como se llama el actual Rector de la UCA?", {"Mario Cornejo", "Andreu Oliva", "Jose Maria Tojeira"}, 0},
        {"Que significan las siglas 'CRAI'?", {"Centro Regional de Apoyo a la Investigacion", "Centro de Recursos para el Aprendizaje y la Investigacion", "Centro de Reflexion Academica Interdisciplinaria"}, 1},
        {"Quien fue el primer Rector de la UCA?", {"Florentino Idoate", "Luis Achaerandio", "Roman Mayorga"}, 0},
        {"Cuantas carreras tiene la Facultad de Ingenieria y Arquitectura?", {"10", "9", "8"}, 0},
        {"Cuantas carreras tiene la Facultad de Ciencias Economicas y Empresariales?", {"6", "7", "8"}, 1},
        {"Cuantas carreras de pre-grado hay en la UCA?", {"30", "29", "28"}, 2},
        {"Cuantas Facultades tiene la UCA?", {"3", "4", "5"}, 1}};

    // Make the three random questions
    for (int i = 0; i < 3; i++)
    {
        int indexOfRandomQuestion; // This variable will store the index of the random question

        // Ask a question that hasn't been asked before
        do
        {
            // This process will be repeated if the question is repeated
            // Generate a random number between 0 and the number of questions - 1
            indexOfRandomQuestion = rand() % NUMBER_OF_QUESTIONS;
        } while (isTheQuestionRepeated(askedQuestions, usedQuestions, indexOfRandomQuestion)); // will be repeated if true

        // This is the process that will be done if the do-while is false
        // Mark the index of the question as used (mark the question as asked)
        askedQuestions[usedQuestions] = indexOfRandomQuestion; // Will store the index of the random asked question in the index of the array with the number of the already asked questions
        usedQuestions++;                                       // +1 in the already asked questions

        // Show the question
        system("cls");        // Clear the console
        ShowTriviaUCATitle(); // Show the title of the game

        cout << "                   +--------------------------------------------------------------------------------+\n";
        cout << "                   Pregunta #" << i + 1 << " " << questions[indexOfRandomQuestion].question << "\n";
        cout << "                   +--------------------------------------------------------------------------------+\n";

        // Show the answers (3 possible answers btw)
        for (int j = 0; j < 3; j++)
        {
            cout << "                   [" << j + 1 << "] " << questions[indexOfRandomQuestion].options[j] << endl;
        }

        // Tell the user to pick a question (1-3)
        cout << "\n\nSelecciona tu respuesta (1-3):\n";

        // Validate the user's answer
        do
        {
            userAnswer = validateInt(); // Validates the int (validates the type)

            // Validate if the int is between 1 and 3
            if (userAnswer < 1 || userAnswer > 3)
            {
                cout << "Por Favor. Ingrese una respuesta (1-3):\n";
            }
        } while (userAnswer < 1 || userAnswer > 3);

        // If the user's answer was validated correctly. Subtract 1 (In order to verify if it is correct or no)
        userAnswer--;

        // Verify if the answer is correct or no
        if (userAnswer == questions[indexOfRandomQuestion].correctAnswer)
        {
            // Correct
            score++;
            cout << "                   +--------------------------------------------------------------------------------+\n";
            cout << "                   Respuesta Correcta\n";
            cout << "                   +--------------------------------------------------------------------------------+\n";
        }
        else
        {
            // Incorrect
            cout << "                   +--------------------------------------------------------------------------------+\n";
            cout << "                   Respuesta Incorrecta\n";
            cout << "                   +--------------------------------------------------------------------------------+\n";
        }

        Sleep(3000); // Pause the execution for 3 seconds, in order to give the user chance to read if the answer was correct or no
    }

    // Finally, show the score
    system("cls");
    ShowTriviaUCATitle();
    cout << "\n                   +--------------------------------------------------------------------------------+\n";
    cout << "                   Puntaje Final: " << score << " Preguntas Contestadas Correctamente.\n";
    cout << "                   +--------------------------------------------------------------------------------+\n\n";
    Sleep(5000);
}
