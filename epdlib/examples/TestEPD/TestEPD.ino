#include <epdlib.h>
#include <epdpaint.h>


#define COLORED     0
#define UNCOLORED   1

#define BUSY_PIN D0
#define DC_PIN D2
#define RST_PIN D1

Epd epd(SS, DC_PIN, BUSY_PIN, RST_PIN);

unsigned char image[16000];
Paint paint(image, 400, 300);    //width should be the multiple of 8 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("e-Paper init");

  if (epd.Init(EPD_PLL_100HZ, 2000000) != 0) {
    Serial.println("e-Paper init failed");
    while(1);
  }

  /* This clears the SRAM of the e-paper display */
  epd.ClearFrame();

  epd.DisplayFrame();
  Serial.println("Clear frame");
  delay(6000);

}

void loop() {
  // put your main code here, to run repeatedly:

  /**
    * Due to RAM not enough in Arduino UNO, a frame buffer is not allowed.
    * In this case, a smaller image buffer is allocated and you have to 
    * update a partial display several times.
    * 1 byte = 8 pixels, therefore you have to set 8*N pixels at a time.
    */

  paint.Clear(UNCOLORED);
  paint.DrawStringAt(20, 0, "e-Paper Demo", &Font24, COLORED);
  paint.DrawStringAt(20, 50, "Hello world", &Font24, COLORED);

  epd.SetPartialWindow(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame();
  Serial.println("Disp hello !");
  delay(6000);
}

