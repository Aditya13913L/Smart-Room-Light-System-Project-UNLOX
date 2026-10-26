const int LDR_PIN = A0;
const int TEMP_PIN = A1;
const int PIR_PIN = 4;
const int LED_PIN = 9;
const int BUZZER_PIN = 8;

const float TEMP_LIMIT = 30.0;
const int LIGHT_THRESHOLD = 500;

void setup() {
  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  Serial.println("SMART ROOM & LAB MONITORING SYSTEM");
  Serial.println("Waiting for PIR sensor...");
}

void loop() {
  // 1. Read LDR
  int lightLevel = analogRead(LDR_PIN);

  // 2. Read PIR motion sensor
  int motion = digitalRead(PIR_PIN);

  // 3. Read TMP36 temperature sensor
  int rawValue = analogRead(TEMP_PIN);

  float voltage = rawValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  // 4. Automatic room-light control
  bool isDark = lightLevel > LIGHT_THRESHOLD;
  // For this wiring, a higher LDR reading is assumed
  // to mean darker conditions. Calibrate if necessary.

  if (motion == HIGH && isDark) {
    analogWrite(LED_PIN, 255);
  } else {
    analogWrite(LED_PIN, 0);
  }

  // 5. Security and temperature alerts
  bool highTemperature = temperature > TEMP_LIMIT;
  bool securityAlert = (motion == HIGH);
  bool buzzerAlert = highTemperature || securityAlert;

  if (buzzerAlert) {
    tone(BUZZER_PIN, highTemperature ? 1500 : 1000);
  } else {
    noTone(BUZZER_PIN);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // 6. Display monitoring dashboard
  Serial.println("-----------------------------");

  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  Serial.print("Room Condition: ");
  Serial.println(isDark ? "DARK" : "BRIGHT");

  Serial.print("Motion: ");
  Serial.println(motion == HIGH ? "DETECTED" : "NOT DETECTED");

  Serial.print("Room Light: ");
  Serial.println((motion == HIGH && isDark) ? "ON" : "OFF");

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  Serial.print("Temperature Status: ");
  Serial.println(highTemperature ? "HIGH TEMPERATURE!" : "NORMAL");

  Serial.print("Security Alert: ");
  Serial.println(securityAlert ? "MOTION DETECTED!" : "NO MOTION");

  Serial.print("Buzzer: ");
  Serial.println(buzzerAlert ? "ON" : "OFF");

  delay(1000);
}