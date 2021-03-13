/*-------------------------------------------------------------------------------------------------------+
|  MemoryGame| Basic memory game based on the comparison between two generated arrays                    |
|            | one program generated (real key) and one human inserted through pression buttons.         |
|            | Final Project for my HackerSchool application.                                            |
+--------------------------------------------------------------------------------------------------------+
||Authors: João Barreiros C. Rodrigues (Joao-Ex-Machina)                                                 |
| Date:    09 March 2021 (created) / 10 March 2021 (saved and 1st test) / (finished)                     |
|References: (main): https://create.arduino.cc/projecthub/Arduino_Scuola/a-simple-simon-says-game-25ba99 |
|                    Important ideas: Two array comparison                                               |
|                                                                                                        |
+-------------------------------------------------------------------------------------------------------*/

int key[50];
int written_key[50];
int level = 1;
int display_time;
  int bass = 3;
int start_b = 4;
int green_b = 5;
int red_b = 6;
int blue_b = 7;
int green_led = 8;
int red_led = 9;
int blue_led = 10;
bool music = true; 


void setup() {
pinMode(start_b, INPUT_PULLUP); //since Im using INPUT_PULLUP there is no need for an external resistor
pinMode(green_b, INPUT_PULLUP);
pinMode(red_b, INPUT_PULLUP);
pinMode(blue_b, INPUT_PULLUP);

pinMode(bass, OUTPUT);
pinMode(green_led, OUTPUT);
pinMode(red_led, OUTPUT); 
pinMode(blue_led, OUTPUT);
digitalWrite(green_led, LOW);
digitalWrite(red_led, LOW);
digitalWrite(blue_led, LOW);

}

void loop() {
  if (level == 1){
    generate_key(); //Since there is no right_key() before level 1, there's a need to generate a key automatically if level ==1
    }
 if (digitalRead(start_b) == LOW || level != 1){ //The game only starts if the start_b is pressed. After level one the following levels start automatically
  music = false;
  display_key();
  write_key();
  }
  
  while ( digitalRead(start_b) == HIGH && music == true){
    waiting_music();
    }
}

void(* resetFunc) (void) = 0; //define reset function as a pointer to address 0 (__vectors. function that restarts the program)
void generate_key(){
  randomSeed(millis()); // generate a time-based random seed
  for (int i = 0; i < 50; i++) //always  
{
  key[i] = random(8,11); // generate the seed-based random int between 8 and 10 
}
  }

void display_key()
{
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  for (int i = 0; i < level; i++)//only displays (level)number of elements of the array
  {
    digitalWrite(key[i], HIGH);
    delay((5000/level)); //The higher the level the shorter the display time
    digitalWrite(key[i], LOW);
    delay(200);
   }
}
void write_key(){
  bool flag = false; //this flag indicates if the sequence is correct

  for (int i = 0; i < level; i++) // will only analyze (level) number of elements of the array
  {
  flag = false;
  while(flag == false)
  {
  if (digitalRead(green_b) == LOW){
    digitalWrite(green_led, HIGH);
    written_key[i] = green_led;
    flag = true;
    delay(200);
    if (written_key[i] != key[i]){
      wrong_key();
      return;
    }
    digitalWrite(green_led, LOW);
  }

  if (digitalRead(red_b) == LOW){
    digitalWrite(red_led, HIGH);
    written_key[i] = red_led;
    flag = true;
    delay(200);
    if (written_key[i] != key[i]){
      wrong_key();
      return;
    }
    digitalWrite(red_led, LOW);
  }

  if (digitalRead(blue_b) == LOW){
    digitalWrite(blue_led, HIGH);
    written_key[i] = blue_led;
    flag = true;
    delay(200);
    if (written_key[i] != key[i]){
      wrong_key();
      return;
    }
    digitalWrite(blue_led, LOW);
  }
 }
}
correct_key();
}
void wrong_key(){
  tone (bass, 60);
  delay(500);
  tone(bass, 55);
  delay(500);
   tone(bass, 50);
  delay(500);
  digitalWrite(red_led, HIGH);
  delay(100);
  digitalWrite(red_led, LOW);
  delay(100);
  digitalWrite(red_led, HIGH);
  delay(100);
  digitalWrite(red_led, LOW);
  delay(1000);
  resetFunc();
}
void  correct_key(){
  level++;
  generate_key();
  }
void waiting_music(){
  //Trabalho de Portfolio MEEC The Clash- Magnificent Seven
    tone(bass,110);
    delay(62.5);
    noTone(bass);
    delay(62.5);
    tone(bass,98);
    delay(62.5);
    noTone(bass);
    delay (62.5);
    tone(bass,82.41);
    delay(62.5);
    noTone(bass);
    delay(62.5);
    tone(bass,73.42);
    delay(62.5);
    noTone(bass);
    delay(62.5);
    tone(bass,65.41);
    delay(62.5);
    noTone(bass);
    delay(62.5);
    tone(bass,55);
    delay(62.5);
    noTone(bass);
    delay(62.5);
    tone(bass,55);
    delay(62.5);
    noTone(bass);
    delay(62.5);
    tone(bass,49);
    delay(62.5);
    noTone(bass);
    delay(62.5);
    tone(bass,55);
    delay(62.5);
    noTone(bass);
    delay(437.5);

    tone(bass, 110);
    delay(250);
    noTone(bass);
    delay(250);
   
   while (digitalRead(start_b) == HIGH && music == true){
    tone(bass,55);
    delay(250);
    noTone(bass);
    delay(250);


    tone(bass,55);
    delay(250);
    noTone(bass);
    delay(250);


    tone(bass, 110);
    delay(62.5);
    noTone(bass);
    delay(62.5);
    tone(bass, 110);
    delay(62.5);
    noTone(bass);
    delay(62.5);

    tone(bass, 98);
    delay(62.5);
    noTone(bass);
    delay(62.5);
    tone(bass, 110);
    delay(62.5);
    noTone(bass);
    delay(62.5);
    tone(bass, 130.8);
    delay(250);
    noTone(bass);
    delay(250);



    tone(bass, 73.42);
    delay(125);
    noTone(bass);
    delay(125);

    tone(bass, 73.42);
    delay(125);
    noTone(bass);
    delay(625);


    tone(bass, 73.42);
    delay(62.5);
    noTone(bass);
    delay(62.5);


    tone(bass, 73.42);
    delay(62.5);
    noTone(bass);
    delay(62.5);



    tone(bass, 65.41);
    delay(125);
    noTone(bass);
    delay(125);


    tone(bass, 73.42);
    delay(62.5);
    noTone(bass);
    delay(62.5);

    tone(bass, 73.42);
    delay(62.5);
    noTone(bass);
    delay(62.5);

    tone(bass, 65.41);
    delay(125);
    noTone(bass);
    delay(125);
    }
  }
