#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iomanip>

using namespace std;

struct Employee {
    char lastName[20];
    int salary;
};
struct Position {
    char posName[30];
    int amountOfPos;
    char requirements[50];
};
struct Company {
    Employee employeeCand[5];
    int employeeCandAvail;
    Position position;
    char companyName[20];
};
int employeeAmount, positionAmount;
FILE *fp;

void initProp() {
    Company companies[5];
    char employeeAns, positionAns;

    if (fp != nullptr) remove("fp.dat");
    else {
        fp = fopen("fp.dat", "wb");
        positionAmount = 0;
        do {
            cout << "Company name\n";
            cin >> companies[positionAmount].companyName;
            cout << "Position\n";
            cin >> companies[positionAmount].position.posName;
            cout << "Amount of positions\n";
            cin >> companies[positionAmount].position.amountOfPos;
            cout << "Requirements\n";
            cin >> companies[positionAmount].position.requirements;
            employeeAmount = 0;
            int i = companies[positionAmount].position.amountOfPos;
            do {
                cout << "Employee candidate last name\n";
                cin >> companies[employeeAmount].employeeCand[employeeAmount].lastName;
                cout << "Salary\n";
                cin >> companies[employeeAmount].employeeCand[employeeAmount].salary;
                employeeAmount++;
                /*cout<<"Add one more employee? y/n\n";
                employeeAns = getch();*/
                i--;
            } while (i != 0/*employeeAns != 'n'*/);
            companies[positionAmount].employeeCandAvail = employeeAmount;
            cout << "Cont input? y/n\n";
            positionAns = getch();
            fwrite(&companies[positionAmount], sizeof(Company), 1, fp);
            positionAmount++;
        } while (positionAns != 'n');
        fclose(fp);
    }
    getch();
}

void outputOfFile() {
    Company company;
    if (!(fp = fopen("fp.dat", "rb"))) cerr << "File doesn't exist(\n";
    else {
        cout << setw(20) << "It is file:\n";
        fread(&company, sizeof(Company), 1, fp);
        while (!feof(fp)) {
            cout << "Company     Position    Amount    Requirements\n";
            cout.setf(ios::left);
            cout << setw(12) << company.companyName << setw(12) << company.position.posName << setw(13)
                 << company.position.amountOfPos
                 << setw(12) << company.position.requirements << endl;

            cout << "Last name      Salary\n";
            for (int i = 0; i < company.employeeCandAvail; ++i) {
                cout.setf(ios::left);
                cout << setw(12) << company.employeeCand[i].lastName << setw(12) << company.employeeCand[i].salary
                     << endl;
            }
            fread(&company, sizeof(Company), 1, fp);
        }
        fclose(fp);
    }
    getch();
}


int main() {
    initProp();
    outputOfFile();
    return 0;
}