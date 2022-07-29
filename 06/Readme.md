Solution of Attached problem file "Vehicle Rental Case Study.docx"

Tool used: Visual Studio 2019 Enterprise 

#####################################################

Problem

Assessment Brief 
This assessment is designed to allow you to demonstrate your fundamental programming skills in C/C++ using good object-oriented practice though the implementation of a basic Vehicle Rental system (and it is very basic as you shall discover).  It is important to read this document and understand the techniques and competencies you are being asked to demonstrate in parts of this application to ensure you meet the grading scheme set out in the Assessment Criteria section of this document (at the end).  Where no specific guidance is given, make your own decisions based on good practice coding.  
Consider and think about your implementation and perhaps undertake refinement passes, depending on your development strategy, to ensure your code is of good quality.  Do not focus purely on implementing the system in isolation of the guidelines; the assessment brief ensures there are suitable opportunities for you to demonstrate your understanding in key areas while also allowing you to demonstrate your creativity and thinking.  While this assessment specification does ask for specific techniques to be used in certain places, there is more left to you to think about the best way of tackling the problem.  
There is no single right solution, and this assessment is as much about you being able to deploy key programming concepts as it is about you being able to think about and problem solve your way through the creation of an application using your knowledge, thinking, experience and general programming skills.
Vehicle Rental Case Study
When the application starts, the program loads a list of rental vehicles from disk into a single Standard Template Library (STL) vector.  There are two types of vehicles that can be rented: Car and Van.  Both types of vehicles have a registration number, make, model and rental cost per day (as a minimum set or attributes).  Cars additionally have information about the number of doors and number of seats.  As well as the basic vehicle properties, Vans also have information about their maximum carry weight and holding capacity.  Full vehicle rental history should not be loaded at this stage and there may be zero or more vehicles to load.  Use C-Strings to store the registration number using your own heap memory management.  Vehicle information should only be saved back to disk once the user closes the application via the Exit option.
The launch screen starts with a main menu vehicle management screen, as illustrated in Figure 1.  On this screen, the user can sort vehicles in alphabetical order of their registration number or by cost per day.  Sorting must be done using a suitable STL algorithm(s), and the vehicle information is redisplayed to reflect the update.  There is no automatic sorting when adding or removing vehicles and they maintain their order unless the user chooses to sort the list using the menu options.
The user can add and/or remove vehicles and search for a car or van from the main menu.  Vehicle registration numbers must be unique within the application (case insensitive).   When a new vehicle is added or one is removed, the required user interaction occurs, and the vehicle management / main menu is redisplayed with the updated list.  Nothing is saved back to disk until the user exits the program by choosing the Exit item on the launch screen and all operations are done to data in memory up to that point.
 
Figure 1: Example of the vehicle management / main menu

The other option from the main menu is to search for a specific car or van.  
If the user wishes to search for a car, they have the following options to search by:
•	Registration number
•	Number of seats
•	Number of doors
If the user wishes to search for a van, they have the following options to search by:
•	Registration number
•	Max carry weight
•	Max holding capacity

The vehicles that match the search criteria are displayed, allowing the user to select one of them or return to the main menu, as illustrated in Figure 2.
 
Figure 2: Example of search for car screen
When the user selects a vehicle, it’s rental history is loaded from disk  and stored in memory, and the vehicle information screen is shown, as illustrated in Figure 3.  The vehicle history should be stored in memory using your own heap array that you resize as needed (do not use an STL vector for this and resize as needed within your application).  The vehicle history must include total rental income, total days rented along with a rental history for each time it was rented to a customer.
	
 
Figure 3: Example of the main vehicle information screen
From the vehicle information screen, the user can view its history (see Figure 4 for an example), create a new rental record, and return to the main menu.  When the user returns to the main menu, the vehicle’s rental history is written back to disk and released from heap memory.

 
Figure 4: Example of vehicle rental history screen
When the user creates a new vehicle rental record, they are asked for the necessary details and this is added to the vehicle’s rental history in memory and the vehicle information screen is reshown.  Saving this rental to disk is not done at this state, and only once the user chooses to exit the vehicle information screen and return to the main menu.  The application returns to the vehicle information screen (Figure 3) upon completing a new rental record with those details updated.  

General Tips and Comments
•	All loading from disk should be done using operator overloading (assisting encapsulation).  There maybe other sensible places that operator overloading can be used – think about the possibilities and deploy additional examples of operator overloading in your application where appropriate
•	You are being asked to load data into memory and only write it back out at certain points to ensure you are successfully managing heap memory (as well as trying to help direct you towards a sensible control flow).  This will also need you to think about your class and data structures to effectively hold that information in memory – remember to use appropriate data types for variables, objects, and full encapsulation principles.
•	Ensure your application gives sensible feedback to the user and handles input errors gracefully, including recovery were possible (i.e. don’t just exit or crash when an error occurs).  You can sensibly limit allowed input characters to do this but remember to tell the user and give useful messages.
•	The amount of heap memory available should be your only limit on the number of vehicles your application can remember along with their history, but don’t be wasteful with heap memory
•	Consider other opportunities to deploy the STL beyond those explicitly stated in this document
•	Write good object-oriented code where algorithms that operate on data are put into the same class and data members have as restrictive access as possible.  A poor design is one where you have a class of data and just get and set methods and the operations on those bits of data is done outside of the class
•	Think about your code, use appropriate C/C++ constructs, and keep the implementation as simple as it allows – code that is unnecessarily complex is harder to maintain, debug, and likely inefficient
•	DO NOT USE ANY FORM OF RECURSION TO DEAL WITH THE MENU SYSTEM NAVIGATION – THIS WILL LEAD TO SPAGHETTI CALL STACKS – USE LOOPS AND METHODS TO STRUCTURE THIS BEHAVIOUR.  I have tried to help lead you down the right path with some of the constraints and behaviours I have asked for in this specification

Submission
Your assignment should be submitted electronically through the module Blackboard site as a single ZIP file that contains your project and source code files (but without the build and intellisense files and folders).  Your last on time attempt will be viewed and graded (as per university regulations).
The submission must be in the form of a Visual Studio 2019 project within the compressed ZIP file and contain all files that allow the project to be opened, built, and run on a campus computer.  Make sure that you upload the correct files by checking what you have submitted by downloading it again from Blackboard and opening the project from the UNZIP of the submission - mistakes discovered after the deadline cannot be corrected; it is your responsibility to ensure that you submit the correct files by the deadline.  You may be asked to provide a walkthrough of your code during which you will need to discuss all aspects of the work you submitted before a grade is awarded.

Avoiding Plagiarism
Looking for snippets of code on the internet and searching for materials that will help solve parts of a problem is part of software development.  If you do this, you must add a comment in your code stating the URL for snippets of code that have heavily influenced your solution and a short summary of what you have taken / learnt to demonstrate you understand and not just unashamedly lift it.  You should not be directly copy from the internet (or elsewhere), even once referenced, but making it your own code anyway.  There is no need to reference core learning that you apply to this task – for example, if you have learnt how to use lambda expression and applied it here, that is fine.  
This assessment is about you demonstrating your knowledge and understanding when it comes to programming and not the internet’s, your friend’s, or Discord’s.  If you try to pass off work as your own that isn’t, then an academic conduct meeting will be arranged, and you’ll likely get zero marks.  A second offense can lead to withdrawal from the course, so please ask if you’re unsure.

Grading
Please see the assessment criteria rubric at the end of this document.  The marking aligns to the university generic grading descriptor against the key competencies and criteria given in the left-most column.  Standard university grading is being used for this task.


Enjoy
