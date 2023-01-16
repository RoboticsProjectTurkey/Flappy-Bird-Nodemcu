

#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"

#include "images.h"
#include "fontovi.h"

SSD1306Wire  display(0x3c, D3, D5);

#define DEMO_DURATION 3000
typedef void (*Demo)(void);

float duvarx[4];
int boşluk[4];
int uzay=32;
int geçişgenişliği=30;
void setup() {

  Serial.begin(9600);
  Serial.println("Kart Başlatıldı");
  Serial.println();

pinMode(D1,OUTPUT);
pinMode(D2,INPUT_PULLUP); 
  display.init();

  for(int i=0;i<4;i++)
  {
    duvarx[i]=128+((i+1)*uzay);
    {boşluk[i]=random(8,32);}
    }

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

}



 // display.drawProgressBar(0, 32, 120, 10, progress);

// display.setPixel(i, i);

 //  display.drawXbm(34, 14, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
//display.fillCircle(96, 32, 32 - i* 3);


//display.drawRect(12, 12, 20, 20);
 //display.setFont(ArialMT_Plain_10);
   // display.setColor(WHITE);
   
  //  display.fillRect(14, 14, 17, 17);
int score=0;
int stis=0;
float fx=30.00;
float fy=22.00;
int yön=0;
unsigned long şuan=0;

int oyun=0;
int çerçeve=0;
int oyna=0;
unsigned long ton=0;
void loop() {

   display.clear();

   if(oyun==0)
   {
    display.setFont(ArialMT_Plain_16);
    display.drawString(0,4,"Flappy ");
   display.drawXbm(0, 0, 128, 64, arkafon);
   display.drawXbm(20, 32, 14, 9, kuş);

   display.setFont(ArialMT_Plain_10);
   display.drawString(0,44,"press to start");
    if(digitalRead(4)==0)
    oyun=1;
    }

   if(oyun==1)
   {
   display.setFont(ArialMT_Plain_10);
   display.drawString(3,0,String(score));
   
   if(digitalRead(4)==0)
   {
    if(stis==0)
      {
        şuan=millis();
        yön=1;
        oyna=1;
        stis=1;
        ton=millis();
       
        }
    
    }else{stis=0;}

   
    for(int j=0;j<4;j++){
       display.setColor(WHITE);
    display.fillRect(duvarx[j],0,6,64);
     display.setColor(BLACK);
      display.fillRect(duvarx[j],boşluk[j],6,geçişgenişliği);
   
    }

  display.setColor(WHITE);
 //display.fillCircle(fx fy, 4,); // oyuncu
  display.drawXbm(fx, fy, 14, 9, kuş);
  
    for(int j=0;j<4;j++)
    {
    duvarx[j]=duvarx[j]-0.01;
    if(duvarx[j]<-7){
      score=score+1;
      
      
       digitalWrite(23,1);
      boşluk[j]=random(8,32);
     
    duvarx[j]=128;
    }
    }
  if((şuan+185)<millis())
  yön=0;

    if((ton+40)<millis())
  oyna=0;

if(yön==0)
 fy=fy+0.01;
else
 fy=fy-0.03;


 if(oyna==1)
 digitalWrite(D1,1);
 else
 digitalWrite(D1,0);

if(fy>63 || fy<0){
oyun=0;
fy=22;
score=0;
 digitalWrite(23,1);
  delay(500);
   digitalWrite(23,0); 
for(int i=0;i<4;i++)
  {
    duvarx[i]=128+((i+1)*uzay);
    {boşluk[i]=random(4,30);}
    }
}

for(int m=0;m<4;m++)
if(duvarx[m]<=fx+7 && fx+7<=duvarx[m]+6)
{
  
 
  if(fy<boşluk[m] || fy+8>boşluk[m]+geçişgenişliği){
  oyun=0;
  fy=22;
  score=0;
  digitalWrite(23,1);
  delay(500);
   digitalWrite(23,0);
  for(int i=0;i<4;i++)
  {
    duvarx[i]=128+((i+1)*uzay);
    {boşluk[i]=random(8,32);}
    }
  }}
   display.drawRect(0,0,128,64);
   }
  
   display.display();

}
