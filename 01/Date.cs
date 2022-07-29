using System;
using System.Globalization;

namespace Project1feb
{
	public class Date
	{
		#region Region of Code by Osama

		//Variables
		//Date in int i.e 20070212 "yyyyMMdd"
		public int dateInInt { get; set; }
		//Date in format i.e. "yyyy-MM-DD"
		public string dateInString { get; set; }
		//year in int
		public int yearInInt { get; set; }
		//Month in int
		public int monthInInt { get; set; }

		//Constructor
		public Date()
		{

		}

		public Date(string dateString)
		{
			this.dateInString = dateString;
		}

		//Methods
		/// <summary>
		/// yyyy-MM-dd to yyyyMMdd
		/// </summary>
		/// <param name="dateInStringFormat"></param>
		/// <returns></returns>
		public string DateConvertor1(string dateInStringFormat)
		{
			//removing first slash i.e output: yyyyMM/dd
			string tempDate1 = dateInStringFormat.Remove(4,1);

			//removing second slash ie output: yyyyMMdd
			string tempDate2 = tempDate1.Remove(6,1);

			return tempDate2;
		}

		/// <summary>
		/// yyyyMMdd to yyyy-MM-dd
		/// </summary>
		/// <param name="dateInStringFormat"></param>
		public string DateConvertor2(string dateInStringFormat)
		{
			//adding slash to date
			//adding first slash i.e output: yyyy-MMdd
			string tempDate1 = dateInStringFormat.Insert(4, "-");

			//adding second slash ie output: yyyy-MM-dd
			string tempDate2 = tempDate1.Insert(7, "-");

			return tempDate2;
		}

		//year Extractor from yyyyMMdd
		public int YearExtractor(int dateInInt)
		{
			//Converting date to string
			string dateInString = dateInInt.ToString();

			DateTime extractedDate = DateTime.ParseExact(dateInString, "yyyyMMdd", CultureInfo.InvariantCulture);

			return int.Parse(extractedDate.Year.ToString());
		}

		//Month Extractor from yyyyMMdd
		public int MonthExtractor(int dateInInt)
		{
			//Converting date to string
			string dateInString = dateInInt.ToString();

			DateTime extractedDate = DateTime.ParseExact(dateInString, "yyyyMMdd", CultureInfo.InvariantCulture);

			return int.Parse(extractedDate.Month.ToString());
		}

		//day extractor 
		public int DayExtractor(int dateInInt)
		{
			//Converting date to string
			string dateInString = dateInInt.ToString();

			DateTime extractedDate = DateTime.ParseExact(dateInString, "yyyyMMdd", CultureInfo.InvariantCulture);

			return int.Parse(extractedDate.Day.ToString());
		}

		#endregion

		#region Region of already codeS
		//public Date() { }

		//// Constructor with a string argument
		//public Date(string fecha1, int fecha2, int day, int month, int year)//Name is a member of a class in the next line
		//{
		//	this.Fecha1 = fecha1; //this is a keyword that references the current object
		//	this.Fecha2 = fecha2;
		//	this.Day = day;
		//	this.Month = month;
		//	this.Year = year;
		//}

		////Define variables
		//public string Fecha1; // must represent date: YYYY-MM-DD
		//public int Fecha2; // must represent date: YYYYMMDD
		//public int Day;
		//public int Month;
		//public int Year;

		////Method that converts a YYYY-MM-DD into YYYYMMDD
		//static void Convert()
		//{
		//	string x = "1990-10-22";
		//	string result = x.Replace("-", string.Empty);
		//	int estesi;
		//	estesi = int.Parse(result);
		//	Console.WriteLine(result);
		//	Console.WriteLine(estesi.GetType());
		//}

		////Method that converts a YYYYMMDD into YYYY-MM-DD
		//static void Convert2()
		//{
		//	string x = "1990-10-22";
		//	string result = x.Replace("-", string.Empty);
		//	int estesi;
		//	estesi = int.Parse(result);
		//	Console.WriteLine(result);
		//	Console.WriteLine(estesi.GetType());
		//}

		////Method that extracts only the Year from YYYYMMDD
		//static void Extractyear()
		//{
		//	string x = "19901022";
		//	Console.WriteLine(x.Substring(0, 4));
		//	Console.Read();
		//}

		////Method that extracts only the Month from YYYYMMDD
		//static void Extractmonth()
		//{
		//	string x = "19901022";
		//	Console.WriteLine(x.Substring(5, 6));
		//	Console.Read();
		//}

		////Method that extracts only the Day from YYYYMMDD
		//static void Extractday()
		//{
		//	string x = "19901022";
		//	Console.WriteLine(x.Substring(5, 6));
		//	Console.Read();
		//}

		#endregion
	}
}
