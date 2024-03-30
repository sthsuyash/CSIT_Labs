/*
 * Abstract class: 
 * Abstract class is a class that is declared using the abstract keyword. 
 * It can have abstract methods(methods without a body) as well as concrete methods (regular methods with a body). 
 * It can have fields, properties, and events. It can have constructors, but it cannot be instantiated. 
 * It can have access modifiers. 
 * It can have static members. 
 * It can have a finalizer. 
 * It can have a class constructor.
 * 
 * Sealed class:
 * Sealed class is a class that is declared using the sealed keyword.
 * It cannot be inherited.
 */
using System;

namespace Basics
{
    abstract class AbstractExpression
    {
        public abstract void Display();
    }

    // inherit abstract class
    class InheritAbstract : AbstractExpression
    {
        public override void Display()
        {
            Console.WriteLine("InheritAbstract class");
        }
    }

    public sealed class SealedExpression
    {
        public void Display()
        {
            Console.WriteLine("Sealed class");
        }
    }

    // try to inherit sealed class
    // compiler error: 'InheritSealed': cannot derive from sealed type 'SealedExpression'
    //public class InheritSealed : SealedExpression
    //{
    //    public void Display()
    //    {
    //        Console.WriteLine("InheritSealed class");
    //    }
    //}

}
