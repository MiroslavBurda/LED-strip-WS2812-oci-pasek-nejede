#include <Arduino.h>
#include <SmartLeds.h>


const int LED_COUNT = 12; // 256 
const int DATA_PIN = 21;
const int CHANNEL = 0;

int stav = 0;

// SmartLed -> RMT driver (WS2812/WS2812B/SK6812/WS2813)
SmartLed leds(LED_WS2812B, LED_COUNT, DATA_PIN, CHANNEL, DoubleBuffer);


void SetLedEyes(uint8_t R, uint8_t G, uint8_t B) // dva protilehé rohy (oči) nahoře + dvě LED cca uprostřed dole 
{
    // kazda barva 0-255, celkem max 20*255
    for (int i = 0; i < 12; i++) 
        leds[i] = Rgb{R, G, B};  // leve oko 

      
}

void SetLedMouth(uint8_t R, uint8_t G, uint8_t B) // dva protilehé rohy (oči) nahoře + dvě LED cca uprostřed dole 
{ 
    leds[245] = Rgb{R, G, B};  // leva nozdra
    leds[250] = Rgb{R, G, B};  // prava nozdra 
}
// ------------------------------------------------------------------------------------------------

int a = 0, c = -1, slider = 0; // testovaci promenne
int EyesR = 6, EyesG = 0, EyesB = 0 ; 
int MouthR = 4, MouthG = 2, MouthB = 0;

void setup()
{
   Serial.begin(115200);
//    leds[0] = Rgb{250, 0, 0}; 
//     leds.wait();
//     leds.show();
}

const int DELAY = 20;
const int OPENING_EYES = 42;
const int STOP_COUNTING = 1000;
void loop()
{
    // if (a < OPENING_EYES) { // rozsvecim 4s     
    //     SetLedEyes(EyesR*a, EyesG*a, EyesB*a);
    //     //SetLedMouth(MouthR*a, MouthG*a, MouthB*a);
    //     leds.wait();
    //     leds.show();

    //     delay(200);
    // }
//************************************************* rozsvěcím postupně oči a tlamu 

    a = (a < STOP_COUNTING) ? a+1 : STOP_COUNTING ; 
    printf("a: %i \n", a); 
    delay(200);

    if (a < OPENING_EYES) { // rozsvecim 4s     
        SetLedEyes(EyesR*a, EyesG*a, EyesB*a);
        leds.wait();
        leds.show();   
    }


    // if (( a > (OPENING_EYES + DELAY)) and  ( a < (OPENING_EYES + DELAY + OPENING_EYES))) { // rozsvecim 4s     
    //     SetLedMouth(MouthR*(a-(OPENING_EYES + DELAY)), MouthG*(a-(OPENING_EYES + DELAY)), MouthB*(a-(OPENING_EYES + DELAY)));
    //     leds.wait();
    //     leds.show();
    // }
  
}

