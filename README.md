# Simplest game for ATtiny85 + OLED Display
Learn how to create the simplest possible game using the Arduino-compatible chip, the ATtiny85, together with the SSD1306 128x64px IIC OLED display, one pushbutton, one resistor, a breadboard, and a few wires. 

This project is as simple as possible, but it´s a good starting point for developing more complex games. We will run it on both the breadboard, as well as on the Tinycade handheld game console. The library used for drawing images on the display is U8x8, which is a very simplified version of the u8g2 library. For graphics, we use online graphics editor Photopea, to convert images into C code we use image2cpp website, and to test the project, we use WOKWI, free online arduino emulator. 

Finally, when it´s time to upload the project on the ATtiny85 chip, we need some kind of programmer. Last time, I was using USBtinyISP, but this time, we will use Arduino UNO. Hope you like this tutorial and good luck with creating your own game!


**YOUTUBE video: https://youtu.be/RmhiZg_6-Mo**

**WOKWI project: https://wokwi.com/projects/380812233514546177**


Links from the video:
- ATtiny85 chip: https://s.click.aliexpress.com/e/_DeT7tBh
- Arduino UNO: https://s.click.aliexpress.com/e/_AXDw1h
- Arduino prototyping shield: https://s.click.aliexpress.com/e/_ApbCwx
- Avrdudess (uploading HEX file to Arduino): https://blog.zakkemble.net/avrdudess-a-gui-for-avrdude/
- U8X8 Documentation: https://github.com/olikraus/u8g2/wiki/u8x8reference
- Previous project with ATTINY85: https://wokwi.com/projects/378925799915970561
- Image2cpp (convert array to image): https://javl.github.io/image2cpp/
- Photopea (online graphics editor like Photoshop): https://www.photopea.com

Videos using ATtiny85 chip: https://www.youtube.com/playlist?list=PLjQRaMdk7pBbt-is-fkRmUoRcV4dzraYH

Related videos with Arduino UNO and 128x64 OLED screen:
- Arduino + OLED displays: https://www.youtube.com/playlist?list=PLjQRaMdk7pBZ1UV3IL5ol8Qc7R9k-kwXA


![THUMB_dice_game_arduino_attiny85](https://github.com/upiir/attiny85_dice_game/assets/117754156/b7625279-4300-4857-8673-a1ac062453ae)



Simple animation:

![simplest_arduino_game_dice](https://github.com/upiir/attiny85_dice_game/assets/117754156/3823957f-e4dc-489f-a0f7-1c3df47116b8)


Screenshots from the video:

![CAMTASIA_simplest_dice_game (Time 0_00_12;21)](https://github.com/upiir/attiny85_dice_game/assets/117754156/c7dace58-900a-47a5-9009-2b557906bb93)
![CAMTASIA_simplest_dice_game (Time 0_00_56;16)](https://github.com/upiir/attiny85_dice_game/assets/117754156/12ce56bf-326d-4826-a06a-c409b0410185)
![CAMTASIA_simplest_dice_game (Time 0_01_43;09)](https://github.com/upiir/attiny85_dice_game/assets/117754156/e1b89c9d-8ae7-4815-b34c-52c502393fce)
![CAMTASIA_simplest_dice_game (Time 0_03_59;14)](https://github.com/upiir/attiny85_dice_game/assets/117754156/b52bbe5f-0cc7-4f7b-b745-6f9750289565)
![CAMTASIA_simplest_dice_game (Time 0_05_13;28)](https://github.com/upiir/attiny85_dice_game/assets/117754156/785ecccb-c846-477b-8615-df1aa81e6226)
![CAMTASIA_simplest_dice_game (Time 0_06_26;21)](https://github.com/upiir/attiny85_dice_game/assets/117754156/04b49676-e900-4d14-b01b-575a3cf7a0e0)
![CAMTASIA_simplest_dice_game (Time 0_11_25;21)](https://github.com/upiir/attiny85_dice_game/assets/117754156/4b9c6f06-70d1-43ed-af0b-260472f58970)
![CAMTASIA_simplest_dice_game (Time 0_14_39;26)](https://github.com/upiir/attiny85_dice_game/assets/117754156/7e95d40a-ae0d-4400-89ff-1c88ad508cc9)
![CAMTASIA_simplest_dice_game (Time 0_21_44;08)](https://github.com/upiir/attiny85_dice_game/assets/117754156/6d59c5ce-8ac2-4be7-b3dc-86234ae6827e)
![CAMTASIA_simplest_dice_game (Time 0_22_39;17)](https://github.com/upiir/attiny85_dice_game/assets/117754156/bd2b333f-3bfb-4171-aa4d-b2238dcd4707)
![CAMTASIA_simplest_dice_game (Time 0_22_50;26)](https://github.com/upiir/attiny85_dice_game/assets/117754156/48a2aa23-ca88-4416-90eb-227ab68bbf86)
![CAMTASIA_simplest_dice_game (Time 0_23_14;02)](https://github.com/upiir/attiny85_dice_game/assets/117754156/56abea72-3d05-428b-b255-cdb33b32fa96)
![CAMTASIA_simplest_dice_game (Time 0_23_30;03)](https://github.com/upiir/attiny85_dice_game/assets/117754156/ceee81e2-a930-4312-a62c-31e9384e189d)
![CAMTASIA_simplest_dice_game (Time 0_24_26;03)](https://github.com/upiir/attiny85_dice_game/assets/117754156/f0e9f6f9-9940-4848-b592-4541038af973)
![CAMTASIA_simplest_dice_game (Time 0_24_57;02)](https://github.com/upiir/attiny85_dice_game/assets/117754156/d17939de-5571-4e0d-a135-e9fec0f29be5)
![CAMTASIA_simplest_dice_game (Time 0_26_15;17)](https://github.com/upiir/attiny85_dice_game/assets/117754156/20a6173c-690f-44fa-aaf8-cad068481435)
![CAMTASIA_simplest_dice_game (Time 0_26_19;28)](https://github.com/upiir/attiny85_dice_game/assets/117754156/3c5fa05d-ccbf-403d-9cea-14f6f7190e35)
![CAMTASIA_simplest_dice_game (Time 0_26_45;27)](https://github.com/upiir/attiny85_dice_game/assets/117754156/f7028e05-4d45-4585-9437-f34e7a9dbdf5)
![CAMTASIA_simplest_dice_game (Time 0_26_55;04)](https://github.com/upiir/attiny85_dice_game/assets/117754156/3aaae921-05d1-4fbc-bf5c-2d0f40f34313)
![CAMTASIA_simplest_dice_game (Time 0_27_00;00)](https://github.com/upiir/attiny85_dice_game/assets/117754156/26507516-d9a9-4ecd-bb71-3280315eff58)
![CAMTASIA_simplest_dice_game (Time 0_27_37;24)](https://github.com/upiir/attiny85_dice_game/assets/117754156/24c32de3-fb0c-4f12-b5fd-10959c8c7697)
![CAMTASIA_simplest_dice_game (Time 0_27_39;00)](https://github.com/upiir/attiny85_dice_game/assets/117754156/4105ca21-7c4b-4c3b-8fa9-478212321011)
