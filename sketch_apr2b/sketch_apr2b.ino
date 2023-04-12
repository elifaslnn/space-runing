#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int up = 25;
int down = 26;
int select = 27;
int health_1=22;
int health_2=23;
int health_3=24;

int rocket[8][8]={
{0,0,0,0,0,0,0,0},
{1,0,0,1,1,0,0,1},
{1,1,1,1,1,1,1,1},
{0,1,1,1,1,1,1,0},
{0,0,1,1,1,1,0,0},
{0,0,1,1,1,1,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0}
};

int mermi[8][8]={
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0},
{0,0,0,0,1,0,0,0},
{0,0,1,0,1,0,1,0},
{0,0,0,1,1,1,0,0},
{0,0,0,0,1,0,0,0}
};

int health[8][8]={
{0,0,0,1,0,0,0,0},
{0,0,1,1,1,0,0,0},
{0,1,1,1,1,1,0,0},
{0,1,1,1,1,1,0,0},
{0,0,1,0,1,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}
};

int meteor[8][8]={
{0,1,0,1,1,0,0,0},
{0,0,1,1,1,1,0,0},
{1,1,1,1,1,1,1,0},
{1,1,1,1,0,0,1,1},
{0,1,1,1,0,0,1,1},
{0,1,1,1,1,1,0,0},
{0,0,1,1,1,0,0,0},
{0,1,0,1,0,0,1,0}
};

int space_garbage[8][8]={
{0,0,0,0,0,0,1,0},
{0,1,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,1,1,0,0,1,0},
{0,0,1,0,0,0,1,0},
{1,0,0,0,1,1,0,0},
{0,0,0,0,0,0,1,0},
{0,0,1,0,0,0,0,0}
};


//bu commit benden abi elif de harişka birisi 

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(health_1, OUTPUT);
  pinMode(health_2, OUTPUT);
  pinMode(health_1, OUTPUT);

  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(select, INPUT);

    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    }
  
  display.display();

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);
  //draw_rocket();
  draw_health();
  display.display();

}

void draw_rocket(){
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(rocket[i][j]==1){
      display.drawPixel(i, j, SSD1306_WHITE);
      }
    }
  }

}


void draw_health(){
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(space_garbage[i][j]==1){
      display.drawPixel(i, j, SSD1306_WHITE);
      }
    }
  }

}



// the loop function runs over and over again forever
void loop() {

  if(digitalRead(up))
    digitalWrite(health_1, HIGH);  // turn the LED on (HIGH is the voltage level)
  else
    digitalWrite(health_1, LOW);  // turn the LED on (HIGH is the voltage level)
}
