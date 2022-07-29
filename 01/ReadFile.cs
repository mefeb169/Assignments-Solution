using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

 
namespace Project1Feb
{
	public class ReadFile
	{
		//adj close for stock

		public string adjClose { get; set; }

		public static double alto2 = 4.2;
		public static double alto;

		//Open file
		public static void openfile()
		{
			List<string> data = new List<string>(); // creating a list

			data = File.ReadAllLines("FB.csv").ToList();
			//int i;
			string adjClose;
			string alto;
			var arr = (dynamic)null;
			//var arr2 = (dynamic)null;
			// double[] arr = new double[];
			// double[] arr;
			//double[] arr2 = new double[280];
			Stack myStack = new Stack();

			int count =0;

			foreach (String line in data)
			{
				if (count <= 0)
				{
					count++;
					continue;
				}

				

				else if (count >0)
				{
					string[] values = line.Split(',');
					//values[0].Trim();
					//values[0].Remove(0);
					// Console.WriteLine(values[0].Replace('/', '-'));
					//string test = values[0].Replace('/', '-');
					adjClose = values[4].Trim();
					alto = values[2].Trim();
					double hari = Convert.ToDouble(adjClose);
					myStack.Push(hari);
					// for (int i = 0; i < 10; i++)
					// arr[i] = hari;
					//  if (test.Contains("Date")
					//     { test.Remove(0); }

					//Console.WriteLine(alto);

					continue;
				}
				
			}
			//Console.ReadLine();
			arr = myStack.ToArray();
			// foreach (object v in arr)
			//{
			// arr2[v] = (Convert.ToDouble(v));
			//}
			// Convert.ToDouble(arr);
			//var bomb = new double[] {  };
			// double avg = Queryable.Average(bomb.AsQueryable());
			//Console.WriteLine("Mean price for FB is = " + avg);
			//arr2 = dList;
			//var arr3 = new double[] { arr2 };
			// double avg = Queryable.Average(arr2.AsQueryable());
			// Console.WriteLine("Mean price for FB is = " + avg);
			//MeanPrice();
		}

		public static void MeanPrice(List<Double> allList)
		{
			//var arr = new double[] { 10.5, 17.9, 25.7, 30.4, 40.5, 55.7 };
			//double avg = Queryable.Average());
			//Console.WriteLine("Mean price for FB is = " + avg);
			//return avg;
		}
	}
}
