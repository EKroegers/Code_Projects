res holds statis resources such as databases, images, etc.

# WxWidgets Download and Configuration 
- video used for reference [here](https://www.youtube.com/watch?v=tHMGA0jIl3Y)
- WxWidgets Version: [3.2.2.1](https://www.wxwidgets.org/downloads/) 
- Additional resources needed
    - [CMake](https://cmake.org/download/)
    - [MinGW](https://osdn.net/projects/mingw/)
- To build on your local machine, follow the instructions in the reference video (5:30-11:30)
- To configure VS Code for use, follow the instructions in the reference video (12:54-36:22)
- Once your project is configured for your machine, to be able to run you will have to move the .dll files into the .build/debug and .build/release folder
    - The files that need to be moved into the .build/debug from your local wxwidgets folder are "wxbase32ud_gcc_custom.dll" and "wxmsw32ud_core_gcc_custom.dll"
    - The files that need to be moved into the .build/debug from your local wxwidgets folder are "wxbase32u_gcc_custom.dll" and "wxmsw32u_core_gcc_custom.dll"
- After those files are moved into your project, and your .json files are correctly formatted in vs code then are going to select main.cpp, click terminal, the click run build task. There should be two options and I choose to do a debug build. 
- And once you do th debug build, there will be a .exe file in the .build/debug folder which will open the project 

--- 
## WxMathPlot 
- [Download Link](https://sourceforge.net/projects/wxmathplot/files/)
