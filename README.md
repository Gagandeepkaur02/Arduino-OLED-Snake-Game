# Arduino OLED Snake Game

A classic Snake Game built using an Arduino Uno, 128×64 SSD1306 OLED Display, Joystick Module, and Buzzer. Control the snake using the joystick, eat food to grow longer, increase your score, and try to beat your high score stored in EEPROM.

## Features

- OLED-based Snake Game
- Joystick controls
- Food generation at random locations
- Snake growth after eating food
- Self-collision detection
- Wall collision detection
- Buzzer sound effects
- Score counter
- High score storage using EEPROM
- Automatic speed increase as score grows
- Game Over screen
- Restart using joystick button
- Lightweight and optimized for Arduino Uno

## Hardware Requirements

| Component | Quantity |
|------------|------------|
| Arduino Uno | 1 |
| SSD1306 OLED Display (128×64 I2C) | 1 |
| Joystick Module (KY-023) | 1 |
| Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |

## Circuit Connections

### OLED Display

| OLED Pin | Arduino Uno |
|-----------|------------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

### Joystick Module

| Joystick Pin | Arduino Uno |
|--------------|------------|
| VCC | 5V |
| GND | GND |
| VRX | A0 |
| VRY | A1 |
| SW | D2 |

### Buzzer

| Buzzer Pin | Arduino Uno |
|------------|------------|
| + | D8 |
| - | GND |

## Required Libraries

Install the following libraries using the Arduino Library Manager:

- Adafruit GFX
- Adafruit SSD1306
- EEPROM (Built-in)

### Library Installation

1. Open Arduino IDE
2. Click Sketch → Include Library → Manage Libraries
3. Search and install:
   - Adafruit GFX
   - Adafruit SSD1306

## Game Controls

| Action | Joystick Direction |
|---------|-------------------|
| Move Up | Up |
| Move Down | Down |
| Move Left | Left |
| Move Right | Right |
| Start Game | Press Joystick |
| Restart Game | Press Joystick |

## Gameplay

1. Press the joystick button to start the game.
2. Move the snake using the joystick.
3. Eat food to increase your score.
4. The snake grows after eating food.
5. Speed increases automatically as the score increases.
6. Avoid:
   - Hitting walls
   - Hitting your own body
7. Try to achieve the highest score possible.

## Educational Concepts Covered

This project is excellent for learning:

- Embedded Systems
- Arduino Programming
- OLED Graphics
- Game Development
- Arrays
- Collision Detection
- EEPROM Memory
- Analog Input Processing
- Real-Time Programming
- Human Machine Interface (HMI)

## Future Improvements

- Difficulty Selection
- Obstacles and Levels
- Pause Functionality
- Animated Splash Screen
- Multiple Food Types
- EEPROM Statistics
- Multiplayer Mode
- AI Snake Mode

## Demonstration

This project demonstrates how classic retro games can be recreated on resource-constrained embedded systems using simple hardware and efficient programming techniques.

## Author

**Gagandeepkaur Saluja**  
Electronics & Telecommunication Engineer  
Robotics | Embedded Systems | STEM Education | AI Training

## License

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files to deal in the software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the software.

## Support

If you found this project useful:
⭐ Star the repository
🍴 Fork the project
📢 Share it with fellow Arduino and Robotics enthusiasts

## Repository Description

Classic Snake Game on Arduino Uno using SSD1306 OLED Display, Joystick Module, EEPROM High Score Storage, and Buzzer Sound Effects.

## Topics

arduino, snake-game, oled-display, ssd1306, arduino-project, embedded-systems, joystick, game-development, electronics, robotics, stem, voltiquex
