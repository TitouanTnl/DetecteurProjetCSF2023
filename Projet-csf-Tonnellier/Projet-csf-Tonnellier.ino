#include "FastLED.h"
#include "LowPower.h"
#define NUM_LEDS 21
#define DATA_PIN    4
CRGB leds[NUM_LEDS];
int lum = 21;

byte varTimer = 0; // La variable du timer

// Definit les ports utilisés pour nos entrées et sorties (Trig, Echo et le capteur de fumée)
const int trig = A1;
const int echo = A2;
const int sensor = A3;

// Definit les variables pour la durée et la distance obtenues
long duree;
int distance;


void setup() {
  // Setup du timer
  bitClear (TCCR2A, WGM20);
  bitClear (TCCR2A, WGM21);
  TCCR2B = 0b00000110;
  TIFR2 = 0b00000001;
  
  // Setup des leds
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);

  // Setup du capteur a ultrason
  pinMode(echo, INPUT); // Definit le port associé a Echo comme une entrée
  pinMode(trig, OUTPUT); // Definit le port associé a Trig comme une sortie
  pinMode(sensor, INPUT); // Definit le port associé au capteur comme une entrée
  
  Serial.begin(9600);
}


void loop() {

  distance = calculDistance(); // Appelle la fonction calculDistance definie en bas pour obtenir la distance mesurée par le capteur
  
  Serial.println(distance); // Ecrit la distance mesurée dans le moniteur série

  if (distance<30) {
    Serial.println("Mouvement detecté");
    
    leds[1] = CRGB(lum,0,0);
    leds[2] = CRGB(lum,0,0);
    leds[3] = CRGB(lum,0,0);
    leds[4] = CRGB(lum,0,0);
    leds[5] = CRGB(lum,0,0);
    leds[6] = CRGB(lum,0,0);
    leds[7] = CRGB(lum,0,0);
    leds[8] = CRGB(lum,0,0);
    leds[9] = CRGB(lum,0,0);
    leds[10] = CRGB(lum,0,0);
    leds[11] = CRGB(lum,0,0);
    leds[12] = CRGB(lum,0,0);
    leds[13] = CRGB(lum,0,0);
    leds[14] = CRGB(lum,0,0);
    leds[15] = CRGB(lum,0,0);
    leds[16] = CRGB(lum,0,0);
    leds[17] = CRGB(lum,0,0);
    leds[18] = CRGB(lum,0,0);
    leds[19] = CRGB(lum,0,0);
    leds[20] = CRGB(lum,0,0);
    FastLED.show(); // Allume les leds de la carte
    varTimer = 0; // On recommence un nouveau cycle
  }
  
  
  if (varTimer++ > 125) { 
    varTimer = 0; // On recommence un nouveau cycle
    
    leds[1] = CRGB(0,0,0);
    leds[2] = CRGB(0,0,0);
    leds[3] = CRGB(0,0,0);
    leds[4] = CRGB(0,0,0);
    leds[5] = CRGB(0,0,0);
    leds[6] = CRGB(0,0,0);
    leds[7] = CRGB(0,0,0);
    leds[8] = CRGB(0,0,0);
    leds[9] = CRGB(0,0,0);
    leds[10] = CRGB(0,0,0);
    leds[11] = CRGB(0,0,0);
    leds[12] = CRGB(0,0,0);
    leds[13] = CRGB(0,0,0);
    leds[14] = CRGB(0,0,0);
    leds[15] = CRGB(0,0,0);
    leds[16] = CRGB(0,0,0);
    leds[17] = CRGB(0,0,0);
    leds[18] = CRGB(0,0,0);
    leds[19] = CRGB(0,0,0);
    leds[20] = CRGB(0,0,0);
    FastLED.show(); //Eteint les leds de la carte
    }


  if (digitalRead(sensor) == HIGH) {
    Serial.println("Absence de fumée"); // Si le capteur ne détecte pas de fumée on envoie ce message
    delay(100);
  }
  if (digitalRead(sensor) == LOW) {
    Serial.println("Présence de fumée !"); // Si le capteur détecte de la fumée on envoie ce message
    delay(100);
  }
}



// Definition de la fonction qui calcul la distance mesurée par le capteur ultrason
int calculDistance(){ 

  digitalWrite(trig, LOW); 
  delayMicroseconds(2); // Definit Trig sur état bas pendant 2 microsecondes
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); // Definit Trig sur état haut pendant 10 microsecondes
  digitalWrite(trig, LOW);
  duree = pulseIn(echo, HIGH); // Lit l'entrée Echo et nous donne le temps que mets le son entre le capteur et l'obstacle
  distance = duree*0.034/2; //Donne la distance en cm
  return distance;
}