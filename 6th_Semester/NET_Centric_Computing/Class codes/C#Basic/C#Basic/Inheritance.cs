using System;
// single level: only one parent A->B
// multi level: chain of parents A->B->C
// multiple: one child can have two parents -> not possible due to class -> only possible using interface

namespace C_Basic
{
    // single level inheritance
    class Employee
    {
        private int id; // this is auto implemented property -> no need to create private variable 
        private string name;
        private string address;
        private string department;

        // method to initialize instance variable
        public void setEmployee(int id, string name, string address, string department)
        {
            this.id = id;
            this.name = name;
            this.address = address;
            this.department = department;
        }

        public void getEmployee()
        {
            Console.WriteLine($"Id: {this.id}");
            Console.WriteLine($"Name: {this.name}");
            Console.WriteLine($"Address: {this.address}");
            Console.WriteLine($"Department: {this.department}");
        }
    }

    // teacher is a sub-class of employee(which is parent)
    class Teacher : Employee
    {
        private string subject;
        private string qualification;

        public void setTeacher(string subject, string qualification, int id, string name, string address, string department)
        {
            this.setEmployee(id, name, address, department);
            this.subject = subject;
            this.qualification = qualification;
        }

        public void getTeacher()
        {
            this.getEmployee();
            Console.WriteLine($"Subject: {this.subject}");
            Console.WriteLine($"Qualification: {this.qualification}");
        }
    }

    // multilevel inheritance
    class PartTimeTeacher : Teacher
    {
        private int hours;

        public void setPartTimeTeacher(int hours)
        {
            this.hours = hours;
        }

        public void getPartTimeTeacher()
        {
            Console.WriteLine($"Hours: {this.hours}");
        }
    }

    class FullTimeTeacher : Teacher
    {
        private int salary;

        public void setFullTimeTeacher(int salary)
        {
            this.salary = salary;
        }

        public void getFullTimeTeacher()
        {
            Console.WriteLine($"Salary: {this.salary}");
        }
    }
}
