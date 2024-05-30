# Coin Counting and Automatic Water Dispensing System

This project is designed to count coins and dispense water automatically based on the total value of coins inserted. The system uses an LCD to display the count of different coin types and the total amount, and a relay to control the water dispensing mechanism.

## Components

- Arduino Uno
- LiquidCrystal I2C LCD (16x2)
- Relay Module
- Resistors
- Wires
- Breadboard
- Coins detection mechanism (can be replaced with push buttons for simulation)

## Features

- **Coin Detection**: Detects and counts coins of three different denominations (1TK, 2TK, and 5TK).
- **Real-time Display**: Uses an LCD to display the count of each coin type and the total amount inserted.
- **Automatic Water Dispensing**: Activates a relay to dispense water based on the total coin value accumulated.
- **Timed Dispense Control**: Dispenses water for a time duration proportional to the total value of coins inserted.
- **Reset Mechanism**: Resets the coin count and total amount after dispensing water.
- **User-friendly Interface**: Provides a clear and interactive display for users to monitor coin counts and total amount.
- **Initialization and Welcome Message**: Displays a welcome message on the LCD during startup.
- **Power-efficient**: Ensures the relay is off at the start to save power.
