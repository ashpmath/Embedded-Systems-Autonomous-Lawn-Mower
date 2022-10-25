# Embedded Systems Autonomous Lawn Mower
Final Project for Embedded Systems
 
![autonomous lawn mower](https://user-images.githubusercontent.com/73625048/197658916-ce5dfcb6-56dd-40a4-b20d-a9bb474c7463.png)

1. Problem Statement: Often autonomous mowers on the market today leave users with unappealing, uneven grass and dry patches in their lawn. These autonomous mowers neglect to use a systematic approach to mow grass. Currently they use randomized movement to cut the lawn which ends up ruining grass rather than helping. The design  implemented uses a GPS module to receive the mower's coordinates and detect the area at which the user would like to mow. Then once acquired, the mower moves in a methodical pattern and orderly fashion to ensure the robot won’t miss sections of your yard. Depending on the users request, the mower allows the user to input the number of passes and windrows. To prevent injury our lawn mower uses a fan provided in our lab kit to simulate the blade of a lawn mower. 

2. Design Objectives: The design objective of the project is to provide lawn mower user’s with a robust autonomous system which mows grass in a systematic manner. The  prototype mower built uses precise coordinates to pinpoint where the robot must navigate to. 

3. Major System Requirements and Constraints:

    Major System Requirements:
    GPS Module uses NMEA standard to acquire mowers position/coordinates
    Push button is implemented to receive the number of passes the mower must take
    Lawn Mower has mechanism for simulating a lawn mower blade (DC Motor with a fan is used). 
    Ultrasonic Sensor must be able to detect the presence of an object so when the mower runs autonomously it doesn’t crash.
    The proximity sensor should also retrieve the distance per path.
    
    ![SystemOverview](https://user-images.githubusercontent.com/73625048/197659556-8ec9bf33-d089-4148-9277-2cf4aad5e0ce.png)

    Major System Constraints:
    Due to time constraints the lawn mower only maneuvers forward and backward a number of times/passes (depends on user input).
    GPS coordinates are restricted to only acquire latitude and longitude not altitude. Some lawns/yards may be hilly so it does not account for this.
    The lawn mower is only a prototype so it can only run on smooth terrain. It does not account for rocky areas or function well on uneven surfaces. 

Societal Factors: This prototype design can change the way lawns are being mowed. People will no longer have to mow their yards. Not only will our mower work autonomously but no longer leave dry patches or mow in random directions leaving one's grass looking rugged. The mower is designed to handle and mow in a methodical, ordered manner providing households with a better looking backyard. 

Public Health, Safety, and Welfare: In order to provide a safe functioning device there is a power button soldered to the mower in the event it malfunctions. I also used the Arduino fan part inside the Arduino kit to simulate a lawn mowers blade. This is to prevent user injury while functioning and testing the design. 

Pseudocode (Summary of code):
1.) Get GPS coordinates
2.) Ask user for number of lawnmower passes
3.) Turn 180 degrees when destination is reached
4.) Go back to the original location
5.) Stop vehicle if an object is detected 
6.) Keep repeating these passes until the number of passes entered by the user is reached, then display to LCD that the mowing is complete

Circuit Schematic: 

![FinalProjectSchematicES](https://user-images.githubusercontent.com/73625048/197660511-aa49d7d8-c161-4a9c-aacf-19d01147bf95.png)

