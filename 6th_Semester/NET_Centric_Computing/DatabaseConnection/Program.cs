using System;

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

            int choice = Convert.ToInt32(Console.ReadLine());
            do {

                switch (choice)
                {
                    case 1:
                        databaseConnection.GetAllData();
                        return;
                    case 2:
                        databaseConnection.GetDataById();
                        return;
                    case 3:
                        databaseConnection.UpdateData();
                        return;
                    case 4:
                        databaseConnection.DeleteData();
                        return;
                    default:
                        Console.WriteLine("Please select the provided options.");
                        return;
                }

                }while (choice > 4) ;
        }
    }
}
