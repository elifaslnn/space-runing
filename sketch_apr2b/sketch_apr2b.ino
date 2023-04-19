#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdlib.h>
#include <SevSeg.h>

SevSeg sevseg; // Create an instance of the SevSeg library


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int up = 25;//buton
int down = 26;//buton
int select = 27;//buton
int health_1=22;//led
int health_2=23;//led
int health_3=24;//led
int potm=A7;
int value=0;
int value2=0;
int fire=28; //buton
int fire_1=50;//led
int fire_2=51;//led
int fire_3=52;//led
int buzz=7;//buzzer
int torch_ldr=A0;

//7 segments
int seg1_1 = 29;
int seg1_2 = 30;
int seg1_3 = 31;
int seg1_4 = 32;
int seg1_5 = 33;
int seg1_6 = 34;
int seg1_7 = 35;

int seg2_1 = 36;
int seg2_2 = 37;
int seg2_3 = 38;
int seg2_4 = 39;
int seg2_5 = 40;
int seg2_6 = 41;
int seg2_7 = 42;

int seg3_1 = 43;
int seg3_2 = 44;
int seg3_3 = 45;
int seg3_4 = 46;
int seg3_5 = 47;
int seg3_6 = 48;
int seg3_7 = 49;




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

void draw_object(int object[][8],int x, int y, int draw_type){
  for(int i=0;i<8 ;i++){
    for(int j=0 ;j<8;j++){
      if(draw_type == 0){
        if(object[i][j]==1){ display.drawPixel(i+x*8, j+y*8, SSD1306_WHITE); }
        else{ display.drawPixel(i+x*8, j+y*8, SSD1306_BLACK);}
        }
      else{
        if(object[i][j]==0) {display.drawPixel(i+x*8, j+y*8, SSD1306_WHITE); }
        //else{ display.drawPixel(i+x*8, j+y*8, SSD1306_WHITE); }
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
  int draw_type = 0;
  //easy option
  display.drawRoundRect(80, 8, 20,50,
  8, SSD1306_WHITE); //90,29
  draw_object(easy,11,3,draw_type);
  draw_object(easy,11,4,draw_type);


  display.drawRoundRect(48, 8, 20,50,
  8, SSD1306_WHITE);//58,29
  
  draw_object(easy,7,2,draw_type);
  draw_object(easy,7,3,draw_type);
  draw_object(easy,7,4,draw_type);
  draw_object(easy,7,5,draw_type);

  if(oyuntipi == 1){  
    display.fillRoundRect(80, 8, 20,50,
    8, SSD1306_INVERSE);
    draw_object_reverse(easy,11,3);
    draw_object_reverse(easy,11,4);
    
      display.drawRoundRect(48, 8, 20,50,
    8, SSD1306_WHITE);//58,29
    draw_object(easy,7,2,draw_type);
    draw_object(easy,7,3,draw_type);
    draw_object(easy,7,4,draw_type);
    draw_object(easy,7,5,draw_type);
    }
    
    else if(oyuntipi==2){
    display.drawRoundRect(80, 8, 20,50,
    8, SSD1306_WHITE); //90,29
    draw_object(easy,11,3,draw_type);
    draw_object(easy,11,4,draw_type);

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
  pinMode(buzz,OUTPUT);
  pinMode(torch_ldr, INPUT);

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


  pinMode(seg1_1, OUTPUT); // Pinlerin çıkış pini olduğunu belirtiyoruz.
  pinMode(seg1_2, OUTPUT);
  pinMode(seg1_3, OUTPUT);
  pinMode(seg1_4, OUTPUT);
  pinMode(seg1_5, OUTPUT);
  pinMode(seg1_6, OUTPUT);
  pinMode(seg1_7, OUTPUT);
  pinMode(seg2_1, OUTPUT); // Pinlerin çıkış pini olduğunu belirtiyoruz.
  pinMode(seg2_2, OUTPUT);
  pinMode(seg2_3, OUTPUT);
  pinMode(seg2_4, OUTPUT);
  pinMode(seg2_5, OUTPUT);
  pinMode(seg2_6, OUTPUT);
  pinMode(seg2_7, OUTPUT);
  pinMode(seg3_1, OUTPUT); // Pinlerin çıkış pini olduğunu belirtiyoruz.
  pinMode(seg3_2, OUTPUT);
  pinMode(seg3_3, OUTPUT);
  pinMode(seg3_4, OUTPUT);
  pinMode(seg3_5, OUTPUT);
  pinMode(seg3_6, OUTPUT);
  pinMode(seg3_7, OUTPUT);
  
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
int game_delay=200;
int immunity_count=0;
int loop_counter=0;
bool check=false;



void catch_health_bullet(int value){ // uzay gemisi kalp yakalarsa health array listinde eksik olan bir canı doldurur
  if(nesne_loop[0][value]==0){//eğer cansa
    for(int i=0; i<3; i++){
      if(health_arr[i]==0){health_arr[i]=1; break;}
      }
    }
   if(nesne_loop[0][value]==3){//eğer mermiyse
    for(int i=0; i<3; i++){
      if(fire_arr[i]==0){fire_arr[i]=1; break;}
      }
    }
}

void shot_down(int value){ //rokete nesne çarparsa
  if(nesne_loop[0][value]==1 || nesne_loop[0][value]==2){
    if(check==false){
    for(int i=0; i<3; i++){
      if(health_arr[i]==1){health_arr[i]=0; break;}
    }
    digitalWrite(buzz,HIGH);
    delay(100);
    digitalWrite(buzz,LOW);
    immunity_count++;
    check=true;
    }
  }else if(check==true){//3 tur boyunca dokunulmaz
    immunity_count++;
    if(immunity_count==3){
      check=false;
      immunity_count=0;
    }
  }

}

void update_leds(){ // health array ve fire array listleri üzerinden ledleri yak
  
    if(health_arr[0]==1){digitalWrite(health_1, HIGH);}
    else if(health_arr[0]==0){digitalWrite(health_1, LOW);}
    
    if(health_arr[1]==1){digitalWrite(health_2, HIGH);}
    else if(health_arr[1]==0){digitalWrite(health_2, LOW);}
        
    if(health_arr[2]==1){digitalWrite(health_3, HIGH);}
    else if(health_arr[2]==0){digitalWrite(health_3, LOW);}
//________________________________________________________________________________

    if(fire_arr[0]==1){digitalWrite(fire_1, HIGH);}
    else if(fire_arr[0]==0){digitalWrite(fire_1, LOW);}
        
    if(fire_arr[1]==1){digitalWrite(fire_2, HIGH);}
    else if(fire_arr[1]==0){digitalWrite(fire_2, LOW);}
        
    if(fire_arr[2]==1){digitalWrite(fire_3, HIGH);}
    else if(fire_arr[2]==0){digitalWrite(fire_3, LOW);}
}

void draw_space_map(int draw_type){ // objeleri ekrana bastıran fonksiyon
          for(i=0;i<15;i++){
          for(int j=0;j<8;j++){
            if(nesne_loop[i][j]==0){ draw_object(health,i,j,draw_type);}
            else if(nesne_loop[i][j]==1){draw_object(meteor,i,j,draw_type);}
            else if(nesne_loop[i][j]==2){draw_object(space_garbage,i,j,draw_type);}
            else if(nesne_loop[i][j]==3){draw_object(mermi,i,j,draw_type);}      
          }
        }
}

int check_bullet_list(){ // cephaneyi kontrol eden ates edip etmemeyi kontrol eden fonksiyon 0 döndürülürse mermi atışı yapamaz
  int sum_of_bullets = 0;
  int var=0;
  for(int i=0 ; i<3; i++){
    if(fire_arr[i] != 0){sum_of_bullets++;}
    }
  if(sum_of_bullets > 0){var=1;}
  return var;
  }

void nesne_loop_sifirla(){
  for(int i=0 ; i<15; i++){
    for(int j=0 ; j<9; j++){
      nesne_loop[i][j]=9;
      if(j==8){nesne_loop[i][j]=15;}
      }
    }
  }

void check_health_list(){ // toplam can miktarını kontrol eden eğer sıfıra düşerse menu loop'una geri döndüren fonksiyon
  int sum_of_health = 0;
  for(int i=0 ; i<3; i++){
    if(health_arr[i] != 0){sum_of_health++;}
    }
  if(sum_of_health == 0){
    menu_loop=1;
    loop_counter=0;
    for(int z=0; z<3 ; z++){health_arr[z]=1;}
    nesne_loop_sifirla();
    }
  }
  
void print_0(int seg_num){
        digitalWrite(seg1_1 + seg_num*7,HIGH);
        digitalWrite(seg1_2 + seg_num*7,HIGH);
        digitalWrite(seg1_3 + seg_num*7,HIGH);
        digitalWrite(seg1_4 + seg_num*7,HIGH);
        digitalWrite(seg1_5 + seg_num*7,HIGH);
        digitalWrite(seg1_6 + seg_num*7,HIGH);
        digitalWrite(seg1_7 + seg_num*7,LOW);
      }
      
      void print_1(int seg_num){
        digitalWrite(seg1_1 + seg_num*7,LOW);
        digitalWrite(seg1_2 + seg_num*7,HIGH);
        digitalWrite(seg1_3 + seg_num*7,HIGH);
        digitalWrite(seg1_4 + seg_num*7,LOW);
        digitalWrite(seg1_5 + seg_num*7,LOW);
        digitalWrite(seg1_6 + seg_num*7,LOW);
        digitalWrite(seg1_7 + seg_num*7,LOW);
      }
      void print_2(int seg_num){
        digitalWrite(seg1_1 + seg_num*7,HIGH);
        digitalWrite(seg1_2 + seg_num*7,HIGH);
        digitalWrite(seg1_3 + seg_num*7,LOW);
        digitalWrite(seg1_4 + seg_num*7,HIGH);
        digitalWrite(seg1_5 + seg_num*7,HIGH);
        digitalWrite(seg1_6 + seg_num*7,LOW);
        digitalWrite(seg1_7 + seg_num*7,HIGH);
      }
      void print_3(int seg_num){
        digitalWrite(seg1_1 + seg_num*7,HIGH);
        digitalWrite(seg1_2 + seg_num*7,HIGH);
        digitalWrite(seg1_3 + seg_num*7,HIGH);
        digitalWrite(seg1_4 + seg_num*7,HIGH);
        digitalWrite(seg1_5 + seg_num*7,LOW);
        digitalWrite(seg1_6 + seg_num*7,LOW);
        digitalWrite(seg1_7 + seg_num*7,HIGH);
      }
      void print_4(int seg_num){
        digitalWrite(seg1_1 + seg_num*7,LOW);
        digitalWrite(seg1_2 + seg_num*7,HIGH);
        digitalWrite(seg1_3 + seg_num*7,HIGH);
        digitalWrite(seg1_4 + seg_num*7,LOW);
        digitalWrite(seg1_5 + seg_num*7,LOW);
        digitalWrite(seg1_6 + seg_num*7,HIGH);
        digitalWrite(seg1_7 + seg_num*7,HIGH);
      }
      void print_5(int seg_num){
        digitalWrite(seg1_1 + seg_num*7,HIGH);
        digitalWrite(seg1_2 + seg_num*7,LOW);
        digitalWrite(seg1_3 + seg_num*7,HIGH);
        digitalWrite(seg1_4 + seg_num*7,HIGH);
        digitalWrite(seg1_5 + seg_num*7,LOW);
        digitalWrite(seg1_6 + seg_num*7,HIGH);
        digitalWrite(seg1_7 + seg_num*7,HIGH);
      }
      void print_6(int seg_num){
        digitalWrite(seg1_1 + seg_num*7,HIGH);
        digitalWrite(seg1_2 + seg_num*7,LOW);
        digitalWrite(seg1_3 + seg_num*7,HIGH);
        digitalWrite(seg1_4 + seg_num*7,HIGH);
        digitalWrite(seg1_5 + seg_num*7,HIGH);
        digitalWrite(seg1_6 + seg_num*7,HIGH);
        digitalWrite(seg1_7 + seg_num*7,HIGH);
      }
      void print_7(int seg_num){
        digitalWrite(seg1_1 + seg_num*7,HIGH);
        digitalWrite(seg1_2 + seg_num*7,HIGH);
        digitalWrite(seg1_3 + seg_num*7,HIGH);
        digitalWrite(seg1_4 + seg_num*7,LOW);
        digitalWrite(seg1_5 + seg_num*7,LOW);
        digitalWrite(seg1_6 + seg_num*7,LOW);
        digitalWrite(seg1_7 + seg_num*7,LOW);
      }
      void print_8(int seg_num){
        digitalWrite(seg1_1 + seg_num*7,HIGH);
        digitalWrite(seg1_2 + seg_num*7,HIGH);
        digitalWrite(seg1_3 + seg_num*7,HIGH);
        digitalWrite(seg1_4 + seg_num*7,HIGH);
        digitalWrite(seg1_5 + seg_num*7,HIGH);
        digitalWrite(seg1_6 + seg_num*7,HIGH);
        digitalWrite(seg1_7 + seg_num*7,HIGH);
      }
      void print_9(int seg_num){
        digitalWrite(seg1_1 + seg_num*7,HIGH);
        digitalWrite(seg1_2 + seg_num*7,HIGH);
        digitalWrite(seg1_3 + seg_num*7,HIGH);
        digitalWrite(seg1_4 + seg_num*7,HIGH);
        digitalWrite(seg1_5 + seg_num*7,LOW);
        digitalWrite(seg1_6 + seg_num*7,HIGH);
        digitalWrite(seg1_7 + seg_num*7,HIGH);
      }
      void match_num_with_funcs(int num,int seg){
        if(num == 0){print_0(seg);}
        else if(num == 1){print_1(seg);}
        else if(num == 2){print_2(seg);}
        else if(num == 3){print_3(seg);}
        else if(num == 4){print_4(seg);}
        else if(num == 5){print_5(seg);}
        else if(num == 7){print_7(seg);}
        else if(num == 8){print_8(seg);}
        else if(num == 9){print_9(seg);}
        }
void seven_segment_led_control(int number,int game_delay){

      int digit1 = number / 100; // Extract the hundreds digit ------> seg3 for 2
      int digit2 = (number / 10) % 10; // Extract the tens digit ------> seg2 for 1
      int digit3 = number % 10; // Extract the ones digit ------> seg1 for 0

       delay(game_delay);
       match_num_with_funcs(digit1,2);
       match_num_with_funcs(digit2,1);
       match_num_with_funcs(digit3,0);

}

// the loop function runs over and over again forever

void loop() {
  //delay(0);
  value=analogRead(potm);
  int ldrValue = analogRead(torch_ldr);
  value=value/128;
  display.display();
  int draw_type = 0;
  
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
      //game_delay=200;
      }
    else if(digitalRead(down)){
      oyuntipi = 2;
      //game_delay_faster=game_delay-(game_delay*2/10);
      }
    else if(digitalRead(select)){
      menu_loop = 0;
      break;
      }
  }
  

  display.clearDisplay();
  //fill_screen_with_white(draw_type);
  //display.display();
  
  if(menu_loop==0){
   
    
    draw_object(rocket,0,value,draw_type);
    //display.display();
    //EĞER ATEŞ EDERSE
    int var = check_bullet_list();
    if(digitalRead(fire)&& var == 1){
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
      draw_object(mermi,x,y,draw_type);
      //display.display();
      x++;
    }
    //////////////////////////////////
    sayi=rand()%2;
    aralik=rand()%3;
    if(aralik==1){
    if(sayi==0){
      for(i=0;i<8;i++){
        if(nesne_0[i]==1){
          nesne_random=rand()%4;
          if(nesne_random==0){nesne_loop[14][i]=0;}// can
          else if(nesne_random==1){nesne_loop[14][i]=1;}//meteor
          else if(nesne_random==2){nesne_loop[14][i]=2;}// uzay çöpü
          else if(nesne_random==3){nesne_loop[14][i]=3;}// mermi
        }
      }
    }else if(sayi==1){
      for(i=0;i<8;i++){
        if(nesne_1[i]==1){
          nesne_random=rand()%4;
          if(nesne_random==0){nesne_loop[14][i]=0;}// can
          else if(nesne_random==1){nesne_loop[14][i]=1;}//meteor
          else if(nesne_random==2){nesne_loop[14][i]=2;}// uzay çöpü
          else if(nesne_random==3){nesne_loop[14][i]=3;}// mermi
        }
      }
    }
    }
    //////////////////////////////////////
    //ekranı kaydırma
    for(i=0;i<14;i++){
      for(int j=0;j<8;j++){
        nesne_loop[i][j]=nesne_loop[i+1][j];
      }
    }
    for(i=0;i<8;i++){
      nesne_loop[14][i]=9;
    }
    //////////////////////////////////////
    draw_space_map(draw_type);
    //display.display();
    
    //mermiyle vurma
    for(i=0;i<15;i++){
      for(int j=0;j<8;j++){
        if(nesne_loop[x][y]==1){//meteor
        nesne_loop[x][y]=2;
        x=20;
        
        }else if(nesne_loop[x-1][y]==1){//meteor
        nesne_loop[x-1][y]=2;
        x=20;
        }else if(nesne_loop[x][y]==2){//uzay çöpü
          nesne_loop[x][y]=9;
          x=20;
        }else if(nesne_loop[x-1][y]==2){//uzay çöpü
          nesne_loop[x-1][y]=9;
          x=20;        
        }
      }
    }
    catch_health_bullet(value);
    shot_down(value);
    check_health_list();
    update_leds();
    seven_segment_led_control(loop_counter,game_delay);

    display.display();
    if(oyuntipi==1)
      delay(game_delay);
    else if(oyuntipi==2){
      delay(game_delay);
      game_delay=game_delay-(game_delay*2/10);
    }    
  }

    if (ldrValue < 512) {display.invertDisplay(false);}//koyu 
    else {display.invertDisplay(true);}// açık




loop_counter++;
}
