using System;

namespace StudentGradingApplication
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Create the scores for the students
            Scores sophiaScore = new Scores("Sophia", 90, 86, 87, 98, 100, new int[] {0});
            Scores andrewScores = new Scores("Andrew", 92, 89, 81, 96, 90);
            Scores emmaScores = new Scores("Emma", 90, 85, 87, 98, 68);
            Scores loganScores = new Scores("Logan", 90, 95, 87, 88, 96);

            // Display the scores
            Console.WriteLine("Student\t\tExam Score\t\tOverall Grade\t\tExtra Credit\n");
            sophiaScore.DisplayScores();
            andrewScores.DisplayScores();
            emmaScores.DisplayScores();
            loganScores.DisplayScores();
        }
    }
}
