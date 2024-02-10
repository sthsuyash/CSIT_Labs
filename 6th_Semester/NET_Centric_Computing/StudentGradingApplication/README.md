# Project overview

A Student Grading application that automates the calculation of grades for each student in a class.

## The parameters for the application are:

- Create a C# console application.
- Start with four students. Each student has five exam scores.
- Each exam score is an integer value, 0-100, where 100 represents 100% correct.
- A student's overall exam score is the average of their five exam scores.

## Criteria for extra credit assignments:

- Include extra credit assignment scores in the student's scores array.
- Extra credit assignments are worth 10% of an exam score (when calculating the final numeric grade).
- Add extra credit assignment scores to the student's total exam score before calculating the final numeric grade.
- The application needs to automatically assign letter grades based on the calculated final score for each student.

## The application needs to include the following features

- The application needs to output/display each student’s name and formatted grade.
- The application needs to support adding other students and scores with minimal impact to the code.

## Integrate extra credit scores when calculating the student's final score and letter grade as follows

- The code must detect extra credit assignments based on the number of elements in the student's scores array.
- The code must apply the 10% weighting factor to extra credit assignments before adding extra credit scores to the sum of exam scores.
  The following list shows the letter grade that corresponds to numeric scores:

  ```readme
  97 - 100   A+
  93 - 96    A
  90 - 92    A-
  87 - 89    B+
  83 - 86    B
  80 - 82    B-
  77 - 79    C+
  73 - 76    C
  70 - 72    C-
  67 - 69    D+
  63 - 66    D
  60 - 62    D-
  0  - 59    F
  ```

## The update application needs to produce a formatted student grading report that appears as follows

  ```readme
  Student         Grade
  
  Sophia:         92.2    A-
  Andrew:         89.6    B+
  Emma:           85.6    B
  Logan:          91.2    A-
  ```
