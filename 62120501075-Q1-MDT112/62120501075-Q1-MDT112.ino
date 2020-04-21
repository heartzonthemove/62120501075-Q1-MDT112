void setup()
{                                   // start of set up
    Serial.begin(9600);             // show in serial monitor
    pinMode(2, INPUT_PULLUP);       // button control 
    pinMode(3, OUTPUT);             // output socket 3
    pinMode(4, OUTPUT);             // output socket 4
    pinMode(5, OUTPUT);             // output socket 5
    pinMode(6, OUTPUT);             // output socket 6
    pinMode(7, OUTPUT);             // output socket 7
    pinMode(9, OUTPUT);             // output socket 9
    pinMode(10, OUTPUT);            // output socket 10
    pinMode(11, OUTPUT);            // output socket 11
    pinMode(12, OUTPUT);            // output socket 12
    pinMode(13, OUTPUT);            // output socket 13
    tone(8,200,500);                // 1st beep sound for 500 milliseconds
    delay(250);                     // wait 0.25 sec
    tone(8,400,100);                // 2nd beep sound for 100 milliseconds
}                                   // end of set up
int b = 3;                           // b for light 'b'ulb
int c = 1;                           // c for 'c'ount
int t = 100;                         // t for 't'ime
void loop() 
{                                    // start of loop
    for(b = 3 ; b <= 13 ; b++)       // chasing right
    {                                // start of for structure (1)
        if(b == 8)                   // mention socket8           
        {
            b++;                     // moving on the lighting
        }
        digitalWrite(b,1);           // switching the LED on
        while(digitalRead(2) == 0)   // button job in
        {                            // start of while loop (1)
            if(digitalRead(2) == 1)  // button job out
            {
            c = c * 2;               // count in two times
            t = t / 2;               // time duration (down!)
            Serial.println("“Faster X 2 (Current Speed : X"+String(c)+"”)");    //show following
            tone(8,400,100);         // beep sound for 100 milliseconds
            }
        }                            // end of while loop (1)
        delay(t);                    // stopping the program for 100 milliseconds
        digitalWrite(b,0);           // switching the LED off
    }                                // end of for structure (1)
    for(b = 13 ; b >= 3 ; b--)       // chasing left
    {                                // start of for Structure (2)
        if(b == 8)                   // mention socket8
        {
            b--;                     // moving on the lighting
        }
        digitalWrite(b,1);           // switching the LED on
        while(digitalRead(2) == 0)   // button job in
        {                            // start of while loop (2)
            if(digitalRead(2) == 1)  // button job out
            {
            c = c * 2;               // count in two times
            t = t / 2;               // time duration (down!)
            Serial.println("“Faster X 2 (Current Speed : X"+String(c)+"”)");    //show following
            tone(8,400,100);         // beep sound for 100 milliseconds
            }
        }                            // end of while loop (2)
        delay(t);                    // stopping the program for 100 milliseconds
        digitalWrite(b,0);           // switching the LED off
    }                                // end of for structure (2)
}                                    // end of loop