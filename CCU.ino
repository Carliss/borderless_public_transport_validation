// FINAL VERSION!!!!

const int preasure_plate_in = A5;
const int preasure_plate_out = 2;

const int button_in = 10;
const int button_out = 8;


void setup() {
  // put your setup code here, to run once:
  pinMode(preasure_plate_in, INPUT);
  pinMode(preasure_plate_out, OUTPUT);

  pinMode(button_in, INPUT);
  pinMode(button_out, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(preasure_plate_out, HIGH);
  digitalWrite(button_out, HIGH);
  
  // Serial.print("Preasure_plate: ");
  // Serial.println(analogRead(preasure_plate_in));

  //Serial.print("button : ");
  //Serial.println(digitalRead(button_in));

  // print 0 for unvalid
  if (analogRead(preasure_plate_in) > 1) {
    Serial.print("0");
    while(analogRead(preasure_plate_in) > 1) {
      delay(200);
    }
  };
  // print 1 for valid
  
  if (digitalRead(button_in) == HIGH) {
    Serial.print("1");
    digitalWrite(preasure_plate_out, LOW);
    delay(7000);
    digitalWrite(preasure_plate_out, HIGH);
  };
  
}
