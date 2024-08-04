`InputHandler` class has a member function to recieve RawInputBuffer data from corresponding Keyboard & Mouse RawInputBuffer classes.
It will have another member function to process recieved input, and `PerformAction` based on provided data.

## To Figure out
- A better structure for keyboard/mouse RawInputBuffers. Since having them talk to a DLL lib would be a nightmare.
- Whether to use single RawInputBuffer class for both mouse and keybaord or separate classes.

## Sources
https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes