# **Project Luminescence** ✨

A custom heart-shaped PCB with 10 red LEDs and smooth brightness control. A handmade birthday gift built for my girlfriend :)

---

## **Hardware:**

- **Microcontroller**: ATtiny85-20PU (low power consumption)
- **Power**: CR2032 coin cell battery (mounted on back)
- **LEDs**: 10× 5mm red LEDs arranged around the heart perimeter
- **Input**: 6mm tactile push button (for mode cycling)
- **Brightness Control**: 1kΩ potentiometer for analog LED dimming
- **Power Switch**: SPDT slide switch (on/off control on back)
- **PCB**: 70×70mm blue FR-4, 2-layer, white silkscreen

---

## **Firmware:**

### Current Features:
- 50ms button debouncing
- Mode cycling: OFF → ON → FADE
- Gamma-corrected PWM brightness control
- Smooth sine-wave breathing effect
- Analog trimpot brightness scaling

---

## **Reproduction**

Full source files included:
- **KiCad schematic & PCB layout** (`kicad/`)
- **Gerber files** for manufacturing (`kicad/gerbers/`)
- **BOM.csv** for component sourcing
- **Firmware** with clean git history (`firmware/`)

See `BOM.csv` for component suppliers and part numbers.<br>
(and change the silkscreen message lmao)

---
