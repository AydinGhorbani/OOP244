//Full Name  : Aydin Ghorabni
//Student ID#: 124226170
//Email      : aghorbani8@museneca.ca
//Date       : May 28rd, 2023
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation.



#include "Population.h"
#include "File.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {

int noOfPop;
Population* population;
void sort()
{
    int i, j;
    Population temp;
    for (i = noOfPop - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
                if (population[j].pop > population[j + 1].pop)
                {
                    temp = population[j];
                    population[j] = population[j + 1];
                    population[j + 1] = temp;
                }
            }
        }
    }
bool load(Population& st)
{
    bool ok = false;
    char name[128];
    if (1)
    {
        ok = read(name);
        ok = ok && read(st.pop);
        st.pCode = new char[strlen(name) + 1];
        strcpy(st.pCode, name);
    }
    return ok;
}
bool load(const char* filename)
{
    bool ok = false;
    int i = 0;
    if (openFile(filename))
    {
        ok = true;
        noOfPop = noOfRecords();
        population = new Population[noOfPop];
        for (i = 0; ok && i < noOfPop; i++)
        {
            ok = ok && load(population[i]);
            }
            if (!ok)
            {
            cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                ok = true;
            }
        closeFile();
        }
    return ok;
}



void display(Population& st)
{
    cout << st.pCode << ":  " << st.pop << endl;
}
void display()
{
    sort();
    cout << "Postal Code: population" << endl;
    cout << "-------------------------" << endl;
    int i, j;
    long total = 0;
    for (i = 0, j = 1; i < noOfPop; i++)
    {
        cout << j++ << "- ";
        display(population[i]);
        total += population[i].pop;
    }
    cout << "-------------------------" << endl;
    cout << "Population of Canada: " << total << endl;
}
// TODO: Implementation for the deallocateMemory function goes here
void deallocateMemory()
{
    int i = 0;
    while (i < noOfPop)
    {
        delete[] population[i].pCode;
        population[i].pCode = nullptr;
        i++;
    }
    delete[] population;
    return;
    
    
    }

}


