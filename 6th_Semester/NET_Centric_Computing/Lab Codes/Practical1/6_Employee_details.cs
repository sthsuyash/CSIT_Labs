using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
 * Create a class EmployeeDetails having data member empId, empName, empGender, empAddress, and empPosition.
 * Constructor to set the details and 
 * display method to display the details. 
 * 
 * Create a subclass SalaryInfo that will inherit EmployeeDetails having own data member salary which will record salary per year.
 * Constructor to set the value of salary and 
 * method calcTax() that deduct the tax on salary and display the final salary. 
 * 
 * Tax rate is given as (if salary <= 400000 tax is 1%, salary between 400001 to 800000 tax is 10% and salary > 800000 tax 20%). 
 * Now create the object of Salary info and demonstrate the scenario.
 */

namespace Practical1
{
    class EmployeeDetails
    {
        protected int empId;
        protected string empName;
        protected char empGender;
        protected string empAddress;
        protected string empPosition;

        // Constructor to set the details
        public EmployeeDetails(int empId, string empName, char empGender, string empAddress, string empPosition)
        {
            this.empId = empId;
            this.empName = empName;
            this.empGender = empGender;
            this.empAddress = empAddress;
            this.empPosition = empPosition;
        }

        // Method to display the details
        public virtual void DisplayDetails()
        {
            Console.WriteLine($"Employee ID: {empId}");
            Console.WriteLine($"Name: {empName}");
            Console.WriteLine($"Gender: {empGender}");
            Console.WriteLine($"Address: {empAddress}");
            Console.WriteLine($"Position: {empPosition}");
        }
    }

    class SalaryInfo : EmployeeDetails
    {
        // Additional data member
        private double salary;

        // Constructor to set the value of salary
        public SalaryInfo(int empId, string empName, char empGender, string empAddress, string empPosition, double salary)
            : base(empId, empName, empGender, empAddress, empPosition)
        {
            this.salary = salary;
        }

        // Method to calculate tax and display the final salary
        public void CalcTax()
        {
            double tax = 0;
            if (salary <= 400000)
            {
                tax = salary * 0.01;
            }
            else if (salary > 400000 && salary <= 800000)
            {
                tax = salary * 0.1;
            }
            else
            {
                tax = salary * 0.2;
            }

            double finalSalary = salary - tax;

            Console.WriteLine($"Salary: {salary}");
            Console.WriteLine($"Tax: {tax}");
            Console.WriteLine($"Final Salary: {finalSalary}");
        }
    }
}
