﻿using System;

namespace DatabaseConnection
{
    internal class Program
    {
        static void Main(string[] args)
        {
            DatabaseConnection databaseConnection = new DatabaseConnection();
            //databaseConnection.CreateTable();
            //databaseConnection.InsertData();

            Console.WriteLine("\n------------------------");
            Console.WriteLine("\tMenu");
            Console.WriteLine("Press: ");
            Console.WriteLine("1. Reading All Data.");
            Console.WriteLine("2. Reading Data by User ID.");
            Console.WriteLine("3. Updating Data by User ID.");
            Console.WriteLine("4. Deleting Data by User ID.");
            Console.WriteLine("5. Exit");
            Console.WriteLine("------------------------\n");

            int choice;
            do {
                Console.Write("\nEnter your choice: ");
                choice = Convert.ToInt32(Console.ReadLine());

                switch (choice)
                {
                    case 1:
                        databaseConnection.GetAllData();
                        break;
                    case 2:
                        databaseConnection.GetDataById();
                        break;
                    case 3:
                        databaseConnection.UpdateData();
                        break;
                    case 4:
                        databaseConnection.DeleteData();
                        break;
                    case 5:
                        Console.Write("Exiting");
                        for (int i = 0; i < 3; i++)
                        {
                            // time delay
                            System.Threading.Thread.Sleep(500);
                            Console.Write(".");
                        }
                        Console.WriteLine();
                        break;
                    default:
                        Console.WriteLine("Please select the provided options.");
                        break;
                }

            } while (choice != 5);
        }
    }
}
