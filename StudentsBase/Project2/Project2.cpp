#include "stdafx.h"
#include <iostream>



class Student {

public:

    char person[20];
    char discipline[20];
    int mark;

    //функция для обнуления i-го элемента массива
    void ZeroStudent() {
        for (size_t i = 0; i < sizeof(person) / sizeof(char); i++) {
            person[i] = 0;
        }
        for (size_t i = 0; i < sizeof(discipline) / sizeof(char); i++) {
            discipline[i] = 0;
        }
        mark = 0;
    }

    //структура для задания i-го элемента массива
    void InitiliseStudent(const char* newPerson, const char* newDiscipline, int newMark) {
        size_t sizeOfPerson = sizeof(person) / sizeof(char);
        size_t sizeOfDiscipline = sizeof(discipline) / sizeof(char);

        strncpy(person, newPerson, sizeOfPerson);
        person[sizeOfPerson - 1] = '\0';

        strncpy(discipline, newDiscipline, sizeOfDiscipline);
        discipline[sizeOfDiscipline - 1] = '\0';
        mark = newMark;

    }

    //вывода всех элементов i-го элемента массива на экран
    void Output() {
        std::cout << person << " ";
        std::cout << discipline << " ";
        std::cout << mark << "\n";
    }
};

class Vedomost {
   
 public:   

    Student students[20];

    //функция для инициализации массива
    void ZeroArrayOfStudents() {
        for (size_t i = 0; i < sizeof(students)/ sizeof(students[0]); i++) {
            students[i].ZeroStudent();
        }
    } 

    // вывода всего массива на экран
    void OutputAll() {
        for (size_t i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
            students[i].Output();
        }
    }
    // функцию для подсчета среднего бала для указанного по фамилии человека
    double CalculateAverageMark(const char* person) {
        double m = 0;
        int q = 0;


        for (size_t i = 0; i < sizeof(students) / sizeof(students[0]); i++) {

            int areEqual = strcmp(students[i].person,person);
            if (areEqual == 0) {
                m += students[i].mark;
                q++;
            }

        }
        return m / q;
    }


};


int main() {
    Vedomost vedomost;


    vedomost.ZeroArrayOfStudents();

    for (int i = 0; i < 5; i++) {
        vedomost.students[i].InitiliseStudent ("Ivanov", "Russian Language", i);
    }
    vedomost.students[5].InitiliseStudent("Petrov", "VeryVeryVeryVeryVeryVeryVeryLongSubject", 0);
    vedomost.students[6].InitiliseStudent("Sidorof", "Russian Languag", 3);
    vedomost.students[7].InitiliseStudent("Sidorof", "Math", 4);
    vedomost.students[8].InitiliseStudent("Sidorof", "Phisics", 5);
    vedomost.students[9].InitiliseStudent("Sidorof", "Philosophy", 7);


    vedomost.OutputAll();
    std::cout << vedomost.CalculateAverageMark("Sidorof");

    getchar();
    return 0;
}
