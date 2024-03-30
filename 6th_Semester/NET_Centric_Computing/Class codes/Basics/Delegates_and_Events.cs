/*
 * Delegates:
 * Delegates in C# are similar to function pointers in C or C++. 
 * A delegate is a reference type variable that holds the reference to a method. The reference can be changed at runtime.
 * It provides a way which tells which method to be called when an event is triggered.
 * 
 * Delegate declaration:
 * delegate <return type> <delegate-name> <parameter list>;
 * 
 * Object Creation:
 * <delegate-name> <object-name> = new <delegate-name>(<method-name>);
 * 
 * Invoking a delegate:
 * <object-name>(<argument list>);
 * 
 * Events:
 * Events are user actions such as key press, clicks, mouse movements, etc., or some occurrence such as system generated notifications.
 * It is a mechanism that helps to notify the class when certain actions occur. It helps in communication between objects.
 * Unlike delegates, events provide an additional layer of abstraction and protection.
 * Events allow clients to subscribe to notifications raised by an object, or unsubscribe from them, but they cannot modify the delegate directly.
 */
using System;

namespace Basics
{
    // Declaring a delegate
    public delegate void SimpleDelegate();
    class Delegates_and_Events
    {
        public void DelegateMethod()
        {
            // Creating an instance of the delegate
            SimpleDelegate d = new SimpleDelegate(() => Console.WriteLine("Delegate is called"));
            // Invoking the delegate
            d();
        }
    }
}
