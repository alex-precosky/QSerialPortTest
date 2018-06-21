# About

This is a quick demo of a Visual Studio Qt project that uses the QSerialPort
class to write and read from a serial port.

It's written in C++.

# Requirements
* Qt 5
* Visual Studio or the Microsoft Build Tools (msbuild)

# Compiling
The serial port used is hard-coded in *main.cpp* and should be changed to the
serial port to use.

File *QSerialPortTest.vcxproj.user* needs to have property QTDIR changed to
point to your Qt installation. For example:
```xml
<QTDIR>C:\Qt\5.8\msvc2015_64</QTDIR>
```

Then, issue the command:

```msbuild /p:Configuration=Release QSerialPortTest.sln```

The executable should appear in x64/Release.
