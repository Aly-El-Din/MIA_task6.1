#include <Wire.h>

const int MPU=0x68;//I2C address of MPU6050
  
int16_t GYRO_Z,gyro_error_z;
float elapsed_time,current_time,previous_time,Yaw;
int c=0;
void setup()
{
  Serial.begin(9600);
  while (Serial.available() == 0);
  Wire.begin(); //Starting commuication
  Wire.beginTransmission(MPU);
  //configuring the power mode of PWR_MGMT_1
  //First we configure register location
  Wire.write(0x6B);
  //Sending values to the predefined register
  Wire.write(0x00);//Sending the value
  Wire.endTransmission(true);
  //Communicating with gyroscope
  Wire.beginTransmission(MPU);
  Wire.write(0x1B);
  Wire.write(0x18);
  calculate_IMU_error();
  delay(50);
}
void loop()
{
  previous_time=current_time;
  current_time=millis();
  elapsed_time=(current_time-previous_time)/1000;
  Wire.beginTransmission(MPU);
  Wire.write(0x43);
  Wire.requestFrom(MPU,6,true);
  GYRO_Z=(Wire.read()<<8 | Wire.read())/131.0;
  GYRO_Z==GYRO_Z+0.79;
  Yaw=Yaw+GYRO_Z*elapsed_time;
  Serial.println("Yaw= ");
  Serial.print(Yaw);
}

void calculate_IMU_error()
{
	  Wire.beginTransmission(MPU);
  	Wire.write(0x43);
  	Wire.endTransmission(false);
  	Wire.requestFrom(MPU,6,true);
  	GYRO_Z=Wire.read()<<8 | Wire.read();
  	gyro_error_z=gyro_error_z/200;
  	Serial.println("Gyro error in z-axis= ");
  	Serial.print(gyro_error_z);
}





