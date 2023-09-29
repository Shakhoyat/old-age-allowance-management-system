//*******************************OOP FINAL PROJECT*******************
//*************************BY MD.SHAKHOYAT RAHMAN**************
//******************************ROLL:2107104**************************
//************************OLD_AGE_ALLOWANCE_MANAGEMENT****************
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class dummy // Abstract class
{
protected:
    string name;

public:
    virtual string getName() const = 0; // Pure Virtual Function
};
class applicant : public dummy // use of Inheritance
{
protected:
    string name;
    string dateOfBirth;
    string NID_no;
    string gender;
    string fatherName;
    string motherName;
public:
    // using Constructor in inheritance
    applicant(const string &name, const string &dateOfBirth, const string &NID_no, const string &gender,
              const string &fatherName, const string &motherName)
    {
        this->name = name;
        this->dateOfBirth = dateOfBirth;
        this->NID_no = NID_no;
        this->gender = gender;
        this->fatherName = fatherName;
        this->motherName = motherName;
    }
    virtual string getName() const // Definition of previous  pure virtual function
    {
        return name;
    }
    string getDateOfBirth() const // Getter functions
    {
        return dateOfBirth;
    }
    string getNID_no() const
    {
        return NID_no;
    }
    string get_gender() const
    {
        return gender;
    }
    string getFatherName() const
    {
        return fatherName;
    }

    string getMotherName() const
    {
        return motherName;
    }
};
template <class T> // use of Template in greaterThan function
bool greaterThan(T a, T b)
{
    return a > b;
}
class eligible : public applicant // Inheriting applicant class publicly in eligible class
{

public:
    string getName() const
    {
        return name;
    }

    // Constructor
    eligible(const string &name, const string &dateOfBirth, const string &NID_no, const string &gender,
             const string &fatherName, const string &motherName) : applicant(name, dateOfBirth, NID_no, gender, fatherName, motherName) {}

    // Overloaded << operator for eligible class
    friend ostream &operator<<(ostream &os, eligible &eligible)
    {
        os << "Eligible Candidate Name: " << eligible.getName() << endl;
        os << "Date of Birth: " << eligible.getDateOfBirth() << endl;
        os << "NID_no: " << eligible.getNID_no() << endl;
        os << "gender: " << eligible.get_gender() << endl;
        os << "Father's Name: " << eligible.getFatherName() << endl;
        os << "Mother's Name: " << eligible.getMotherName() << endl;
        return os;
    }
};
class non_eligible : public applicant // Inheriting applicant class publicly in non_eligible class
{
public:
    string getName() const
    {
        return name;
    }

    // Constructor
    non_eligible(const string &name, const string &dateOfBirth, const string &NID_no, const string &gender,
                 const string &fatherName, const string &motherName)

        : applicant(name, dateOfBirth, NID_no, gender, fatherName, motherName)
    {
    }

