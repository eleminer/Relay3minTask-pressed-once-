const int pushbutton = A2; //An PIN 2 wird der Taster angeschlossen
const int relay = 3; //An PIN 3 wird das Relay angeschlossen
unsigned long previousMillisInterval = 0;
unsigned long previousMillisButton = 0;
const long interval = 500; //Intervall bitte hier einstellen in Millisekunden
const long duration = 180000; //Dauer bitte hier einstellen in Millisekunden
volatile int stateLED = 0;
volatile int stateButton=0;
unsigned long currentMillis=0;

void setup() { 
  digitalWrite(12, HIGH); pinMode(12, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(relay, LOW); pinMode(relay, OUTPUT);
  Serial.begin(9600);
}

void loop() {    
  currentMillis = millis();
  if (analogRead(pushbutton) >= 1000){stateButton = 0;}
  Serial.println(analogRead(pushbutton));
  if ((analogRead(pushbutton) <= 100) && stateButton == 0){pushTimeReset(); Serial.println("pressed"); stateButton = 1;}
  if (previousMillisButton >= currentMillis)
  {
  
    if (currentMillis - previousMillisInterval >= interval)
    {
      previousMillisInterval = currentMillis;
      if (stateLED == 0)
      {
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(relay, HIGH);
        stateLED = 1;
      }
      else
      {
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(relay, LOW);
        stateLED = 0;
      }
    }

  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(relay, LOW);
    if (currentMillis>4233600000)
    {
      digitalWrite(12, LOW);
    }
  }
}

void pushTimeReset() {
  previousMillisButton = currentMillis + duration;
}
