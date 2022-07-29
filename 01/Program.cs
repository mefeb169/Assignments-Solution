using System;
using System.IO; // to import file 
using System.Collections.Generic; //to import file 
using System.Linq; //to read file 
using System.Windows.Forms; //Message Box
using System.Collections;
using Project1Feb;


namespace Project1feb
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Please enter the file name: ");
			string fileName = Console.ReadLine();

			//Evaluating if input file name is wrong 
			bool fileExist = CheckFile(fileName);

			if (fileExist)
			{
				//loading data from file
				List<Stock> csvData = ReadDateFromFile(fileName);

				//manipulating data
				//Finding Mean of list
				List<Stock> data = csvData;
				double mean = MeanPrice(data);


				//Calculating highest of adjusted prices
				Tuple<string, string> resultHighest = HighestPrice(csvData);

				//Calculating lowest of adjusted prices
				Tuple<string, string> resultLowest = LowestPrice(csvData);

				//Converting dates
				Date date = new Date();

				// Printing Info at screen
				//Lowest Value
				Console.WriteLine($"Lowest: {resultLowest.Item1} with date {date.DateConvertor2(resultLowest.Item2)}");

				//Highest value
				Console.WriteLine($"Highest: {resultHighest.Item1} with date {date.DateConvertor2(resultHighest.Item2)}");

				//Mean Value
				Console.WriteLine($"mean is: {mean}");


				////Calling Date Convertors Function
				{//Date date = new Date();
				 //int year = date.YearExtractor(20091224);
				 //int month = date.MonthExtractor(20091224);
				 //int day = date.DayExtractor(20091224);
				 //Console.WriteLine($"Year extracted is: {year}");
				 //Console.WriteLine($"Month extracted is: {month}");
				 //Console.WriteLine($"Day extracted is: {day}");
				}

				//to hold the console
				Console.ReadLine();
			}
			else
			{
				Console.WriteLine("File mentioned not Exist");

				//holding Console
				Console.ReadLine();
			}
		}

		/// <summary>
		/// this method will calculate Lowest price among adjusted prices
		/// </summary>
		/// <param name="csvData"></param>
		/// <returns></returns>
		private static Tuple<string, string> LowestPrice(List<Stock> csvData)
		{
			//copying data for securing it 
			List<Stock> csvDataHere = csvData;

			////removing header row
			//csvDataHere.RemoveAt(0);

			//sorting according to adjclose property 
			List<Stock> SortedList = csvDataHere.OrderBy(x => x.AdjClose).ToList();


			//To verify
			//Console.WriteLine($"Lowest: {SortedList[0].AdjClose} with date {SortedList[0].Date.dateInString}");
			//Console.WriteLine($"Highest: {SortedList[SortedList.Count - 1].AdjClose} with date {SortedList[SortedList.Count - 1].Date.dateInString}");
			//Console.ReadLine();

			// Returning Lowest value with date
			return new Tuple<string, string>(SortedList[0].AdjClose, SortedList[0].Date.dateInString);
		}

		/// <summary>
		/// This method will check the file if it exists or not 
		/// </summary>
		/// <param name="fileName"></param>
		/// <returns></returns>
		private static bool CheckFile(string fileName)
		{
			if (fileName.ToUpper() == "FB.CSV")
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		/// <summary>
		/// This method will calculate the mean of given data
		/// </summary>
		private static double MeanPrice(List<Stock> csvData)
		{
			//copying data for securing it 
			List<Stock> csvDataHere = csvData;

			//sorting according to adjclose property 
			List<string> adjCloseList = csvDataHere.Select(x => x.AdjClose).ToList();

			//Converting the list to decimal or doubles
			List<double> adjCloseListInDouble = adjCloseList.Select(double.Parse).ToList();

			//Total sum
			double sumTotal = adjCloseListInDouble.Aggregate((x, y) => x + y);

			//Mean
			double mean = sumTotal / adjCloseList.Count;

			return mean;

			//Console.WriteLine($"mean is: {mean}");

			//Console.ReadLine();
		}

		/// <summary>
		/// This method will calculate the highest and Lowest of the adjusted price.
		/// ie. column AdjClose
		/// </summary>
		/// <param name="csvData"></param>
		private static Tuple<string, string> HighestPrice(List<Stock> csvData)
		{
			//copying data for securing it 
			List<Stock> csvDataHere = csvData;

			//sorting according to adjclose property 
			List<Stock> SortedList = csvDataHere.OrderBy(x => x.AdjClose).ToList();


			////To verify
			//Console.WriteLine($"Lowest: {SortedList[0].AdjClose} with date {SortedList[0].Date}");
			//Console.WriteLine($"Highest: {SortedList[SortedList.Count - 1].AdjClose} with date {SortedList[SortedList.Count - 1].Date}");
			//Console.ReadLine();

			// Returning Highest value respectively
			return new Tuple<string, string>(SortedList[SortedList.Count - 1].AdjClose, SortedList[SortedList.Count - 1].Date.dateInString);
		}
		/// <summary>
		/// This method will read data from given file name
		/// File has to be present in debug folder
		/// i.e. /project1feb/bin/debug/file.csv
		/// </summary>
		private static List<Stock> ReadDateFromFile(string fileName)
		{
			//below list variable will hold the data from file
			List<Stock> dataListFromFile = new List<Stock>();

			string[] csvRow = File.ReadAllLines(fileName);
			for (int i = 0; i < csvRow.Length; i++)
			{
				//ignoring header row
				if (i == 0)
				{
					continue;
				}

				string[] csvRows = null;
				if (csvRow[i] != null)
				{
					csvRows = csvRow[i]?.Split(',');
				}

				//Data from file into strings
				string dateString = csvRows[0];//date format: dd/MM/yyyy
				string open = csvRows[1];
				string high = csvRows[2];
				string low = csvRows[3];
				string close = csvRows[4];
				string adjClose = csvRows[5];
				string volume = csvRows[6];

				//converting date fetched from file to propirate Date variable
				//Removing slash from it
				Date date = new Date();


				//ouput: datefetched = yyyyMMdd
				string dateFetched = date.DateConvertor1(dateString);

				//ouput: datefetched = yyyyMMdd (int)
				int DateInInt = Convert.ToInt32(dateFetched);

				date.dateInString = dateFetched;
				date.dateInInt = DateInInt;

				//storing data in class model to use it later
				Stock dataRow = new Stock(date, open, high, low, close, adjClose, volume);
				dataListFromFile.Add(dataRow);
			}

			////just for ensuring that all of file data is loading completely 
			{
				//int count = 1;
				//foreach (Stock data in dataListFromFile)
				//{
				//	Console.WriteLine($"{count}   {data.Date.dateInString}\t\t{data.Open}\t{data.High}\t{data.Low}\t\t{data.Close}\t{data.AdjClose}\t{data.Volume}");
				//	count++;
				//}
				//Console.ReadLine();
			}

			return dataListFromFile;
		}
	}
}