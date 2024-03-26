using System;

namespace UserRegistrationConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Registration registration = new Registration();
            registration.CreateTable();
            registration.InsertData();
            registration.DisplayData();
            registration.UpdateData();
            registration.DeleteData();
            registration.DisplayMaleFromNepal();
        }
    }
}
