#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//global variables

//for id of customer
int temp = 0;

//name
char FirstName[30];
char LastName[30];

//birthdate
int BMonth = 0;
int BDay = 0;
int BYear = 0;

//age
int Age = 0;

//email
char EMailAddress[50];

//phone info
int PhoneType = 0;
int PhoneNo = 0;

//home address
char Address1[50];
char Address2[50];
char City[30];
char Province[3];
char PostalCode[6];

//living situation
int LivingSituation = 0;

//duration of living at address
int LYears = 0;
int LMonths = 0;

//social insurance number
char SIN[9] = "\0";

//kind of work
int JobCategory = 0;
char JobDescription[30];

//yearly income
int PersonalIncome = 0;
int OtherIncome = 0;

//pay for housing
int PayForHouse = 0;

//customer id
int CustomerId = 0;

//card Number
char CardNumber[16] = "123456789";

//password
char Password[9] = "Hithere";

///////////////////Function Headers////////////////////////////////////////////

//functions headers from assignment
void getCardNumber();
void getPassword();
void getFirstName();
void getLastName();
void getAddress();
void getDateOfBirth();
void checkAge();
void checkName();
void checkCardNumber();
void checkPassword(char pass[8]);

//custom function headers 
void handleExistingCustomer();
void handleNewCustomer();
void loadSampleData();
void showSampleData();
int calculateAge();
void checkEmail();
void getLivingSituation();
void getLivingDuration();
void getInsuranceNo();
void getJobCategory();
void getJobDesc();
void getYearlyIncome();
void getHouseHoldIncome();
void getCustomerId();
void showAllData();
void showMenu();

//////////////////////Functions Body/////////////////////////////////////////

