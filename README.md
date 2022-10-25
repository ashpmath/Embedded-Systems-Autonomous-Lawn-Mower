# Embedded Systems Autonomous Lawn Mower
Final Project for Embedded Systems

 ![lawn_mower](https://drive.google.com/file/d/16pOdbF1Pzxdpmm4ZNJFjJisFDZkH7_l5/view)

1. Problem Statement: Often autonomous mowers on the market today leave users with unappealing, uneven grass and dry patches in their lawn. These autonomous mowers neglect to use a systematic approach to mow grass. Currently they use randomized movement to cut the lawn which ends up ruining grass rather than helping. Our design would use a GPS module to receive the mower's coordinates and detect the area at which the user would like to mow. Then once acquired our mower moves in a methodically pattern and orderly fashion to ensure the robot won’t miss sections of your yard. Depending on the users request, our mower would allow the user to input the number of passes and windrows. To prevent injury our lawn mower uses a fan provided in our lab kit to simulate the blade of a lawn mower. 

2. Design Objectives: The design objective of our project is to provide lawn mower user’s with a robust autonomous system which mows grass in a systematic manner. Our mower uses precise coordinates to pinpoint where the robot must navigate to. 

3. Major System Requirements and Constraints:

    Major System Requirements:
    GPS Module uses NMEA standard to acquire mowers position/coordinates
    Push button is implemented to receive the number of passes the mower must take
    Lawn Mower has mechanism for simulating a lawn mower blade
    In our case, a DC Motor with a fan is used. 
    Ultrasonic Sensor must be able to detect the presence of an object so when the mower runs autonomously it doesn’t crash.
    The proximity sensor should also retrieve the distance per path.

    Major System Constraints:
    Due to time constraints the lawn mower only maneuvers forward and backward a number of times/passes (depends on user input).
    GPS coordinates are restricted to only acquire latitude and longitude not altitude. Some lawns/yards may be hilly so it does not account for this.
    The lawn mower is only a prototype so it can only run on smooth terrain. It does not account for rocky areas or function well on uneven surfaces. 

Societal Factors: Our design could change the way lawns are being mowed. People will no longer have to mow their yards. Not only will our mower work autonomously but no longer leave dry patches or mow in random directions leaving one's grass looking rugged. Our mower is designed to handle and mow in a methodical, ordered manner providing households with a better looking backyard. 

Public Health, Safety, and Welfare: In order to provide a safe functioning device there is a power button soldered to the mower in the event it malfunctions. We also use the Arduino fan part inside our kit to simulate a lawn mowers blade. This is to prevent user injury while functioning and testing our design. 
Social and Cultural Factors: Our design does not culturally enhance a specific group but is user friendly for all individuals regardless of their culture, ethnicity or background. 

Environmental Factors: Our device doesn’t exhibit any environmental concerns or cause hazardous effects to humans or nature. Ashley used recycled cardboard boxes to create a chassis for her mower and Erics used an RC car he previously owned.
Economic Factors: Autonomous vehicles are expensive due to the engineering and electronics costs. However, the budget needed for our project is relatively affordable for both students so while selecting components students found the cheapest items available on the market during Covid-19 pandemic. 

Pseudocode (Summary of code):
1.) Get GPS coordinates
2.) Ask user for number of lawnmower passes
3.) Turn 180 degrees when destination is reached
4.) Go back to the original location
5.) Stop vehicle if an object is detected 
6.)Keep repeating these passes until the number of passes entered by the user is reached, then display to LCD that the mowing is complete
