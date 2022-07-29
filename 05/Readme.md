Solution of Attached problem file "IPC144 S1A Assignment 2.pdf"

Tool used: Visual Studio 2019 Enterprise

#################
Problem Statement

IPC144 S1A Assignment 2
In continuation to Assignment 1, the goal is to code procedures/functions in C programming language that prompt the customer to apply credit card application. You would need to create functions to get their data elements. These functions also responsible for checking the validity of the data elements (check the requirements listed below). Before you start the assignment, please make sure you know the followings:
• How to create a Hello-World program in C programing language.
• How to use printf to output characters, array of characters and strings, integer and floating-point numbers.
• How to use variables such as char, int, float, and array of characters.
• How to use scanf to read variables such as char, int, and float, array of characters
• How to use conditional if-then-else or switch statements in C programing language.
• How to create a function in C that return a value. How to create a function in C that perform a task without returning a value.
Requirements:
• You need to develop an application that would allow Customers to apply a credit card. For this purpose, you need to use the data elements in the appendix in order to collect customer’s information.
• When the application starts, you will ask Customer whether they are already an existing client or not
• If Customers responds with Yes, then the application would ask Card Number and password to validate the customer
• If Customer enters Card Number and password correctly, then the application pre-populates data elements as per the requirements.
• Then Customers would enter data elements as per the specs
• If Customers responds with No, then the application would get data elements from Customer as per the specs listed in the table
• Customers can try to enter Card Number and password max 3 times. After 3 times, the application displays a message and flow ends
• Customer can enter max of 3 Phone Types
• The application would check Customer’s response to satisfy data requirements
• The application would display values of all data elements before ending
• Because there is no database usage, you need to hard code data elements from your code and variable would keep captured data elements.
• Create functions to get data elements
• Before you end your program, you would need to summarize all data elements and display them on monitor.
• Check the name of the customer to be valid.
o The names should not contain any digits (e.g., “007” is not a valid name)
o Both first name and last name should have max of 30 characters.
o For simplicity, no middle name is needed and should not be captured.
• The customer should be 18 years and older. For simplicity, only track month and year of birth of the customer.
• Customer Phone number should be 10 character and includes only numbers from 0 to 9.
• The address should have Address, City, Province, Postal Code details
o Length of Address1 and Address2 fields should be max 50 characters.
o Length of City field should be max 30 characters.
o Length of Province field should be max 2 characters and be one of the following values (AB, BC, MB, NB, NL, NT, NS, NU, ON, PE, QC, SK, YT)
o Length of Postal code must be 6 characters.
• Process customer password by following these rules:
o At least 8 characters long.
o A mixture of both uppercase and lowercase letters
o A mixture of letters and numbers
o Inclusion of at least one special character (e.g., ! @ # ? & $)
o It should not include their birth year
o It should not contain common passwords (12345678, 1234567890, qwerty12, password, qwerty123, 1q2w3e4r, 11111111, abcd1234, AAAAAAAA)
• Make sure you create and use the following functions/procedures:
o getCardNumber
o getPassword
o getFirstName
o getLastName
o getAddress
o getDateOfBirth
o checkAge
o checkName
o checkCardNumber
o checkPassword
o other functions (details are provided under SPECIAL REQUIREMENTS of the appendix)
Submission Details:
1. The assignment is due TBD. When due date is decided, it will be posted on Blackboard. Source code (as *.c file) of the solution should be submitted to Blackboard. E-mail submissions are not accepted.
2. You need to convert/export your diagrams to PDF, Word or Image of the solution.
3. You should submit your solutions to Blackboard as one single file. You may want to package them as ZIP or RAR file. E-mail submissions are not accepted.
4. This assignment is composing 10% of your final mark.
5. This assignment should be done individually or with a team of 2 members. You can discuss it with your friends and classmates, but no more than one individual or team should submit the same assignment. If it is done so, all members will be punished with zero and disciplinary action will be applied. If you decide to work with a partner, both team members will get the same mark.
6. Any assignment that is submitted after due date will be punished with 10 points per day. It will be marked as zero after 2 days.
7. Please make sure all documentation is done using MS Word or PDF:
a. Please check the spellings, make sure your final document should have page numbers.
b. Please make sure you have a cover page that includes group member’s name, student number and the section you enrolled. Kindly make sure to include “IPC144 S1A - Assignment 2” in the cover page.
c. You need to explain your design along with some assumptions, if any.


Enjoy
