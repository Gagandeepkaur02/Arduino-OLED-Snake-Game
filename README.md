# Arduino-OLED-Snake-Game

A classic Snake Game built using an Arduino Uno, 128×64 SSD1306 OLED Display, Joystick Module, and Buzzer. Control the snake using the joystick, eat food to grow longer, increase your score, and try to beat your high score stored in EEPROM.

Features
-- OLED-based Snake Game
--Joystick controls
--Food generation at random locations
--Snake growth after eating food
--Self-collision detection
--Wall collision detection
--Buzzer sound effects
--Score counter
--High score storage using EEPROM
-- Automatic speed increase as score grows
-- Game Over screen
-- Restart using joystick button
-- Lightweight and optimized for Arduino Uno

Hardware Requirements

Component	Quantity
Arduino Uno	1
SSD1306 OLED Display (128×64 I2C)	1
Joystick Module (KY-023)	1
Buzzer	1
Breadboard	1
Jumper Wires	As Required

Circuit Connections

OLED Display
OLED Pin	Arduino Uno
VCC	5V
GND	GND
SDA	A4
SCL	A5

Joystick Module
Joystick Pin	Arduino Uno
VCC	5V
GND	GND
VRX	A0
VRY	A1
SW	D2
Buzzer
Buzzer Pin	Arduino Uno
+	D8
-	GND
Required Libraries

Install the following libraries using the Arduino Library Manager:

Adafruit GFX
Adafruit SSD1306
EEPROM (Built-in)
Library Installation
Open Arduino IDE
Navigate to Sketch → Include Library → Manage Libraries
Search and install:
Adafruit GFX
Adafruit SSD1306
Game Controls
Action	Joystick Direction
Move Up	Up
Move Down	Down
Move Left	Left
Move Right	Right
Start Game	Press Joystick
Restart Game	Press Joystick
Gameplay
Press the joystick button to start.
Move the snake using the joystick.
Eat food to increase your score.
The snake grows after eating food.
Speed increases automatically every few points.
Avoid:
Hitting walls
Hitting your own body
Try to achieve the highest score possible.
Project Structure
Arduino_OLED_Snake_Game/
│
├── Arduino_OLED_Snake_Game.ino
├── README.md
└── Images/
    ├── Circuit_Diagram.png
    ├── Gameplay.png
    └── Hardware_Setup.jpg

Future Improvements
-- Difficulty Selection
-- Obstacles and Levels
-- Pause Functionality
-- Animated Splash Screen
-- Multiple Food Types
-- EEPROM Statistics
-- Multiplayer Mode
-- AI Snake Mode

Educational Concepts Covered:
This project is excellent for learning:

--Embedded Systems
--Arduino Programming
--OLED Graphics
--Game Development
--Arrays
--Collision Detection
--EEPROM Memory
--Analog Input Processing
--Real-Time Programming
--Human Machine Interface (HMI)

Demonstration:
This project demonstrates how classic retro games can be recreated on resource-constrained embedded systems using simple hardware and efficient programming techniques.

Author
Gagandeep Singh
Electronics & Telecommunication Engineer
Robotics | Embedded Systems | STEM Education | AI Training


License

This project is released under the MIT License.

Feel free to use, modify, and distribute this project for educational and non-commercial purposes.

GitHub Repository Description (Short)
Classic Snake Game on Arduino Uno using SSD1306 OLED Display, Joystick Module, EEPROM High Score Storage, and Buzzer Sound Effects.
GitHub Topics
arduino
snake-game
oled-display
ssd1306
embedded-systems
arduino-project
game-development
joystick
electronics
robotics
stem
voltiquex
Suggested Repository Name
Arduino-OLED-Snake-Game
