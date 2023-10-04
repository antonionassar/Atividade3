const float pi = 3.1415926;
bool booleano = true; 
const int inteiro = 2;
float area;
float m2;

void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("\nCaluladora de área\nQual a figura?\n(círculo, retângulo, triângulo)");
  while(Serial.available() == 0){}
  String figura = Serial.readString();
  Serial.println("Medida 1: (raio ou base)");
  while(Serial.available() == 0){}
  float m1 = Serial.parseFloat();
  if (figura == "retângulo" || figura == "triângulo"){
    Serial.println("Medida 2: (altura)");
    while (Serial.available() == 0){}
    m2 = Serial.parseFloat();
  }
  if (figura == "triângulo"){
    area = m1 * m2 / inteiro;
  } else if (figura == "círculo"){
    area = pi * (m1*m1);
  } else {
    
  }
  Serial.println("área:");
  Serial.println(area);
}
