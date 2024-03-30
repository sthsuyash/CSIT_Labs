/*
 * Asynchronous programming is a form of parallel programming that allows a unit of work to run separately from the main application thread. 
 * When the work is complete, it can notify the main thread about completion or failure of the work.
 * It is an efficient approach towards activities blocked or access is delayed.
 * In synchronous programming, if a function takes a long time to execute, it will block the execution of the program until the function returns the result.
 * 
 * In C#, the async and await keywords are used to implement asynchronous programming.
 */
using System;
using System.Threading.Tasks;

namespace Basics
{
    class Asynchronous_Programming
    {
        public async void CallProcess()
        {
            Console.WriteLine("Process started");
            await Process();
            Console.WriteLine("Process completed");
        }

        public async Task Process()
        {
            await Task.Run(() =>
            {
                for (int i = 0; i < 100; i++)
                {
                    Console.WriteLine(i);
                }
            });
        }
    }
}
