using System;

namespace StudentGradingApplication.Exceptions
{
    class DivideZeroException : Exception
    {
        public DivideZeroException(string message) : base(message) { }
    }
}
