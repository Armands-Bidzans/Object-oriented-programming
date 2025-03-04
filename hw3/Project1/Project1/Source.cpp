#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const short MAX_STUDENTS = 100;
const short MAX_SUBJECTS = 20;

class Subject {
public:
    string name;
};

class Student {
public:
    string name;
    short grades[MAX_SUBJECTS];

    Student() {
        for (short i = 0; i < MAX_SUBJECTS; i++) {
            grades[i] = 0;
        }
    }
};

class Group {
public:
    string name;
    Student students[MAX_STUDENTS];
    Subject subjects[MAX_SUBJECTS];
    short studentCount;
    short subjectCount;

    Group() {
        studentCount = 0;
        subjectCount = 0;
    }

    void loadStudents(string filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Unable to open students file: " << filename << endl;
            exit(1);
        }
        while (studentCount < MAX_STUDENTS && getline(file, students[studentCount].name)) {
            studentCount++;
        }
        file.close();
    }

    void loadSubjects(string filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Unable to open subjects file: " << filename << endl;
            exit(1);
        }
        while (subjectCount < MAX_SUBJECTS && getline(file, subjects[subjectCount].name)) {
            subjectCount++;
        }
        file.close();
    }

    void loadGrades(string filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Unable to open grades file: " << filename << endl;
            exit(1);
        }
        for (short i = 0; i < studentCount; i++) {
            for (short j = 0; j < subjectCount; j++) {
                if (!(file >> students[i].grades[j])) {
                    cerr << "Error reading grades from file: " << filename << endl;
                    exit(1);
                }
            }
        }
        file.close();
    }

    void printReport() {
        cout << "\nStudent grades:" << endl;
        for (short j = 0; j < subjectCount; j++) {
            cout << subjects[j].name << " ";
        }
        cout << endl;
        for (short i = 0; i < studentCount; i++) {
            cout << students[i].name << " ";
            for (short j = 0; j < subjectCount; j++) {
                cout << students[i].grades[j] << " ";
            }
            cout << endl;
        }

        cout << "\nAverage grades of students:" << endl;
        for (short i = 0; i < studentCount; i++) {
            short sum = 0;
            for (short j = 0; j < subjectCount; j++) {
                sum += students[i].grades[j];
            }
            cout << students[i].name << ": " << (sum / subjectCount) << endl;
        }

        cout << "\nAverage grades by subject:" << endl;
        for (short j = 0; j < subjectCount; j++) {
            short sum = 0;
            for (short i = 0; i < studentCount; i++) {
                sum += students[i].grades[j];
            }
            cout << subjects[j].name << ": " << (sum / studentCount) << endl;
        }

        cout << "\nGroup average grade:" << endl;
        short totalSum = 0;
        short totalCount = studentCount * subjectCount;
        for (short i = 0; i < studentCount; i++) {
            for (short j = 0; j < subjectCount; j++) {
                totalSum += students[i].grades[j];
            }
        }
        cout << "Overall average grade: " << (totalSum / totalCount) << endl;

        cout << "\nMaximum and minimum grades:" << endl;
        for (short j = 0; j < subjectCount; j++) {
            short maxGrade = 0, minGrade = 10;
            string maxStudent, minStudent;
            for (short i = 0; i < studentCount; i++) {
                if (students[i].grades[j] > maxGrade) {
                    maxGrade = students[i].grades[j];
                    maxStudent = students[i].name;
                }
                if (students[i].grades[j] < minGrade) {
                    minGrade = students[i].grades[j];
                    minStudent = students[i].name;
                }
            }
            cout << subjects[j].name << " - Max: " << maxGrade << " (" << maxStudent << "), Min: " << minGrade << " (" << minStudent << ")\n";
        }
    }
};

int main() {
    Group group;
    string studentFile, subjectFile, gradesFile;
    cout << "Enter the student file name: ";
    cin >> studentFile;
    cout << "Enter the subject file name: ";
    cin >> subjectFile;
    cout << "Enter the grades file name: ";
    cin >> gradesFile;

    group.loadStudents(studentFile);
    group.loadSubjects(subjectFile);
    group.loadGrades(gradesFile);

    group.printReport();
    return 0;
}
