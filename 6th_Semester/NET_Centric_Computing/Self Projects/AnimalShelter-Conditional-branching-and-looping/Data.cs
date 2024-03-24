using System;
using System.Collections.Generic;
using System.Linq;

namespace AnimalShelter_Conditional_branching_and_looping
{
    class Data
    {
        public static List<Animal> Animals { get; private set; }

        static Data()
        {
            Animals = new List<Animal>
            {
                new Animal(1, Species.Dog, 2, "medium sized cream", "belly rubbed", "lola"),
                new Animal(2, Species.Dog, 9, "large reddish-brown", "ears rubbed", "loki"),
                new Animal(3, Species.Cat, 1, "small white female", "friendly", "Puss"),
                new Animal(4, Species.Cat, 3, "medium sized black", "housebroken", "cattie")
            };
        }

        public static void AddAnimal(Animal animal)
        {
            Animals.Add(animal);
        }

        public static void EditAnimal(int id, int age)
        {
            Animals.FirstOrDefault(animal => animal.Id == id)?.EditAge(age);
        }

        public static void EditAnimal(int id, string personalityDescription)
        {
            Animals.FirstOrDefault(animal => animal.Id == id)?.EditPersonalityDescription(personalityDescription);
        }

        public static void DisplayAnimal(Species species, string characteristic)
        {
            Console.WriteLine($"Given characteristic: {characteristic}");
            Console.WriteLine($"Our current {species} information with the given characteristic is:");

            var filteredAnimals = Animals.Where(animal => animal.Species == species && animal.CharacteristicDescription.Contains(characteristic));

            foreach (var animal in filteredAnimals)
            {
                Console.WriteLine(animal);
                Console.WriteLine();
            }
        }

        public static void EnsureCompletion(string[] characteristics)
        {
            foreach (var characteristic in characteristics)
            {
                bool isCharacterIncomplete = Animals.Any(animal => string.IsNullOrEmpty(animal.CharacteristicDescription) || animal.CharacteristicDescription.Contains(characteristic));

                if (isCharacterIncomplete)
                {
                    Console.WriteLine($"Please ensure the characteristic description for '{characteristic}' is complete.");
                }
            }
        }

        public static void DisplayAllAnimals()
        {
            Console.WriteLine("Our current pet information is:");
            foreach (var animal in Animals)
            {
                Console.WriteLine(animal);
                Console.WriteLine();
            }
        }
    }
}
