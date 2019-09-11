# LED Clock
<p align="center">
  <img src="https://raw.githubusercontent.com/wiki/jakubwieczorek/spectral_clock/overall.JPG" width="900" />
</p>

## About 
LED clock or Spectral Clock is a device which consist of a bar with over a dozen of leds attached to it and motor which accelerates the bar to quite huge speed. LEDs are controlled by the microcontroller and when the motor speed is big enough switching off and on the leds in strictly defined moments results in continues image. The image is just an impression, because the human eye is unable to notice the differences or the changes in objects which oscillates more than 20Hz. Taking above into consideration 1200 turns the engine per minute results in a pure continues image. Lets say in simpliest example one led will be switched on all the time. Then observer will see the circle. Imagine what will happen if microcontroller calculate the time of ratio and basing on that time the half of it turn on the led and the second turn off. Then he'll see a half of the circle. Because of huge microcontroller computing power leds can be turned off and on whenever the constructor or programmer wants, so it is possible to display quite sophisticated pictures like this one below.

<p align="center">
  <img src="https://raw.githubusercontent.com/wiki/jakubwieczorek/spectral_clock/clocks.png" width="900" />
</p>

In order to change the picture was written dedicated android application.

<p align="left">
  <img src="https://raw.githubusercontent.com/wiki/jakubwieczorek/spectral_clock/connection_success.png" width="200" />
</p>

**To find out more, please check out the [spectral clock wiki][wiki].**

**Video from the action [https://www.youtube.com/watch?v=dwCs7caOApE&feature=youtu.be][yt]**

## Project structure
The Spectral Clock project consist of a few connected parts, because it isn't itself only a software. The project is divided into:

| **Hardware**     | **Microcontroller**     | **PCBs**           | **Mobile app** |
|-------------------------------------|-------------------------------|-----------------------------------|-----------------------------------|
| Engine, connection between parts, wood case and different harware stuff related to the device construction. Check [hardware wiki][hardware_wiki].| STM32 project written in HAL library help and STMCubeMX generator which has the logic responsible for controlling the image displayed by leds. Check [microcontroller wiki][microcontroller_wiki].| Clock's bar designed in Altium environment with the microcontroller, leds and rest electronic elements. Also PCB for BLDC controller. Check [PCBs wiki][pcbs_wiki]. | The user interface which is Android mobile application written in Java. Enables changing the images by user remotly via bluetooth. Check [mobile app wiki][mobile_wiki]. |

## Questions or need help?
Don't hesitate to send me a mail on jakub.wieczorek0101@gmail.com.

## Copyright and license
Spectral Clock project is copyright to Jakub Wieczorek under the [MIT License](https://opensource.org/licenses/MIT).

[wiki]: https://github.com/jakubwieczorek/spectral_clock/wiki
[yt]: https://www.youtube.com/watch?v=dwCs7caOApE&feature=youtu.be
[hardware_wiki]: https://github.com/jakubwieczorek/spectral_clock/wiki/Hardware
[microcontroller_wiki]: https://github.com/jakubwieczorek/spectral_clock/wiki/Microcontroller
[pcbs_wiki]: https://github.com/jakubwieczorek/spectral_clock/wiki/PCBs
[mobile_wiki]: https://github.com/jakubwieczorek/spectral_clock/wiki/Mobile-application
