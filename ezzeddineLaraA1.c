/************************EzzeddineLaraA1.c**************
Student Name: Lara Ezzeddine Email Id: lezzeddi
Due Date: 07/10/2020 Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material that I have used, whether directly quoted or paraphrased. Furthermore, I certify that this assignment was prepared by me specifically for this course.
  ********************************************************/
// compiling: gcc ezzeddineLaraA1.c -std=c99 -Wall
// running the program: ./a.out


#include<stdio.h>
#include<stdlib.h>

// this function will get us the total cost based on user input
double
getTotalCost ()
{

  // declaring an array to store departure times
  int departureArray[8] = { 715, 815, 915, 1015, 1115, 1515, 1615, 1715 };
  char *departurePeriodLabelArray[8] =
    { "07:15 a.m.", "08:15 a.m.", "09:15 a.m.", "10:15 a.m.", "11:15 a.m.",
"03:15 p.m.", "04:15 p.m.", "05:15 p.m." };
  int departureArraySize = sizeof (departureArray) / sizeof (int);
  char *arrivalPeriodLabelArray[8] =
    { "08:25 a.m.", "09:25 a.m.", "10:25 a.m.", "11:25 a.m.", "12:25 p.m.",
"04:25 p.m.", "05:25 p.m.", "06:25 p.m." };
  // declaring an array to store cost times
  int costArray[8] = { 231, 226, 226, 283, 283, 226, 226, 401 };

  int timeFormat = 0;
  int hour = 0;
  int minutes = 0;
  char period = 's';
  char finalSelectedTime[50];
  int daysHotel = 0;
  int hotelRoom = 2;
  int hotelType;
  int needRide;
  double totalCost = 0;
  int hotelCosts[3] = { 248, 90, 128 };
  int rideCosts[3] = { 0, 25, 20 };
  int dayOfBirth;
  int gotDiscount1 = 0;
  int gotDiscount2 = 0;
  double totalDiscount = 0;
  int totalHotelCost = 0;
  int totalRideCost = 0;
  double finalCost;

  // Task 1 & 2 starts here

  printf ("This will run for 3 transactions\n");

  while (timeFormat != 1 && timeFormat != 2)
    {

      printf
	("\nWould you like to enter the time in 12-hour format (enter 1) or 24-hour format (enter 2)? ");

      scanf ("%d", &timeFormat);

    }

  if (timeFormat == 1)
    {
      printf ("\nEnter time in 12 hour format \n");
      printf ("\nEnter a value between 0 and 12 for hour: ");
      scanf ("%02d", &hour);

      while (hour > 12 || hour < 0)
	{

	  printf ("Enter a value between 0 and 12 for hour: ");
	  scanf ("%02d", &hour);

	}
      printf ("Enter a value between 0 and 60 for minutes: ");
      scanf ("%02d", &minutes);
      while (minutes > 60 || minutes < 0)
	{

	  printf ("Enter a value between 0 and 60 for minutes: ");
	  scanf ("%02d", &minutes);

	}
      printf ("Enter a for a.m and p for p.m: ");
      while (period != 'a' && period != 'p')
	{
	  scanf ("%c", &period);

	}
    }
  else if (timeFormat == 2)
    {
      printf ("\nEnter time in 24 hour format \n");
      printf ("Enter a value between 0 and 24 for hour: ");
      scanf ("%02d", &hour);
      while (hour > 24 || hour < 0)
	{
	  printf ("Enter a value between 0 and 24 for hour: ");
	  scanf ("%02d", &hour);
	}
      printf ("Enter a value between 0 and 60 for minutes: ");
      scanf ("%02d", &minutes);
      while (minutes > 60 || minutes < 0)
	{
	  printf ("Enter a value between 0 and 60 for minute: \n");
	  scanf ("%02d", &minutes);
	}
    }

  printf ("\n");
  printf ("----------------------------------------\n");

  if (timeFormat == 1)
    {
      printf ("You entered %02d:%02d %c.m\n", hour, minutes, period);

      if (period == 'a')
	{
	  if (hour >= 12)
	    {
	      sprintf (finalSelectedTime, "%02d%02d", hour + 12, minutes);
	      printf ("In 24 hours format - you entered %02d:%02d \n",
		      hour + 12, minutes);
	    }
	  else
	    {

	      sprintf (finalSelectedTime, "%02d%02d", hour, minutes);
	      printf ("In 24 hours format - you entered %02d:%02d \n", hour,
		      minutes);

	    }
	}

      if (period == 'p')
	{
	  if (hour >= 12)
	    {
	      sprintf (finalSelectedTime, "%02d%02d", hour, minutes);
	      printf ("In 24 hours format - you entered %02d:%02d \n", hour,
		      minutes);
	    }
	  else
	    {

	      sprintf (finalSelectedTime, "%02d%02d", hour + 12, minutes);
	      printf ("In 24 hours format - you entered %02d:%02d \n",
		      hour + 12, minutes);

	    }
	}
    }
  else if (timeFormat == 2)
    {
      printf ("You entered %02d:%02d \n", hour, minutes);
      if (hour == 12)
	{

	  printf ("In 12 hours format - you entered %02d:%02d p.m. \n", hour,
		  minutes);

	}
      else if (hour == 24)
	{

	  printf ("In 12 hours format - you entered %02d:%02d a.m. \n",
		  hour - 12, minutes);

	}
      if (hour <= 23 && hour > 12)
	{

	  printf ("In 12 hours format - you entered %02d:%02d p.m. \n",
		  hour - 12, minutes);

	}
      else if (hour == 0)
	{

	  printf ("In 12 hours format - you entered 12:%02d a.m. \n",
		  minutes);

	}
      else if (hour < 12)
	{

	  printf ("In 12 hours format - you entered %02d:%02d a.m. \n", hour,
		  minutes);

	}

      sprintf (finalSelectedTime, "%02d%02d", hour, minutes);

    }


  printf ("----------------------------------------\n");

  int selectedTime = atoi (finalSelectedTime);
  sscanf (finalSelectedTime, "%d", &selectedTime);
  int selectedDepartureArrayIndex = 0;
  for (int i = 0; i < departureArraySize; i++)
    {

      if (departureArray[i] > selectedTime)

	{

	  selectedDepartureArrayIndex = i;
	  break;

	}
    }

  printf ("Closest departure times is %s, arriving at %s \n",
	  departurePeriodLabelArray[selectedDepartureArrayIndex],
	  arrivalPeriodLabelArray[selectedDepartureArrayIndex]);

  // Task 1 & 2 ends here

  // Task 3, 4 & 5 starts from here

  printf
    ("\nWould you like a hotel in Montreal - enter 0 for no; 1 for yes? ");

  scanf ("%d", &hotelRoom);

  if (hotelRoom == 1)
    {

      printf ("\nThere are 3 hotels: \n");

      printf ("1. Marriot for $248.00 per night \n");

      printf ("2. Sheraton for $90.00 per night \n");

      printf ("3. The Double Tree $128.00 per night \n");

      printf ("\nYour choice?:");

      scanf ("%d", &hotelType);

      printf ("\nHow many days are you going to be staying in Montreal?");

      scanf ("%d", &daysHotel);

      printf
	("\nWould you like a ride from the airport to the hotel - enter 0 for no; 1 for yes? ");

      scanf ("%d", &needRide);

      totalHotelCost = (hotelCosts[hotelType - 1] * daysHotel);
      totalRideCost = rideCosts[hotelType - 1];
      totalCost =
	costArray[selectedDepartureArrayIndex] + totalHotelCost +
	totalRideCost;

    }

  else if (hotelRoom == 0)
    {

      totalCost = costArray[selectedDepartureArrayIndex];

    }

  // Task 6 starts here

  printf ("\nNow you enter day of birth to qualify for discount2: ");

  scanf ("%d", &dayOfBirth);

  int tempTotalCost = totalCost;
  // if its a multiple of 11, we give him discount1
  if (tempTotalCost % 11 == 0)
    {
      totalDiscount = (totalCost * 0.05);
      tempTotalCost = tempTotalCost - totalDiscount;
      gotDiscount1 = 1;
      int sum = 0;
      while (dayOfBirth != 0)
	{
	  sum = sum + dayOfBirth % 10;
	  dayOfBirth = dayOfBirth / 10;
	}
      // if its still multiple of 11, we give him discount2
      if (tempTotalCost % sum == 0)
	{
	  totalDiscount = totalDiscount + (totalCost * 0.05);
	  gotDiscount2 = 1;
	}
    }
  else
    {
      int sum = 0;
      while (dayOfBirth != 0)
	{
	  sum = sum + dayOfBirth % 10;
	  dayOfBirth = dayOfBirth / 10;
	}
      // if its still multiple of 11, we give him discount2
      if (tempTotalCost % sum == 0)
	{
	  totalDiscount = totalDiscount + (totalCost * 0.05);
	  gotDiscount2 = 1;
	}
    }
  // Task 6 ends here

  printf ("\nYour total cost comes to: \n");

  printf ("Cost of closest departure time: $ %d.00\n",
	  costArray[selectedDepartureArrayIndex]);
  printf ("Cost of Hotel for %d days: $ %d.00\n", daysHotel, totalHotelCost);

  if (needRide == 0)
    {

      printf ("Cost of ride: $ 0\n");

    }

  else
    {

      printf ("Cost of Ride: $ %d.00\n", totalRideCost);

    }

  printf ("\nTotal Cost Before Tax: $ %0.2lf\n", totalCost);

  // Task 3, 4 & 5 ends from here
  // if we get the discount1
  if (gotDiscount1 == 1)
    {

      printf
	("\nYou got a discount of 5%% because the total cost was a multiple of 11 :) \n");

    }
  else
    {

      printf
	("\nSorry - you missed out on the 5%% discount because the total cost was not a multiple of 11 \n");

    }

  // if we get the discount2
  if (gotDiscount2 == 1)
    {

      printf
	("You get an additonal 5%% discount because the total cost was a multiple of the sum of digits in your day of birth :) \n");
    }
  else
    {

      printf
	("Sorry - you missed out on the additional 5%% discount because the total was not multiple of sum of your day of birth\n");

    }

  printf ("\nThe total cost after discounts 1 and 2 is : $ %0.2lf\n",
	  totalCost - totalDiscount);

  // no calculting the total discount
  totalCost = totalCost - totalDiscount;
  finalCost = totalCost + (totalCost * 0.13);
  printf ("\nFinally, your total cost after taxes: $ %0.2lf\n", finalCost);

  printf ("----------------------------------------\n");
  printf ("\n");

  return finalCost;
}

int
main (void)
{

  // the following will store the best deal for the user in terms of cost
  double costArray[3];
  // initializing it to the hightest
  double lowestCost = 10000;
  int lowestCostIndex = 0;

  for (int i = 0; i < 3; i++)
    {
      costArray[i] = getTotalCost ();
    }

  for (int j = 0; j < 3; j++)
    {
      if (lowestCost > costArray[j])
	{
	  lowestCost = costArray[j];
	  lowestCostIndex = j + 1;
	}
    }


  printf
    ("\nOption number %d is the best option for you with a minimum cost %0.2lf\n",
     lowestCostIndex, lowestCost);
  // using loop to find the lowest
  return 0;
}
