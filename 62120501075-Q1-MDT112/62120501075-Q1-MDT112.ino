void setup()
{
    Serial.begin(9600);  // show in serial monitor
    pinMode(2, INPUT_PULLUP);  // control
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    
    tone(8,200,500);    // 1st beep sound for 500 milliseconds
    delay(250);         // wait 0.25 sec
    tone(8,400,100);    // 2nd beep sound for 100 milliseconds
}

int b = 3;       // b for light 'b'ulb
int c = 1;       // c for count
int t = 100;     // t for t

void loop() 
{
    for(b = 3 ; b <= 13 ; b++)      // chasing right
    {
        if(b == 8)
        {
            digitalWrite(b,0);  // turn off socket8
            continue;
        }

        digitalWrite(b,1);      // switching the LED on
        delay(t);               // stopping the program for 100 milliseconds
        digitalWrite(b,0);      // switching the LED off
        
        if (digitalRead(2) == 0)
        {
            c = c * 2;
            t = t / 2;
            Serial.println("“Faster X 2 (Current Speed : X"+String(c)+"”)");    //show following
            tone(8,400,100);    // beep sound for 100 milliseconds
        }
    }
    for(b = 13 ; b >= 3 ; b--)
    {
        if(b == 8)
        {
            digitalWrite(b,0);  // turn off socket8
            continue;
        }
        digitalWrite(b,1);      // switching the LED on
        delay(t);               // stopping the program for 100 milliseconds
        digitalWrite(b,0);      // switching the LED off

        if (digitalRead(2) == 0)
        {
            c = c * 2;
            t = t / 2;
            Serial.println("“Faster X 2 (Current Speed : X"+String(c)+"”)");    //show following
            tone(8,400,100);    // beep sound for 100 milliseconds
        }
    }
}