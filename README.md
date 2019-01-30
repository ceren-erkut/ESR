# ESR
The device is developed on a PCB and the Arduino Uno microcontroller. Erythrocyte sedimentation rate in human blood is measured with infrared optical analysis.

Uno controls the volume of IR LED, pinch valve and measurement duration. An IR photodetector (800-1000nm, opt. 900nm) detects the IR radiation emitted across the blood. A transimpedance amplifier and a filter prepare proper input for the Uno. Uno samples at every 200 ms and simultaneously toggles the valve at every 500 ms. The whole process (including the sampling) lasts for 5 min.

Below is a circuitry of the pcb developped for the whole process.
https://easyeda.com/cerne/valvecontrol
