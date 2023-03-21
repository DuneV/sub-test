#include <Servo.h>

/*
 * Pins definition on the esp32, look for more information
 * url: 
 */

#define P_M0      12
#define P_M1      13
#define P_M2      16
#define P_M3      17
#define P_M4      18
#define P_M5      20

/*
 * Define the buffer size of the message to connect and recieve the msg
 */

#define MAX_BUFF_LEN    255
char msg;
char str[MAX_BUFF_LEN];
uint8_t idx = 0; 


/*
 * Set stop and clockside and counterclock velocity 
 * don't bother about that XD
 */

float stop = 1500;
int av = 1100;
int rev = 1900;
int baud = 115200;

/*
 * Define the six motors 
 */

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;
Servo motor5;
Servo motor6; 


void motor_init() {
  
   //
  
  motor1.attach(P_M0);
  motor2.attach(P_M1);
  motor3.attach(P_M2);
  motor4.attach(P_M3); 
  motor5.attach(P_M4);
  motor6.attach(P_M5);

  //
  
  motor1.writeMicroseconds(stop);
  motor2.writeMicroseconds(stop);
  motor3.writeMicroseconds(stop);
  motor4.writeMicroseconds(stop);
  motor5.writeMicroseconds(stop);
  motor6.writeMicroseconds(stop);

  //
  
  delay(7000); 
  
}

bool verify(){
  bool flag = false;
  if (Serial.available() > 0){
    
    flag = true; 
    
  }
  return flag; 
} 

void setup() {
  
  //
  
  Serial.begin(baud);
  motor_init();
  
}

void loop() {
  
  // using namespace std; 
  //Serial.println("Hello from ESP!");
  if(verify()){
  
    msg = Serial.read();      // Read one byte
    
    if(msg != '\n'){          // Still reading
      
      str[idx++] = msg;       // Parse the string byte (char) by byte
      
    }
    else{                     // Done reading
      str[idx] = '\0';
      idx = 0; 

      Serial.print("ESP: ");
      Serial.println(str);
    }
 
  }
}
