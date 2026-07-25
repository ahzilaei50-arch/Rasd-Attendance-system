#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// هيكل لتمثيل بيانات الطالب
struct Student {
    string name;
    bool isPresent;
};

// دالة لرسم خط فاصل لتنظيم العرض
void drawLine(int n) {
    for (int i = 0; i < n; i++) cout << "-";
    cout << endl;
}

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "\n--- نظام رصد لحضور وغياب الطلاب ---\n";
        cout << "1. إضافة طلاب جدد\n";
        cout << "2. تسجيل الحضور والغياب\n";
        cout << "3. عرض تقرير الحضور\n";
        cout << "4. خروج\n";
        cout << "----------------------------------\n";
        cout << "اختر رقم العملية: ";
        
        // التحقق من صحة المدخلات الرقمية
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            int num;
            cout << "كم عدد الطلاب الذين تريد إضافتهم؟ ";
            cin >> num;
            for (int i = 0; i < num; i++) {
                Student s;
                cout << "أدخل اسم الطالب " << i + 1 << ": ";
                cin.ignore();
                getline(cin, s.name);
                s.isPresent = false; // القيمة الافتراضية غائب
                students.push_back(s);
            }
            cout << "\nتمت إضافة الطلاب بنجاح!\n";
        } 
        else if (choice == 2) {
            if (students.empty()) {
                cout << "\nلا يوجد طلاب مسجلين حالياً!\n";
            } else {
                for (int i = 0; i < students.size(); i++) {
                    char status;
                    cout << "هل الطالب [" << students[i].name << "] حاضر؟ (y/n): ";
                    cin >> status;
                    students[i].isPresent = (status == 'y' || status == 'Y');
                }
                cout << "\nتم تسجيل الحضور بنجاح!\n";
            }
        } 
        else if (choice == 3) {
            if (students.empty()) {
                cout << "\nالقائمة فارغة! لا يوجد بيانات لعرضها.\n";
            } else {
                cout << "\n--- تقرير الحضور والغياب ---\n";
                cout << left << setw(20) << "اسم الطالب" << "الحالة" << endl;
                drawLine(35);
                int count = 0;
                for (const auto& s : students) {
                    cout << left << setw(20) << s.name << (s.isPresent ? "حاضر" : "غائب") << endl;
                    if (s.isPresent) count++;
                }
                drawLine(35);
                cout << "إجمالي الحضور: " << count << " من " << students.size() << endl;
            }
        } 
        else if (choice == 4) {
            cout << "\nشكراً لاستخدامك نظام رصد. مع السلامة!\n";
            break;
        } 
        else {
            cout << "\nاختيار غير صحيح، حاول مرة أخرى.\n";
        }
    }

    return 0;
}
