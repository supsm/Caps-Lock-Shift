# Caps Lock Shift  
  
Makes it so that the caps lock key toggles shift.  
When <kbd>Caps</kbd> is pressed, the program turns off `Caps Lock` and holds <kbd>Shift</kbd> until <kbd>Caps</kbd> is pressed again.  
  
Unfortunately, because the program turns off caps lock, the way that I've implemented the Shift Lock indicator is by flashing the `Caps Lock` light. This means that occasionally, `Caps Lock` is on while the Shift Lock is also on, resulting in lowercase letters.  
The program does this, since when `Caps Lock` is on, shift actually undoes the capitalization that `Caps Lock` does.  
  
If you close the program while the Shift Lock is on, it will still be holding down shift. To fix this, simply press the left <kbd>Shift</kbd> (and release it).  
Similarly, if you press the left <kbd>Shift</kbd> when the Shift Lock is on, it won't work until you retoggle it (Press <kbd>Caps</kbd> twice).  
  
It is recommended to run this app on startup. To do so, place the downloaded `.exe` file into `%appdata%\Microsoft\Windows\Start Menu\Programs\Startup` or the folder that opens when `shell:startup` is entered into Run (<kbd>Win</kbd>+<kbd>R</kbd>). Note that it takes a minute or two after startup to actually run the startup folder apps.  
