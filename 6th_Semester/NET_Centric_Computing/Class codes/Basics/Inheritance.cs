/*
 * Inheritance is a mechanism in which one class acquires the properties and behavior of another class.
 * It represents the IS-A relationship which is also known as a parent-child relationship.
 * single level: only one parent A->B
 * multi level: chain of parents A->B->C
 * 
 * multiple: one child can have two parents -> not possible due to class -> only possible using interface, check InterfaceExpression.cs
 */
using System;

namespace Basics
{
    //parent class
    class Employee
    {
        public int id;
        public string name;
        public string address;
        public string department;

        public void SetEmployee(int id, string name, string address, string department)
        {
            this.id = id;
            this.name = name;
            this.address = address;
            this.department = department;
        }

        public void GetEmployee()
        {
            Console.WriteLine($"Id: {this.id}");
            Console.WriteLine($"Name: {this.name}");
            Console.WriteLine($"Address: {this.address}");
            Console.WriteLine($"Department: {this.department}");
        }
    }

    // teacher is a sub-class of employee(which is parent)
    // single level inheritance
    class Teacher : Employee
    {
        protected string subject;
        protected string qualification;

        public void SetTeacher(string subject, string qualification, int id, string name, string address, string department)
        {
            SetEmployee(id, name, address, department);
            this.subject = subject;
            this.qualification = qualification;
        }

        public void GetTeacher()
        {
            GetEmployee();
            Console.WriteLine($"Subject: {this.subject}");
            Console.WriteLine($"Qualification: {this.qualification}");
        }
    }

    // part time teacher is a sub-class of teacher(which is parent) and teacher is a sub-class of employee(which is parent)
    // so, multilevel inheritance is A->B->C
    class PartTimeTeacher : Teacher
    {
        private int hours;

        public void SetPartTimeTeacher(int hours, string subject, string qualification, int id, string name, string address, string department)
        {
            SetTeacher(subject, qualification, id, name, address, department);
            this.hours = hours;
        }

        public void GetPartTimeTeacher()
        {
            GetTeacher();
            Console.WriteLine($"Hours: {this.hours}");
        }
    }
}