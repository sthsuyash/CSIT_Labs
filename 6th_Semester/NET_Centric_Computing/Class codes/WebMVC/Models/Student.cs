/*
 * Model is used to store data and logic. 
 * It is accessible by controller and view to provide necessary response, to use model by controller
 * It should using project name.models and to use model in view in view it should add @using projectname.models. as model is class it normally conatins properties
 */

namespace WebMVC.Models
{
    public class Student
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Gender { get; set; }
        public string Faculty { get; set; }
        public string Grade { get; set; }

    }
}
