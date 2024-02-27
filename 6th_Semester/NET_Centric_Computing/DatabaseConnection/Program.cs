using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DatabaseConnection
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Insert insert = new Insert();
            insert.createTable();
            insert.insertData();
        }
    }
}
