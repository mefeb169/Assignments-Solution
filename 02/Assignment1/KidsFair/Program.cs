using System;

namespace KidsFair
{
	class Program
	{
		static void Main(string[] args)
		{
			//Create then an object of each class in the Main method inside the class Program.
			Album album = new Album();
			Pet pet = new Pet();
			TicketSeller ticketSeller = new TicketSeller();


			//Greetings from pet class
			pet.GreetingsFromPetClass();

			//Taking input of pet name
			string petName = pet.InputPetName();

			//Taking input of pet age
			string petAge = pet.InputPetAge(petName);

			//Taking gender of pet
			string petGender = pet.InputPetGender(petName);

			//Printing Information
			pet.ShowInfoOnConsole(petName,petAge,petGender);

			//For holding the console
			Console.ReadLine();
		}
	}
}
