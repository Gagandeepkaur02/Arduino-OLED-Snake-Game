#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Joystick
#define JOY_X A0
#define JOY_Y A1
#define JOY_SW 2

// Buzzer
#define BUZZER 8

// Grid
#define CELL_SIZE 4
#define GRID_W (SCREEN_WIDTH / CELL_SIZE)
#define GRID_H (SCREEN_HEIGHT / CELL_SIZE)

#define MAX_SNAKE 100

enum Direction {
  UP,
  DOWN,
  LEFT,
  RIGHT
};

int snakeX[MAX_SNAKE];
int snakeY[MAX_SNAKE];

int snakeLength;
Direction dir;

int foodX, foodY;

int score = 0;
int highScore = 0;

bool gameOver = false;

unsigned long lastMove = 0;
int moveDelay = 150;

void beepEat() {
  tone(BUZZER, 1200, 50);
}

void beepGameOver() {
  tone(BUZZER, 500, 200);
  delay(250);
  tone(BUZZER, 250, 500);
}

void resetGame() {
  snakeLength = 3;
  score = 0;
  moveDelay = 150;
  dir = RIGHT;
  gameOver = false;

  snakeX[0] = 10;
  snakeY[0] = 8;

  snakeX[1] = 9;
  snakeY[1] = 8;

  snakeX[2] = 8;
  snakeY[2] = 8;

  spawnFood();
}

void spawnFood() {
  bool valid;

  do {
    valid = true;

    foodX = random(GRID_W);
    foodY = random(GRID_H);

    for (int i = 0; i < snakeLength; i++) {
      if (snakeX[i] == foodX && snakeY[i] == foodY) {
        valid = false;
        break;
      }
    }
  } while (!valid);
}

void drawBorder() {
  display.drawRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
}

void readJoystick() {

  int x = analogRead(JOY_X);
  int y = analogRead(JOY_Y);

  if (x < 300 && dir != RIGHT)
    dir = LEFT;

  else if (x > 700 && dir != LEFT)
    dir = RIGHT;

  else if (y < 300 && dir != DOWN)
    dir = UP;

  else if (y > 700 && dir != UP)
    dir = DOWN;
}

void moveSnake() {

  for (int i = snakeLength - 1; i > 0; i--) {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }

  switch (dir) {
    case UP:
      snakeY[0]--;
      break;

    case DOWN:
      snakeY[0]++;
      break;

    case LEFT:
      snakeX[0]--;
      break;

    case RIGHT:
      snakeX[0]++;
      break;
  }

  // Wall Collision
  if (snakeX[0] < 0 ||
      snakeX[0] >= GRID_W ||
      snakeY[0] < 0 ||
      snakeY[0] >= GRID_H) {
    gameOver = true;
    return;
  }

  // Self Collision
  for (int i = 1; i < snakeLength; i++) {
    if (snakeX[0] == snakeX[i] &&
        snakeY[0] == snakeY[i]) {
      gameOver = true;
      return;
    }
  }

  // Food
  if (snakeX[0] == foodX &&
      snakeY[0] == foodY) {

    beepEat();

    if (snakeLength < MAX_SNAKE)
      snakeLength++;

    score++;

    if (score > highScore) {
      highScore = score;
      EEPROM.update(0, highScore);
    }

    if (score % 5 == 0 && moveDelay > 50) {
      moveDelay -= 10;
    }

    spawnFood();
  }
}

void drawGame() {

  display.clearDisplay();

  // Food
  display.fillCircle(
    foodX * CELL_SIZE + 2,
    foodY * CELL_SIZE + 2,
    2,
    WHITE);

  // Snake Head
  display.drawRect(
    snakeX[0] * CELL_SIZE,
    snakeY[0] * CELL_SIZE,
    CELL_SIZE,
    CELL_SIZE,
    WHITE);

  // Body
  for (int i = 1; i < snakeLength; i++) {
    display.fillRect(
      snakeX[i] * CELL_SIZE,
      snakeY[i] * CELL_SIZE,
      CELL_SIZE,
      CELL_SIZE,
      WHITE);
  }

  // Score
  display.fillRect(0, 0, 40, 8, BLACK);

  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.print(score);

  display.setCursor(90, 0);
  display.print(highScore);

  display.display();
}

void showStartScreen() {

  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(10, 10);
  display.println("SNAKE");

  display.setTextSize(1);
  display.setCursor(20, 40);
  display.println("Press Joystick");

  display.display();

  while (digitalRead(JOY_SW) == HIGH);

  delay(300);
}

void showGameOver() {

  beepGameOver();

  while (true) {

    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(10, 10);
    display.println("GAME");

    display.setCursor(10, 30);
    display.println("OVER");

    display.setTextSize(1);

    display.setCursor(80, 10);
    display.print("S:");
    display.print(score);

    display.setCursor(80, 25);
    display.print("H:");
    display.print(highScore);

    display.setCursor(20, 55);
    display.print("Press to Restart");

    display.display();

    if (digitalRead(JOY_SW) == LOW) {
      delay(300);
      resetGame();
      return;
    }
  }
}

void setup() {

  pinMode(JOY_SW, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);

  randomSeed(analogRead(A3));

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (1);
  }

  highScore = EEPROM.read(0);

  if (highScore > 200)
    highScore = 0;

  showStartScreen();

  resetGame();
}

void loop() {

  if (gameOver) {
    showGameOver();
  }

  readJoystick();

  if (millis() - lastMove >= moveDelay) {

    moveSnake();

    if (!gameOver)
      drawGame();

    lastMove = millis();
  }
}
