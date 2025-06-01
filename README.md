# Arduino-TFT-Menu-Navigation-with-Button-Input
This project demonstrates a simple menu navigation system on a TFT LCD using an Arduino-compatible board. 


Description:
This project demonstrates a simple menu navigation system on a TFT LCD using an Arduino-compatible board. A single push button cycles through multiple menu options displayed on the screen.

Features:
Uses the TFT_eSPI library for easy control of the TFT display.
Single button input with debouncing to navigate between menu items.
Displays different menu pages such as "Temperature", "Acceleration", and "Current Time".
Clean and modular code structure for easy extension.

Hardware requirements:
Arduino-compatible board (e.g., ESP32).
TFT LCD compatible with TFT_eSPI library.
Push button connected to pin 12 (configured as input with pull-up).

Libraries used:
TFT_eSPI (for display control)
SPI (for SPI communication)
