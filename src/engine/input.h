//
// Created by Diego Santos Seabra on 16/08/21.
//

#pragma once

//enum Key {
//    A, B, C, D, E, F, G,
//    H, I, J, K, L, M, N,
//    O, P, Q, R, S, T, U,
//    V, W, X, Y, Z,
//    LEFT_SHIFT, RIGHT_SHIFT,
//    LEFT_ALT, RIGHT_ALT,
//    LEFT_CONTROL, RIGHT_CONTROL,
//    ARROW_LEFT, ARROW_RIGHT
//};

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

    Alpha1 = 30,
    Alpha2 = 31,
    Alpha3 = 32,
    Alpha4 = 33,
    Alpha5 = 34,
    Alpha6 = 35,
    Alpha7 = 36,
    Alpha8 = 37,
    Alpha9 = 38,
    Alpha0 = 39,

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

    PrintScreen = 74,
    PageUp = 75,
    Delete = 76,
    End = 77,
    PageDown = 78,

    Right = 79,
    Left = 80,
    Down = 81,
    Up = 82,

    KeypadNumLock = 84,
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

    F13 = 104,

    // TODO: Continue implementation >> https://www.libsdl.org/tmp/SDL/include/SDL_scancode.h
};

enum class KeyPad {


};

enum class Button {

};

class Input
{
public:
    bool isPressed();
};


