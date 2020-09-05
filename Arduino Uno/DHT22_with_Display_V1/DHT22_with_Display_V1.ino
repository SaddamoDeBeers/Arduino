
#include <Adafruit_Sensor.h>
#include <DHT_U.h>

#include <Adafruit_GFX.h>  // Graphics library for the display
#include <Adafruit_SSD1306.h>  // Adafruit_SSD1306 library to drive the display

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(128, 64);  // Create display


#include <Fonts/FreeMonoBold12pt7b.h>  // Add a custom font
#include <Fonts/FreeMono9pt7b.h>  // Add a custom font


#define DHTPIN 2     // DHT sensor is connected to the pin 2
// Sensor type DHT22 with 3 legZ + data -
#define DHTTYPE    DHT22     // DHT 22 (AM2302)

DHT dht = DHT(DHTPIN, DHTTYPE);

void setup()  // Setup Start
{                

  // Set serial communication at a baud rate of 9600:
  Serial.begin(9600);
  Serial.print("Booting...");
  // Setup sensor:
  dht.begin();

  display.clearDisplay();
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
  display.clearDisplay();  // Clear the buffer
  display.setTextColor(WHITE);  // Set color of the text
  display.setRotation(0);  // Set orientation. 0, 1, 2, 3
  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.                         
  display.dim(0);  //Set brightness (0 is maximun and 1 is a little dim)

}  // End of setup


void loop()  // Start of loop
{

  delay(2000);
  
  // Humidity in %
  float h = dht.readHumidity();
  // Temperature in Celsius:
  float t = dht.readTemperature();
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" % ");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" C");

  display.clearDisplay();  // Clear the display for refresh
    
  display.setFont(&FreeMono9pt7b);  // Set a custom font
  display.setTextSize(0);  // Set text size. Custom font always 0

  // Print text:
  display.setCursor(5, 10);  // (x,y)
  display.println("Temperature");  // Text or value to print

  //display.drawRoundRect(0, 0, 128, 32, 10, WHITE);  // Draw rounded rectangle (x,y,width,height,radius,color)
                                                    // It draws from the location to down-right
  
  // Print variable with left alignment:
  
  display.setCursor(28, 26);  // (x,y)
  display.println(t);  // Text or value to print

  display.setCursor(88, 26);  // (x,y)
  display.println("C");  // Text or value to print
  
  // Print text:
  display.setCursor(20, 45);  // (x,y)
  display.println("Humidity");  // Text or value to print

  //display.drawRoundRect(0, 32, 128, 32, 10, WHITE);  // Draw rounded rectangle (x,y,width,height,radius,color)
                                                    
  // Print variable with left alignment:
  display.setCursor(28, 61);  // (x,y)
  display.println(h);  // Text or value to print

  display.setCursor(88, 61);  // (x,y)
  display.println("%");  // Text or value to print
  
  display.display();  // Print everything   

}  // End of loop
