#include <bits/stdc++.h>
using namespace std;

class Student;
class Course;
class RegistrationRecord;

class Student
{
private:
    string studentId;
    string studentName;

public:
    ~Student()
    {
        studentId.resize(0);
        studentName.resize(0);
    }

    Student(string id, string name) : studentId(id), studentName(name) {}

    string getStudentId()
    {
        return studentId;
    }

    string getStudentName()
    {
        return studentName;
    }

    void show()
    {
        cout << "Student ID: " << studentId << "\n";
        cout << "Student Name: " << studentName << "\n";
    }

    friend class University;
    friend class InputManager;
    friend class RegistrationRecord;
};

class Course
{
private:
    string courseCode;
    string courseName;
    int maxSeats;
    int enrolledStudents;

public:
    ~Course()
    {
        courseCode.resize(0);
        courseName.resize(0);
    }

    Course(string code, string name, int maxSeats) : courseCode(code), courseName(name), maxSeats(maxSeats), enrolledStudents(0) {}

    string getCourseCode()
    {
        return courseCode;
    }

    string getCourseName()
    {
        return courseName;
    }

    int getMaxSeats()
    {
        return maxSeats;
    }

    int getEnrolledStudents()
    {
        return enrolledStudents;
    }

    void add_students(int num)
    {
        enrolledStudents += num;
    }

    void show()
    {
        cout << "Course Code: " << courseCode << "\n";
        cout << "Course Name: " << courseName << "\n";
        cout << "Max Seats: " << maxSeats << "\n";
        cout << "Enrolled Students: " << enrolledStudents << "\n";
    }

    friend class University;
    friend class InputManager;
};

class RegistrationRecord
{
private:
    Student student;
    Course course;

public:
    RegistrationRecord(const Student &s, const Course &c) : student(s), course(c) {}

    void show()
    {
        student.show();
        course.show();
    }

    friend class University;
};

class University
{
private:
    vector<Course> courses;
    vector<Student> students;
    vector<RegistrationRecord> registrations;

public:
    void addCourse(string code, string name, int maxSeats)
    {
        Course newCourse(code, name, maxSeats);
        courses.push_back(newCourse);
    }

    void addStudent(string id, string name)
    {
        Student newStudent(id, name);
        students.push_back(newStudent);
    }

    bool registerStudent(Student &student, Course &course)
    {
        if (course.getEnrolledStudents() < course.getMaxSeats())
        {
            course.add_students(1);
            registrations.emplace_back(RegistrationRecord(student, course));
            cout << "Registration successful: " << student.getStudentName() << " enrolled in " << course.getCourseName() << endl;
            return true;
        }
        else
        {
            cout << "Registration failed: No available seats in " << course.getCourseName() << endl;
            return false;
        }
    }

    void show(string studID)
    {
        for (auto record : registrations)
        {
            if (record.student.getStudentId() == studID)
            {
                record.show();
                break;
            }
            cout << "\n";
        }
    }

    void show()
    {
        for (auto record : registrations)
        {
            record.show();
            cout << "\n";
        }
    }

    friend class InputManager;
};

class InputManager
{
public:
    static Student getStudentInfo()
    {
        string id, name;
        cout << "Enter student ID: ";
        cin >> id;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        return Student(id, name);
    }

    static Course getCourseInfo()
    {
        string code, name;
        int maxSeats;
        cout << "Enter course code: ";
        cin >> code;
        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter maximum seats: ";
        cin >> maxSeats;
        return Course(code, name, maxSeats);
    }
};

int main()
{
    University university;

    cout << "Welcome to University Course Registration System!" << endl;

    while (true)
    {
        cout << "\nMenu:\n0. Exit\n1. Register Student for Course\n2. Show all students\n3. Show student info by ID\n\nSelect an option: ";
        int choice;
        cin >> choice;

        if (choice == 0)
        {
            cout << "Thank you for using the University Course Registration System. Goodbye!" << endl;
            break;
        }
        else if (choice == 1)
        {
            Student student = InputManager::getStudentInfo();
            Course course = InputManager::getCourseInfo();
            university.registerStudent(student, course);
        }
        else if (choice == 2)
        {
            university.show();
        }
        else if (choice == 3)
        {
            string studID;
            cout << "Enter Student ID: ";
            cin >> studID;
            university.show(studID);
        }
        else
        {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
