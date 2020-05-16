#include "Quaternion.h"

Quaternion::Quaternion(float x, float y, float z, float w)
{
    this.x = x;
    this.y = y;
    this.z = z;
    this.w = w;

}


Quaternion Quaternion::soustraction(Quaternion Q1, Quaternion Q2){
    /// fait la soustraction du premier quaternion avec le deuxième et retourne le résultat sous la forme d'un nouveau quaternion
    float x = Q1.x - Q2.x;
    float y = Q1.y - Q2.y;
    float z = Q1.z - Q2.z;
    float w = Q1.w - Q2.w;

    return Quaternion(x,y,z,w);
}


Quaternion Quaternion::addition(Quaternion Q1, Quaternion Q2){
    /// aditionne 2 quaternions et retourne le résultat sous la forme d'un nouveau quaternion
    float x = Q1.x + Q2.x;
    float y = Q1.y + Q2.y;
    float z = Q1.z + Q2.z;
    float w = Q1.w + Q2.w;

    return quaternion(x,y,z,w);
}


Quaternion Quaternion::multiplication(Quaternion Q1, Quaternion Q2){
    /// multiplie 2 quaternions et retourne le résultat sous la forme d'un nouveau quaternion
    float x = (Q1.y * Q2.z) - (Q1.z * Q2.y) + (Q2.w * Q1.x) + (Q1.w * Q2.x);
    float y = (Q1.z * Q2.x) - (Q1.x * Q2.z) + (Q2.w * Q1.y) + (Q1.w * Q2.y);
    float z = (Q1.x * Q2.y) - (Q1.y * Q2.x) + (Q2.w * Q1.z) + (Q1.w * Q2.z);
    float w = (Q1.w * Q2.w) - (Q1.x * Q2.x) - (Q1.y * Q2.y) - (Q1.z * Q2.z);

    return Quaternion(x,y,z,w);
}


Quaternion Quaternion::conjugue(Quaternion Q){
    x = - Q.x;
    y = - Q.y;
    z = - Q.z;

    return Quaternion(x,y,z,Q.z);
}

float Quaternion::norme(Quaternion Q){
    return x*x + y*y + z*z + w*w;
}

