// project using ATtiny85 with SSD1306 OLED Display to create a simplest possible game (dice game)

// created by upir, 2023
// youtube channel: https://www.youtube.com/upir_upir

// YOUTUBE VIDEO: https://youtu.be/RmhiZg_6-Mo
// SOURCE FILES: https://github.com/upiir/attiny85_dice_game
// WOKWI simulation: https://wokwi.com/projects/380812233514546177

// Links from the video:
// ATtiny85 chip: https://s.click.aliexpress.com/e/_DeT7tBh
// Arduino UNO: https://s.click.aliexpress.com/e/_AXDw1h
// Arduino prototyping shield: https://s.click.aliexpress.com/e/_ApbCwx
// Avrdudess (uploading HEX file to Arduino): https://blog.zakkemble.net/avrdudess-a-gui-for-avrdude/
// U8X8 Documentation: https://github.com/olikraus/u8g2/wiki/u8x8reference
// Previous project with ATTINY85+OLED: https://wokwi.com/projects/378925799915970561
// Image2cpp (convert array to image): https://javl.github.io/image2cpp/
// Photopea (online graphics editor like Photoshop): https://www.photopea.com

// Videos using ATtiny85 chip: https://www.youtube.com/playlist?list=PLjQRaMdk7pBbt-is-fkRmUoRcV4dzraYH

// Related videos with Arduino UNO and 128x64 OLED screen:
// Arduino + OLED displays: https://www.youtube.com/playlist?list=PLjQRaMdk7pBZ1UV3IL5ol8Qc7R9k-kwXA



#include <Arduino.h>
#include <U8x8lib.h> // u8x8 library for drawing on the OLED display

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 4, /* data=*/ 3, /* reset=*/ U8X8_PIN_NONE); // software IIC communication with the OLED display

// images were generated using the image2cpp website
// when generating images, make sure to set the Draw mode to Vertical
// and delete "PROGMEM" word after generating the arrays

