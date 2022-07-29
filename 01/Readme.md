This is the solution of the folowing problem

Problem Statement
Create a program that reads in stock data from a .csv file. When the program runs, it should do the following:

 Create a Date class that does the following (30 points):
	o A default constructor
	o A constructor with an string argument
	o An integer member variable that represents date in the following format:
	 YYYYMMDD
	 i.e. 20070212 means February 12, 2007
	o A string member variable that represents date in the following format:
	 YYYY-MM-DD
	o An integer member variable that represents a year
	o An integer member variable that represents a month
	o An integer member variable that represents a day of the month
	o A method that converts a YYYY-MM-DD into YYYYMMDD
	o A method that converts a YYYYMMDD into YYYY-MM-DD
	o A method that extracts only the year from YYYYMMDD
	o A method that extracts only the month from YYYYMMDD
	o A method that extracts only the day from YYYYMMDD
	
 Create a Stock Class: this class will represent a stock. You need to decide the member variables of this class based on the input file. This input file is given to you and it is a “comma-separated-value” file (.csv). This class must have a Date type member variable. Use properties for all of the private member variables/fields. (30 points)

 The program will asks the user the file name which is “FB.csv”. If the user enters incorrect file name, the program terminates after displaying an error message on the Console. If the file name is correct, it creates a List of stocks and put all of the stock data into list. Each stock object represents one row of data from the FB.csv file. (10 Points)

 After reading all of the stock data into the program, create a method in the Main class named MeanPrice, which calculates the average price of the stock, Facebook. This method returns a double value. (10 Points)

 Create a method in the Main class named HighestPrice, which returns the highest price of the stock and its date. (10 Points) Create a method in the Main class named LowestPrice, which returns the LowestPrice of the stock and its date. (10 points).

Output

The program will display the mean price of the stock on the Console. It also displays the highest price and lowest price along with their corresponding dates on the Console.

Note
When calculating the mean, highest, and lowest price of the stock, please use adjusted price of the stock, NOT open, close, high, or low.
To understand how to read data from a .CSV file, you can download the sample code, ReadCSVFile.cs from Canvas.
What File To Turn In and How to Turn In Your Work using Canvas


You must turn in your C# program source code file(s) which must be named as follows:
Use this format: HW1_lastname_firstname.zip.
