#ifndef COMMON_H
#define COMMON_H
namespace ST {
enum ShapeType {
None = 0x00,
Line = 0x01<<0,
Rectangle = 0x01<<1,
Ellipse = 0x01<<2,
Triangle = 0x01<<3,
Diamond = 0x01<<4,
Text = 0x01<<5,
Graph = 0x01<<6,
TypeMask = 0x0f
};
}

#define BACKGROUND_COLOR Qt::blue
#define FOREGROUND_COLOR Qt::white


#endif // COMMON_H
