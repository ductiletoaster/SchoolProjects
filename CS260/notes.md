#CS 260 Notes

###08.27.2015
Hardware control
- Assembly controls hardware more so than higher level languages so it is used to created libraries like DirectX
- Drivers faciliate communication between applications and hardware.
- Drivers are also applications for performing specific tasks

DirectX
- Is a technology and C++ is the means in which we implement it
- An api that abstracts the functionality for interfacing with the overall system

###09.03.2015
```
Game Development (DirectX)
    |
    |               Describe
Windows (GUI) ----- Register
    |               Create
    |               Show
Event-Driven
```

#### Describe
Windows Programming
- Primarily written in C++ (OOP)
- Classes contain funtions and variables both of which are called members

lpfnWndProc is a refrence to a callback function/procedure
```CPP
WNDCLASSEX windowClass = { 0 };
windowClass.lpfnWndProc = WindProc; // Callback function
```

#### Register
Pass the above class object by refrence to the register
```CPP
if (!RegisterClassEx(&windowClass))
{
    return -1 // Failed to register -- Handle error
}
```

