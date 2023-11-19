const int analogPin = A0;                             // Analog pin for LM35
const int ledPin = 13;                                // Onboard LED pin

const int belowThresholdBlinkInterval = 250;          // Blink interval when temperature is below 30 degrees Celsius (in loop iterations)
const int aboveThresholdBlinkInterval = 500;          // Blink interval when temperature is above 30 degrees Celsius (in loop iterations)

int temperatureThreshold = 30;                        // Temperature threshold in degrees Celsius

int blinkCounter = 0;                                 // Counter to track the number of loop iterations

void setup() 
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
 // Read temperature from LM35 sensor
  int rawValue = analogRead(analogPin);               
  float voltage = (rawValue / 1023.0) * 5.0;
  float temperatureC = (voltage - 0.5) * 100.0;

  // Print temperature to serial monitor
  Serial.print("Temperature: ");                      
  Serial.print(temperatureC);
  Serial.println(" degrees Celsius");

  // Check temperature and control LED accordingly
  if (temperatureC < temperatureThreshold) 
  {                                                        
    updateLEDState(belowThresholdBlinkInterval);       
  } 
  else 
  {
    updateLEDState(aboveThresholdBlinkInterval);
  }
}

void updateLEDState(int interval) 
{
  if (blinkCounter >= interval)
  {
    // Toggle the LED state
    digitalWrite(ledPin, !digitalRead(ledPin));        
    // Reset the counter
    blinkCounter = 0;                                  
  } 
  else 
  {
    // Increment the counter
    blinkCounter++;                                    
  } 

}
