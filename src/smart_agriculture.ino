#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3gMAiFtRF"
#define BLYNK_TEMPLATE_NAME "Smart Agriculture"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// Wi-Fi

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// Pin Configuration

#define DHT_PIN 4
#define DHT_TYPE DHT22

#define SOIL_PIN 34
#define RELAY_PIN 26
#define LED_PIN 2

// Soil Moisture Threshold

#define SOIL_THRESHOLD 30

// DHT Sensor

DHT dht(DHT_PIN, DHT_TYPE);

BlynkTimer timer;

// Send Sensor Data

void sendSensorData()
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check DHT22

  if (isnan(humidity) || isnan(temperature))
  {
    Serial.println("ERROR: DHT22 reading failed!");
    return;
  }

  // Read Soil Moisture

  int soilRaw = analogRead(SOIL_PIN);

  int soilMoisture = map(soilRaw, 0, 4095, 0, 100);

  soilMoisture = constrain(soilMoisture, 0, 100);

  // Automatic Irrigation Control

  if (soilMoisture < SOIL_THRESHOLD)
  {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);

    Serial.println("Soil Status : DRY");
    Serial.println("Pump Status : ON");

    Blynk.virtualWrite(V3, 1);
  }
  else
  {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_PIN, LOW);

    Serial.println("Soil Status : MOIST");
    Serial.println("Pump Status : OFF");

    Blynk.virtualWrite(V3, 0);
  }

  // Serial Monitor

  Serial.println("----------------------------------------");

  Serial.print("Temperature : ");
  Serial.print(temperature, 2);
  Serial.println(" °C");

  Serial.print("Humidity    : ");
  Serial.print(humidity, 2);
  Serial.println(" %");

  Serial.print("Soil Raw    : ");
  Serial.println(soilRaw);

  Serial.print("Soil Moisture : ");
  Serial.print(soilMoisture);
  Serial.println(" %");

  Serial.println("----------------------------------------");
  Serial.println();

  // Send Data to Blynk

  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, soilMoisture);
}

// Setup

void setup()
{
  Serial.begin(115200);

  // Start DHT22

  dht.begin();

  delay(2000);

  // Pin Configuration

  pinMode(SOIL_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Initially Pump and LED OFF

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  // Start Message

  Serial.println();
  Serial.println("========================================");
  Serial.println("       SMART AGRICULTURE SYSTEM");
  Serial.println("========================================");

  // Connect to Wokwi Wi-Fi

  Serial.println("Connecting to Wokwi Wi-Fi...");

  WiFi.begin(ssid, pass, 6);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi Connected!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Connect to Blynk

  Serial.println("Connecting to Blynk...");

  Blynk.config(BLYNK_AUTH_TOKEN);

  if (Blynk.connect(10000))
  {
    Serial.println("Blynk Connected Successfully!");
  }
  else
  {
    Serial.println("Blynk Connection Failed!");
  }

  // Send data every 2 seconds

  timer.setInterval(2000L, sendSensorData);

  Serial.println("System Ready!");
  Serial.println();
}

// Main Loop

void loop()
{
  Blynk.run();
  timer.run();
}
