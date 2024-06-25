#include <Arduino.h>

/* this function will be invoked when additionalTask was created */
void anotherTask( void * parameter )
{
  /* loop forever */
  for(;;)
  {
    Serial.println("this is another Task");

    delay(1000);
  }
  /* delete a task when finish,
  this will never happen because this is infinity loop */
  vTaskDelete( NULL );
}

/*This is a third task*/
void thirdTask( void * parameter )
{
  /* loop forever */
  for(;;)
  {
    digitalWrite(19, HIGH);
    vTaskDelay(100);
    digitalWrite(19,LOW);
    delay(1000);
  }
  /* delete a task when finish,
  this will never happen because this is infinity loop */
  vTaskDelete( NULL );
}

void setup()
{
  Serial.begin(115200);
  pinMode(19,OUTPUT);
  /* we create a new task here */
  xTaskCreate(
  anotherTask, /* Task function. */
  "another Task", /* name of task. */
  10000, /* Stack size of task */
  NULL, /* parameter of the task */
  1, /* priority of the task */
  NULL); /* Task handle to keep track of created task */

  /* we create a new task here */
  xTaskCreate(
  thirdTask, /* Task function. */
  "Third Task", /* name of task. */
  10000, /* Stack size of task */
  NULL, /* parameter of the task */
  1, /* priority of the task */
  NULL); /* Task handle to keep track of created task */
}

/* the forever loop() function is invoked by Arduino ESP32 loopTask */
void loop()
{
  Serial.println("this is ESP32 Task");
  digitalWrite(LED_BUILTIN, HIGH);
  vTaskDelay(100);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}

