ESP32 BLE HID Attack Tool

Overview

This project transforms an ESP32 microcontroller into a wireless penetration testing tool that simulates keyboard input attacks via Bluetooth Low Energy (BLE). When activated, the device can execute various pre-programmed payloads on nearby vulnerable computers.

Technical Specifications

· Microcontroller: ESP32 with BLE capabilities
· Protocol: Bluetooth Low Energy HID (Human Interface Device)
· Programming: Arduino Framework with BleKeyboard library
· Input: 4 physical trigger buttons
· Range: Standard BLE range (approximately 10 meters/30 feet)

Attack Vectors (Triggers)

🔴 Trigger 1 - Psychological Attack

· Opens Notepad automatically
· Types intimidating message: "YOUR SYSTEM HAS BEEN HACKED BY ANONYMOUS"
· Creates immediate visual impact on target

🔴 Trigger 2 - Website Redirect

· Automatically opens web browser
· Navigates to hackerseye.in (security research website)
· Can be modified to redirect to any phishing page or malicious site

🔴 Trigger 3 - YouTube Channel Access

· Opens web browser to specific YouTube channel (@hecc21)
· Demonstrates social engineering capabilities
· Could be modified to access malicious video content

🔴 Trigger 4 - System Shutdown

· Most powerful trigger with immediate effect
· Opens Command Prompt with administrative privileges
· Executes force shutdown command: shutdown /s /f /t 0
· Completely disables target computer without warning

How It Works

1. BLE HID Emulation: ESP32 appears as a standard Bluetooth keyboard ("BLE-HID")
2. Button Triggers: Physical buttons activate different attack sequences
3. Keystroke Injection: Sends predefined keyboard commands to target computer
4. Timing Delays: Carefully calibrated to ensure commands execute properly

Security Implications

This device demonstrates several critical security vulnerabilities:

· Wireless attack vector without physical USB connection
· Social engineering through fake keyboard appearance
· Lack of authentication for Bluetooth HID devices
· Automatic command execution without user confirmation

Ethical Considerations

⚠️ This tool should only be used for:

· Security research and education
· Penetration testing with explicit permission
· Demonstrating Bluetooth HID vulnerabilities
· Defensive security training

🚫 Never use this tool for:

· Unauthorized access to systems
· Malicious attacks
· Disrupting critical systems
· Any illegal activities

Protection Measures

To defend against such attacks:

1. Disable Bluetooth when not in use
2. Require authentication for Bluetooth connections
3. Use security software that monitors for keystroke injection
4. Implement device whitelisting for HID devices
5. Keep systems updated with latest security patches

Educational Value

This project serves as an important demonstration of:

· Wireless attack methodologies
· Physical security threats
· Social engineering techniques
· The importance of Bluetooth security
· Real-world implementation of HID spoofing attacks
