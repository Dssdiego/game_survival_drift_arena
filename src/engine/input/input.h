//
// Created by Diego Santos Seabra on 16/08/21.
//

#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_haptic.h>
#include <SDL_joystick.h>

// These are generally copied from the SDL2 Scancode Keys,
// which are in turn based on the USB standards:
// https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf
enum class Key {
    Unknown = 0,

    A = 4,
    B = 5,
    C = 6,
    D = 7,
    E = 8,
    F = 9,
    G = 10,
    H = 11,
    I = 12,
    J = 13,
    K = 14,
    L = 15,
    M = 16,
    N = 17,
    O = 18,
    P = 19,
    Q = 20,
    R = 21,
    S = 22,
    T = 23,
    U = 24,
    V = 25,
    W = 26,
    X = 27,
    Y = 28,
    Z = 29,

    Number1 = 30,
    Number2 = 31,
    Number3 = 32,
    Number4 = 33,
    Number5 = 34,
    Number6 = 35,
    Number7 = 36,
    Number8 = 37,
    Number9 = 38,
    Number0 = 39,

    Return = 40,
    Escape = 41,
    Backspace = 42,
    Tab = 43,
    Space = 44,

    Minus = 45,
    Equals = 46,
    LeftBracket = 47,
    RightBracket = 48,
    Backslash = 49,

    Semicolon = 51,
    Apostrophe = 52,
    Grave = 53,
    Comma = 54,
    Period = 55,
    Slash = 56,
    CapsLock = 57,

    F1 = 58,
    F2 = 59,
    F3 = 60,
    F4 = 61,
    F5 = 62,
    F6 = 63,
    F7 = 64,
    F8 = 65,
    F9 = 66,
    F10 = 67,
    F11 = 68,
    F12 = 69,

    PrintScreen = 70,
    ScrollLock = 71,
    Pause = 72,
    Insert = 73,

    Home = 74,
    PageUp = 75,
    Delete = 76,
    End = 77,
    PageDown = 78,

    Right = 79,
    Left = 80,
    Down = 81,
    Up = 82,

    KeypadNumLockClear = 83, // Num lock on PC, clear on Mac keyboards
    KeypadDivide = 84,
    KeypadMultiply = 85,
    KeypadMinus = 86,
    KeypadPlus = 87,
    KeypadEnter = 88,

    Keypad1 = 89,
    Keypad2 = 90,
    Keypad3 = 91,
    Keypad4 = 92,
    Keypad5 = 93,
    Keypad6 = 94,
    Keypad7 = 95,
    Keypad8 = 96,
    Keypad9 = 97,
    Keypad0 = 98,

    KeypadPeriod = 99,
    KeypadEquals = 103,
    KeypadComma = 133,
    
    F13 = 104,
    F14 = 105,
    F15 = 106,
    F16 = 107,
    F17 = 108,
    F18 = 109,
    F19 = 110,
    F20 = 111,
    F21 = 112,
    F22 = 113,
    F23 = 114,
    F24 = 115,

    LeftControl = 224,
    LeftShift = 225,
    LeftAlt = 226, // Alt on windows, option on Mac
    LeftOS = 227, // Windows key, Command (Mac) key

    RightControl = 228,
    RightShift = 229,
    RightAlt = 230, // Alt gr on windows, option on mac
    RighOS = 231, // Windows key, Command (Mac) key

    // Reference: https://www.libsdl.org/tmp/SDL/include/SDL_scancode.h
};

enum class JoystickButton 
{
    None = -1,

    A = 0,
    B = 1,
    X = 2,
    Y = 3,

    Back = 4,
    Select = 5,
    Start = 6,

    LeftStick = 7,
    RightStick = 8,

    Up = 11,
    Down = 12,
    Left = 13,
    Right = 14,
};

enum class MouseButton
{
    None = -1,
    Left = 0,
    Middle = 1,
    Right = 2,
};

enum class KeyPad {


};

enum class Button {

};

class Input
{
public:
//    static bool isPressed();
//    static bool getKeypressed(Key key);
//    static bool getButtonPressed(Button btn);
//    static bool getMouseButtonPressed(MouseButton mouseBtn);

    static void init();
    static void dispose();

    static void vibrateJoystick(float force, int seconds);

    //bool isJoystickConnected();

    static int mouseX, mouseY;
private:
    inline static SDL_Joystick *mJoystick = nullptr;
    inline static SDL_Haptic *mHaptic = nullptr;
};


