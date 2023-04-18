#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdlib.h>

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
int game_delay=200;
int immunity_count=0;
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

void check_health_list(){ // toplam can miktarını kontrol eden eğer sıfıra düşerse menu loop'una geri döndüren fonksiyon
  int sum_of_health = 0;
  for(int i=0 ; i<3; i++){
    if(health_arr[i] != 0){sum_of_health++;}
    }
  if(sum_of_health == 0){menu_loop=0;}
  }


void fill_screen_with_white(int draw_type){
 for(int i=0; i<128; i++){
  for(int j=0; j<64; j++ ){
     bool pixel_state = display.getPixel(x, y);
     
    }
  }
}


// the loop function runs over and over again forever

int loop_counter=0;
void loop() {
  //delay(0);
  value=analogRead(potm);
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


    if(loop_counter>3){display.invertDisplay(true);}

    if(loop_counter>6){display.invertDisplay(false);}

  

    display.display();
    if(oyuntipi==1)
      delay(game_delay);
    else if(oyuntipi==2){
      delay(game_delay);
      game_delay=game_delay-(game_delay*2/10);
    }    
  }

loop_counter++;
}