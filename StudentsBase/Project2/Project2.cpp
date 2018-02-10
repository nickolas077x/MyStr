#include "stdafx.h"
#include <iostream>

struct Student {
    char person[20];
    char discipline[20];
    int mark;
};

//функция для обнуления i-го элемента массива
void ZeroStudent(Student* student) {
    for (size_t i = 0; i < sizeof(student->person) / sizeof(char); i++) {
        student->person[i] = 0;
    }
    for (size_t i = 0; i < sizeof(student->discipline) / sizeof(char); i++) {
        student->discipline[i] = 0;
    }
    student->mark = 0;
}

//функция для инициализации массива
void ZeroArrayOfStudents(Student* arrayOfStudents, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        ZeroStudent(&arrayOfStudents[i]);
    }
}

//структура для задания i-го элемента массива
void InitiliseStudent(Student* student, const char* person, const char* discipline, int mark) {
    size_t sizeOfPerson = sizeof(student->person) / sizeof(char);
    size_t sizeOfDiscipline = sizeof(student->discipline) / sizeof(char);

    strncpy(student->person, person, sizeOfPerson);
    student->person[sizeOfPerson - 1] = '\0';

    strncpy(student->discipline, discipline, sizeOfDiscipline);
    student->discipline[sizeOfDiscipline - 1] = '\0';
    student->mark = mark;

}

//вывода всех элементов i-го элемента массива на экран
void Output(Student* student) {
    std::cout << student->person << " ";
    std::cout << student->discipline << " ";
    std::cout << student->mark << "\n";
}

// вывода всего массива на экран
void OutputAll(Student* arrayOfStudents, size_t size) {
    for (size_t i = 0; i < size; i++) {
        Output(&arrayOfStudents[i]);
    }
}
// функцию для подсчета среднего бала для указанного по фамилии человека
double CalculateAverageMark(Student* arrayOfStudents, size_t size, const char* person) {
    double m = 0;
    int q = 0;


    for (size_t i = 0; i < size; i++) {

        int areEqual = strcmp(arrayOfStudents[i].person, person);
        if (areEqual == 0) {
            m += arrayOfStudents[i].mark;
            q++;
        }

    }
    return m / q;
}


int main() {
    Student StudBase[10];
    ZeroArrayOfStudents(StudBase, 10);

    for (int i = 0; i < 5; i++) {
        InitiliseStudent(&StudBase[i], "Ivanov", "Russian Language", i);
    }
    InitiliseStudent(&StudBase[5], "Petrov", "VeryVeryVeryVeryVeryVeryVeryLongSubject", 0);
    InitiliseStudent(&StudBase[6], "Sidorof", "Russian Languag", 3);
    InitiliseStudent(&StudBase[7], "Sidorof", "Math", 4);
    InitiliseStudent(&StudBase[8], "Sidorof", "Phisics", 5);
    InitiliseStudent(&StudBase[9], "Sidorof", "Philosophy", 7);


    OutputAll(StudBase, 10);
    std::cout << CalculateAverageMark(StudBase, 10, "Sidorof");

    getchar();
    return 0;
}
