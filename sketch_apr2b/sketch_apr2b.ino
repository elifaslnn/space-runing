 #include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdlib.h>

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
int potm=A7;
int value=0;
int value2=0;
int fire=28;
int fire_1=50;
int fire_2=51;
int fire_3=52;

int empty[8][8]={
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}  
};

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

int hard[8][8]={
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,0,0,0,0,0,0,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0}
};

int easy[8][8]={
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0}
};

int i=0;

void draw_object(int object[][8],int x, int y){
  for(int i=0;i<8 ;i++){
    for(int j=0 ;j<8;j++){
      if(object[i][j]==1){
      display.drawPixel(i+x*8, j+y*8, SSD1306_WHITE);
      }else{
      display.drawPixel(i+x*8, j+y*8, SSD1306_BLACK);
      }
    }
  }
}

void draw_object_reverse(int object[][8],int x, int y){
  for(int i=0;i<8 ;i++){
    for(int j=0 ;j<8;j++){
      if(object[i][j]==0){
      display.drawPixel(i+x*8, j+y*8, SSD1306_WHITE);
      }
    }
  }
}

int oyuntipi = 0; // 0-> seçim yok , 1 -> kolay , 2 -> Zor 
void draw_menu(){
  //easy option
  display.drawRoundRect(80, 8, 20,50,
  8, SSD1306_WHITE); //90,29
  draw_object(easy,11,3);
  draw_object(easy,11,4);


  display.drawRoundRect(48, 8, 20,50,
  8, SSD1306_WHITE);//58,29
  
  draw_object(easy,7,2);
  draw_object(easy,7,3);
  draw_object(easy,7,4);
  draw_object(easy,7,5);

  if(oyuntipi == 1){  
    display.fillRoundRect(80, 8, 20,50,
    8, SSD1306_INVERSE);
    draw_object_reverse(easy,11,3);
    draw_object_reverse(easy,11,4);
    
      display.drawRoundRect(48, 8, 20,50,
    8, SSD1306_WHITE);//58,29
    draw_object(easy,7,2);
    draw_object(easy,7,3);
    draw_object(easy,7,4);
    draw_object(easy,7,5);
    }
    
    else if(oyuntipi==2){
    display.drawRoundRect(80, 8, 20,50,
    8, SSD1306_WHITE); //90,29
    draw_object(easy,11,3);
    draw_object(easy,11,4);

    display.fillRoundRect(48, 8, 20,50,
    8, SSD1306_INVERSE);
    draw_object_reverse(easy,7,2);
    draw_object_reverse(easy,7,3);
    draw_object_reverse(easy,7,4);
    draw_object_reverse(easy,7,5);

    
  }

  display.display();

  }

//bu commit benden abi elif de harişka birisi 

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(health_1, OUTPUT);
  pinMode(health_2, OUTPUT);
  pinMode(health_3, OUTPUT);
  pinMode(fire_1, OUTPUT);
  pinMode(fire_2, OUTPUT);
  pinMode(fire_3, OUTPUT);


  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(select, INPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    }
  
  display.display();

  // Clear the buffer
  display.clearDisplay();

  draw_menu();
  //draw_object(rocket,0,value);

  display.display();

}

int nesne_0[9]={9,1,9,1,9,1,9,1,15};
int nesne_1[9]={1,0,1,0,1,0,1,0};
int nesne_loop[15][9]={
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15},
{9,9,9,9,9,9,9,9,15}
}
;

int menu_loop = 1;
int y;
int x=999;
int sayi;
int nesne_random;
int p=15;
int c=0;
int aralik;
int fire_arr[3]={1,1,1};
int health_arr[3]={1,1,1};

// the loop function runs over and over again forever

