#include <iostream> // Cout Cin
#include <Windows.h> // Для использования русского языка
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iomanip> // setw и т.д.


struct person
{
    int age;
    char name[20];
};




using namespace std;



//---------------------------Создание файла и запись в файл------------------------------------

void create_file(const char* fname)
{

    setlocale(LC_ALL, "Russian");

    FILE* fwriter = fopen(fname, "a");


    char hello[50];
    char dad[10];
    cout << "Введите то что хотите помесить в массив.Помещается в конец файла.";
    cin.get(hello, 50);
    cin.get();
    cin.get(dad, 5);
    fputs(hello, fwriter);
    fseek(fwriter, 0, SEEK_SET);
     fputs(dad, fwriter);
     fclose(fwriter);
}




void Sort(const char* fname)
{
   char aro1;


    FILE* freader = fopen(fname, "r+");
    long sizer = ftell(freader);
    rewind (freader);
    fseek(freader, 2, SEEK_SET);
    fread(&aro1, 1, sizeof(char), freader);
    fseek(freader, 0, SEEK_END);
    fwrite(&aro1, 1, sizeof(char), freader);
}


int main()
{

    struct person people[] = { 40,"Ivan",10,"John",18,"Eick" };
    int n = sizeof(people) / sizeof(people[0]);
    for(int i=0;i<n;i++)
    {
        cout << "Name  :" << people[i].name << "    Age   :" <<people[i].age<<"\n";
    }






    const char* fname = "main.txt";
   
    
     create_file(fname);
     Sort(fname);
}