void getCardNumber()
{
	//getting card number from user
	char inputCNo[16];
	printf("\nEnter Card Number: ");
	scanf("%s", inputCNo);

	if (strcmp(CardNumber, CardNumber))
	{
		printf("\n\nInvalid Card Number.\n\n");
		exit(1);
	}
}
void getPassword()
{
	// getting password from user
	char inputPass[8];
	printf("\nEnter Password: ");
	scanf("%s", inputPass);

	if (strcmp(inputPass, Password))
	{
		printf("\n\nInvalid Password.\n\n");
		exit(1);
	}
}
void getFirstName()
{
	// getting first from user
	char inputFName[30];
	printf("\n(Max 30 Char)Enter First Name: ");
	scanf("%s", inputFName);

	strcpy(FirstName, inputFName);
}
void getLastName()
{
	// getting first from user
	char inputLName[30];
	printf("\n(Max 30 Char)Enter Last Name: ");
	scanf("%s", inputLName);

	strcpy(FirstName, inputLName);
}
void getAddress()
{
	char response[50];
	printf("\nEnter Address1: ");
	scanf("%s", &response);
	strcpy(Address1, response);

	char response1[50];
	printf("\nEnter Address2: ");
	scanf("%s", &response1);
	strcpy(Address2, response1);

	char response2[30];
	printf("\nEnter City: ");
	scanf("%s", &response2);
	strcpy(City, response2);

	char response3[3];
	printf("\n(AB, BC, MB, NB, NL, NT, NS, NU, ON, PE, QC, SK, YT) Enter Province: ");
	scanf("%s", &response3);
	if (strcmp(response3, "ab") && strcmp(response3, "bc") && strcmp(response3, "mb") && strcmp(response3, "nb") && strcmp(response3, "nl") && strcmp(response3, "nt")
		&& strcmp(response3, "ns") && strcmp(response3, "nu") && strcmp(response3, "on") && strcmp(response3, "pe") && strcmp(response3, "qc") && strcmp(response3, "sk")
		&& strcmp(response3, "yt"))
	{
		printf("\n\nEnter the valid province from list given.\n\n");
		exit(1);
	}
	strcpy(Province, response3);

	char response4[6];
	printf("\nEnter Postal Code: ");
	scanf("%s", &response4);
	strcpy(PostalCode, response4);

}
void getDateOfBirth()
{
	int response;
	printf("\nEnter Month of birth (1-12): ");
	scanf("%d", &response);

	if (!response >= 1 && !response <= 12)
	{
		printf("\n\nEnter Month of birth between range(1-12).\n\n");
		exit(1);
	}
	BDay = response;

	response = 0;
	printf("\nEnter day of birth (1-31): ");
	scanf("%d", &response);

	if (!response >= 1 && !response <= 31)
	{
		printf("\n\nEnter Day of birth between range(1-31).\n\n");
		exit(1);
	}
	BMonth = response;

	response = 0;
	printf("\nEnter year of birth: ");
	scanf("%d", &response);

	BYear = response;
}
void checkAge()
{
	if (Age < 18)
	{
		printf("\n\nAge cannot be less than 18.\n\n");
		exit(1);
	}
}
void checkName()
{
	for (int i = 0; i < sizeof FirstName; i++)
	{
		if ((int)FirstName[i] >= 48 && (int)FirstName[i] <= 57)
		{
			printf("\n\nFirst Name or Last Name cannot contain intergers\n\n");
			exit(1);
		}
	}

	for (int i = 0; i < sizeof LastName; i++)
	{
		if ((int)LastName[i] >= 48 && (int)LastName[i] <= 57)
		{
			printf("\n\nFirst Name or Last Name cannot contain intergers\n\n");
			exit(1);
		}
	}
}
void checkCardNumber() {}
void checkPassword(char pass[8]) 
{
	bool isSCharExist = false;
	bool isNumberExist = false;
	bool isUpperCase = false;
	bool isLowerCase = false;
	bool isBirthYearFree = false;
	bool isNotCommonPass = false;

	//if less than 8 char
	if(sizeof(pass)/sizeof pass[0] <9)
	{
		printf("%d\n",sizeof pass) / sizeof pass[0];
		printf("\nPassword should be 8 char long");
		exit(0);
	}

	for (int i = 0; i < sizeof pass; i++)
	{
		if (pass[i] == '!' || pass[i] == '@' || pass[i] == '#' || pass[i] == '&' || pass[i] == '$')
		{
			isSCharExist = true;
		}

		if(pass[i] >= 48 && pass[i]<= 57)
		{
			isNumberExist = true;
		}

		if(pass[i] >= 65 && pass[i] <= 90)
		{
			isUpperCase = true;
		}

		if (pass[i] >= 97 && pass[i] <= 122)
		{
			isLowerCase = true;
		}
	}

	if(strstr(pass, (char*)BYear) == NULL)
	{
		isBirthYearFree = true;
	}

	if(strcmp(pass, "12345678") && strcmp(pass, "1234567890") && strcmp(pass, "qwerty12") && strcmp(pass, "password") && strcmp(pass, "qwerty123") 
		&& strcmp(pass, "1q2w3e4r") && strcmp(pass, "11111111") && strcmp(pass, "abcd1234") && strcmp(pass, "AAAAAAAA"))
	{
		isNotCommonPass = true;
	}


	{
		if(isSCharExist !=  true && isNumberExist !=  true, isUpperCase !=   true, isLowerCase != true, isBirthYearFree != true,
		   isNotCommonPass != true)
		{
			printf("\n\nEnter a valid password.\n\n");
		}

		else 
		{
			strcpy(Password, pass);
		}
	}
}

