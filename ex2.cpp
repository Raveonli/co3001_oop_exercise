#include <iostream>
#include <string>
class Person {
protected:
  std::string name;
  std::string address;

public:
  Person(std::string name, std::string address) : name(name), address(address) {}

  std::string getName() const { return name; }
  std::string getAddress() const { return address; }
  void setAddress(std::string address) { this->address = address; }
  std::string toString() const { return name + "(" + address + ")"; }

  
};

class Student : public Person {
private:
  std::string program;
  int year;
  double fee;

public:
  Student(std::string name, std::string address, std::string program, int year, double fee)
      : Person(name, address), program(program), year(year), fee(fee) {}

  std::string getProgram() const { return program; }
  std::string getYear() const { return std::to_string(year); }
std::string getFee() const { return std::to_string(fee); }
  void setYear(int year) { this->year = year; }
  void setFee(double fee) { this->fee = fee; }
  void setProgram(std::string program) { this->program = program; }
  std::string toString() const { return getName()  + getAddress() + getProgram() + getYear() + getFee(); }
};

class Staff : public Person {
private:
  std::string school;
  double pay;

public:
  Staff(std::string name, std::string address, std::string school, double pay)
      : Person(name, address), school(school), pay(pay) {}

  std::string getSchool() const { return school; }
  void setSchool(std::string school) { this->school = school; }
  void setPay(double pay) { this->pay = pay; }
  std::string getPay() const { return std::to_string(pay); }
 std::string toString() const {
    return getName() + " (" + getAddress() + "), School: " + getSchool() + ", Pay: $" + getPay();
}
};


#include <iostream>

int main() {
    // a. Create and initialize an array of five students.
    Student students[5] = {
        Student("Alice", "123 Main St", "Computer Science", 2020, 5000.0),
        Student("Bob", "456 Elm St", "Physics", 2019, 5500.0),
        Student("Charlie", "789 Oak St", "Mathematics", 2021, 4800.0),
        Student("David", "101 Pine St", "Chemistry", 2018, 5200.0),
        Student("Eve", "202 Maple St", "Biology", 2022, 4900.0)
    };

    // b. Set a new year 2023 for all of the students.
    for (int i = 0; i < 5; ++i) {
        students[i].setYear(2023);
    }

    // c. Create a loop to print information of all the students.
    for (int i = 0; i < 5; ++i) {
        std::cout << "Student " << i + 1 << " Information: " << std::endl;
        std::cout << "Name: " << students[i].getName() << std::endl;
        std::cout << "Address: " << students[i].getAddress() << std::endl;
        std::cout << "Program: " << students[i].getProgram() << std::endl;
        std::cout << "Year: " << students[i].getYear() << std::endl;
        std::cout << "Fee: $" << students[i].getFee() << std::endl;
        std::cout << std::endl;
    }

    // d. Create a staff and set a new address for the staff.
    Staff staff("John", "333 Oak Ave", "High School", 60000.0);
    staff.setAddress("444 Elm Ave");

    // Printing staff information
    std::cout << "Staff Information: " << std::endl;
    std::cout << "Name: " << staff.getName() << std::endl;
    std::cout << "Address: " << staff.getAddress() << std::endl;
    std::cout << "School: " << staff.getSchool() << std::endl;
    std::cout << "Pay: $" << staff.getPay() << std::endl;

    return 0;
}