    // Overloaded << operator for non_eligible class using friend 
    friend ostream &operator<<(ostream &os, const non_eligible &non_eligible)
    {
        os << "Non_Eligible Candidate Name: " << non_eligible.getName() << endl;
        os << "Date of Birth: " << non_eligible.getDateOfBirth() << endl;
        os << "NID_no: " << non_eligible.getNID_no() << endl;
        os << "gender: " << non_eligible.get_gender() << endl;
        os << "Father's Name: " << non_eligible.getFatherName() << endl;
        os << "Mother's Name: " << non_eligible.getMotherName() << endl;
        return os;
    }
};
bool isAbove65(const string &dateOfBirth)
{
    string currentDate = "2023-09-24";

    // Compare the birth date with the current date
    // Assuming the date format is "yyyy-mm-dd"
    string yearOfBirth = dateOfBirth.substr(0, 4);
    string yearOfCurrentDate = currentDate.substr(0, 4);

    int age = std::stoi(yearOfCurrentDate) - std::stoi(yearOfBirth);
    return greaterThan(age, 65); // use of templatized function
}
bool isAbove62(const string &dateOfBirth)
{
    string currentDate = "2023-09-24";

    // Compare the birth date with the current date
    // Assuming the date format is "yyyy-mm-dd"
    string yearOfBirth = dateOfBirth.substr(0, 4);
    string yearOfCurrentDate = currentDate.substr(0, 4);

    int age = stoi(yearOfCurrentDate) - stoi(yearOfBirth);
    return greaterThan(age, 62); // use of templatized function
}
int main()
{
    ifstream inputFile("input.txt"); // Open the input file
    string s, s1 = "eligible", s2 = "non_eligible";
    vector<eligible> vi;      // declaring vector for eligible class(using STL)
    vector<non_eligible> nvi; // declaring vector for non_eligible class
    if (!inputFile)           // checking in case the program failed to open the file
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    string inputType, name, dateOfBirth, fatherName, motherName, gender, NID_no;
    string tmp;
    // Read and process each set of data from the file
    while (inputFile >> inputType)
    {
        // Read the person's data line by line
        inputFile.ignore(); // Ignore the newline character
        getline(inputFile, name);
        getline(inputFile, dateOfBirth);
        getline(inputFile, NID_no);
        getline(inputFile, gender);
        getline(inputFile, fatherName);
        getline(inputFile, motherName);
        if (isAbove65(dateOfBirth) and gender == "male")
        // According to Bangladeshi Law the age criteria for Old-Age-Allowance (male) is  65 years
        {
            // Create an instance of eligible with the read data
            eligible eligible(name, dateOfBirth, NID_no, gender, fatherName, motherName);
            // Access and display the information using overloaded operator
            vi.push_back(eligible);
        }
        else if (isAbove62(dateOfBirth) and gender == "female")
        // According to Bangladeshi Law the age criteria for Old-Age-Allowance (female) is  62 years
        { // Create an instance of eligible with the read data
            eligible eligible(name, dateOfBirth, NID_no, gender, fatherName, motherName);
            // Access and display the information using overloaded operator
            vi.push_back(eligible);
        }
        else
        {
            // Create an instance of eligible with the read data
            non_eligible non_eligible(name, dateOfBirth, NID_no, gender, fatherName, motherName);
            // Access and display the information using overloaded operator
            nvi.push_back(non_eligible);
        }
    }
    string j;
    j = "Yes";
    while (j == "Yes") // showing option for the user
    {
        cout << "What do you want to see:(list/profile)" << endl;
        cin >> s;
        if (s == "list")
        {
            cout << "What kind of list:(all/eligible/non_eligible)" << endl;
            cin >> s;
            int c = 0;
            if (s == "all")
            {
                c = 1;
                cout << "\nTotal candidate in the list" << endl;
                cout << vi.size() + nvi.size() << endl;
            }
            if (s == s1 || c)
            {
                if (!c)
                {
                    cout << "\nTotal Number of eligible candidate in the list" << endl;
                    cout << vi.size() << endl;
                }
                for (auto x : vi)
                {
                    cout << x << endl;
                }
            }
            if (s == s2 || c)
            {
                if (!c)
                {
                    cout << "\nTotal Number of non_eligible candidate in the list" << endl;
                    cout << nvi.size() << endl;
                }
                for (auto x : nvi)
                    cout << x << endl;
            }
        }
        else
        {  //Implementation part for the profile wise search option
            cin.ignore(); // Ignore the newline character
            string dob;   // date of birth as string
            string name;
            string gender;
            cout << "Enter Name:\n ";
            getline(cin, name);
            cout << "Enter NID Number:\n ";
            getline(cin, NID_no);
            cout << "Enter gender:\n ";
            getline(cin, gender);
            cout << "Enter date of birth (yyyy-mm-dd):\n ";
            getline(cin, dob);
            int i, k = 0;
            if ((isAbove62(dob) and gender == "female") or (isAbove65(dob) and gender == "male"))
            {

                for (i = 0; i < vi.size(); i++)
                {
                    if (vi[i].getNID_no() == NID_no)
                    {
                        cout << "\n\nType: ELIGIBLE CANDIDATE" << endl;
                        cout << vi[i] << endl;
                        k = 1;
                    }
                }
            }
            else
            {

                for (i = 0; i < nvi.size(); i++)
                {
                    if (nvi[i].getNID_no() == NID_no)
                    {
                        cout << "\n\nType: NOT ELIGIBLE CANDIDATE" << endl;
                        cout << nvi[i] << endl;
                        k = 1;
                    }
                }
            }

            if (!k)
                cout << "\n SORRY ENTERED CANDIDATE  NOT_FOUND.Please try entering info with proper spacing and use proper case \n"
                     << endl;
        }
        cout << "Do you want to see more (Yes/No): ";
        cin >> j;
        if (j != "Yes")
            break;
        cout << endl;
    }
    inputFile.close(); // Close the input file after usage

    return 0;
}