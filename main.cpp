#include<iostream>#include<conio.h>#include<cstdlib>#include<cstdio>#include<cstring>#include<iomanip>using namespace std;struct Employee {    char lastName[20];    int salary;};struct Position {    char posName[30];    char requirements[50];};struct Company {    int amountOfEmpl;    int amountOfPos;    char companyName[20];    Position position;    Employee employeeCand[10];};int j, i;FILE *fp;void initProp() {    Company companies[5];    char employeeAns, positionAns;    if (fp != nullptr) remove("fp.dat");    else {        fp = fopen("fp.dat", "wb");        i = 0;        do {            cout << "Company name\n";            cin >> companies[i].companyName;            cout << "Position\n";            cin >> companies[i].position.posName;            cout << "Amount of positions\n";            cin >> companies[i].amountOfPos;            cout << "Requirements\n";            cin >> companies[i].position.requirements;            j = 0;            int k = companies[i].amountOfPos;            do {                cout << "Employee candidate last name\n";                cin >> companies[j].employeeCand[j].lastName;                cout << "Salary\n";                cin >> companies[j].employeeCand[j].salary;                j++;                /*cout<<"Add one more employee? y/n\n";                employeeAns = getch();*/                k--;            } while (k != 0/*employeeAns != 'n'*/);            companies[i].amountOfEmpl = j;            cout << "Cont input? y/n\n";            positionAns = getch();            fwrite(&companies[i], sizeof(Company), 1, fp);            i++;        } while (positionAns != 'n');        fclose(fp);    }    getch();}void listOfEmpl() {    Company company;    if (!(fp = fopen("fp.dat", "rb")))//перевірка існування файлу при відкритті        cerr << "File do not exist!";    else {        fread(&company, sizeof(Company), 1, fp); //читання даних з 1 предмету        while (!feof(fp)) {            cout << " " << company.position.posName << endl;            for (int k = 0; k < company.amountOfEmpl; ++k) {                cout.setf(ios::left);                cout << "      " << setw(12) << company.employeeCand[k].lastName << setw(10)                     << company.employeeCand[k].salary << endl;            }            fread(&company,sizeof(Company),1,fp);//читання даних з 1 предмету        }        fclose(fp); //закриття файлу    }    getch();}void outputOfFile() {    Company company;    if (!(fp = fopen("fp.dat", "rb"))) cerr << "File doesn't exist(\n";    else {        cout << setw(20) << "It is file:\n";        fread(&company, sizeof(Company), 1, fp);        while (!feof(fp)) {            cout << "Company     Position    Amount    Requirements\n";            cout.setf(ios::left);            cout << setw(12) << company.companyName << setw(12) << company.position.posName << setw(13)                 << company.amountOfPos                 << setw(12) << company.position.requirements << endl << endl;            cout << "Last name      Salary\n";            for (j = 0; j < company.amountOfEmpl; ++j) {                cout.setf(ios::left);                cout << setw(12) << company.employeeCand[j].lastName << setw(12) << company.employeeCand[j].salary                     << endl;            }            fread(&company, sizeof(Company), 1, fp);        }        fclose(fp);    }    getch();}int main() {    initProp();    cout<<"//////////\n\n";    listOfEmpl();    cout<<"\n///////////\n";    outputOfFile();    return 0;}