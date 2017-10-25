byte controller = 0;
byte value = 0;
const int numIns = 10;
const int numOuts = 10;
int Matrix[numIns][numOuts];

void setup()
{
  for (int i =0; i < 10; i++) {
    for (int o =0; o < 10; o++) {
      Matrix[i][o] = 0;
    }
  }
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(23, INPUT);
  pinMode(22, INPUT);
  pinMode(21, INPUT);
  pinMode(20, INPUT);
  pinMode(19, INPUT);
  pinMode(18, INPUT);
  pinMode(17, INPUT);
  pinMode(16, INPUT);
  pinMode(15, INPUT);
  pinMode(14, INPUT);
  pinMode(13, INPUT);
}

void loop()
{
  for (int i=0; i<10; i++) {
    int outputPin = i + 2;
    int outputPd = i;
    digitalWrite(outputPin, HIGH);
    for (int r=10; r>0; r--) {
      int inputPd = abs(r - 10);
      int value = digitalRead(r + 13);
      if (value == HIGH){
        value = 1;  
      }
      else{
        value = 0;
      }
      if (Matrix[outputPd][inputPd] != value) {
        usbMIDI.sendControlChange(outputPd, r, value + 1);
        Matrix[outputPd][inputPd] = value;
      }
    }
    digitalWrite(outputPin, LOW);
  }
}
