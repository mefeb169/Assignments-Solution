using System;
//using Date1; // no se si esto esta bien 
using Project1feb;
using Project1Feb;

namespace Project1feb
{
    public class Stock
    {
		#region Region New Code
		public Stock()
		{

		}

		public Stock(Date date, string open, string high, string low, string close, string adjClose, string volume)
		{
			Date = date;
			Open = open;
			High = high;
			Low = low;
			Close = close;
			AdjClose = adjClose;
			Volume = volume;
		}

		public Date Date { get; set; }
		public string Open { get; set; }
		public string High { get; set; }
		public string Low { get; set; }
		public string Close { get; set; }
		public string AdjClose { get; set; }
		public string Volume { get; set; }
		#endregion

		#region Region Old Code
		private DateTime date;
		private double open;
		private double high;
		private double low;
		private double close;

		//public string adjclose = Readfile.adjClose;

		private int volume;

		public string _adjclose
		{
			get { return _adjclose; }
			set
			{
				ReadFile readFile = new ReadFile();
				_adjclose = readFile.adjClose;
			}
		}


	#endregion
	}
}