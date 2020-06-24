#include "Quaternion.h"
#include <math.h>

Quaternion::Quaternion(float x, float y, float z, float w)
{
    _x = x;
    _y = y;
    _z = z;
    _w = w;
}


Quaternion Quaternion::soustraction(Quaternion Q1, Quaternion Q2){
    /// fait la soustraction du premier quaternion avec le deuxième et retourne le résultat sous la forme d'un nouveau quaternion
    float x = Q1._x - Q2._x;
    float y = Q1._y - Q2._y;
    float z = Q1._z - Q2._z;
    float w = Q1._w - Q2._w;

    return Quaternion(x,y,z,w);
}


Quaternion Quaternion::addition(Quaternion Q1, Quaternion Q2){
    /// aditionne 2 quaternions et retourne le résultat sous la forme d'un nouveau quaternion
    float x = Q1._x + Q2._x;
    float y = Q1._y + Q2._y;
    float z = Q1._z + Q2._z;
    float w = Q1._w + Q2._w;

    return Quaternion(x,y,z,w);
}


Quaternion Quaternion::multiplication(Quaternion Q1, Quaternion Q2){
    /// multiplie 2 quaternions et retourne le résultat sous la forme d'un nouveau quaternion
    float x = (Q1._y * Q2._z) - (Q1._z * Q2._y) + (Q2._w * Q1._x) + (Q1._w * Q2._x);
    float y = (Q1._z * Q2._x) - (Q1._x * Q2._z) + (Q2._w * Q1._y) + (Q1._w * Q2._y);
    float z = (Q1._x * Q2._y) - (Q1._y * Q2._x) + (Q2._w * Q1._z) + (Q1._w * Q2._z);
    float w = (Q1._w * Q2._w) - (Q1._x * Q2._x) - (Q1._y * Q2._y) - (Q1._z * Q2._z);

    return Quaternion(x,y,z,w);
}


Quaternion Quaternion::conjugue(Quaternion Q){
    float x = - Q._x;
    float y = - Q._y;
    float z = - Q._z;

    return Quaternion(x,y,z,Q._w);
}

float Quaternion::norme(Quaternion Q){
    return sqrt(Q._x * Q._x + Q._y + Q._z + Q._w);
}
