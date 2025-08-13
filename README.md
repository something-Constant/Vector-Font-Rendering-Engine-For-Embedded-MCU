## ***Vector Font Rendering Engine For Embedded MCU***
# Overview
I decided to write the Vector Font because I needed a font with different sizes and optimized for a microcontroller, and there wasn't any clear library that had this feature.
In starting this, I have had to write a library for myself, and this repo was born. Currently, it only supports upper-case ASCII, numbers, and some of the necessary symbols, 
as that is all that is required to write something on a screen.

# Features
  - Simulation in Windows using SDL3 & CMD
  - Font 10x10 px
  - All development is in the 'C' programming language.
  - The numeric data type is integer by default
  - Flexibility
    - variable size
    - variable depth
  - support for runtime scaling of fonts 

# File Index
  - PC LCD Simulation/GraphicLCDSimulation.c - Graphics Display Unit Tests in CMD.
  - PC LCD Simulation/SDL_Simulation.c - Graphics Display Unit Tests in SDL.
  - Embedded MCU Execution/Inc/Font/font_10x10.h - Vector Font.
  - Embedded MCU Execution/Inc/Font/font_render_engine.h - Vector Font Rendering Engine.
  - Embedded MCU Execution/Inc/ssd1306/ssd1306.h - ssd1306 header Library using I2C.
  - Embedded MCU Execution/Inc/ssd1306/ssd1306.h - ssd1306 source Library using I2C.
  - Embedded MCU Execution/Src/main.c - Test Application using HAL library for STM32F1XX.

# Gallery
  ### **CDM simulation test**
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/8cb3b126-5a16-4a5f-b7a3-5c541a722799" />
  
  ### **CDM Font scaling**
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/08770fd0-ac5c-49c2-800b-dff9cf5aa662" />
    
  ### **CDM Bezier curve**
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/0f58d14a-440a-4c2c-8102-67825537c5a5" />

  ### **SDL Bezier curve**
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/8efdbb7c-f8a8-493b-b7dd-e1931a9279ab" />
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/cd2b8d4a-464f-4258-87e9-e8b1c57ad2ce" />

  ### **ssd1306 Bezier curve**
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/52794e61-89f0-4667-abf5-6aa433c0696a" />
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/6894ba80-0f14-4363-a7bf-7527a8a5246c" />

  ### **ssd1306 font**
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/d6dd21a1-c43a-487e-bbec-503d377ede2b" />
    
  ### **ssd1306 font scaling**
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/41af0e4d-3b1c-4f26-aeb7-9b72a93d64ee" />
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/c3110446-16e1-4823-bf44-d784eba0f7cd" />
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/f8c1d9c8-15f9-4c1f-9b9b-35431ef099c0" />
  

  ### **ssd1306 Test Application**
  <img width="480" height="369" alt="image" src="https://github.com/user-attachments/assets/f86a1424-398b-4f80-8a33-f7581078538e" />

  # Developed By
  - Mohamad Hoseyn Meymandi
    - [Email](https://mail.google.com/mail/?view=cm%to=mohamadmeymandi82@gmail.com)
    - [Telegram](https://t.me/mohamad_electro)
       

      
