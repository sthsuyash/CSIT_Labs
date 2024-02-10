using System;
using StudentGradingApplication.Exceptions;

namespace StudentGradingApplication
{
    class Scores
    {
        private int currentAssignments; // number of assignments

        private string name;
        private int mark1;
        private int mark2;
        private int mark3;
        private int mark4;
        private int mark5;

        private int[] extraCreditScores; // extra credit scores [optional

        private int sum; // sum of the marks
        private decimal average; // average of the marks
        string grade; // grade of the student

        public Scores(string name, int mark1, int mark2, int mark3, int mark4, int mark5, int[] extraCreditScores = null)
        {
            this.currentAssignments = 5; // default number of assignments
            this.name = name;
            this.mark1 = mark1;
            this.mark2 = mark2;
            this.mark3 = mark3;
            this.mark4 = mark4;
            this.mark5 = mark5;
            this.extraCreditScores = extraCreditScores ?? new int[0]; // default extra credit scores
        }

        // Properties
        public int Mark1
        {
            get { return mark1; }
        }

        public int Mark2
        {
            get { return mark2; }
        }

        public int Mark3
        {
            get { return mark3; }
        }

        public int Mark4
        {
            get { return mark4; }
        }

        public int Mark5
        {
            get { return mark5; }
        }

        // get the sum of the marks
        public int Sum
        {
            get { return sum; }
        }

        // get the average of the marks
        public decimal Average
        {
            get { return average; }
        }

        // get the grade of the student
        public string Grade
        {
            get { return grade; }
        }

        // get extra credit scores
        public int[] ExtraCreditScores
        {
            get { return extraCreditScores; }
        }

        // function to calculate the sum of the marks
        private void CalculateSum()
        {
            int totalSum = 0;
            int[] marks = { this.mark1, this.mark2, this.mark3, this.mark4, this.mark5 };
            foreach (int mark in marks)
            {
                totalSum += mark;
            }

            // add the extra credit scores to the total sum, but divide by 10 as bonus points are equal to 10% of the exam score
            foreach (int extraCredit in this.extraCreditScores)
            {
                totalSum += extraCredit / 10;
            }
            this.sum = totalSum;
        }

        // function to calculate the average of the marks
        private void CalculateScore()
        {
            try
            {
                if (currentAssignments == 0)
                {
                    throw new DivideZeroException("Divide by zero error, currentAssignments cannot be zero");
                }
                this.average = (decimal)this.sum / currentAssignments;
                this.CalculateGrade();
            }
            catch (DivideZeroException e)
            {
                Console.WriteLine(e.Message);
            }
        }

        // function to calculate the grade of the student
        private void CalculateGrade()
        {
            switch (this.average)
            {
                case var _ when this.average >= 97 && this.average <= 100:
                    this.grade = "A+";
                    break;
                case var _ when this.average >= 93 && this.average < 97:
                    this.grade = "A";
                    break;
                case var _ when this.average >= 90 && this.average < 93:
                    this.grade = "A-";
                    break;
                case var _ when this.average >= 87 && this.average < 90:
                    this.grade = "B+";
                    break;
                case var _ when this.average >= 83 && this.average < 87:
                    this.grade = "B";
                    break;
                case var _ when this.average >= 80 && this.average < 83:
                    this.grade = "B-";
                    break;
                case var _ when this.average >= 77 && this.average < 80:
                    this.grade = "C+";
                    break;
                case var _ when this.average >= 73 && this.average < 77:
                    this.grade = "C";
                    break;
                case var _ when this.average >= 70 && this.average < 73:
                    this.grade = "C-";
                    break;
                case var _ when this.average >= 67 && this.average < 70:
                    this.grade = "D+";
                    break;
                case var _ when this.average >= 63 && this.average < 67:
                    this.grade = "D";
                    break;
                case var _ when this.average >= 60 && this.average < 63:
                    this.grade = "D-";
                    break;
                default:
                    this.grade = "F";
                    break;
            }
        }

        // function to display the tabular format of the marks
        public void DisplayScores()
        {
            // calculate the sum and the average of the marks
            this.CalculateSum();
            this.CalculateScore();

            // display the tabular format of the marks
            Console.WriteLine($"{this.name}:\t\t{this.average}\t{this.grade}");
        }
    }
}
