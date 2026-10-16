#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
    string surname;
    array<int, 4> grades{};
};

int main() {
    const int STUDENTS = 10;
    const int SUBJECTS = 4;

    const array<string, SUBJECTS> subjectNames = {
        "Інформатика",
        "Вища математика",
        "Фізика",
        "Програмування"
    };

    vector<Student> group(STUDENTS);

    for (int i = 0; i < STUDENTS; ++i) {
        getline(cin >> ws, group[i].surname);

        for (int j = 0; j < SUBJECTS; ++j) {
            cin >> group[i].grades[j];
        }
    }

    int count[SUBJECTS][4] = {};

    for (const Student& student : group) {
        for (int subject = 0; subject < SUBJECTS; ++subject) {
            int grade = student.grades[subject];

            if (grade >= 2 && grade <= 5) {
                count[subject][grade - 2]++;
            }
        }
    }

    cout << "Кількість оцінок 2, 3, 4, 5 з кожної дисципліни:\n\n";

    cout << left
         << setw(20) << "Дисципліна"
         << setw(8) << "2"
         << setw(8) << "3"
         << setw(8) << "4"
         << setw(8) << "5" << '\n';

    cout << string(52, '-') << '\n';

    for (int subject = 0; subject < SUBJECTS; ++subject) {
        cout << left
             << setw(20) << subjectNames[subject]
             << setw(8) << count[subject][0]
             << setw(8) << count[subject][1]
             << setw(8) << count[subject][2]
             << setw(8) << count[subject][3]
             << '\n';
    }

    return 0;
}
