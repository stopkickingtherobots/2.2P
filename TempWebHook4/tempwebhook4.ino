// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

#define DHTPIN 3     // what pin we're connected to

//#define DHTTYPE DHT11		// DHT 11 
#define DHTTYPE DHT22		// DHT 22 (AM2302)
//#define DHTTYPE DHT21		// DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600); 
	Serial.println("DHTxx test!");

	dht.begin();
}

void loop() {
// Wait a few seconds between measurements.
	delay(30000);


// Read temperature as Celsius
	float t = dht.getTempCelcius();

// Check if any reads failed and exit early (to try again).
	if (isnan(t)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}


	Serial.print("Temp: "); 
	Serial.print(t);
	Serial.print("*C ");

	Serial.println(Time.timeStr());
	
	String temp = String(t);
    Particle.publish("temp", temp, PRIVATE);
}

