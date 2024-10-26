#ifndef VEC_MATH_HPP
#define VEC_MATH_HPP





#include "raylib.h"

// Addition operators
inline Vector2 operator+(const Vector2& v1, const Vector2& v2) {
     return { v1.x + v2.x, v1.y + v2.y };
}

inline Vector2& operator+=(Vector2& v1, const Vector2& v2) {
     v1.x += v2.x;
     v1.y += v2.y;
     return v1;
}

// Subtraction operators
inline Vector2 operator-(const Vector2& v1, const Vector2& v2) {
     return { v1.x - v2.x, v1.y - v2.y };
}

inline Vector2& operator-=(Vector2& v1, const Vector2& v2) {
     v1.x -= v2.x;
     v1.y -= v2.y;
     return v1;
}

// Multiplication operators
inline Vector2 operator*(const Vector2& v, float scalar) {
     return { v.x * scalar, v.y * scalar };
}

inline Vector2 operator*(float scalar, const Vector2& v) {
     return v * scalar;
}

inline Vector2& operator*=(Vector2& v, float scalar) {
     v.x *= scalar;
     v.y *= scalar;
     return v;
}

// Division operators
inline Vector2 operator/(const Vector2& v, float scalar) {
     return scalar != 0.0f ? Vector2{ v.x / scalar, v.y / scalar } : Vector2{ 0, 0 };
}

inline Vector2& operator/=(Vector2& v, float scalar) {
     if (scalar != 0.0f) {
          v.x /= scalar;
          v.y /= scalar;
     }
     else {
          v.x = 0;
          v.y = 0;
     }
     return v;
}


inline void RenderTexture(const Texture2D& texture, Vector2 position, float rotation, 
     float scale=1.0, Color tint=WHITE)
{
     float width = texture.width * scale;
     float height = texture.height * scale;

     Rectangle source = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
     Rectangle dest = { position.x, position.y, width, height };
     Vector2 origin = { width * 0.5f, height * 0.5f };

     DrawTexturePro(texture, source, dest, origin, rotation, tint);
}

#endif // !VEC_MATH_HPP