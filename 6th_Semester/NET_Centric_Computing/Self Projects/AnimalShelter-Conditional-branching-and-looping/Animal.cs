using System;

namespace AnimalShelter_Conditional_branching_and_looping
{
    enum Species
    {
        Dog,
        Cat
    }

    internal class Animal
    {
        public int Id { get; private set; }
        public Species Species { get; private set; }
        public int Age { get; set; }
        public string CharacteristicDescription { get; private set; }
        public string PersonalityDescription { get; set; }
        public string Nickname { get; set; }

        public void EditAge(int newAge)
        {
            Age = newAge;
        }

        public void EditPersonalityDescription(string newPersonalityDescription)
        {
            PersonalityDescription = newPersonalityDescription;
        }

        public Animal()
        {
            Menu();
        }

        public Animal(int id, Species species, int age, string characteristicDescription, string personalityDescription, string nickname)
        {
            Id = id;
            Species = species;
            Age = age;
            CharacteristicDescription = characteristicDescription;
            PersonalityDescription = personalityDescription;
            Nickname = nickname;
        }

        public void Menu()
        {
            Console.WriteLine("Welcome to the Contoso PetFriends app. Your main menu options are:");
            Console.WriteLine(" 1. List all of our current pet information");
            Console.WriteLine(" 2. Add a new animal friend");
            Console.WriteLine(" 3. Ensure animal ages and physical descriptions are complete");
            Console.WriteLine(" 4. Ensure animal nicknames and personality descriptions are complete");
            Console.WriteLine(" 5. Edit an animal’s age");
            Console.WriteLine(" 6. Edit an animal’s personality description");
            Console.WriteLine(" 7. Display all cats with a specified characteristic");
            Console.WriteLine(" 8. Display all dogs with a specified characteristic");
            Console.WriteLine(" 0. Exit the program");

            int selection;
            do
            {
                Console.Write("Enter your selection number: ");
                if (int.TryParse(Console.ReadLine(), out selection))
                {
                    ProcessSelection(selection);
                }
                else
                {
                    Console.WriteLine("Invalid selection. Please enter a valid number.");
                }
            } while (selection != 0);
        }

        private void ProcessSelection(int selection)
        {
            switch (selection)
            {
                case 1:
                    Data.DisplayAllAnimals();
                    break;
                case 2:
                    AddAnimal();
                    break;
                case 3:
                    EnsureCharacteristicsComplete("age", "personalityDescription");
                    break;
                case 4:
                    EnsureCharacteristicsComplete("nickname", "personalityDescription");
                    break;
                case 5:
                    EditAnimalAge();
                    break;
                case 6:
                    EditAnimalPersonalityDescription();
                    break;
                case 7:
                    DisplayAnimalsWithSpecificCharacteristics(Species.Cat);
                    break;
                case 8:
                    DisplayAnimalsWithSpecificCharacteristics(Species.Dog);
                    break;
                case 0:
                    Console.WriteLine("Exiting the program. Goodbye!");
                    break;
                default:
                    Console.WriteLine("Invalid selection. Please enter a valid number.");
                    break;
            }
        }

        private void AddAnimal()
        {
            Console.WriteLine("Enter the animal's id");
            if (int.TryParse(Console.ReadLine(), out int id))
            {
                Console.WriteLine("Enter the animal's species (Dog or Cat)");
                if (Enum.TryParse(Console.ReadLine(), out Species species))
                {
                    Console.WriteLine("Enter the animal's age");
                    if (int.TryParse(Console.ReadLine(), out int age))
                    {
                        Console.WriteLine("Enter the animal's characteristic description");
                        string characteristicDescription = Console.ReadLine();
                        Console.WriteLine("Enter the animal's personality description");
                        string personalityDescription = Console.ReadLine();
                        Console.WriteLine("Enter the animal's nickname");
                        string nickname = Console.ReadLine();

                        Animal newAnimal = new Animal(id, species, age, characteristicDescription, personalityDescription, nickname);
                        Data.AddAnimal(newAnimal);

                        Console.WriteLine("Animal added successfully!");
                    }
                    else
                    {
                        Console.WriteLine("Invalid age. Please enter a valid number.");
                    }
                }
                else
                {
                    Console.WriteLine("Invalid species. Please enter Dog or Cat.");
                }
            }
            else
            {
                Console.WriteLine("Invalid id. Please enter a valid number.");
            }
        }

        private void EditAnimalAge()
        {
            Console.Write("Enter the animal's id: ");
            if (int.TryParse(Console.ReadLine(), out int id))
            {
                Console.Write("Enter the animal's new age: ");
                if (int.TryParse(Console.ReadLine(), out int newAge))
                {
                    Data.EditAnimal(id, newAge);
                    Console.WriteLine("Animal age updated successfully!");
                }
                else
                {
                    Console.WriteLine("Invalid age. Please enter a valid number.");
                }
            }
            else
            {
                Console.WriteLine("Invalid id. Please enter a valid number.");
            }
        }

        private void EditAnimalPersonalityDescription()
        {
            Console.Write("Enter the animal's id: ");
            if (int.TryParse(Console.ReadLine(), out int id))
            {
                Console.Write("Enter the animal's new personality description: ");
                string newPersonalityDescription = Console.ReadLine();
                Data.EditAnimal(id, newPersonalityDescription);
                Console.WriteLine("Animal personality description updated successfully!");
            }
            else
            {
                Console.WriteLine("Invalid id. Please enter a valid number.");
            }
        }

        private void DisplayAnimalsWithSpecificCharacteristics(Species species)
        {
            Console.Write($"Enter the characteristic you are looking for in {species}s: ");
            string characteristic = Console.ReadLine();
            Data.DisplayAnimal(species, characteristic);
        }

        private void EnsureCharacteristicsComplete(params string[] characteristics)
        {
            Data.EnsureCompletion(characteristics);
        }

        public override string ToString()
        {
            return $"id: {Id}\nSpecies: {Species}\nAge: {Age}\nNickname: {Nickname}\nDescription: {CharacteristicDescription}\nPersonality: {PersonalityDescription}";
        }
    }
}
