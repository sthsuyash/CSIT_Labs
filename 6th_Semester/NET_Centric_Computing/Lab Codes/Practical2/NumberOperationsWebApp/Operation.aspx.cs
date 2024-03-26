using System;

namespace NumberOperationsWebApp
{
    public partial class Operation : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e) { }

        // Validation function
        private (int firstNumber, int secondNumber) validateNumbers(object sender, EventArgs e)
        {
            string firstNumberString = firstNumber.Text;
            string secondNumberString = secondNumber.Text;

            // check if the input fields are empty
            if (!firstNumberString.Equals("") && !secondNumberString.Equals(""))
            {
                // check if the input fields are numbers
                if (int.TryParse(firstNumberString, out int firstNumber) && int.TryParse(secondNumberString, out int secondNumber)){
                    return (firstNumber, secondNumber);
                }
                else{
                    output.Text = "Please enter valid numbers";
                    return (0, 0);
                }
            }
            else{
                output.Text = "Please enter numbers";
                return (0, 0);
            }
        }

        // Add button click event
        protected void addButton_Click(object sender, EventArgs e)
        {
            int firstNumber, secondNumber;
            (firstNumber, secondNumber) = validateNumbers(sender, e);
            if (firstNumber == 0 && secondNumber == 0)
            {
                return;
            }
            output.Text = (firstNumber + secondNumber).ToString();
        }

        // Subtract button click event
        protected void subtractButton_Click(object sender, EventArgs e)
        {
            int firstNumber, secondNumber;
            (firstNumber, secondNumber) = validateNumbers(sender, e);
            if (firstNumber == 0 && secondNumber == 0){
                return;
            }
            if (firstNumber < secondNumber){
                output.Text = "First number should be greater than the second number";
                return;
            }
            output.Text = (firstNumber - secondNumber).ToString();
        }

        // Find Prime button click event
        protected void primeButton_Click(object sender, EventArgs e)
        {
            int firstNumber, secondNumber;
            (firstNumber, secondNumber) = validateNumbers(sender, e);
            if (firstNumber == 0 && secondNumber == 0){
                return;
            }

            output.Text = "";
            for (int i = firstNumber; i <= secondNumber; i++){
                if (isPrime(i)) output.Text += i + " ";
            }
        }

        // Check if the number is prime
        private bool isPrime(int number)
        {
            if (number <= 1)
                return false;
            for (int i = 2; i <= Math.Sqrt(number); i++){
                if (number % i == 0)
                    return false;
            }
            return true;
        }
    }
}