void handleExistingCustomer()
{
	//getting card number and password
	getCardNumber();
	getPassword();

	//pre populating data
	loadSampleData();

	//showing sample data
	showSampleData();

	exit(1);
}
void handleNewCustomer()
{
	//taking input of name
	getFirstName();
	getLastName();

	//checking name if valid
	checkName();

	//input of birth info
	getDateOfBirth();

	//calculate age
	Age = calculateAge();

	checkAge();

	//geting email address
	char response[50];
	printf("\n(Max 50 Char)Enter Email Address: ");
	scanf("%s", response);
	strcpy(EMailAddress, response);

	//validating email address
	checkEmail();

	//getting address
	getAddress();

	//geting living situation
	getLivingSituation();

	//living duration
	getLivingDuration();

	//social insurance no
	getInsuranceNo();

	//getting job category
	getJobCategory();

	//getting job decription
	getJobDesc();

	//getting yearly income
	getYearlyIncome();

	//get optional income
	getHouseHoldIncome();

	//how much for housing
	printf("\nHow much do you pay for housing? if no hit enter. ");
	int response1;
	scanf("%d", &response1);

	if(response1 != '\n')
	{
		PayForHouse = response1;
	}

	//customer id generation
	getCustomerId();

	//getting card number
	printf("\nEnter Card Number (0-9) ");
	char response2[16];
	scanf("%s", &response2);
	strcpy(CardNumber, response2);

	//getting new password
	printf("\nEnter password it should have:");
	printf("\n - 8 char long");
	printf("\n - mixture of upper and lower case");
	printf("\n - mixture of letter and number");
	printf("\n - at least one special char e.g @");
	printf("\n - it should not be birth year \n");
	char response3[8];
	scanf("%s", &response3);
	checkPassword(response3);

	//showing info
	showAllData();
	
}
void loadSampleData()
{
	// pre populating data
	// first name
	strcpy(FirstName, "M");

	// Last name
	strcpy(LastName, "Osama");

	// age
	BDay = 30;
	BMonth = 12;
	BYear = 1999;
	Age = calculateAge();

	// email
	strcpy(EMailAddress, "iam123@gmail.com");

	// phone type
	PhoneType = 3;

	// phone number
	PhoneNo = 3488004655;

	// home address
	strcpy(Address1, "HNo 9, street 10f");
	strcpy(Address2, "HNo 11, street 11a");
	strcpy(City, "New York");
	strcpy(Province, "MB");
	strcpy(PostalCode, "90000");


	// sin
	//not available

	// job category
	// not available

	// job decription
	//not available
}
void showSampleData()
{
	// showing pre populating data
	// name
	printf("\nName: %s %s", FirstName, LastName);

	// age
	printf("\nAge: %d", Age);

	// email
	printf("\nEmail: %s", EMailAddress);

	// phone type
	if (PhoneType == 1)
	{
		printf("\nPhone Type: Home");
	}
	else if (PhoneType == 2)
	{
		printf("\nPhone Type: Work");
	}

	else if (PhoneType == 3)
	{
		printf("\nPhone Type: Mobile");
	}

	// phone number
	printf("\nPhone No: %d", PhoneNo);

	// home address
	printf("\nAddress1: %s", Address1);
	printf("\nAddress2: %s", Address2);
	printf("\nCity: %s", City);
	printf("\nProvice: ", Province);
	printf("\nPostal Code: %s", PostalCode);


	// sin
	//not available

	// job category
	// not available

	// job decription
	//not available
}
int calculateAge()
{
	int currentYear = 2022;

	int ageTemp = currentYear - BYear;

	return ageTemp;
}
void checkEmail()
{
	bool isDotExist = false, isAtExist = false;

	for (int i = 0; i < sizeof EMailAddress; i++)
	{
		if (EMailAddress[i] == '@')
		{
			isAtExist = true;
		}

		if (EMailAddress[i] == '.')
		{
			isDotExist = true;
		}
	}

	if (isDotExist == false || isAtExist == false)
	{
		printf("\n\nEnter Valid Email Address Next time.\n\n");
		exit(1);
	}
}
void getLivingSituation()
{
	printf("\nEnter Living situation: ");
	printf("\n 1. Rent: ");
	printf("\n 2. Own/Buying: ");
	printf("\n 3. Live With Parents: ");
	printf("\n 4. Room or Board: ");
	printf("\n 5. Other: \n");

	int response;
	scanf("%d", &response);

	if (!response >= 1 && !response <= 5)
	{
		printf("\n\nEnter the correct choice\n\n");
		exit(1);
	}

	LivingSituation = response;
}
void getLivingDuration()
{
	printf("\nFrom How long you living in this address?");
	printf("\nEnter Years. eg 2: ");
	int response;
	scanf("%d", &response);
	LYears = response;

	printf("\nEnter Month: ");
	int response2;
	scanf("%d", &response2);

	if (!response2 >= 1 && !response2 <= 12)
	{
		printf("\n\nEnter Month of birth between range(1-12).\n\n");
		exit(1);
	}
	LMonths = response2;
}
void getInsuranceNo()
{
	char response[9];
	printf("\nEnter Insurance No if no hit enter: ");
	scanf("%s[^\n]", &response);

	if (strcmp(response, "\n"))
	{
		strcpy(SIN, response);
	}
}
void getJobCategory()
{
	printf("\nEnter Job Category: if no hit enter ");
	printf("\n 1. Category-1 ");
	printf("\n 2. Category-2 ");
	printf("\n 3. Category-3 ");
	printf("\n 4. Category-4 ");
	printf("\n 5. Category-5 \n");

	int response = 0;
	scanf("%s[\^n]", &response);

	if (response != '\n' || response != '\r')
	{
		if (!response >= 1 && !response <= 5)
		{
			printf("\n\nEnter the correct choice\n\n");
			exit(1);
		}

		JobCategory = response;
	}
}
void getJobDesc()
{

	char response[30] = "\n";
	printf("\n(Max 30 char) Enter job description if no hit enter: ");
	while ((getchar()) != '\n');
	fgets(response, sizeof response, stdin);
	//scanf("%s", &response);
	if(strcmp(response, "\n"))
	{
		strcpy(JobDescription,response);
	}
}
void getYearlyIncome()
{
	int response;
	printf("\nEnter yearly personal income: ");
	scanf("%d", &response);

	if (response == NULL) 
	{
		printf("\n\nEnter yearly personal income correctly\n\n");
		exit(1);
	}

	PersonalIncome = response;
}
void getHouseHoldIncome()
{
	int response;
	printf("\nEnter House hold income if no hit enter: ");
	scanf("%d", &response);

	if(response != '\n')
	{
		OtherIncome = response;
	}
}
void getCustomerId()
{
	//generating customer id
	temp += 2;
	CustomerId = temp;
}
void showAllData()
{
	// showing pre populating data
	// name //all info
	printf("\nName: %s %s", FirstName, LastName);

	// age
	printf("\nAge: %d", Age);

	// email
	printf("\nEmail: %s", EMailAddress);

	// phone type
	if (PhoneType == 1)
	{
		printf("\nPhone Type: Home");
	}
	else if (PhoneType == 2)
	{
		printf("\nPhone Type: Work");
	}

	else if (PhoneType == 3)
	{
		printf("\nPhone Type: Mobile");
	}

	// phone number
	printf("\nPhone No: %d", PhoneNo);

	// home address
	printf("\nAddress1: %s", Address1);
	printf("\nAddress2: %s", Address2);
	printf("\nCity: %s", City);
	printf("\nProvice: ", Province);
	printf("\nPostal Code: %s", PostalCode);

	//living situation
	if(LivingSituation == 1)
	{
		printf("\n 1. Rent: ");
	}
	else if(LivingSituation == 2)
	{
		printf("\n 2. Own/Buying: ");
	}
	else if (LivingSituation == 3)
	{
		printf("\n 3. Live With Parents: ");
	}
	else if (LivingSituation == 4)
	{
		printf("\n 4. Room or Board: ");
	}
	else if (LivingSituation == 5)
	{
		printf("\n 5. Other: ");
	}

	//duration of living
	printf("\nLiving at the address from: %d years and %d months",LYears,LMonths);

	//sin
	printf("Social Insurance: %s",SIN);

	//kind of work
	if(JobCategory == 1)
	{
		printf("\n 1. Category-1 ");
	}
	else if(JobCategory == 2)
	{
		printf("\n 2. Category-2 ");
	}
	else if (JobCategory == 3)
	{
		printf("\n 3. Category-3 ");
	}
	else if (JobCategory == 4)
	{
		printf("\n 4. Category-4 ");
	}
	else if (JobCategory == 5)
	{
		printf("\n 5. Category-5 ");
	}

	//job description
	printf("\nJob Description: %s",JobDescription);

	//income
	printf("\nPersonal income: %d other income: ", PersonalIncome, OtherIncome);

	//pay for house
	printf("\nPaying for House: %d",PayForHouse);

	//CustomerId
	printf("\nCustomer Id: %d", CustomerId);

	//card number
	printf("Card Number: %d", CardNumber);
}
void showMenu()
{
	//checking if customer is already client or not
	char inputResponse[8];
	printf("Are you existing client? ");
	scanf("%s", inputResponse);

	if (!strcmp(inputResponse, "yes"))
	{
		handleExistingCustomer();
	}

	else if (!strcmp(inputResponse, "no"))
	{
		handleNewCustomer();
	}
}


/////////////////Main Function///////////////////////////////

int main()
{
	showMenu();
}