// ' tile_dice_empty', 8x8px
unsigned char epd_bitmap__tile_dice_empty [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// ' tile_dice_dot', 8x8px
unsigned char epd_bitmap__tile_dice_dot [] = {
	0x00, 0x3c, 0x7e, 0x7e, 0x7e, 0x7e, 0x3c, 0x00
};
// ' tile_outline_left', 8x8px
 unsigned char epd_bitmap__tile_outline_left [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff
};
// ' tile_outline_right', 8x8px
unsigned char epd_bitmap__tile_outline_right [] = {
	0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// ' tile_outline_bottom', 8x8px
 unsigned char epd_bitmap__tile_outline_bottom [] = {
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
};
// ' tile_outline_top', 8x8px
unsigned char epd_bitmap__tile_outline_top [] = {
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80
};


// dice dots lookup table, 0=empty, 1=dot
byte dice_tile_lookup[7][9] = {
  { // 0 - fully empty dice, displayed when the game has not started yet
    0, 0, 0,
    0, 0, 0, 
    0, 0, 0
  },
  { // 1
    0, 0, 0,
    0, 1, 0, 
    0, 0, 0
  },
  { // 2
    1, 0, 0,
    0, 0, 0, 
    0, 0, 1
  },
  { // 3
    1, 0, 0,
    0, 1, 0, 
    0, 0, 1
  },
  { // 4
    1, 0, 1,
    0, 0, 0, 
    1, 0, 1
  },
  { // 5
    1, 0, 1,
    0, 1, 0, 
    1, 0, 1
  },
  { // 6
    1, 0, 1,
    1, 0, 1, 
    1, 0, 1
  }
};


void setup(void)
{
  u8x8.begin(); // display initialization
  u8x8.setPowerSave(0); // this is required

  // draw outline of the dice
  // since drawing the outlines made from individual images takes some time (because we use software IIC)
  // the drawing is in the order that it looks like it´s being drawn as a continuous line
  
  u8x8.drawTile(/*x*/3, /*y*/2, /*tiles*/1, epd_bitmap__tile_outline_top); 
  u8x8.drawTile(/*x*/4, /*y*/2, /*tiles*/1, epd_bitmap__tile_outline_top); 
  u8x8.drawTile(/*x*/5, /*y*/2, /*tiles*/1, epd_bitmap__tile_outline_top);     

  u8x8.drawTile(/*x*/6, /*y*/3, /*tiles*/1, epd_bitmap__tile_outline_right);       
  u8x8.drawTile(/*x*/6, /*y*/4, /*tiles*/1, epd_bitmap__tile_outline_right);       
  u8x8.drawTile(/*x*/6, /*y*/5, /*tiles*/1, epd_bitmap__tile_outline_right);       

  u8x8.drawTile(/*x*/5, /*y*/6, /*tiles*/1, epd_bitmap__tile_outline_bottom);       
  u8x8.drawTile(/*x*/4, /*y*/6, /*tiles*/1, epd_bitmap__tile_outline_bottom);       
  u8x8.drawTile(/*x*/3, /*y*/6, /*tiles*/1, epd_bitmap__tile_outline_bottom);           

  u8x8.drawTile(/*x*/2, /*y*/5, /*tiles*/1, epd_bitmap__tile_outline_left);         
  u8x8.drawTile(/*x*/2, /*y*/4, /*tiles*/1, epd_bitmap__tile_outline_left);         
  u8x8.drawTile(/*x*/2, /*y*/3, /*tiles*/1, epd_bitmap__tile_outline_left);      
  
  u8x8.drawTile(/*x*/3+7, /*y*/2, /*tiles*/1, epd_bitmap__tile_outline_top); 
  u8x8.drawTile(/*x*/4+7, /*y*/2, /*tiles*/1, epd_bitmap__tile_outline_top); 
  u8x8.drawTile(/*x*/5+7, /*y*/2, /*tiles*/1, epd_bitmap__tile_outline_top);     

  u8x8.drawTile(/*x*/6+7, /*y*/3, /*tiles*/1, epd_bitmap__tile_outline_right);       
  u8x8.drawTile(/*x*/6+7, /*y*/4, /*tiles*/1, epd_bitmap__tile_outline_right);       
  u8x8.drawTile(/*x*/6+7, /*y*/5, /*tiles*/1, epd_bitmap__tile_outline_right);       

  u8x8.drawTile(/*x*/5+7, /*y*/6, /*tiles*/1, epd_bitmap__tile_outline_bottom);       
  u8x8.drawTile(/*x*/4+7, /*y*/6, /*tiles*/1, epd_bitmap__tile_outline_bottom);       
  u8x8.drawTile(/*x*/3+7, /*y*/6, /*tiles*/1, epd_bitmap__tile_outline_bottom);           

  u8x8.drawTile(/*x*/2+7, /*y*/5, /*tiles*/1, epd_bitmap__tile_outline_left);         
  u8x8.drawTile(/*x*/2+7, /*y*/4, /*tiles*/1, epd_bitmap__tile_outline_left);         
  u8x8.drawTile(/*x*/2+7, /*y*/3, /*tiles*/1, epd_bitmap__tile_outline_left);     

  u8x8.setFont(u8x8_font_chroma48medium8_r); // set u8x8 font, list of the available fonts is here: https://github.com/olikraus/u8g2/wiki/fntlist8x8
  u8x8.drawString(0,1,"   Dice Game!   "); // draw a string, include spaces to delete anything that was drawn previously  

  pinMode(0, INPUT);


}

// function to draw 3x3 dice on defined position, dice is made either from dot or empty piece
// note that outline is not redrawn, as it´s outside the cube, and only drawn once on startup
void draw_dice(byte xoffset, byte yoffset, byte dice_number, byte dice_number_previous) {

  // update all 9 sections of the dice
  for (byte i = 0; i < 9; i++) {
    // update all 9 sections, but only redraw areas that are different from the previously displayed dice
    // this speeds up the redrawing quite a lot    
    if ((dice_tile_lookup[dice_number][i] == 1) && (dice_tile_lookup[dice_number_previous][i] != 1)) {
      u8x8.drawTile(/*x*/xoffset + (i % 3), /*y*/yoffset + (i / 3), /*tiles*/1, epd_bitmap__tile_dice_dot); // draw dot tile      
    } 
    else if ((dice_tile_lookup[dice_number][i] == 0) && (dice_tile_lookup[dice_number_previous][i] != 0)) {
      u8x8.drawTile(/*x*/xoffset + (i % 3), /*y*/yoffset + (i / 3), /*tiles*/1, epd_bitmap__tile_dice_empty); // draw empty tile    
    }
  }
}  

byte dice_left = 0; // value for the left dice
byte dice_right = 0; // value for the right dice

byte dice_left_prev = 0; // previous value, used to not redraw all the dots
byte dice_right_prev = 0; // previous value, used to not redraw all the dots

unsigned long elapsed_time_millis; // time in milliseconds since the sketch started
unsigned long elapsed_time_millis_prev; // previously measured time

byte game_status = 0; // game status: 0: waiting for the game to start, 1: game is running, 2: game has ended



void loop(void) // main loop
{

  if (game_status == 1) {
    // game is running, find out if the elapsed time between the last frame was bigger than 500ms
    // and if that´s the case, show different values for dices    
    elapsed_time_millis = millis(); // get the time from starting the sketch in milliseconds
    if ((elapsed_time_millis - elapsed_time_millis_prev) > 500) { // time from last dices update is > 500ms ==> update dices
      // randomize new dices...
      dice_left = random(1, 6);
      dice_right = random(1, 6);  
      //...and draw them
      draw_dice(3, 3, /*number*/ dice_left, /*number previous*/ dice_left_prev);
      draw_dice(10, 3, /*number*/ dice_right, /*number previous*/ dice_right_prev);  
      // update the previous values
      dice_left_prev = dice_left;
      dice_right_prev = dice_right;
      // update the previously measured time
      elapsed_time_millis_prev = elapsed_time_millis;
    }
  }
            

  if (digitalRead(0) == HIGH) { // button is pressed
    if (game_status == 0) { // waiting for the game to start ==> start the game
      u8x8.drawString(0,1,"Press btn = stop"); 
      game_status = 1; // start the game
    } else if (game_status == 1) { // game is running ==> find out if there is a winner or not
      if (dice_left == dice_right) { // we have a winner
        u8x8.drawString(0,1,"    Winner!!    "); 
      } else {
        u8x8.drawString(0,1,"Sorry not winner"); 
      }
      game_status = 2; // game is done
    } else if (game_status == 2) {  // game has ended ==> jump back to the beginning
      dice_left = 0; // set dice to empty dice
      dice_right = 0; // set dice to empty dice
      draw_dice(3, 3, /*number*/ dice_left, /*number previous*/ dice_left_prev); // draw empty dice
      draw_dice(10, 3, /*number*/ dice_right, /*number previous*/ dice_right_prev); // draw empty dice
      dice_left_prev = dice_left;
      dice_right_prev = dice_right;
      u8x8.drawString(0,1,"   Dice Game!   "); 
      game_status = 0; // waiting for game to start
    }

    delay(50); // add a small delay to not accidentaly jump between multiple different steps
  }

}