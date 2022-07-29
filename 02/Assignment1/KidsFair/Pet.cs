using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KidsFair
{
	/// <summary>
	/// Pet is a class that handles some basic data for a pet animal
	/// </summary>
	public class Pet
	{
		public void GreetingsFromPetClass()
		{
			Console.WriteLine("Greeting from Pet Class\n");
		}

		//Taking input of pet name
		public string InputPetName()
		{
			Console.WriteLine("What is your pet Name? ");
			string petName = Console.ReadLine();

			return petName;
		}

		//Taking input of pet age
		public string InputPetAge(string petName)
		{
			Console.WriteLine($"What is {petName}'s age? ");
			string petAge = Console.ReadLine();

			return petAge;
		}

		//Input of pet gender
		public string InputPetGender(string petName)
		{
			Console.WriteLine($"Is {petName} Female? [y/n]");
			string petGender = Console.ReadLine();

			return petGender;
		}

		//it will show infor to console
		public void ShowInfoOnConsole(string petName, string petAge, string petGender)
		{
			Console.WriteLine("\n++++++++++++++++++++++++++++++");
			Console.WriteLine($"Name: {petName}");
			Console.WriteLine($"Age: {petAge}");
			Console.WriteLine($"{petName} is a good Boy");
			Console.WriteLine($"Is {petName} female? {petGender}");
			Console.WriteLine("\n++++++++++++++++++++++++++++++");
		}
	}
}
