#include <Arduino.h>
#include <MIDIUSB.h>
#include <Wire.h>

// ---------- PCF8575 IO EXPANDER (16 PUSH BUTTONS) ----------
// PCF8575 address is detected on boot across the valid 0x20-0x27 range.
const byte PCF8575_ADDR_START = 0x20;
const byte PCF8575_ADDR_END = 0x27;
byte pcf8575Addr = 0;
const byte buttonNotes[] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75};
bool buttonStates[16] = {0};

// ---------- 74HC4067 MULTIPLEXER (15 POTENTIOMETERS) ----------
// Selection pins for the multiplexer
const int MUX_S0 = 15;
const int MUX_S1 = 14;
const int MUX_S2 = 16;
const int MUX_S3 = 10;
const int MUX_INPUT = A0; // Analog input from multiplexer

const byte potCCs[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
int potValues[15] = {0};
const int potThreshold = 2;

// ---------- ROTARY ENCODERS ----------
// Music selection encoder (top middle)
const int encoderA_Music = 4;
const int encoderB_Music = 5;
const byte encoderCC_Music = 25;
bool encoderLastState_Music = 0;

// Jog wheel encoder 1
const int encoderA_Jog1 = 8;
const int encoderB_Jog1 = 9;
const byte encoderCC_Jog1 = 26;
bool encoderLastState_Jog1 = 0;

// Jog wheel encoder 2
const int encoderA_Jog2 = 6;
const int encoderB_Jog2 = 7;
const byte encoderCC_Jog2 = 27;
bool encoderLastState_Jog2 = 0;

// ---------- PUSH BUTTONS ON ARDUINO PINS (with software pullup) ----------
// Music selection buttons (top)
const int buttonPin_A3 = A3;
const int buttonPin_A2 = A2;
const int buttonPin_A1 = A1;
const byte buttonNote_A3 = 76;
const byte buttonNote_A2 = 77;
const byte buttonNote_A1 = 78;
bool buttonState_A3 = false;
bool buttonState_A2 = false;
bool buttonState_A1 = false;

// ---------- FUNCTION DECLARATIONS ----------
void noteOn(byte pitch);
void noteOff(byte pitch);
void handlePots();
void selectMuxChannel(int channel);
void sendCC(byte cc, byte val);
void handleEncoders();
uint16_t readPCF8575();
bool detectPCF8575();
void configurePCF8575Inputs();

void setup()
{
  // Serial.begin(9600);
  // delay(500);
  // Serial.println("Booting DJ controller...");

  // Initialize I2C for PCF8575
  Wire.begin();
  delay(50); // Give I2C time to initialize

  if (detectPCF8575())
  {
    configurePCF8575Inputs();
    // Serial.print("PCF8575 detected at 0x");
    // Serial.println(pcf8575Addr, HEX);
  }
  else
  {
    // Serial.println("No PCF8575 found on I2C addresses 0x20-0x27");
  }

  // Initialize multiplexer selection pins
  pinMode(MUX_S0, OUTPUT);
  pinMode(MUX_S1, OUTPUT);
  pinMode(MUX_S2, OUTPUT);
  pinMode(MUX_S3, OUTPUT);

  // Initialize music selection encoder pins
  pinMode(encoderA_Music, INPUT_PULLUP);
  pinMode(encoderB_Music, INPUT_PULLUP);
  encoderLastState_Music = digitalRead(encoderA_Music);

  // Initialize jog wheel encoder 1 pins
  pinMode(encoderA_Jog1, INPUT_PULLUP);
  pinMode(encoderB_Jog1, INPUT_PULLUP);
  encoderLastState_Jog1 = digitalRead(encoderA_Jog1);

  // Initialize jog wheel encoder 2 pins
  pinMode(encoderA_Jog2, INPUT_PULLUP);
  pinMode(encoderB_Jog2, INPUT_PULLUP);
  encoderLastState_Jog2 = digitalRead(encoderA_Jog2);

  // Initialize music selection button pins with software pullup
  pinMode(buttonPin_A3, INPUT_PULLUP);
  pinMode(buttonPin_A2, INPUT_PULLUP);
  pinMode(buttonPin_A1, INPUT_PULLUP);
}

void loop()
{
  // ------------------ PUSH BUTTONS (PCF8575) ------------------
  uint16_t buttonData = readPCF8575();

  for (int i = 0; i < 16; i++)
  {
    bool pressed = !(bitRead(buttonData, i)); // Active LOW

    if (pressed && !buttonStates[i])
    {
      // Serial.print("Button ");
      // Serial.print(i);
      // Serial.print(" pressed - Note: ");
      // Serial.println(buttonNotes[i]);

      noteOn(buttonNotes[i]);
      buttonStates[i] = true;
    }
    else if (!pressed && buttonStates[i])
    {
      // Serial.print("Button ");
      // Serial.print(i);
      // Serial.println(" released");

      noteOff(buttonNotes[i]);
      buttonStates[i] = false;
    }
  }

  // ------------------ MUSIC SELECTION BUTTONS (A3, A2, A1) ------------------
  // Button on A3
  bool pressedA3 = !digitalRead(buttonPin_A3);
  if (pressedA3 && !buttonState_A3)
  {
    // Serial.println("Button A3 pressed - Note: 76");
    noteOn(buttonNote_A3);
    buttonState_A3 = true;
  }
  else if (!pressedA3 && buttonState_A3)
  {
    // Serial.println("Button A3 released");
    noteOff(buttonNote_A3);
    buttonState_A3 = false;
  }

  // Button on A2
  bool pressedA2 = !digitalRead(buttonPin_A2);
  if (pressedA2 && !buttonState_A2)
  {
    // Serial.println("Button A2 pressed - Note: 77");
    noteOn(buttonNote_A2);
    buttonState_A2 = true;
  }
  else if (!pressedA2 && buttonState_A2)
  {
    // Serial.println("Button A2 released");
    noteOff(buttonNote_A2);
    buttonState_A2 = false;
  }

  // Button on A1
  bool pressedA1 = !digitalRead(buttonPin_A1);
  if (pressedA1 && !buttonState_A1)
  {
    // Serial.println("Button A1 pressed - Note: 78");
    noteOn(buttonNote_A1);
    buttonState_A1 = true;
  }
  else if (!pressedA1 && buttonState_A1)
  {
    // Serial.println("Button A1 released");
    noteOff(buttonNote_A1);
    buttonState_A1 = false;
  }

  handlePots();

  handleEncoders();

  delay(2); // Reduced debounce for faster response
}

// ------------------ MIDI FUNCTIONS ------------------

void noteOn(byte pitch)
{
  midiEventPacket_t noteOnMsg = {0x09, 0x90, pitch, 127};
  MidiUSB.sendMIDI(noteOnMsg);
  MidiUSB.flush();
}

void noteOff(byte pitch)
{
  midiEventPacket_t noteOffMsg = {0x08, 0x80, pitch, 0};
  MidiUSB.sendMIDI(noteOffMsg);
  MidiUSB.flush();
}

void handlePots()
{
  static unsigned long lastReadTime = 0;
  const unsigned long readInterval = 5; // Faster polling (was 10ms)

  if (millis() - lastReadTime < readInterval)
    return;
  lastReadTime = millis();

  for (int i = 0; i < 15; i++)
  {
    // Select the channel on the multiplexer
    selectMuxChannel(i);

    // Read the analog value
    int raw = analogRead(MUX_INPUT);
    int mapped = raw / 8;

    if (abs(mapped - potValues[i]) >= potThreshold)
    {
      // Serial.print("Pot ");
      // Serial.print(i);
      // Serial.print(" (CC ");
      // Serial.print(potCCs[i]);
      // Serial.print("): ");
      // Serial.println(mapped);

      potValues[i] = mapped;
      sendCC(potCCs[i], mapped);
    }
  }
}

// Select channel on 74HC4067 multiplexer
void selectMuxChannel(int channel)
{
  digitalWrite(MUX_S0, bitRead(channel, 0));
  digitalWrite(MUX_S1, bitRead(channel, 1));
  digitalWrite(MUX_S2, bitRead(channel, 2));
  digitalWrite(MUX_S3, bitRead(channel, 3));
  delayMicroseconds(5); // Reduced settling time for faster response
}

void sendCC(byte cc, byte val)
{
  midiEventPacket_t ccMsg = {0x0B, 0xB0, cc, val};
  MidiUSB.sendMIDI(ccMsg);
  MidiUSB.flush();
}

void handleEncoders()
{
  // ---------- MUSIC SELECTION ENCODER (pins 4, 5) ----------
  int currentState_Music = digitalRead(encoderA_Music);
  if (currentState_Music != encoderLastState_Music)
  {
    int bState = digitalRead(encoderB_Music);
    byte directionValue;

    if (currentState_Music == bState)
    {
      directionValue = 0x41;
      // Serial.println("Music Encoder - CW");
    }
    else
    {
      directionValue = 0x3F;
      // Serial.println("Music Encoder - CCW");
    }

    midiEventPacket_t cc = {0x0B, 0xB0, encoderCC_Music, directionValue};
    MidiUSB.sendMIDI(cc);
    MidiUSB.flush();

    encoderLastState_Music = currentState_Music;
  }

  // ---------- JOG WHEEL ENCODER 1 (pins 8, 9) ----------
  int currentState_Jog1 = digitalRead(encoderA_Jog1);
  if (currentState_Jog1 != encoderLastState_Jog1)
  {
    int bState = digitalRead(encoderB_Jog1);
    byte directionValue;

    if (currentState_Jog1 == bState)
    {
      directionValue = 0x41;
      // Serial.println("Jog Wheel 1 - CW");
    }
    else
    {
      directionValue = 0x3F;
      // Serial.println("Jog Wheel 1 - CCW");
    }

    midiEventPacket_t cc = {0x0B, 0xB0, encoderCC_Jog1, directionValue};
    MidiUSB.sendMIDI(cc);
    MidiUSB.flush();

    encoderLastState_Jog1 = currentState_Jog1;
  }

  // ---------- JOG WHEEL ENCODER 2 (pins 6, 7) ----------
  int currentState_Jog2 = digitalRead(encoderA_Jog2);
  if (currentState_Jog2 != encoderLastState_Jog2)
  {
    int bState = digitalRead(encoderB_Jog2);
    byte directionValue;

    if (currentState_Jog2 == bState)
    {
      directionValue = 0x41;
      // Serial.println("Jog Wheel 2 - CW");
    }
    else
    {
      directionValue = 0x3F;
      // Serial.println("Jog Wheel 2 - CCW");
    }

    midiEventPacket_t cc = {0x0B, 0xB0, encoderCC_Jog2, directionValue};
    MidiUSB.sendMIDI(cc);
    MidiUSB.flush();

    encoderLastState_Jog2 = currentState_Jog2;
  }
}

// ---------- PCF8575 I2C FUNCTIONS ----------

// Read all 16 inputs from PCF8575 as a 16-bit value
uint16_t readPCF8575()
{
  static unsigned long lastWarning = 0;

  if (pcf8575Addr == 0)
  {
    if (millis() - lastWarning > 1000)
    {
      // Serial.println("Skipping PCF8575 read: no expander detected");
      lastWarning = millis();
    }
    return 0xFFFF;
  }

  Wire.requestFrom(pcf8575Addr, (uint8_t)2); // Request 2 bytes

  uint8_t low = 0xFF; // Default to all 1s (unpressed)
  uint8_t high = 0xFF;

  if (Wire.available() >= 1)
  {
    low = Wire.read();
  }
  if (Wire.available() >= 1)
  {
    high = Wire.read();
  }

  // Combine into 16-bit value
  uint16_t value = ((uint16_t)high << 8) | low;
  return value;
}

bool detectPCF8575()
{
  for (byte addr = PCF8575_ADDR_START; addr <= PCF8575_ADDR_END; addr++)
  {
    Wire.beginTransmission(addr);
    byte error = Wire.endTransmission();
    if (error == 0)
    {
      pcf8575Addr = addr;
      return true;
    }
  }

  pcf8575Addr = 0;
  return false;
}

void configurePCF8575Inputs()
{
  // PCF8575 uses quasi-bidirectional pins. Writing HIGH configures pins as inputs.
  Wire.beginTransmission(pcf8575Addr);
  Wire.write(0xFF);
  Wire.write(0xFF);
  byte error = Wire.endTransmission();

  if (error == 0)
  {
    // Serial.println("PCF8575 configured for input pull-high");
  }
  else
  {
    // Serial.print("PCF8575 init write failed, error=");
    // Serial.println(error);
  }
}