void loop() {
  //delay(0);
  value=analogRead(potm);
  value=value/128;
  display.display();

 
  while(menu_loop){
    //ledlerin yakımı
    digitalWrite(health_1, HIGH);
    digitalWrite(health_2, HIGH);
    digitalWrite(health_3, HIGH);
    digitalWrite(fire_1, HIGH);
    digitalWrite(fire_2, HIGH);
    digitalWrite(fire_3, HIGH);

    //////////////////////////////
    display.clearDisplay();
    draw_menu();
    if(digitalRead(up)){
      oyuntipi = 1;
      }
    else if(digitalRead(down)){
      oyuntipi = 2;
      }
    else if(digitalRead(select)){
      menu_loop = 0;
      break;
      }
  }

  display.clearDisplay();
  if(menu_loop==0){
    draw_object(rocket,0,value);
    //EĞER ATEŞ EDERSE
    if(digitalRead(fire)){
      for(i=0;i<3;i++){
        if(fire_arr[i]==1){
          if(i==0){
            digitalWrite(fire_1, LOW);
          }else if(i==1){
            digitalWrite(fire_2, LOW);
          }else if(i==2){
            digitalWrite(fire_3, LOW);
          }
          fire_arr[i]=0;
          break;
        }
      }   
      x=1;
      y=value;
      
    }
    if(x!=999){
      draw_object(mermi,x,y);
      x++;
    }
    //////////////////////////////////
    sayi=rand()%2;
    aralik=rand()%3;
    if(aralik==1){
    if(sayi==0){
      for(i=0;i<8;i++){
        if(nesne_0[i]==1){
          nesne_random=rand()%3;
          if(nesne_random==0){
            //draw_object(health,15,i);
            nesne_loop[14][i]=0;
          }else if(nesne_random==1){
            //draw_object(meteor,15,i);
            nesne_loop[14][i]=1;

          }else if(nesne_random==2){
            //draw_object(space_garbage,15,i);
            nesne_loop[14][i]=2;
          }
        }
      }
    }else if(sayi==1){
            for(i=0;i<8;i++){
        if(nesne_1[i]==1){
          nesne_random=rand()%3;
          if(nesne_random==0){
            //draw_object(health,15,i);
            nesne_loop[14][i]=0;
          }else if(nesne_random==1){
            //draw_object(meteor,15,i);
            nesne_loop[14][i]=1;

          }else if(nesne_random==2){
            //draw_object(space_garbage,15,i);
            nesne_loop[14][i]=2;
          }
        }
      }
    }
    }
    //////////////////////////////////////
    for(i=0;i<14;i++){
      for(int j=0;j<8;j++){
        nesne_loop[i][j]=nesne_loop[i+1][j];
      }
    }
    for(i=0;i<8;i++){
      nesne_loop[14][i]=9;
    }
    //////////////////////////////////////
    for(i=0;i<15;i++){
      for(int j=0;j<8;j++){
        if(nesne_loop[i][j]==0){
          draw_object(health,i,j);
        }else if(nesne_loop[i][j]==1){
          draw_object(meteor,i,j);
        }else if(nesne_loop[i][j]==2){
          draw_object(space_garbage,i,j);
        }      
      }
    }
    //mermiyle vurma
    for(i=0;i<15;i++){
      for(int j=0;j<8;j++){
        if(nesne_loop[x][y]==0){
          for(int z=0;z<3;z++){
            if(z==0){
            digitalWrite(fire_1, HIGH);
          }else if(z=1){
            digitalWrite(fire_2, HIGH);
          }else if(z==2){
            digitalWrite(fire_3, HIGH);
          }
          fire_arr[z]=1;
          break;
        }
        nesne_loop[x][y]=9;
        x=20;
        }else if(nesne_loop[x][y]==1){
        nesne_loop[x-1][y]=2;
        nesne_loop[x][y]=9;
        x=20;
        }else if(nesne_loop[x][y]==2){
          nesne_loop[x][y]=9;
          x=20;
        }
      }
    }
    //çarpışma
    for(i=0;i<15;i++){
      for(int j=0;j<8;j++){
        if(nesne_loop[0][value]==0 || nesne_loop[0][value]==1 || nesne_loop[0][value]==2){
         for(int z=0;z<3;z++){
           if(health_arr[z]==1){
              digitalWrite(health_3, HIGH);
           }
         } 
        }
      }
    }


    


    display.display();
    delay(20);    
  }


}